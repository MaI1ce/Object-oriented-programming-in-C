static struct Set_item {
    const void * class;
    void * ob;
    struct Set_item * next;
} Set_item;

#ifndef SET_H

#include "set.h"

#endif


static void * Set_ctor(void * _self, va_list * arg);

static void * Set_item_ctor(void * _self, va_list * arg);

static void * Set_dtor(void * _self);

static void * Set_item_dtor(void * _self);

const _Class_  _Set = {
    sizeof(/*struct*/ Set),
    Set_ctor,
    Set_dtor,
    NULL
};

static _Class_ _Set_item = {
    sizeof(struct Set_item),
    Set_item_ctor,
    Set_item_dtor,
    NULL
};

const void * _Set_ = &_Set;

static const void * _Set_item_ = &_Set_item;

int get_count(Set * set){
    int ret = -1;
    /*struct*/ Set * self = set;
    if(self){
        ret = self->count;
    }
    return ret;
}


void * push(Set * set, void * element)
{
    /*struct*/ Set * self = set;
    if(self && element){
        struct Set_item * new_item = _new_(_Set_item_, element);
        new_item->next = self->first_item;
        self->first_item = new_item;
        self->count++;
    }
    return self;
}

void * pop(Set * set)
{
    void * obj_p = NULL;
    /*struct*/ Set * self = set;
    if(self && self->first_item){
        struct Set_item * pop_item = self->first_item;
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
    /*struct*/ Set * self = _self;
    if(self){
        self->class = _Set_;
        self->count = 0;
        self->first_item = NULL;
    }
    printf("Set constructor called\n");
    return self;
}

static void * Set_dtor(void * _self)
{
    /*struct*/ Set * self = _self;
    if(self->first_item){
        _delete_(self->first_item);
    }
    printf("Set destructor called\n");
    return self;
}

/*va_list has 1 argument - pointer to object*/
static void * Set_item_ctor(void * _self, va_list * arg)
{
    struct Set_item * self = _self;
    if(self){
        self->class = _Set_item_;
        self->ob = va_arg(*arg, void *);
        self->next = NULL;
    }
    printf("Set_item constructor called\n");
    return self;
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
    printf("Set_item destructor called\n");
    return self;
}


