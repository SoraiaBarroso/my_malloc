#ifndef MY_MALLOC
#define MY_MALLOC
    #include <errno.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/mman.h>
    #include <unistd.h>

    #define MEMORY_BLOCK_SIZE (1 << 16)  // size block of data -> 65536 -> 64 kilobytes
    #define ALIGNMENT 16                 // 16 bits

    typedef struct HeapBlock {
        size_t size;                     // size memory
        char free;                       // used memory
        struct HeapBlock* next_node;     // pointer next memory block
    } Block;

    /* Memory functions implementation */
    void*    my_realloc (void* ptr, size_t new_size);
    void*    my_calloc  (size_t num, size_t size);
    void     my_free    (void* ptr);
    void*    my_malloc  (size_t size);

    /* Helpers */
    size_t   get_available_size  ();
    void     my_memcpy           (void* destination, const void* source, size_t num);
    void*    my_memset           (void* ptr, int value, size_t num);

    /* Heap Managment */
    void     init_memory_map    (size_t size);
    void*    split_heap         (Block* current_block, size_t allocate_size);
    void     merge_free_blocks  ();

    /* Memory aligment */
    size_t   align               (size_t size);
    size_t   align_memory_block  (size_t size);

    extern void*  memory_map;
    extern Block* head;
#endif
