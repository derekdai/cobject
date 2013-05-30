#ifndef __POINT_H_
#define __POINT_H_

#include "shape.h"

#define POINT_CLASS(c) ((PointClass *) (c))

#define POINT(o) ((Point *) (o))

typedef struct _PointClass PointClass;

typedef struct _Point Point;

struct _PointClass
{
	ShapeClass base;
};

struct _Point
{
	Shape base;
	float x;
	float y;
};

Shape * point_new();

float point_get_x(const Point * self);

void point_set_x(Point * self, float x);

float point_get_y(const Point * self);

void point_set_y(Point * self, float y);

extern const PointClass point_class;

#endif /* __POINT_H_ */
