#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <stdint.h>
#include "object.h"

#define SHAPE_CLASS(c) ((ShapeClass *) (c))

#define SHAPE(o) ((Shape *) (o))

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
