//#include <stdarg.h>
#ifndef NEW_H

#include "new.h"

#endif

void * _new_(const void * _class, ...)
{
    const struct _Class_ * class = (const struct _Class_ *)_class;
    void * p = calloc(1, class->size);

    if(p){
        /*
          each object as first member has pointer to _Class_ struct
          which has size of memory needed and pointers to constructor and destructor
          pointer to this 

          each class in its implementation file has his own initialized _Class_ struct, which is passed to new()
        */
        * (const struct _Class_ *)p = _class;
        if(class->ctor){
            //initialize variable length set of arguments for constructor
            va_list varlist;
            va_start(varlist, _class;

            p = class->ctor(p, &varlist);

            va_end(varlist);
        }
    }
    return p;
}

/*
    _class_ob is a pointer to object
    each object in the begining has a pointer to _Class_ struct
    _Class_ struct has in it pionter to destructor of the class
*/
void * _delete_(const void * _class_ob)
{
    const struct _Class_ ** class = _class_ob;
    if(_class_ob && (*class) && (*class)->dtor){
        (*class)->dtor(_class_ob);
    }
    free(_class_ob);
    return _class_ob;
}


