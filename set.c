#ifndef SET_H

#include "set.h"

#endif

static struct _Set_ {
    const void * class;
    int count;
    struct _Set_item_ * first_item;
} _Set_;

static struct _Set_item_ {
    const void * class;
    void * ob;
    struct _Set_item_ * next;
} _Set_item_;

static void * Set_ctor(void * _self, va_list * arg);

static void * Set_item_ctor(void * _self, va_list * arg);

static void * Set_dtor(void * _self);

static void * Set_item_dtor(void * _self);

const _Class_  _Set = {
    sizeof(struct _Set_),
    Set_ctor,
    Set_dtor,
    NULL
};

static _Class_ _Set_item = {
    sizeof(struct _Set_item_),
    Set_item_ctor,
    Set_item_dtor,
    NULL
};

const void * Set = &_Set;

static const void * Set_item = &_Set_item;

int get_count(void * set){
    int ret = -1;
    struct _Set_ * self = set;
    if(self){
        ret = self->count;
    }
    return ret;
}


void * push(void * set, void * element)
{
    struct _Set_ * self = set;
    if(self && element){
        struct _Set_item_ * new_item = _new_(Set_item, element);
        new_item->next = self->first_item;
        self->first_item = new_item;
        self->count++;
    }
    return self;
}

void * pop(void * set)
{
    void * obj_p = NULL;
    struct _Set_ * self = set;
    if(self && self->first_item){
        struct _Set_item_ * pop_item = self->first_item;
        self->first_item = pop_item->next;
        obj_p = pop_item->ob;
        pop_item->next = NULL;
        pop_item->ob = NULL;
        _delete_(pop_item);
        self->count--;
    }
    return obj_p;
}

/*in va_list no arguments*/
static void * Set_ctor(void * _self, va_list * arg)
{
    struct _Set_ * self = _self;
    if(self){
        self->class = Set;
        self->count = 0;
        self->first_item = NULL;
    }
    printf("Set constructor called\n");
    return self;
}

static void * Set_dtor(void * _self)
{
    struct _Set_ * self = _self;
    if(self->first_item){
        _delete_(self->first_item);
    }
    printf("Set destructor called\n");
    return self;
}

/*va_list has 1 argument - pointer to object*/
static void * Set_item_ctor(void * _self, va_list * arg)
{
    struct _Set_item_ * self = _self;
    if(self){
        self->class = Set_item;
        self->ob = va_arg(*arg, void *);
        self->next = NULL;
    }
    printf("Set_item constructor called\n");
    return self;
}

static void * Set_item_dtor(void * _self)
{
    struct _Set_item_ * self = _self;
    if(self){
        if(self->next){
            _delete_(self->next);
        }
        if(self->ob){
            _delete_(self->ob);
        }
    }
    printf("Set_item destructor called\n");
    return self;
}


