#ifndef BASIC_OBJECTS_H
#include "basic_objects.h"
#endif

CONSTRUCTOR(INT)
    self->val = 0;
END_CONSTRUCTOR(INT);

DESTRUCTOR(INT)
END_DESTRUCTOR(INT)

CONSTRUCTOR(LONG)
    self->val = 0;
END_CONSTRUCTOR(LONG);

DESTRUCTOR(LONG)
END_DESTRUCTOR(LONG)

CONSTRUCTOR(CHAR)
    self->val = 0;
END_CONSTRUCTOR(CHAR);

DESTRUCTOR(CHAR)
END_DESTRUCTOR(CHAR)

CONSTRUCTOR(FLOAT)
    self->val = 0;
END_CONSTRUCTOR(FLOAT);

DESTRUCTOR(FLOAT)
END_DESTRUCTOR(FLOAT)

CONSTRUCTOR(DOUBLE)
    self->val = 0;
END_CONSTRUCTOR(DOUBLE);

DESTRUCTOR(DOUBLE)
END_DESTRUCTOR(DOUBLE)

CONSTRUCTOR(SHORT)
    self->val = 0;
END_CONSTRUCTOR(SHORT);

DESTRUCTOR(SHORT)
END_DESTRUCTOR(SHORT)

CONSTRUCTOR(LLONG)
    self->val = 0;
END_CONSTRUCTOR(LLONG);

DESTRUCTOR(LLONG)
END_DESTRUCTOR(LLONG)

CONSTRUCTOR(LDOUBLE)
    self->val = 0;
END_CONSTRUCTOR(LDOUBLE);

DESTRUCTOR(LDOUBLE)
END_DESTRUCTOR(LDOUBLE)

