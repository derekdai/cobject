#ifndef __CURCLE_H_
#define __CURCLE_H_

#include "point.h"

#define CIRCLE_CLASS(c) ((CircleClass *) (c))

#define CIRCLE(o) ((Circle *) (o))

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
