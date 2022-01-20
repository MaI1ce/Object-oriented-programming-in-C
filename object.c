#ifndef OBJECT_H

#include "object.h"

#endif

static void * Object_ctor(void * _self, va_list * arg);

static void * Object_dtor(void * _self);

const _Class_ _Object = {
    sizeof(Object),
    Object_ctor,
    Object_dtor,
    NULL
};

const void * _Object_ = &_Object;


static void * Object_ctor(void * _self, va_list * arg)
{
    Object * self = _self;
    if(self){
        self->class = _Object_;
        self->index = va_arg(*arg, int);
    }
    printf("Object constructor called\n");
    return self;
}

static void * Object_dtor(void * _self)
{
    Object * self = _self;
    printf("Object desstructor called\n");
    return self;
}
