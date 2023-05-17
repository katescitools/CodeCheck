int main() {
    size_t num, size;
    void *ptr;

    void *c = calloc(num, size);  // UndCC_Valid
    void *m = malloc(size);
    void *r = realloc(ptr, size);
    free(ptr);

    return 0;
}
