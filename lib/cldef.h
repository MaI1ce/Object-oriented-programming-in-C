#ifndef CLDEF_H
#define CLDEF_H

#ifndef CLASS_H
#include "class.h"
#endif

#define CLASS_DECLARATION(NAME) typedef struct NAME##_ {\


#define END_CLASS_DECLARATION(NAME)                     \
} NAME##_;                                              \
                                                        \
typedef struct NAME {                                   \
    RTTI_info * info;                                   \
    NAME##_  data;                                      \
} NAME;                                                 \
                                                        \
                                                        \
extern const RTTI_info* RTTI_##NAME ;                   \
                                                        \
void wrapper_##NAME##_ctor(NAME * _self, ...);          \
                                                        \
void wrapper_##NAME##_dtor(NAME * _self);               \


#define CTOR(NAME, self, ...)                           \
wrapper_##NAME##_ctor(&self __VA_OPT__(,) __VA_ARGS__)

#define DTOR(NAME, self)                                \
wrapper_##NAME##_dtor(&self)


#define CONSTRUCTOR(NAME)                               \
                                                        \
static void * NAME##_ctor(void * _self, va_list * arg); \
                                                        \
static void * NAME##_dtor(void * _self);                \
                                                        \
static RTTI_info NAME##_info = {                        \
    sizeof(NAME),                                       \
    NAME##_ctor,                                        \
    NAME##_dtor,                                        \
    &NAME##_vtbl                                        \
};                                                      \
                                                        \
const RTTI_info * RTTI_##NAME = &(NAME##_info);         \
                                                        \
void wrapper_##NAME##_ctor(NAME * _self, ...)           \
{                                                       \
    _self->info = &(NAME##_info);                       \
    va_list varlist;                                    \
    va_start(varlist, _self);                           \
    NAME##_ctor(_self, &varlist);                       \
    va_end(varlist);                                    \
}                                                       \
                                                        \
static void * NAME##_ctor(void * _self, va_list * arg)  \
{                                                       \
    NAME * self = (NAME *)_self;                        \
    if(self){                                           \



#define END_CONSTRUCTOR(NAME)                           \
    }                                                   \
    return self;                                        \
}                                                       \


#define DESTRUCTOR(NAME)                                \
                                                        \
void wrapper_##NAME##_dtor(NAME * _self)                \
{                                                       \
    NAME##_dtor(_self);                                 \
}                                                       \
                                                        \
static void * NAME##_dtor(void * _self)                 \
{                                                       \
    NAME * self = (NAME *)_self;                        \


#define END_DESTRUCTOR(NAME)                            \
    return self;                                        \
}

#define DERIVED_FROM(NAME) NAME##_ NAME##__;            \


#define BASE_CTOR(TYPE)                                 \
TYPE##_ctor(self, arg) 

#define BASE_DTOR(TYPE) TYPE##_dtor(self)


#define VTBL_DECLARATION(NAME) typedef struct vtbl_##NAME {

#define END_VTBL_DECLARATION(NAME) } vtbl_##NAME;

#define VTBL_INITIALISATION(NAME)                       \
static vtbl_##NAME NAME##_vtbl = {

#define END_VTBL_INITIALISATION };

#define VTBL_DERIVED_FROM(BASE, NAME)\
static vtbl_##BASE NAME##_vtbl = {

#endif