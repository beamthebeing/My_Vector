#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "status.h"

typedef void* MY_VECTOR;

MY_VECTOR my_vector_init_default(void);

int my_vector_get_size(MY_VECTOR hVector);
int my_vector_get_capacity(MY_VECTOR hVector);

Status my_vector_push_back(MY_VECTOR hVector, int item);

Status my_vector_pop_back(MY_VECTOR hVector);

//shrink to fit

int* my_vector_at(MY_VECTOR hVector, int index);


//set the capacity??


void my_vector_destroy(MY_VECTOR* phVector);

#endif
