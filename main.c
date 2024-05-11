#include "my_malloc.h"

int main(int argc, char* argv[])
{
    if (argc > 1 && !argv[0]) {
        return 1;
    } 
        char* str =  (char*) my_malloc(100 * sizeof(char));
        char* str2 = (char*) my_malloc(13 * sizeof(char));
        char* str3 = (char*) my_malloc(10000 * sizeof(char));
        
        if (str == NULL || str2 == NULL || str3 == NULL) {
            printf("Error: Memory allocation failed\n");
            return 1;
        }

        strcpy(str, "Hello, world!");
        strcpy(str2, "Hello, there!");
        strcpy(str3, "Hello, big memory allocated!");

        printf("========MALLOC===========\n");
        printf("String 1: %s address: %p \n", str, str);
        printf("String 2: %s address: %p \n", str2, str2);
        printf("String 3: %s address: %p \n", str3, str3);
        printf("=========================\n\n");
        
        my_free(str);

        int* ptr = (int*) my_calloc(5, sizeof(int));

        if (ptr == NULL) {
            printf("Error: Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < 5; ++i) {
            ptr[i] = i + 1;
        }

        printf("========CALLOC===========\n");
        printf("Calloc init to 0: %c\n", ptr[0]);
        printf("Calloc add values to ptr: ");
        for (int i = 0; i < 5;++i) {
            printf("%d, ", ptr[i]);
        }
        printf("\n=========================\n\n");


        printf("========REALLOC===========\n");
        printf("String 2 before realloc: %s\n", str2);

        str2 = (char*) my_realloc(str2, 29);
        strcat(str2, " new data added after realloc");

        printf("String 2 after realloc: %s", str2);
        printf("\n=========================\n\n");
    
    return 0;
}
