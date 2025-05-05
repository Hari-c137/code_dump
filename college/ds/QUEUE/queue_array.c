#include <stdio.h>
#define MAX 128

typedef struct { int items[MAX], front, rear; } Queue;

void enq(Queue *q, int v) { q->rear < MAX - 1 ? (q->items[++q->rear] = v, q->front == -1 ? q->front = 0 : 0) : printf("Overflow\n"); }
int deq(Queue *q) { return (q->front != -1 && q->front <= q->rear) ? q->items[q->front++] : (printf("Underflow\n"), -1); }
int peek(Queue *q) { return (q->front != -1 && q->front <= q->rear) ? q->items[q->front] : (printf("Empty\n"), -1); }
void disp(Queue *q) { 
    if (q->front == -1 || q->front > q->rear) printf("Empty\n"); 
    else for (int i = q->front; i <= q->rear; i++) printf("%d ", q->items[i]); 
    printf("\n"); 
}

int main() {
    Queue q = {.front = -1, .rear = -1}; int ch, v;
    while (1) {
        printf("1.Enq 2.Deq 3.Peek 4.Disp 5.Exit: "); scanf("%d", &ch);
        if (ch == 1) { printf("Val: "); scanf("%d", &v); enq(&q, v); }
        else if (ch == 2) { v = deq(&q); if (v != -1) printf("Dequeued: %d\n", v); }
        else if (ch == 3) { v = peek(&q); if (v != -1) printf("Front: %d\n", v); }
        else if (ch == 4) disp(&q);
        else if (ch == 5) break;
        else printf("Invalid\n");
    }
}

