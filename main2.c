#include <stdio.h>

#include "new.h"
#include "basic_objects.h"


int main(void)
{
    INT * ob = new(INT);

    printf("ob->val = %d\n", ob->val);

    ob->val = 10;

    printf("ob->val = %d\n", ob->val);

    delete(ob);

    return 0;
}
