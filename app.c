#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef char* string;

void *memory_alloc(unsigned int);

int main(int argc, const char** argv) {
    string option_test = (string) memory_alloc(50 * sizeof(char));
    strcpy(option_test, "This is a test");

    printf("String: %s\n", option_test);

    assert(option_test != NULL);
    assert(!strcmp(option_test, "This is a test"));

    free(option_test);
    return 0;
}

void *memory_alloc(unsigned int size) {
    void *pointer;

    if ((pointer = malloc(size)) == NULL)
        perror("Failed to allocate memory inside the pointer");

    return pointer;
}