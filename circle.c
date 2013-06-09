#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "circle.h"

static void circle_draw(Shape * self)
{
	printf("Circle\n");
}

static void circle_class_init(CircleClass * clazz)
{
	SHAPE_CLASS(clazz)->draw = circle_draw;
}

static void circle_init(Circle * self)
{
	self->radius = 1.0f;
}

Type circle_get_type()
{
	static Type type = TYPE_INVALID;
	if(! type) {
		type = type_register(TYPE_POINT,
							 "Circle",
							 sizeof(CircleClass),
							 (ClassInitFunc) circle_class_init,
							 sizeof(Circle),
							 0);
	}

	return type;
}

Shape * circle_new()
{
   return object_create_instance(TYPE_CIRCLE);
}

void circle_free(Circle * self)
{
	free(self);
}

float circle_get_radius(const Circle * self)
{
	assert(NULL != self);
	
	return self->radius;
}

void circle_set_radius(Circle * self, float radius)
{
	assert(NULL != self);
	
	self->radius = radius;
}
