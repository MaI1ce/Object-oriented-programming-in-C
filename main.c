#include <stdio.h>

#include "new.h"
#include "set.h"
#include "object.h" 


int main(void)
{
    void * s = new(Set);

/*
    void * a = new(Object);
    void * b = new(Object);
    add(s, a);
    add(s, b);
*/
    /*add returns pointer to an added object*/
    void * a = add(s, new(Object));
    void * b = add(s, new(Object));
    void * c = new(Object);

    if(contains(s, a) && contains(s, b)){
        printf(" s contains a and b\n");
    }

    if(different(a, add(s,a))){
        printf("diferent\n");
    } else {
        printf("the same \n");
    }

    /*drop returns pointer to deleted from set object*/
    if(contains(s, drop(s, a))){
        printf("s contains a\n");
    }else {
        printf("s does not conatin a\n");
    }

    delete(a);
    delete(b);
    delete(c);
    delete(s);

    return 0;
}
