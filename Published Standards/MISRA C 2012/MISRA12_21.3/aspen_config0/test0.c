#include <stdlib.h>

int main() {
    size_t num, size;
    void *ptr;

    void *c = calloc(num, size);  // UndCC_Violation
    void *m = malloc(size);       // UndCC_Violation
    void *r = realloc(ptr, size); // UndCC_Violation
    free(ptr);                    // UndCC_Violation

    return 0;
}
