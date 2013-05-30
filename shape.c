#include <stddef.h>
#include <assert.h>
#include "shape.h"

static void shape_init(Shape * self)
{
    self->argb = 0xffffffff;
}

uint32_t shape_get_argb(const Shape * self)
{
    assert(NULL != self);

    return self->argb;
}

void shape_set_argb(Shape * self, uint32_t argb)
{
    assert(NULL != self);

    self->argb = argb;
}

void shape_draw(Shape * self)
{
	assert(NULL != self);
	assert(NULL != SHAPE_CLASS(object_get_class(self))->draw);
	
	SHAPE_CLASS(object_get_class(self))->draw(self);
}

const ShapeClass shape_class = {
   OBJECT_CLASS(& object_class),	/* parent */
   "Shape",							/* name */
   sizeof(Shape),					/* instance size */
   (InstanceInitFunc) shape_init,	/* constructor */
   CLASS_FLAGS_ABSTRACT,			/* Shape is uninstantiatable */
   NULL								/* No default draw() function */
};
