#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <stdint.h>

#define SHAPE(o) ((Shape *) (o))

typedef struct _Shape Shape;

struct _Shape
{
    uint32_t argb;
    
    void (* draw)(Shape * self);
};

void shape_init(Shape * self);

uint32_t shape_get_argb(const Shape * self);

void shape_set_argb(Shape * self, uint32_t argb);

void shape_draw(Shape * self);

#endif /* __SHAPE_H_ */
