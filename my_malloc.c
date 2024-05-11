#include "my_malloc.h"

int init_map = 0;

void* split_heap(Block* current_block, size_t allocate_size)
{
    size_t remaining_size = current_block->size - allocate_size - sizeof(Block);

    // Update current with size requested
    current_block->size = allocate_size;

    // Create new block, adds size of the block header and allocated size positioning the new block immediately after the allocated portion
    Block* new_block = (Block*) ((char*) current_block + sizeof(Block) + allocate_size);

    // Add the remaining size after subtracting the requested size
    new_block->size = remaining_size;

    new_block->next_node = current_block->next_node;
    new_block->free = 1;

    current_block->next_node = new_block;
    current_block->free = 0;

    if (new_block->next_node == NULL) {
        new_block->next_node = NULL;
    }

    return (void*) (current_block + 1);
}

// Returns the pointer to the beginning of newly allocated memory.
void* my_malloc(size_t size)
{
    if (size <= 0) return NULL;

    size_t allocate_size = align(size);

    // if not initialized, init memory map
    if (init_map == 0) {
        init_memory_map(allocate_size);
        init_map = 1;
    }

    Block* current_block = head;

    // Loop through memory blocks
    while (current_block) {
        // If free and its size is large enough to accommodate requested data
        if (current_block->free == 1 && current_block->size == allocate_size) {
            current_block->free = 0;
            return (void*) (current_block + 1); // return a pointer after the block header
        }
        // If the size of the block is too big for the requested size split the block
        else if (current_block->size > allocate_size && current_block->free == 1) {
            return split_heap(current_block, allocate_size);
        }
        current_block = current_block->next_node;
    }

    return NULL;
}
