#ifndef OBJECT_H
#define OBJECT_H

#include "new.h"

extern const void * _Object_;

typedef struct Object {
    const void * class;
    int index;
} Object;

#endif
