
   #include "MyClass.h"
   
   VTBL_INITIALISATION(MyClass)
    END_VTBL_INITIALISATION

    CONSTRUCTOR(MyClass)
        self->data.x = va_arg(*arg,int);
    END_CONSTRUCTOR(MyClass)

    DESTRUCTOR(MyClass)
        self->data.x = 0;
    END_DESTRUCTOR(MyClass)