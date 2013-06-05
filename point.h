#ifndef __POINT_H_
#define __POINT_H_

#include "shape.h"

#define POINT(o)				(TYPE_CHECK_INSTANCE_CAST(o, & point_class, Point))
#define IS_POINT(o)				(TYPE_CHECK_INSTANCE_TYPE(o, & point_class))
#define POINT_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, & point_class, PointClass))
#define POINT_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, & point_class, PointClass))
#define IS_POINT_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, & point_class))

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
