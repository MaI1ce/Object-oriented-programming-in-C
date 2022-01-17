#ifndef SET_H
#define SET_H

extern const void * Set;

void * add(void * set, void * element);

void * drop(void * set, void * element);

void * find(void * set, void * element);

int contain(void * set, void * element);

#endif
