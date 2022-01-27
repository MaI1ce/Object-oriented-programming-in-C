#ifndef MYSTRING_H_
#define MYSTRING_H_



#ifndef NEW_H
#include "new.h"
#endif

#include "stdio.h"

CLASS_DECLARATION(STRING)
    int len;
    char * str;
END_CLASS_DECLARATION(STRING)

VTBL_DECLARATION(STRING)
    void (*show)(const STRING * _self);
    void (*copy)(const STRING * _self, const char * str, int len);
END_VTBL_DECLARATION(STRING)
#endif