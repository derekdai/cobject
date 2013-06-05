#ifndef __CURCLE_H_
#define __CURCLE_H_

#include "point.h"

#define CIRCLE(o)				(TYPE_CHECK_INSTANCE_CAST(o, & circle_class, Circle))
#define IS_CIRCLE(o)			(TYPE_CHECK_INSTANCE_TYPE(o, & circle_class))
#define CIRCLE_GET_CLASS(o)		(TYPE_INSTANCE_GET_CLASS(o, & circle_class, CircleClass))
#define CIRCLE_CLASS(c)			(TYPE_CHECK_CLASS_CAST(c, & circle_class, CircleClass))
#define IS_CIRCLE_CLASS(c)		(TYPE_CHECK_CLASS_TYPE(c, & circle_class))

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

Shape * circle_new();

float circle_get_radius(const Circle * self);

void circle_set_radius(Circle * self, float radius);

extern const CircleClass circle_class;

#endif /* __CURCLE_H_ */
