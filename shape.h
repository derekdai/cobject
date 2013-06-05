#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <stdint.h>
#include "object.h"

#define SHAPE(o)				(TYPE_CHECK_INSTANCE_CAST(o, & shape_class, Shape))
#define IS_SHAPE(o)				(TYPE_CHECK_INSTANCE_TYPE(o, & shape_class))
#define SHAPE_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, & shape_class, ShapeClass))
#define SHAPE_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, & shape_class, ShapeClass))
#define IS_SHAPE_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, & shape_class))

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

uint32_t shape_get_argb(const Shape * self);

void shape_set_argb(Shape * self, uint32_t argb);

void shape_draw(Shape * self);

extern const ShapeClass shape_class;

#endif /* __SHAPE_H_ */
