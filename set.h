#ifndef SET_H
#define SET_H

#include "new.h"

extern const void * _Set_;

typedef struct Set {
    const void * class;
    int count;
    struct Set_item * first_item;
} Set;



void * push(Set * set, void * element);

void * pop(Set * set);

int get_count(Set * set);

#endif
