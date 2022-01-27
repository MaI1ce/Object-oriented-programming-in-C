#include<iostream>

extern "C" {
#include"new.h"
#include"MyString.h"
}

int main(void){

    STRING * str = NEW(STRING, 128);

    char * str_to_copy = "Hello world\0";

    vtbl_STRING * vtbl = (vtbl_STRING *)str->info->vtbl;

    vtbl->copy(str,str_to_copy,12);

    vtbl->show(str);

    str = (STRING *)DELETE(str);
    return 0;
}