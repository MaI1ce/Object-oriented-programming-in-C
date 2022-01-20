#include <stdio.h>

#include "new.h"
#include "set.h"
#include "object.h" 
//#include "basic_objects.h"


int main(void)
{
    Set * s = (Set *)_new_(_Set_);

    int count = get_count(s);
    printf("-------------number of items in set: %d\n",count);

    push(s, _new_(_Object_,10));

    push(s, _new_(_Object_,11));

    count = get_count(s);

    printf("-------------number of items in set: %d\n",count);

    void * a = pop(s);

    count = get_count(s);

    printf("-------------number of items in set: %d\n",count);

    _delete_(s);
    _delete_(a);

    return 0;
}
