#include <stdlib.h>

int main() {
    size_t num, size;
    void *ptr;

    void *c = calloc(num, size); // UndCC_Violation
    void *m = malloc(size);
    void *r = realloc(ptr, size);
    free(ptr);

    return 0;
}
