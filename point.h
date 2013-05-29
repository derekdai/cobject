#ifndef __POINT_H_
#define __POINT_H_

#include "shape.h"

typedef struct _Point Point;

struct _Point
{
	Shape base;
	
	float x;
	
	float y;
};

Point * point_new();

void point_free(Point * self);

void point_init(Point * self);

float point_get_x(const Point * self);

void point_set_x(Point * self, float x);

float point_get_y(const Point * self);

void point_set_y(Point * self, float y);

#endif /* __POINT_H_ */
