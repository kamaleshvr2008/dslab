#include<stdio.h>
#include<stdlib.h>
struct Node 
{
int data;
struct Node* next;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if(!newNode) {
printf("memory allocation error\n"); exit(1);
}
newNode->data= data;
newNode->next= NULL;
return newNode;
}
void push(struct Node** top,int data){
struct Node*newNode = createNode(data);
newNode->next = *top;
*top=newNode;
printf("element pushed:%d\n",data);
}
int pop(struct Node**top) {
if(*top==NULL) {
printf("error: Stack underflow.cannot pop element.\n");
return -1;
} 
struct Node*temp=*top;
int poppedElement=temp->data;
*top=(*top)->next;
free(temp);
return poppedElement;
}
void displayStack(struct Node*top) {
if(top==NULL) {
printf("stack is empty.\n");
return;
}
printf("stack elements:");
struct Node*temp=top;
while(temp!=NULL) {
printf("%d->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}
int main() {
struct Node*top=NULL;
int choice,element;
while(1) {
printf("\n Stack operations menu:\n");
printf("1. push\n");
printf("2. pop\n");
printf("3. display\n");
printf("4. exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice) {  
case 1:
printf("enter element to push:");
scanf("%d",&element);
push(&top,element);
break;
case 2:
element=pop(&top);
if(element!=-1)
printf("popped element:%d\n",element);
break;
case 3:
displayStack(top);
break;
case 4:
exit(0);
default:
printf("invalid choice! please enter a valid option.\n");
}
}
return 0;
}
