//#include <stdarg.h>
#ifndef NEW_H

#include "new.h"

#endif
/*
typedef struct RTTI_info {
    size_t size;
    void * (*ctor)(void * self, va_list * varl);
    void * (*dtor)(void * self);
    void * vtbl; //pointer to virtual methods table
} RTTI_info;
*/
void * _new_(const RTTI_info * rtti_info, ...)
{
    const RTTI_info * info = rtti_info;
    if(info == NULL){
        return NULL;
    } 
    if(info->size == 0){
        return NULL;
    }
    void * p = calloc(1, info->size);
    if(!errno){
        if(p){
        /*
          each object as first member has pointer to RTTI_info struct
          which has size of memory needed and pointers to constructor and destructor
          pointer to this 

          each class in its implementation file has his own initialized RTTI_info struct, which is passed to new()
        */
            * (const RTTI_info **)p = rtti_info;
            if(info->ctor){
            //initialize variable length set of arguments for constructor
                va_list varlist;
                va_start(varlist, rtti_info);

                info->ctor(p, &varlist);

                va_end(varlist);
            }
        }
        return p;
    }
    else {
        free(p);
        return NULL;
    }
}

/*
    _class_ob is a pointer to object
    each object in the begining has a pointer to RTTI_info struct
    RTTI_info struct has in it pointer to destructor of the class
*/
void * _delete_(void * _class_ob)
{
    const RTTI_info ** info = _class_ob;
    if(_class_ob && (*info) && (*info)->dtor){
        (*info)->dtor(_class_ob);
    }
    free(_class_ob);
    _class_ob = NULL;
    return _class_ob;
}


