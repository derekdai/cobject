#include <stdlib.h>
#include "point.h"

int main()
{
	Point * point = point_new();
	printf("point->base.argb = 0x%x, shape_get_argb() = 0x%x\n",
		   point->base.argb,
		   shape_get_argb((Shape *) point));
	
	return 0;
}

