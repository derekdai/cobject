#include <stdlib.h>
#include <assert.h>
#include "object.h"

Type object_get_type()
{
	static Type type = TYPE_INVALID;
	if(! type) {
		type = type_register(TYPE_INVALID,
							 "Object",
							 sizeof(ObjectClass),
							 NULL,
							 sizeof(Object),
							 TYPE_FLAGS_ABSTRACT);
	}

	return type;
}

static void object_init(Object * self, Type type)
{
	if(TYPE_OBJECT != type) {
		object_init(self, type_get_parent(type));
	}

	ObjectClass * clazz = OBJECT_CLASS(type_get_class(type));
	if(clazz->init) {
		clazz->init(self);
	}
}

void * object_create_instance(Type type)
{
	assert(type_is(type, TYPE_OBJECT));
	
	Object * object = OBJECT(type_create_instance(type));
	if(object) {
		object_init(object, type);
	}

	return object;
}

void object_free(void * self)
{
	free(self);
}
