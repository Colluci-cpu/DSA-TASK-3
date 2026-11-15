#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
        front = 0;
    rear = (rear + 1) % SIZE;
    q[rear] = x;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q[front];
    if (front == rear)          // last element removed
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    return x;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    for (int n = 10; n <= 50; n += 10)
        enqueue(n);
    dequeue();
    dequeue();
    enqueue(60);    // reuses freed space at index 0
    display();      // 30 40 50 60
    return 0;
}
