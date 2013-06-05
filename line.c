#include <stdio.h>
#include <assert.h>
#include "line.h"

static void line_init(Line * self)
{
	self->x1 = 0.0f;
	self->y1 = 0.0f;
	self->x2 = 0.0f;
	self->y2 = 0.0f;
}

static void line_draw()
{
	printf("Line\n");
}

Shape * line_new()
{
	return object_create_instance(OBJECT_CLASS(& line_class));
}

float line_get_x1(const Line * self)
{
	assert(NULL != self);

	return self->x1;
}

void line_set_x1(Line * self, float x1)
{
	assert(NULL != self);

	self->x1 = x1;
}

float line_get_y1(const Line * self)
{
	assert(NULL != self);

	return self->y1;
}

void line_set_y1(Line * self, float y1)
{
	assert(NULL != self);

	self->y1 = y1;
}

float line_get_x2(const Line * self)
{
	assert(NULL != self);

	return self->x2;
}

void line_set_x2(Line * self, float x2)
{
	assert(NULL != self);

	self->x2 = x2;
}

float line_get_y2(const Line * self)
{
	assert(NULL != self);

	return self->y2;
}

void line_set_y2(Line * self, float y2)
{
	assert(NULL != self);

	self->y2 = y2;
}

const LineClass line_class = {
		OBJECT_CLASS(& shape_class),
		"Line",
		sizeof(Line),
		(InstanceInitFunc) line_init,
		CLASS_FLAGS_NONE,
		line_draw
};
