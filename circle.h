#ifndef __CURCLE_H_
#define __CURCLE_H_

#include "point.h"

#define CIRCLE(o) ((Circle *) (o))

typedef struct _Circle Circle;

struct _Circle
{
	Point base;
	float radius;
};

Circle * circle_new();

void circle_free(Circle * self);

void circle_init(Circle * self);

float circle_get_radius(const Circle * self);

void circle_set_radius(Circle * self, float radius);

#endif /* __CURCLE_H_ */
