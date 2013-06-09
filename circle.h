#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "point.h"

#define TYPE_CIRCLE				(circle_get_type())
#define CIRCLE(o)				(TYPE_CHECK_INSTANCE_CAST(o, TYPE_CIRCLE, Circle))
#define IS_CIRCLE(o)			(TYPE_CHECK_INSTANCE_TYPE(o, TYPE_CIRCLE))
#define CIRCLE_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, TYPE_CIRCLE, CircleClass))
#define CIRCLE_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, TYPE_CIRCLE, CircleClass))
#define IS_CIRCLE_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, TYPE_CIRCLE))

typedef struct _CircleClass CircleClass;

typedef struct _Circle Circle;

struct _CircleClass
{
   PointClass base;
};

struct _Circle
{
	Point base;
	float radius;
};

Type circle_get_type();

Shape * circle_new();

float circle_get_radius(const Circle * self);

void circle_set_radius(Circle * self, float radius);

#endif /* __CIRCLE_H_ */
