#include <stdio.h>
#include <stdlib.h>

struct heap {
    int c;          // Capacity of heap
    int s;          // Current size
    int *element;   // Array to store heap elements
};

typedef struct heap *pqueue;

/* Initialize the priority queue */
pqueue initialize(int max) {
    pqueue heap1;

    if (max <= 3) {
        printf("\nPriority queue is too small\n");
        exit(EXIT_FAILURE);
    }

    heap1 = (pqueue)malloc(sizeof(struct heap));

    if (heap1 == NULL) {
        printf("\nOut of space\n");
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for elements */
    heap1->element = (int *)malloc((max + 1) * sizeof(int));

    if (heap1->element == NULL) {
        printf("\nOut of space\n");
        free(heap1);
        exit(EXIT_FAILURE);
    }

    heap1->c = max;
    heap1->s = 0;

    /* Sentinel value */
    heap1->element[0] = -999999;

    return heap1;
}

/* Check whether heap is empty */
int isempty(pqueue heap1) {
    return (heap1->s == 0);
}

/* Check whether heap is full */
int isfull(pqueue heap1) {
    return (heap1->s == heap1->c);
}

/* Insert an element into the min heap */
void insert(int x, pqueue heap1) {
    int i;

    if (isfull(heap1)) {
        printf("\nHeap is full\n");
        return;
    }

    /* Percolate up */
    for (i = ++heap1->s;
         heap1->element[i / 2] > x;
         i = i / 2) {

        heap1->element[i] = heap1->element[i / 2];
    }

    heap1->element[i] = x;
}

/* Delete minimum element */
int deletemin(pqueue heap1) {
    int i, child;
    int min, last;

    if (isempty(heap1)) {
        printf("\nHeap is empty\n");
        return -1;
    }

    /* Minimum element is at root */
    min = heap1->element[1];

    /* Get last element */
    last = heap1->element[heap1->s--];

    /* Percolate down */
    for (i = 1; i * 2 <= heap1->s; i = child) {

        child = i * 2;

        /* Select smaller child */
        if (child != heap1->s &&
            heap1->element[child + 1] < heap1->element[child]) {
            child++;
        }

        if (last > heap1->element[child]) {
            heap1->element[i] = heap1->element[child];
        }
        else {
            break;
        }
    }

    heap1->element[i] = last;

    return min;
}

/* Display heap */
void display(pqueue heap1) {
    int i;

    if (isempty(heap1)) {
        printf("\nHeap is empty.\n");
        return;
    }

    printf("\nElements in the heap: ");

    for (i = 1; i <= heap1->s; i++) {
        printf("%d ", heap1->element[i]);
    }

    printf("\n");
}

/* Main function */
int main() {
    int s, ch, ele;
    pqueue heap1;

    printf("\nEnter the size of the queue: ");
    scanf("%d", &s);

    heap1 = initialize(s);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Insert\n");
        printf("2. Delete Minimum\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 1:
                printf("\nEnter the element to insert: ");
                scanf("%d", &ele);

                insert(ele, heap1);
                break;

            case 2:
                ele = deletemin(heap1);

                if (ele != -1) {
                    printf("\nThe deleted element is %d\n", ele);
                }
                break;

            case 3:
                display(heap1);
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice\n");
        }

    } while (ch != 4);

    /* Free allocated memory */
    free(heap1->element);
    free(heap1);

    return 0;
}
