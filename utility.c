#include "my_malloc.h"

// contains total size of mmap region
void* memory_map;

// head linked list to init the heap
Block* head = NULL;

/*  
    1. creates a new memory map with the requested size
    we need to align the size
*/
void init_memory_map(size_t size)
{
    size_t available_size = align_memory_block(size);

    // returns a pointer to the mapped area. 
    memory_map = mmap(0, available_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (memory_map == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    // store heap
    head = (Block*) memory_map; // address
    head->size = available_size; // size
    head->next_node = NULL;
    head->free = 1; // free true
}

size_t align(size_t size)
{
    return (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1));
}

size_t align_memory_block(size_t size)
{
    return (((size) + (MEMORY_BLOCK_SIZE - 1)) & ~(MEMORY_BLOCK_SIZE - 1));
}

// get the biggest available size from the memory blocks
size_t get_available_size()
{
    Block* curr = head;
    size_t available_size = 0;

    while (curr) {
        if (curr->free == 1 && available_size <= curr->size) {
            available_size = curr->size;
        }
        curr = curr->next_node;
    }

    // printf("available size: %ld", available_size);
    return available_size;
}
