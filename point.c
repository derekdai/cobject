#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "point.h"

static void point_draw(Shape * self)
{
	printf("Point\n");
}

static void point_class_init(ShapeClass * clazz)
{
	clazz->draw = point_draw;
}

static void point_init(Point * self)
{
	self->x = 0.0f;
	self->y = 0.0f;
}

Type point_get_type()
{
	static Type type = TYPE_INVALID;
	if(! type) {
		type = type_register(TYPE_SHAPE,
							 "Point",
							 sizeof(PointClass),
							 (ClassInitFunc) point_class_init,
							 sizeof(Point),
							 0);
	}

	return type;
}

Shape * point_new()
{
   return object_create_instance(TYPE_POINT);
}

void point_free(Point * self)
{
	free(self);
}

float point_get_x(const Point * self)
{
	assert(NULL != self);
	
	return self->x;
}

void point_set_x(Point * self, float x)
{
	assert(NULL != self);
	
	self->x = x;
}

float point_get_y(const Point * self)
{
	assert(NULL != self);
	
	return self->y;
}

void point_set_y(Point * self, float y)
{
	assert(NULL != self);
	
	self->y = y;
}
