#include <stddef.h>
#include <assert.h>
#include "shape.h"

static void shape_class_init(ShapeClass * clazz)
{
	clazz->draw = NULL;
}

static void shape_init(Shape * self)
{
    self->argb = 0xffffffff;
}

Type shape_get_type()
{
	static Type type = TYPE_INVALID;
	if(! type) {
		type = type_register(TYPE_OBJECT,
							 "Shape",
							 sizeof(ShapeClass),
							 (ClassInitFunc) shape_class_init,
							 sizeof(Shape),
							 TYPE_FLAGS_ABSTRACT);
	}

	return type;
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
	assert(NULL != SHAPE_GET_CLASS(self)->draw);
	
	SHAPE_GET_CLASS(self)->draw(self);
}
