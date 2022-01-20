#ifndef BASIC_OBJECTS_H
#define BASIC_OBJECTS_H

#include "cldef.h"
#include "class.h"

CLASS_DECLARATION(INT)
    int val;
END_CLASS_DECLARATION(INT)

////////////////////////////

CLASS_DECLARATION(LONG)
    long val;
END_CLASS_DECLARATION(LONG)

////////////////////////////

CLASS_DECLARATION(CHAR)
    char val;
END_CLASS_DECLARATION(CHAR)

///////////////////////////

CLASS_DECLARATION(FLOAT)
    float val;
END_CLASS_DECLARATION(FLOAT)

//////////////////////////

CLASS_DECLARATION(DOUBLE)
    double val;
END_CLASS_DECLARATION(DOUBLE)

//////////////////////////

CLASS_DECLARATION(SHORT)
    short val;
END_CLASS_DECLARATION(SHORT)

/////////////////////////

CLASS_DECLARATION(LLONG)
    long long val;
END_CLASS_DECLARATION(LLONG)

/////////////////////////

CLASS_DECLARATION(LDOUBLE)
    long double val;
END_CLASS_DECLARATION(LDOUBLE)

#endif
