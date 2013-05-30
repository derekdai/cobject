#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "circle.h"

static void circle_draw(Shape * self)
{
	printf("Circle\n");
}

void circle_init(Circle * self)
{
	assert(NULL != self);
	
	point_init(POINT(self));
	SHAPE(self)->draw = circle_draw;
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

