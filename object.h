#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <stddef.h>

#define OBJECT_CLASS(c) ((const ObjectClass *) (c))

#define OBJECT(o) ((Object *) (o))

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

extern const ObjectClass object_class;

#endif /* __OBJECT_H_ */
