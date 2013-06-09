#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <stdint.h>
#include "object.h"

#define TYPE_SHAPE				(shape_get_type())
#define SHAPE(o)				(TYPE_CHECK_INSTANCE_CAST(o, TYPE_SHAPE, Shape))
#define IS_SHAPE(o)				(TYPE_CHECK_INSTANCE_TYPE(o, TYPE_SHAPE))
#define SHAPE_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, TYPE_SHAPE, ShapeClass))
#define SHAPE_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, TYPE_SHAPE, ShapeClass))
#define IS_SHAPE_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, TYPE_SHAPE))

typedef struct _ShapeClass ShapeClass;

typedef struct _Shape Shape;

struct _ShapeClass
{
	ObjectClass base;

	void (* draw)(Shape * self);
};

struct _Shape
{
	Object base;

    uint32_t argb;
};

Type shape_get_type();

uint32_t shape_get_argb(const Shape * self);

void shape_set_argb(Shape * self, uint32_t argb);

void shape_draw(Shape * self);

#endif /* __SHAPE_H_ */
