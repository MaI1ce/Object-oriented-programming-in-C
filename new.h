#ifndef NEW_H
#define NEW_H

//#include <stdarg.h>
//#include <stdlib.h>
/*
    each object as first member has pointer to _Class_ struct
    which has size of memory needed and pointers to constructor and destructor

    each class in its implementation file has his own initialized _Class_ struct, which is passed to new()
*/
#include "class.h"

void * _new_(const void * _class, int argc, ...);

void * _delete_ (void * item);

#endif
