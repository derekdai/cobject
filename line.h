#ifndef __LINE_H_
#define __LINE_H_

#include "shape.h"

#define LINE_CLASS(c) ((const LineClass *) (c))

#define LINE(o) ((Line *) (o))

typedef struct _LineClass LineClass;

typedef struct _Line Line;

struct _LineClass
{
	ShapeClass base;
};

struct _Line
{
	Shape base;

	float x1;
	float y1;
	float x2;
	float y2;
};

Shape * line_new();

float line_get_x1(const Line * self);

void line_set_x1(Line * self, float x1);

float line_get_y1(const Line * self);

void line_set_y1(Line * self, float y1);

float line_get_x2(const Line * self);

void line_set_x2(Line * self, float x2);

float line_get_y2(const Line * self);

void line_set_y2(Line * self, float v);

extern const LineClass line_class;

#endif /* __LINE_H_ */
