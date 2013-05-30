#include <stddef.h>
#include <assert.h>
#include "shape.h"

void shape_init(Shape * self)
{
    assert(NULL != self);

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
	assert(NULL != self->draw);
	
	self->draw(self);
}
