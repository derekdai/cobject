#include <stdlib.h>
#include <assert.h>
#include "point.h"

void point_init(Point * self)
{
	assert(NULL != self);
	
	shape_init((Shape *) self);
	self->x = 0.0f;
	self->y = 0.0f;
}

Point * point_new()
{
	Point * self = malloc(sizeof(Point));
	if(self) {
		point_init(self);
	}
	
	return self;
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
