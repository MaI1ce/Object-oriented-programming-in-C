#ifndef CLDEF_H
#define CLDEF_H

#define CLASS_DECLARATION(NAME) typedef struct NAME {   \
    const void * class;                                 \


#define END_CLASS_DECLARATION(NAME)                     \
} NAME;                                                 \
extern const void * _##NAME##_ ;                        \
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
void wrapper_##NAME##_ctor(NAME * _self, ...)           \
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
        self->class = _##NAME##_;                       \


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
}                                                       \

#endif