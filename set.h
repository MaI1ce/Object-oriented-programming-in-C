#ifndef SET_H
#define SET_H

#include "new.h"

extern const void * Set;
/*
extern struct _Set_ ;{
    const void * class;
    int count;
    struct _Set_item_ * first_item;
} _Set_;*/


void * push(void * set, void * element);

void * pop(void * set);

int get_count(void * set);

#endif
