#include "my_malloc.h"

void merge_free_blocks()
{
    Block* current_block = head;

    while (current_block->next_node != NULL) {
        if (current_block->free == 1 && current_block->next_node->free == 1) {
            // Merge current_block and its next_node
            current_block->size += current_block->next_node->size + sizeof(Block);
            current_block->next_node = current_block->next_node->next_node;
        } else {
            current_block = current_block->next_node;
        }
    }
}

void my_free(void* ptr)
{
    if (ptr == NULL) {
        printf("Error: Trying to free an invalid pointer\n");
        return;
    }

    Block* free_block = (Block*) (ptr - sizeof(Block));
    Block* current_block = head;

    while (current_block) {
        if (current_block == free_block) {
            current_block->free = 1;

            merge_free_blocks();

            // printf("Memory block freed successfully\n");
            return;
        }
        current_block = current_block->next_node;
    }

    printf("Error: Memory block not found\n");
}
