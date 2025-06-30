#include <stdio.h>
#define MAX_SIZE 5

struct circularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct circularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct circularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct circularQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

void enqueue(struct circularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->items[queue->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

int dequeue(struct circularQueue *queue) {
    int dequeuedItem;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        dequeuedItem = queue->items[queue->front];
        if (queue->front == queue->rear) {
            initializeQueue(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("%d dequeued from the queue.\n", dequeuedItem);
        return dequeuedItem;
    }
}

void display(struct circularQueue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    struct circularQueue queue;
    initializeQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    return 0;
}