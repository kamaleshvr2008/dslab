#include<stdio.h>
#define MAX_SIZE 100
void createArray(int arr[],int*size) {
int n,i;
printf("enter the number of elements:");
scanf("%d",&n);
if(n>MAX_SIZE) {
printf("enter:number of element exceeds the maximum array size.\n");
return;
}
printf("enter %d elements:",n);
for(i=0; i<n; i++) {
scanf("%d",&arr[i]);
}
*size = n;
printf("Array created successfully.\n");
}
void insertElement(int arr[],int *size, int element, int position) {
int i;
if(*size >= MAX_SIZE) {
printf("enter: array is full. cannot insert element.\n");
return;
}
if((position < 0) ||(position > *size)) {
printf("enter:Invalid position.\n");
return;
}
for(i = *size; i> position; i--) {
arr[i] = arr[i - 1];
}
arr[position] = element;
(*size)++;
printf("Element inserted successfully.\n");
}
int searchElement(int arr[], int size, int element) {
int i;
for(i = 0; i < size; i++) {
if(arr[i] == element) {
return i;
}
}
return -1;
}
void deleteElement(int arr[], int *size, int position) {
int i;
if((position < 0) || (position >= *size)) {
printf("Enter; Invalid position.\n");
return;
}
for(i = position; i < *size -1; i++) {
arr[i] = arr[i + 1];
}
(*size)--;
printf("Element deleted successfully.\n");
}
void displayArray(int arr[], int size) {
int i;
if(size == 0) {
printf("array is empty.\n");
return;
}
printf("array elements: ");
for(i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
int main() 
{
int arr[MAX_SIZE];
int size = 0;
int choie, alament, position, result;
while(1) {
printf("\nArray operation menu:\n");
printf("1. create Array\n");
printf("2. Intert Element\n");
printf("3. search Element\n");
printf("4. delete Element\n");
printf("5. Display Array\n");
printf("6. Exit\n");
printf("Enter your choice:");
scanf("%d", &choie);
switch(choie) {
case 1:
createArray(arr, &size);
break;
case 2:
printf("Enter elament to insert: ");
scanf("%d", &alament);
printf("Enter position to instert (0 to %d): ", size);
scanf("%d", &position);
insertElement(arr,&size, alament,position);
break;
case 3:
printf("enter element to search: ");
scanf("%d", &alament);
result = searchElement(arr, size, alament);
if(result != -1)
printf("Element found at position: %d\n",result);
else
printf("Eelent not found in the array\n");
break;
case 4:
printf("Enter position to delete (0 to %d): ",size-1);
scanf("%d", &position);
deleteElement(arr, &size, position);
break;
case 5:
displayArray(arr, size);
break;
case 6:
return 0;
default:
printf("Invalid choice! please enter a valid option.\n");
}
}
return 0;
}
