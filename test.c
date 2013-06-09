#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "circle.h"
#include "line.h"

int main()
{
	Type types[] = {
			TYPE_OBJECT,
			TYPE_SHAPE,
			TYPE_POINT,
			TYPE_CIRCLE,
			TYPE_LINE
	};
	Shape * shapes[] = {
			point_new(),
			circle_new(),
			line_new()
	};
	int i, j;
	for(j = 0; j < sizeof(shapes) / sizeof(shapes[0]); j ++) {
		Type shape_type = TYPE_FROM_INSTANCE(shapes[j]);
		for(i = 0; i < sizeof(types) / sizeof(types[0]); i ++) {
			printf("%s %s %s\n",
				   type_get_name(shape_type),
				   type_is(shape_type, types[i]) ? "is" : "is not",
				   type_get_name(types[i]));
		}
	}

	return 0;
}

