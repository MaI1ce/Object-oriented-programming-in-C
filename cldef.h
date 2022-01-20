#ifndef CLDEF_H
#define CLDEF_H

#define CLASS_DEFINE(NAME) typedef struct NAME {        \
    const void * class;                                 \

#define END_CLASS_DEFINE(NAME)                          \
} NAME;                                                 \
extern const void * _##NAME##_ ;                        \



#define CONSTRUCTOR(NAME)                               \
                                                        \
static void * NAME##_ctor(void * _self, va_list * arg); \
                                                        \
static void * NAME##_dtor(void * _self);                \
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