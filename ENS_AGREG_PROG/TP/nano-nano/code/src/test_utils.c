#include "test_utils.h"

void print_line(const Line *L, size_t index) 
{
    if (!L) 
    {
        printf("line %zu: [NULL]\n", index);
        return;
    }

    printf("line %zu: \"%s\" (len=%zu, cap=%zu)\n",
           index,
           L->data ? L->data : "(null)",
           L->len,
           L->cap);
}

void print_buffer(const Buffer *B) 
{
    if (!B) 
    {
        printf("[Buffer NULL]\n");
        return;
    }

    printf("=== BUFFER STATE ===\n");
    printf("Lines: %zu / Capacity: %zu\n", B->count, B->cap);

    for (size_t i = 0; i < B->count; ++i) print_line(&B->lines[i], i);

    printf("====================\n");
}