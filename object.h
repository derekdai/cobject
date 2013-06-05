#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <stddef.h>

#define TYPE_CHECK_INSTANCE_TYPE(o, c)			(object_class_is(object_get_class(o), (c)))
#define TYPE_CHECK_INSTANCE_CAST(o, c, ctype)	(TYPE_CHECK_INSTANCE_TYPE(o, c) ? (ctype *) (o) : NULL)
#define TYPE_INSTANCE_GET_CLASS(o, c, ctype)	(TYPE_CHECK_CLASS_CAST(object_get_class(o), c, ctype))
#define TYPE_CHECK_CLASS_TYPE(c1, c2)			(object_class_is((c1), (c2)))
#define TYPE_CHECK_CLASS_CAST(c1, c2, ctype)	((const ctype *) (c1))

#define OBJECT(o)				(TYPE_CHECK_INSTANCE_CAST(o, & object_class, Object))
#define IS_OBJECT(o)			(TYPE_CHECK_INSTANCE_TYPE(o, & object_class))
#define OBJECT_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, & object_class, ObjectClass))
#define OBJECT_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, & object_class, ObjectClass))
#define IS_OBJECT_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, & object_class))

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
