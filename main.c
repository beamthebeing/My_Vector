//
#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"

int main(int argc, char* argv[])
{
    MY_VECTOR hVector;
    int i;
    
    hVector = my_vector_init_default();
    if (hVector == NULL)
    {
        printf("Failed to allocate memory for object.\n");
        exit(1);
    }
    
    printf("%d/%d\n", my_vector_get_size(hVector), my_vector_get_capacity(hVector));
    
    for (i = 0; i < 10; i++)
    {
        my_vector_push_back(hVector, rand());
        printf("%d/%d\n", my_vector_get_size(hVector),
               my_vector_get_capacity(hVector));
    }
    printf("\n");
    
    *my_vector_at(hVector, 1) = 9999;
    
    for (i = 0; i < my_vector_get_size(hVector); i++)
    {
        printf("%d:%d\n", i, *my_vector_at(hVector, i));
    }
    
    printf("\n");
    
    my_vector_pop_back(hVector);
    my_vector_pop_back(hVector);
    my_vector_pop_back(hVector);
    
    for (i = 0; i < my_vector_get_size(hVector); i++)
    {
        printf("%d:%d\n", i, *my_vector_at(hVector, i));
    }
    printf("\n");
    
    
    my_vector_destroy(&hVector);
    return 0;
}
