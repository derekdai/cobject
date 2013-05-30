#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "circle.h"

int main()
{
	Shape * shapes[] = { SHAPE(point_new()), SHAPE(circle_new()) };
	int i;
	for(i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i ++) {
		shape_draw(shapes[i]);
	}
	point_free(POINT(shapes[0]));
	circle_free(CIRCLE(shapes[1]));
	
	return 0;
}

