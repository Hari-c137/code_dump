#include <stdio.h>

#define MAX 128

typedef struct {int items[MAX]; int front; int rear;} Queue;


// enq takes 2 parameters, <queue_addr> & <value>, check if rear where data is inserted in the queue is full by checking MAX - 1 condition and if condition fails it prints overflow else it will create add val to the rear and then increment, after than it checks where the front is empty or nor using -1 and if it returns false return 0 else it set front as 0
void enq(Queue *q, int val) {q->rear < MAX - 1 ? q->items[++q->rear] = val, q->front = -1 ? q->front = 0 : 0 : printf("overflow\n");}
// deq takes a single parameter, for deletion in queue it is done at the front. so it checks whether the front is empty or not using -1 and also checks using front <= rear if front is less than rear then it is normal if any of these fail undeflow is printed and if both are true then the value at front i returned and front is post_incremented
int  deq(Queue *q) { return (q->front != - 1 && q->front <= q->rear) ? q->items[q->front++] : printf("underflow\n");}
// similar to dequeue but it does post_incremented the front, it just return the value stored at front without affecting anything 
int peek(Queue *q) { return (q->front !=  -1 && q->front <= q->rear) ? q->items[q->front] : printf("empty\n");}
// to display takes a 2 single parameter, first it checks if front is empty or front is larger than rear is any of these cases are true then it will print empty else it will start a for loop with starting i as front condition i <= rear then i increments and print all the items[] array with that corresponding index address
void shw(Queue *q) {
  if (q->front == -1 || q->front > q->rear)
    printf("empty\n");
  else {
    for(int i = q->front; i <= q->rear; i++) printf("%d\n", q->items[i]);
    printf("\n");
  }
}


void main() {
  Queue q  = {.front = -1, .rear = -1}; int ch, val; // initialize instance of queue structure 'q' and setup front and rear as =1 indicating its emty
  while(1) {
    printf("1.INSERT  2.DELETE  3.HIGH  4.SHOW  5.EXIT "); scanf("%d", &ch);
    if(ch == 1) { printf("Value: "); scanf("%d", &val); enq(&q, val); }
    else if (ch == 2) {val = deq(&q); printf("Deleted value: %d\n", val); }
    else if (ch == 3) {val = peek(&q); printf("Peeked value: %d\n", val); }
    else if (ch == 4) shw(&q); 
    else if (ch == 5) break;
    else printf("Invalid statement\n");
  }
}

