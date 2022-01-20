#include <stdio.h>

#include "new.h"
#include "basic_objects.h"


int main(void)
{
    INT * ob = new(INT);

    INT ob2;

    CTOR(INT,ob2);


    ob->val = 10;
    printf("ob->val = %d\n", ob->val);

    ob2.val = 11;
    printf("ob2->val = %d\n", ob2.val);

    delete(ob);

    DTOR(INT,ob2);

    return 0;
}
