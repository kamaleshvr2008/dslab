#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Queue {
   int arr[MAX];
   int front;
   int rear;
};
void initializeQueue(struct Queue*queue) {
   queue->front=-1;
   queue->rear=-1;
}
int isFull(struct Queue*queue) {
   return queue->rear==MAX-1;
}
int isEmpty(struct Queue*queue) {
   return queue->front==-1|| queue->front>queue->rear;
}
void enqueue(struct Queue*queue,int element) {
   if (isFull(queue)) {
      printf("error:Queue overflow.cannot enqueue element.\n");
      return;
   }
   if(queue->front==-1) {
      queue->front=0;
   }
   queue->arr[++queue->rear]=element;
   printf("element enqueued:%d\n", element);
}
int dequeue(struct Queue*queue) {
   if (isEmpty(queue)) {
      printf("error:Queue underflow.cannot dequeue element.\n");
      return -1; 
   }
   int element = queue->arr[queue->front++]; 
   if(queue->front>queue->rear) {
      queue->front=-1;
      queue->rear=-1;
   }
   return element;
}
void displayQueue(struct Queue*queue) {
   if (isEmpty(queue)) {
      printf("Queue is empty.\n");
      return; 
   }
   printf("Queue elements:");
   for(int i=queue->front;i<=queue->rear;i++) {
      printf("%d",queue->arr[i]);
   }
   printf("\n");
}
int main() {
   struct Queue queue;
   int choice,element;
   initializeQueue(&queue);
   while(1) {
      printf("\n Queue operations menu:\n");
      printf("1. enqueue\n");
      printf("2. dequeue\n");
      printf("3. display\n");
      printf("4. exit\n");
      printf("enter your choice:");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("enter element to enqueue:");
            scanf("%d",&element);
            enqueue(&queue,element);
            break;
         case 2:
            element=dequeue(&queue);
            if (element!=-1)
               printf("dequeue element :%d\n",element);
            break;
        case 3:
            displayQueue(&queue);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice! please enter a valid option.\n");
      }
   }
   return 0;
}

      
    
