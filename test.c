#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "circle.h"
#include "line.h"

int main()
{
	const ObjectClass * classes[] = {
			OBJECT_CLASS(& shape_class),
			OBJECT_CLASS(& point_class),
			OBJECT_CLASS(& circle_class),
			OBJECT_CLASS(& line_class),
	};
	Shape * shape = point_new();
	const ObjectClass * clazz = OBJECT_GET_CLASS(shape);
	int i;
	for(i = 0; i < sizeof(classes) / sizeof(classes[0]); i ++) {
		printf("%s %s %s\n",
			   object_class_get_name(clazz),
			   TYPE_CHECK_CLASS_TYPE(clazz, classes[i]) ? "is" : "is not",
			   object_class_get_name(classes[i]));
	}

	return 0;
}

