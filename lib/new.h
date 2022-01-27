#ifndef NEW_H
#define NEW_H


#include <stdlib.h>
#include <errno.h>

/*
    each object as first member has pointer to _Class_ struct
    which has size of memory needed and pointers to constructor and destructor

    each class in its implementation file has his own initialized _Class_ struct, which is passed to new()
*/
#ifndef CLASS_H
#include "class.h"
#endif

#ifndef CLDEF_H
#include "cldef.h"
#endif


void * _new_(const RTTI_info * rtti_info, ...);

void * _delete_ (void * item);

/*
    variadic macross 
    sequence of tokens replaces the identifier __VA_ARGS__
    If the variable argument has any tokens, then a __VA_OPT__ invocation expands to its argument;
    but if the variable argument does not have any tokens, the __VA_OPT__ expands to nothing
*/
#define NEW(TYPE, ...) ( TYPE *)_new_( RTTI_##TYPE __VA_OPT__(,) __VA_ARGS__)

#define DELETE(OBJ) _delete_(OBJ)

#endif
