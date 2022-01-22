#ifndef NEW_H
#define NEW_H

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

#include <stdio.h>

/*
    each object as first member has pointer to _Class_ struct
    which has size of memory needed and pointers to constructor and destructor

    each class in its implementation file has his own initialized _Class_ struct, which is passed to new()
*/
#include "class.h"

void * _new_(const _Class_ * _class, ...);

void * _delete_ (void * item);

/*
variadic macross 
sequence of tokens replaces the identifier __VA_ARGS__
If the variable argument has any tokens, then a __VA_OPT__ invocation expands to its argument;
but if the variable argument does not have any tokens, the __VA_OPT__ expands to nothing
*/
#define new(type, ...) ( type *)_new_(_##type##_ __VA_OPT__(,) __VA_ARGS__)

#define delete(ob) _delete_(ob)

#endif
