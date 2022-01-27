#ifndef MYSTRING_H_
#include "MyString.h"
#endif

#define MAX_STRING_LEN 256

static void show_string(const STRING * _self)
{
    if(_self){
        if(_self->data.str){
            printf("%s\n",_self->data.str);
        }
        else printf("Error: string is empty\n");
    } 
    else printf("Error: NULL pointer to STRING object\n");
}

static void copy_string(const STRING * _self, const char * str, int len)
{
    if(_self){
        if(_self->data.len > len){
            if(str){
                int i = 0;
                for(; i < _self->data.len; ++i)
                {
                    if(i < len){
                        _self->data.str[i] = str[i];
                    }
                    else _self->data.str[i] = 0;
                }
            }
            else printf("Error: empty string\n");
        }
        else printf("Error: string is to long\n");
    } 
    else printf("Error: NULL pointer to STRING object\n");
}

VTBL_INITIALISATION(STRING)
    show_string,
    copy_string
END_VTBL_INITIALISATION

CONSTRUCTOR(STRING)
    self->data.str = NULL;
    self->data.len = va_arg(*arg, int);
    if((self->data.len > 0) && (self->data.len < MAX_STRING_LEN)){
        self->data.str = (char *)malloc(self->data.len);
    }
    if(!self->data.str){
        free(self->data.str);
        fprintf(stderr,"malloc error in constructor\n");
    }
    printf("string_ctor len = %d\n", self->data.len);
END_CONSTRUCTOR(STRING)

DESTRUCTOR(STRING)
    free(self->data.str);
    printf("string_dtor\n");
END_DESTRUCTOR(STRING)