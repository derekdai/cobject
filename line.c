#include <stdio.h>
#include <assert.h>
#include "line.h"

static void line_draw()
{
	printf("Line\n");
}

static void line_class_init(LineClass * clazz)
{
	SHAPE_CLASS(clazz)->draw = line_draw;
}

static void line_init(Line * self)
{
	self->x1 = 0.0f;
	self->y1 = 0.0f;
	self->x2 = 0.0f;
	self->y2 = 0.0f;
}

Type line_get_type()
{
	static Type type = TYPE_INVALID;
	if(TYPE_INVALID == type) {
		type = type_register(TYPE_SHAPE,
							 "Line",
							 sizeof(LineClass),
							 (ClassInitFunc) line_class_init,
							 sizeof(Line),
							 TYPE_FLAGS_NONE);
	}

	return type;
}

Shape * line_new()
{
	return object_create_instance(TYPE_LINE);
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
