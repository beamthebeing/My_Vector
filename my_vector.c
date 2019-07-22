#include <stdlib.h>
#include <stdio.h>
#include "my_vector.h"

struct my_vector  //Known type
{
    int size; // number of items the vector holds
    int capacity; //number of items the vector CAN hold
    int* data;
};

typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void)
{
    My_vector* pVector;
    pVector = (My_vector*)malloc(sizeof(My_vector));
    if (pVector != NULL)
    {
        pVector->size = 0;
        pVector->capacity = 1;
        pVector->data = (int*)malloc(sizeof(int) * pVector->capacity);
        if (pVector->data == NULL)
        {
            free(pVector);
            return NULL;
        }
    }
    return (MY_VECTOR)pVector;
}

int my_vector_get_size(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->size;
}

int my_vector_get_capacity(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    return pVector->capacity;
}

Status my_vector_push_back(MY_VECTOR hVector, int item)
{
    My_vector* pVector = (My_vector*)hVector;
    int* pTemp;
    int i;
    
    if (pVector->size >= pVector->capacity)
    {
        pTemp = (int*) malloc(sizeof(int) * 2 * pVector->capacity);
        if (pTemp == NULL)
        {
            return FAILURE;
        }
        for (i = 0; i < pVector->size; i++)
        {
            pTemp[i] = pVector->data[i];
        }
        free(pVector->data);
        pVector->data = pTemp;
        pVector->capacity *= 2;
    }
    
    pVector->data[pVector->size] = item;
    pVector->size++;
    return SUCCESS;
}

int* my_vector_at(MY_VECTOR hVector, int index)
{
    My_vector* pVector = (My_vector*)hVector;
    if (index < 0 || index >= pVector->size)
    {
        return NULL;
    }
    return &(pVector->data[index]);
}

Status my_vector_pop_back(MY_VECTOR hVector)
{
    My_vector* pVector = (My_vector*)hVector;
    if (pVector->size <= 0)
    {
        return FAILURE;
    }
    
    pVector->size--;
    return SUCCESS;
}

void my_vector_destroy(MY_VECTOR* phVector)
{
    My_vector* pVector = (My_vector*)*phVector;
    free(pVector->data);
    free(pVector); //clean up the memory footprint of the object
    *phVector = NULL;
    return;
}
