#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <stddef.h>
#include "type.h"

#define TYPE_OBJECT				(object_get_type())
#define OBJECT(o)				(TYPE_CHECK_INSTANCE_CAST(o, TYPE_OBJECT, Object))
#define IS_OBJECT(o)			(TYPE_CHECK_INSTANCE_TYPE(o, TYPE_OBJECT))
#define OBJECT_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, TYPE_OBJECT, ObjectClass))
#define OBJECT_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, TYPE_OBJECT, ObjectClass))
#define IS_OBJECT_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, TYPE_OBJECT))

typedef struct _ObjectClass ObjectClass;

typedef struct _Object Object;

struct _ObjectClass
{
	TypeClass base;

	void (* init)(Object * self);
	
	void (* destroy)(Object * self);
};

struct _Object
{
	TypeInstance base;
};

Type object_get_type();

void * object_create_instance(Type type);

void object_free(void * self);

const void * object_get_class(void * self);

int object_class_is(const ObjectClass * self, const ObjectClass * other);

const char * object_class_get_name(const ObjectClass * self);

#endif /* __OBJECT_H_ */
