#include <stdio.h>
#define MAX_SIZE 100

struct PriorityQueueElement {
    int data;
    int priority;
};

struct PriorityQueue {
    struct PriorityQueueElement elements[MAX_SIZE];
    int size;
};

void initializePriorityQueue(struct PriorityQueue *pq) {
    pq->size = 0;
}

void swap(struct PriorityQueueElement *a, struct PriorityQueueElement *b) {
    struct PriorityQueueElement temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct PriorityQueue *pq, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if (leftChild < pq->size && pq->elements[leftChild].priority > pq->elements[largest].priority) {
        largest = leftChild;
    }
    if (rightChild < pq->size && pq->elements[rightChild].priority > pq->elements[largest].priority) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(&pq->elements[index], &pq->elements[largest]);
        heapify(pq, largest);
    }
}

void enqueue(struct PriorityQueue *pq, int data, int priority) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }
    struct PriorityQueueElement newElement;
    newElement.data = data;
    newElement.priority = priority;
    pq->elements[pq->size] = newElement;
    pq->size++;
    int i = pq->size - 1;
    while (i > 0 && pq->elements[(i - 1) / 2].priority < pq->elements[i].priority) {
        swap(&pq->elements[(i - 1) / 2], &pq->elements[i]);
        i = (i - 1) / 2;
    }
}

struct PriorityQueueElement dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        struct PriorityQueueElement emptyElement = {0, 0};
        return emptyElement;
    }
    struct PriorityQueueElement highestPriorityElement = pq->elements[0];
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return highestPriorityElement;
}

void display(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements (data, priority): ");
    for (int i = 0; i < pq->size; ++i) {
        printf("(%d, %d) ", pq->elements[i].data, pq->elements[i].priority);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initializePriorityQueue(&pq);
    enqueue(&pq, 1, 3);
    enqueue(&pq, 2, 1);
    enqueue(&pq, 3, 4);
    enqueue(&pq, 4, 2);
    display(&pq);
    struct PriorityQueueElement dequeuedElement = dequeue(&pq);
    if (dequeuedElement.priority != 0) {
        printf("Dequeued element: (%d, %d)\n", dequeuedElement.data, dequeuedElement.priority);
    }
    display(&pq);
    return 0;
}