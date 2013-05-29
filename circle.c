#include <stdlib.h>
#include <assert.h>
#include "circle.h"

void circle_init(Circle * self)
{
	assert(NULL != self);
	
	point_init(POINT(self));
	self->radius = 1.0f;
}

Circle * circle_new()
{
	Circle * self = malloc(sizeof(Circle));
	if(self) {
		circle_init(self);
	}
	
	return self;
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

