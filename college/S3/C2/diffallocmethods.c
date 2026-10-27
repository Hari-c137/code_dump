#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int size, id;
    struct Block *next;
} Block;

Block *create(int size, int id) {
    Block *b = malloc(sizeof(Block));
    if (!b) exit(EXIT_FAILURE);
    b->size = size;
    b->id = id;
    b->next = NULL;
    return b;
}

void add(Block **head, int size, int id) {
    Block *b = create(size, id);
    if (!*head) {
        *head = b;
        return;
    }
    Block *p = *head;
    while (p->next) p = p->next;
    p->next = b;
}

void allocate(Block *head, int process[], int n, int choice) {
    printf("\nProcess\tSize\tBlock\n");

    for (int i = 0; i < n; i++) {
        Block *p = head, *best = NULL;

        while (p) {
            if (p->size >= process[i] &&
                (best == NULL ||
                 (choice == 2 && p->size < best->size) ||
                 (choice == 3 && p->size > best->size))) {
                best = p;
                if (choice == 1) break;
            }
            p = p->next;
        }

        if (best) {
            printf("P%d\t%d\t%d\n", i + 1, process[i], best->id);
            best->size -= process[i];
            if (best->size == 0) best->id = -1;
        } else {
            printf("P%d\t%d\tNot allocated\n", i + 1, process[i]);
        }
    }
}

int main(void) {
    Block *head = NULL;
    int process[] = {212, 417, 112, 426};
    int choice;

    add(&head, 100, 1);
    add(&head, 500, 2);
    add(&head, 200, 3);
    add(&head, 300, 4);
    add(&head, 600, 5);

    printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3)
        allocate(head, process, 4, choice);
    else
        printf("Invalid choice\n");

    while (head) {
        Block *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
