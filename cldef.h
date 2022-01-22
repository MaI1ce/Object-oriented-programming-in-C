#ifndef CLDEF_H
#define CLDEF_H

#ifndef NEW_H
#include "class.h"
#endif

#define CLASS_DECLARATION(NAME) typedef struct NAME##_ {\


#define END_CLASS_DECLARATION(NAME)                     \
} NAME##_;                                              \
                                                        \
typedef struct NAME {                                   \
    const _Class_ * class;                              \
    NAME##_  data;                                      \
} NAME;                                                 \
                                                        \
extern const void * _##NAME##_ ;                        \
                                                        \
void wrapper_##NAME##_ctor(NAME##_ * _self, ...);       \
                                                        \
void wrapper_##NAME##_dtor(NAME * _self);               \


#define CTOR(NAME, self, ...)                           \
self.class = _##NAME##_;                                \
wrapper_##NAME##_ctor(&(self.data) __VA_OPT__(,) __VA_ARGS__)

#define DTOR(NAME, self)                                \
wrapper_##NAME##_dtor(&self)


#define CONSTRUCTOR(NAME)                               \
                                                        \
static void * NAME##_ctor(void * _self, va_list * arg); \
                                                        \
void wrapper_##NAME##_ctor(NAME##_ * _self, ...)        \
{                                                       \
    va_list varlist;                                    \
    va_start(varlist, _self);                           \
    NAME##_ctor(_self, &varlist);                       \
    va_end(varlist);                                    \
}                                                       \
                                                        \
static void * NAME##_dtor(void * _self);                \
                                                        \
void wrapper_##NAME##_dtor(NAME * _self)                \
{                                                       \
    NAME##_dtor(_self);                                 \
}                                                       \
                                                        \
static const _Class_ _##NAME = {                        \
    sizeof(NAME),                                       \
    NAME##_ctor,                                        \
    NAME##_dtor,                                        \
    NULL                                                \
};                                                      \
                                                        \
const void * _##NAME##_ = &(_##NAME);                   \
                                                        \
static void * NAME##_ctor(void * _self, va_list * arg)  \
{                                                       \
    NAME * self = _self;                                \
    if(self){                                           \



#define END_CONSTRUCTOR(NAME)                           \
    }                                                   \
    return self;                                        \
}                                                       \


#define DESTRUCTOR(NAME)                                \
static void * NAME##_dtor(void * _self)                 \
{                                                       \
    NAME * self = _self;                                \


#define END_DESTRUCTOR(NAME)                            \
    return self;                                        \
}

#define DERIVED_FROM(NAME) NAME##_ NAME##__;            \


#define BASE_CTOR(TYPE, ...)                            \
wrapper_##TYPE##_ctor(&(self->data.TYPE##__) __VA_OPT__(,) __VA_ARGS__) 


#define BASE_DTOR(TYPE) wrapper_##TYPE##_dtor((TYPE *)self)

#endif