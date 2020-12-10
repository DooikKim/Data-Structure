#include <stdio.h>

typedef struct list {
    char data;
    List* prev;
    List* next;
} List;

List head;

