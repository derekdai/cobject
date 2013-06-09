#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "type.h"

#define INIT_REGISTRY_SIZE (1 << 12)

#define SIZE_TO_N_ENTRIES(s) ((s - sizeof(TypeRegistry)) / sizeof(TypeClass *))

#define N_ENTRIES_TO_SIZE(n) (n * sizeof(TypeClass *) + sizeof(TypeRegistry))

typedef struct _TypeRegistry TypeRegistry;

struct _TypeRegistry
{
	size_t n_entries;

	Type next_type;

	TypeClass * classes[0];
};

static void type_class_init(TypeClass * self);

static TypeRegistry * type_registry = NULL;

static TypeRegistry * type_registry_get()
{
	if(! type_registry) {
		type_registry = malloc(INIT_REGISTRY_SIZE);
		type_registry->next_type = 1;
		type_registry->n_entries = SIZE_TO_N_ENTRIES(INIT_REGISTRY_SIZE);
		type_registry->classes[0] = NULL;
	}

	return type_registry;
}

static TypeRegistry * type_registry_get_for_add()
{
	TypeRegistry * self = type_registry_get();
	if(self->next_type >= self->n_entries) {
		size_t new_size = N_ENTRIES_TO_SIZE(self->n_entries);
		self = realloc(self, new_size);
		self->n_entries = SIZE_TO_N_ENTRIES(new_size);
		type_registry = self;
	}

	return self;
}

static Type type_registry_add(TypeClass * clazz)
{
	assert(NULL != clazz);

	TypeRegistry * self = type_registry_get_for_add();
	clazz->type = self->next_type ++;
	self->classes[clazz->type] = clazz;

	return clazz->type;
}

static Type type_registry_get_n_classes()
{
	return type_registry_get()->next_type;
}

static TypeClass * type_registry_get_class(Type type)
{
	assert(type_registry_get_n_classes() > type);

	return type_registry_get()->classes[type];
}

Type type_register(Type parent,
				   const char * name,
				   size_t class_size,
				   ClassInitFunc class_init,
				   size_t inst_size,
				   TypeFlags flags)
{
	assert(NULL != name && 3 <= strlen(name));
	assert(type_registry_get_n_classes() > parent);

	if(parent) {
		assert(type_registry_get_class(parent)->class_size <= class_size);
		assert(type_registry_get_class(parent)->inst_size <= inst_size);
	}
	else {
		assert(sizeof(TypeClass) <= class_size);
		assert(sizeof(TypeInstance) <= inst_size);
	}

	TypeClass * clazz = malloc(class_size);
	* clazz = (TypeClass) {
		.parent		= parent,
		.name		= strdup(name),
		.class_size	= class_size,
		.class_init = class_init,
		.inst_size	= inst_size,
		.flags		= flags,
		.inited		= 0
	};

	if(! clazz) {
		fprintf(stderr, "Out of memory\n");
		abort();
	}

	return type_registry_add(clazz);
}

TypeClass * type_get_class(Type self)
{
	return type_registry_get_class(self);
}

static int type_class_is_inited(TypeClass * self)
{
	return self->inited;
}

static void type_class_do_init(TypeClass * self, Type acestor)
{
	TypeClass * acestor_class = type_get_class(acestor);
	if(! type_class_is_inited(acestor_class)) {
		type_class_init(acestor_class);
	}

	if(TYPE_INVALID != acestor_class->parent) {
		type_class_do_init(acestor_class, acestor_class->parent);
	}

	if(acestor_class->class_init) {
		acestor_class->class_init(self);
	}
}

static void type_class_init(TypeClass * self)
{
	assert(! type_class_is_inited(self));

	if(TYPE_INVALID != self->parent) {
		type_class_do_init(self, self->parent);
	}

	if(self->class_init) {
		self->class_init(self);
	}

	self->inited = 1;
}

int type_is_instantiatable(Type self)
{
	if(TYPE_INVALID == self) {
		return 0;
	}

	if(TYPE_FLAGS_ABSTRACT & type_get_class(self)->flags) {
		return 0;
	}

	return 1;
}

TypeInstance * type_create_instance(Type self)
{
	assert(TYPE_INVALID != self);
	assert(type_is_instantiatable(self));

	TypeClass * clazz = type_get_class(self);
	if(! type_class_is_inited(clazz)) {
		type_class_init(clazz);
	}

	TypeInstance * inst = malloc(clazz->inst_size);
	if(inst) {
		inst->type = self;
	}

	return inst;
}

const char * type_get_name(Type self)
{
	return type_registry_get_class(self)->name;
}

int type_is(Type self, Type other)
{
	Type curr = self;
	do {
		if(curr == other) {
			return 1;
		}

		curr = type_get_class(curr)->parent;
	}
	while(TYPE_INVALID != curr);

	return 0;
}

TypeClass * type_instance_get_class(TypeInstance * self)
{
	assert(NULL != self);

	return type_get_class(self->type);
}

Type type_get_parent(Type type)
{
	if(TYPE_INVALID == type) {
		return TYPE_INVALID;
	}

	return type_get_class(type)->parent;
}
