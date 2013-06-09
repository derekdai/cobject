#ifndef __POINT_H_
#define __POINT_H_

#include "shape.h"

#define TYPE_POINT				(point_get_type())
#define POINT(o)				(TYPE_CHECK_INSTANCE_CAST(o, TYPE_POINT, Point))
#define IS_POINT(o)				(TYPE_CHECK_INSTANCE_TYPE(o, TYPE_POINT))
#define POINT_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, TYPE_POINT, PointClass))
#define POINT_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, TYPE_POINT, PointClass))
#define IS_POINT_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, TYPE_POINT))

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

Type point_get_type();

Shape * point_new();

float point_get_x(const Point * self);

void point_set_x(Point * self, float x);

float point_get_y(const Point * self);

void point_set_y(Point * self, float y);

#endif /* __POINT_H_ */
