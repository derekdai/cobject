#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <stddef.h>

#define OBJECT(o) ((Object *)(o))
#define IS_OBJECT(o) (object_class_is(OBJECT_GET_CLASS(o), & object_class))
#define OBJECT_GET_CLASS(o) (object_get_class(o))
#define OBJECT_CLASS(c) ((ObjectClass *) (c))
#define IS_OBJECT_CLASS(c) (object_class_is(c, & object_class))

typedef enum _ClassFlags ClassFlags;

typedef struct _ObjectClass ObjectClass;

typedef struct _Object Object;

typedef void (* InstanceInitFunc)(void * object);

enum _ClassFlags
{
	CLASS_FLAGS_NONE		= 0,
	CLASS_FLAGS_ABSTRACT	= 1 << 1,
};

struct _ObjectClass
{
	const ObjectClass * parent;
	
	const char * name;
	
	size_t inst_size;
	
	InstanceInitFunc inst_init;
	
	ClassFlags flags;
};

struct _Object
{
	const ObjectClass * clazz;
};

void * object_create_instance(const ObjectClass * clazz);

void object_free(void * self);

const void * object_get_class(void * self);

int object_class_is(const ObjectClass * self, const ObjectClass * other);

const char * object_class_get_name(const ObjectClass * self);

extern const ObjectClass object_class;

#endif /* __OBJECT_H_ */
