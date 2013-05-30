#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "circle.h"

int main()
{
	Shape * shapes[] = { point_new(), circle_new() };
	int i;
	for(i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i ++) {
	   shape_draw(shapes[i]);
	   object_free(shapes[i]);
	}
	
	return 0;
}

