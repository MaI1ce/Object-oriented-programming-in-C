#ifndef SET_H

#include "set.h"

#endif

static struct Set_item {
    const void * class;
    void * ob;
    struct Set_item * next;
} Set_item;

void * push(void * set, void * element)
{
    struct Set * self = set;
    if(self && element){
        struct Set_item * new_item = _new_(_Set_item_, element);
        new_item->next = self->first_item;
        self->first_item = new_item;
    }
    return self;
}

void * pop(void * set)
{
    void * obj_p = NULL;
    struct Set * self = set;
    if(self && self->first_item){
        struct Set_item * pop_item = self->first_item;
        self->first_item = pop_item->next;
        obj_p = pop_item->ob;
        pop_item->next = NULL;
        pop_item->ob = NULL;
        _delete(pop_item);
    }
    return obj_p;
}

/*in va_list no arguments*/
static void * Set_ctor(void * _self, va_list * arg)
{
    struct Set * self = _self;
    if(self){
        self->class = &_Set_;
        self->count = 0;
        self->first_item = NULL;
    }
    return _self;
}

static void * Set_dtor(void * _self)
{
    struct Set * self = _self;
    if(self->first_item){
        _delete_(self->first_item);
    }
    return _self;
}

/*va_list has 1 argument - pointer to object*/
static void * Set_item_ctor(void * _self, va_list * arg)
{
    struct Set_item * self = _self;
    if(self){
        self->class = &_Set_item_;
        self->ob = va_arg(arg, void *);
        self->next = NULL;
    }
    return _self;
}

static void * Set_item_dtor(void * _self)
{
    struct Set_item * self = _self;
    if(self){
        if(self->next){
            _delete_(self->next);
        }
        if(self->ob){
            _delete_(self->ob);
        }
    }
    return _self;
}

const struct _Class_ * _Set_ = {
    sizeof(struct Set),
    Set_ctor,
    Set_dtor,
    NULL
};

static struct _Class_ * _Set_item_ = {
    sizeof(struct Set_item),
    Set_item_ctor,
    Set_item_dtor,
    NULL
};


/*
struct String {
const void * class; // must be first 
char * text;
};

static void * String_ctor (void * _self, va_list * app)
{ 
    struct String * self = _self;
    const char * text = va_arg(* app, const char *);
    self —> text = malloc(strlen(text) + 1);
    assert(self —> text);
    strcpy(self —> text, text);
    return self;
}

static void * String_dtor (void * _self)
{
    struct String * self = _self;
    free(self —> text), 
    self —> text = 0;
    return self;
}

static const struct Class _String = {
    sizeof(struct String),
    String_ctor,
    String_dtor
}; 


const void * String = & _String;//passed to new
*/