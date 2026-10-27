#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int id, size;
    struct Block *prev, *next;
} Block;

void add(Block **head, int id, int size) {
    Block *b = malloc(sizeof(Block)), *p = *head;
    if (!b) exit(EXIT_FAILURE);

    *b = (Block){id, size, NULL, NULL};

    if (!*head) {
        *head = b;
        return;
    }

    while (p->next) p = p->next;
    p->next = b;
    b->prev = p;
}

void display(Block *p) {
    printf("ID\tSize\tStatus\n-------------------------\n");
    while (p) {
        printf("%d\t%d\t%s\n", p->id, p->size,
               p->id == -1 ? "FREE" : "ALLOCATED");
        p = p->next;
    }
    printf("\n");
}

void garbageCollection(Block *p) {
    printf("Garbage collection: free blocks identified.\n");
    while (p) {
        if (p->id == -1)
            printf("Free block of size %d found.\n", p->size);
        p = p->next;
    }
}

void compact(Block **head) {
    Block *p = *head, *tail = NULL;
    int freeSize = 0;

    while (p) {
        Block *next = p->next;

        if (p->id == -1) {
            freeSize += p->size;
            free(p);
        } else {
            p->prev = tail;
            p->next = NULL;

            if (tail) tail->next = p;
            else *head = p;

            tail = p;
        }
        p = next;
    }

    if (freeSize) {
        Block *b = malloc(sizeof(Block));
        if (!b) exit(EXIT_FAILURE);

        *b = (Block){-1, freeSize, tail, NULL};

        if (tail) tail->next = b;
        else *head = b;
    }
}

int main(void) {
    Block *head = NULL;

    add(&head, 101, 20);
    add(&head, -1, 15);
    add(&head, 102, 30);
    add(&head, -1, 10);
    add(&head, 103, 25);

    printf("INITIAL MEMORY:\n");
    display(head);

    garbageCollection(head);

    compact(&head);
    printf("\nAFTER GARBAGE COLLECTION AND COMPACTION:\n");
    display(head);

    while (head) {
        Block *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
