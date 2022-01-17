//#include <stdarg.h>
#ifndef NEW_H

#include "new.h"

#endif

void * _new_(const void * _class, /*int argc,*/ ...)
{
    const _Class_ * class = (const _Class_ *)_class;
    void * p = calloc(1, class->size);

    if(p){
        /*
          each object as first member has pointer to _Class_ struct
          which has size of memory needed and pointers to constructor and destructor
          pointer to this 

          each class in its implementation file has his own initialized _Class_ struct, which is passed to new()
        */
        * (const _Class_ *)p = _class;
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

void * _delete_(const void * _class_ob)
{
    const _Class_ ** class = _class_ob;
    if(_class_ob){
        if(class && (*class)->dtor){
            (*class)->dtor(_class_ob);
        }
        free(_class_ob);
    }
    return _class_ob;
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
