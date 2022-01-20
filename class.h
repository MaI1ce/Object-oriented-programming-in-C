#ifndef CLASS_H
#define CLASS_H
#include<stdarg.h>
#include<stddef.h>

typedef struct _Class_ {
    size_t size;
    void * (*ctor)(void * self, va_list * varl);
    void * (*dtor)(void * self);
    void * vtbl; //pointer to virtual methods table
} _Class_;

//#include "cldef.h"

#endif
