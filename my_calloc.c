#include "my_malloc.h"

// Sets the first num bytes of the block of memory pointed by ptr to the specified value
void* my_memset(void* ptr, int value, size_t num) 
{   
    unsigned char* copy = ptr;

    while (num > 0) {
        *copy++ = (unsigned char)value;
        num--;
    }

    return ptr;
}

/*  
    Allocates memory for an array of num objects of size 
    and initializes all bytes in the allocated storage to zero.  
    returns a pointer to the lowest (first) byte in the allocated memory block
*/
void* my_calloc(size_t num, size_t size)
{
    if (num == 0 || size == 0) {
        printf("Error: Invalid allocation parameters\n");
        return NULL;
    }

    if (size > get_available_size()) {
        printf("Error: Not enough space left\n");
        return NULL;
    }

    size_t total_size = num * size;
    void* new = NULL;

    if (!(new = my_malloc(total_size))) {
        printf("Error: Not enough space left\n");
        return NULL;
    }

    my_memset(new, 0, total_size);

    return new;
}
