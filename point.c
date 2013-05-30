#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "point.h"

static void point_draw(Shape * self)
{
	printf("Point\n");
}

static void point_init(Point * self)
{
	self->x = 0.0f;
	self->y = 0.0f;
}

Shape * point_new()
{
   return object_create_instance(OBJECT_CLASS(& point_class));
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

const PointClass point_class = {
   OBJECT_CLASS(& shape_class),			/* parent */
   "Point",								/* name */
   sizeof(Point),						/* instance size */
   (InstanceInitFunc) point_init,		/* constructor */
   CLASS_FLAGS_NONE,					/* class flags */
   point_draw							/* virtual function draw, from ShapeClass */
};
