#include <stdio.h>
#define MAX 128

typedef struct {int items[MAX]; int front; int rear;} Queue;

void enq(Queue *q, int val) {q->rear < MAX -1 ? (q->items[++q->rear] = val), q->front == -1 ? q->front = 0 : 0 : printf("overflow\n");}
int  deq(Queue *q) { return (q->front != -1 && q->front <= q->rear) ? q->items[q->front++] : printf("underflow\n"); }
int  pek(Queue *q) { return (q->front != -1 && q->front <= q->rear) ? q->items[q->front] : printf("empty\n"); }
void shw(Queue *q) {
  if (q->front == -1 || q->front > q->rear) printf("empty\n");
  else for (int i = q->front; i <= q->rear; i++) printf("%d\n", q->items[i]);
  printf("\n");
}

  int main() {
  Queue q = {.front = -1, .rear = -1}; int val, ch;
  while(1) {
    printf("1.add 2.del 3.peek 4.display 5.end "); scanf("%d", &ch);
    if(ch == 1) {printf("val: "); scanf("%d", &val); enq(&q, val); }
    else if(ch == 2) { val = deq(&q); printf("%d\n", val); }
    else if(ch == 3) { val = pek(&q); printf("%d\n", val); }
    else if(ch == 4) shw(&q);
    else if(ch == 5) break;
    else printf("invalid choice\n");
  }
}
