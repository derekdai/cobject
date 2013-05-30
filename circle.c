#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "circle.h"

static void circle_draw(Shape * self)
{
	printf("Circle\n");
}

static void circle_init(Circle * self)
{
	self->radius = 1.0f;
}

Shape * circle_new()
{
   return object_create_instance(OBJECT_CLASS(& circle_class));
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

const CircleClass circle_class = {
   OBJECT_CLASS(& point_class),		/* parent */
   "Circle",						/* name */
   sizeof(Circle),					/* instance size */
   (InstanceInitFunc) circle_init,	/* constructor */
   CLASS_FLAGS_NONE,                /* Circle is a concrete class */
   circle_draw						/* virtual function draw */
};
