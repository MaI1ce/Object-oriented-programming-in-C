#include <stdio.h>

#include "new.h"
#include "set.h"
#include "object.h" 


int main(void)
{
    void * s = _new_(Set);

    int count = get_count(s);
    printf("-------------number of items in set: %d\n",count);

    push(s, _new_(Object,10));

    push(s, _new_(Object,11));

    count = get_count(s);

    printf("-------------number of items in set: %d\n",count);

    void * a = pop(s);

    count = get_count(s);

    printf("-------------number of items in set: %d\n",count);

    _delete_(s);
    _delete_(a);

    return 0;
}
