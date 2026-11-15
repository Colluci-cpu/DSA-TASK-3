#include <stdio.h>
#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull()  { return (rear + 1) % SIZE == front; }

// a) Front insertion
void insertFront(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + SIZE) % SIZE;
    dq[front] = x;
}

// b) Rear insertion
void insertRear(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    dq[rear] = x;
}

// c) Front deletion
void deleteFront() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d from front\n", dq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// d) Rear deletion
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d from rear\n", dq[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + SIZE) % SIZE;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();          // 5 10 20
    deleteFront();      // Deleted 5 from front
    deleteRear();       // Deleted 20 from rear
    display();          // 10
    return 0;
}
