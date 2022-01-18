#ifndef SET_H
#define SET_H

#include "new.h"

extern const struct _Class_ * _Set_;

struct Set {
    const void * class;
    int count;
    static struct Set_item * first_item;
} Set;


void * push(void * set, void * element);

void * pop(void * set);

#endif
