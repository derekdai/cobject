#ifndef __TYPE_H_
#define __TYPE_H_

#define TYPE_INVALID (0)

#define TYPE_FROM_INSTANCE(i)					(((TypeInstance *) i)->type)
#define TYPE_FROM_CLASS(c)						(((TypeClass *) c)->type)
#define TYPE_CHECK_INSTANCE_TYPE(i, t)			(type_is(TYPE_FROM_INSTANCE(i), t))
#define TYPE_CHECK_INSTANCE_CAST(i, t, ctype)	(TYPE_CHECK_INSTANCE_TYPE(i, t) ? (ctype *) (i) : NULL)
#define TYPE_CHECK_CLASS_TYPE(c, t)				(type_is(TYPE_FROM_CLASS(c), t))
#define TYPE_CHECK_CLASS_CAST(c, t, ctype)		(TYPE_CHECK_CLASS_TYPE(c, t) ? (ctype *) (c) : NULL)
#define TYPE_INSTANCE_GET_CLASS(i, t, ctype)	(TYPE_CHECK_CLASS_CAST(type_instance_get_class((TypeInstance *) (i)), t, ctype))

typedef unsigned int Type;

typedef enum _TypeFlags TypeFlags;

typedef struct _TypeClass TypeClass;

typedef struct _TypeInstance TypeInstance;

typedef void (* ClassInitFunc)(TypeClass * clazz);

enum _TypeFlags
{
	TYPE_FLAGS_NONE			= 0,
	TYPE_FLAGS_ABSTRACT		= 1 << 1,
};

struct _TypeClass
{
	Type parent;

	Type type;

	char * name;

	size_t class_size;

	ClassInitFunc class_init;

	size_t inst_size;

	TypeFlags flags : 16;

	int inited : 1;
};

struct _TypeInstance
{
	Type type;
};

Type type_register(Type parent,
				   const char * name,
				   size_t class_size,
				   ClassInitFunc class_init,
				   size_t inst_size,
				   TypeFlags flags);

const char * type_get_name(Type type);

TypeClass * type_get_class(Type self);

int type_is_instantiatable(Type self);

TypeInstance * type_create_instance(Type self);

TypeClass * type_instance_get_class(TypeInstance * self);

Type type_get_parent(Type type);

int type_is(Type self, Type other);

#endif /* __TYPE_H_ */
