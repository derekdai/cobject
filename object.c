#include <stdlib.h>
#include <assert.h>
#include "object.h"

static void object_init(Object * self, const ObjectClass * clazz);

void * object_create_instance(const ObjectClass * clazz)
{
	assert(NULL != clazz);
	assert(! (CLASS_FLAGS_ABSTRACT & clazz->flags));
	assert(sizeof(Object) <= clazz->inst_size);
	
	void * self = malloc(clazz->inst_size);
	if(self) {
		OBJECT(self)->clazz = clazz;
		object_init(self, clazz);
	}
	
	return self;
}

void object_free(void * self)
{
	free(self);
}

static void object_init(Object * self, const ObjectClass * clazz)
{
	if(clazz->parent) {
		object_init(self, clazz->parent);
	}
	
	if(clazz->inst_init) {
		clazz->inst_init(self);
	}
}

const void * object_get_class(void * self)
{
	assert(NULL != self);
	
	return OBJECT(self)->clazz;
}

const ObjectClass object_class = {
	NULL,							/* parent */
	"Object",						/* name */
	sizeof(Object),					/* instance size */
	NULL,							/* constructor */
	CLASS_FLAGS_ABSTRACT			/* Object is a abstract class */
};
