#ifndef CLASS_H
#define CLASS_H

typedef struct _Class_ {
    size_t size;
    void * (*ctor)(void * self, va_list * varl);
    void * (*dtor)(void * self);
} _Class_;

#endif
