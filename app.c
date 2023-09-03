#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef char* string;

void *memory_alloc(unsigned int);

int main(int argc, const char** argv) {
    string option_test = (string)memory_alloc(50);
    strcpy(option_test, "This is a test");

    printf("String: %s\n", option_test);

    assert(option_test != NULL);
    assert(!strcmp(option_test, "This is a test"));

    free(option_test);
    return 0;
}

void *memory_alloc(unsigned int size) {
    void *pointer;

    if (size < 1) size = 1;
    if ((pointer = (void*)malloc(size * sizeof(void))) == NULL)
        perror("Failed to allocate memory inside the pointer");

    return pointer;
}