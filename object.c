#ifndef OBJECT_H

#include "object.h"

#endif

struct _Object_ {
    const void * class;
    int index;
} _Object_;

static void * Object_ctor(void * _self, va_list * arg);

static void * Object_dtor(void * _self);

const _Class_ _Object = {
    sizeof(struct _Object_),
    Object_ctor,
    Object_dtor,
    NULL
};

const void * Object = &_Object;


static void * Object_ctor(void * _self, va_list * arg)
{
    struct _Object_ * self = _self;
    if(self){
        self->class = Object;
        self->index = va_arg(*arg, int);
    }
    printf("Object constructor called\n");
    return self;
}

static void * Object_dtor(void * _self)
{
    struct _Object_ * self = _self;
    printf("Object desstructor called\n");
    return self;
}


/*
struct String {
const void * class; // must be first 
char * text;
};

static void * String_ctor (void * _self, va_list * app)
{ 
    struct String * self = _self;
    const char * text = va_arg(* app, const char *);
    self —> text = malloc(strlen(text) + 1);
    assert(self —> text);
    strcpy(self —> text, text);
    return self;
}

static void * String_dtor (void * _self)
{
    struct String * self = _self;
    free(self —> text), 
    self —> text = 0;
    return self;
}

static const struct Class _String = {
    sizeof(struct String),
    String_ctor,
    String_dtor
}; 


const void * String = & _String;//passed to new
*/