#include "my_malloc.h"

/*
    Copies the values of num bytes from the location pointed to by source 
    directly to the memory block pointed to by destination
*/
void my_memcpy(void* destination, const void* source, size_t num)
{
    char* cpy_dest = (char*) destination;
    const char* cpy_src = (const char*) source;

    if (cpy_dest == NULL) {
        printf("Error: Invalid destination\n");
        return;
    }

    for (size_t i = 0; i < num; i++) {
        cpy_dest[i] = cpy_src[i];
    }
}


// Reallocates the given area of memory.
void* my_realloc(void* ptr, size_t new_size)
{
    // If there is not enough memory, the old memory block is not freed and null pointer is returned.
    if (new_size <= 0 || new_size > get_available_size()) {
        printf("Error: Invalid size");
        return NULL;
    }

    if (ptr == NULL) {
        printf("Error: Trying to realloc an invalid pointer\n");
        return NULL;
    }

    void* new = my_malloc(new_size);

    Block* curr = head;
    while (curr) {
        if (ptr == curr) {
            break;
        }
        curr = curr->next_node;
    }

    my_memcpy(new, ptr, align(new_size));

    my_free(ptr);

    return new;
}
