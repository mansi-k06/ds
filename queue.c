#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int order) {
    if (rear == MAX - 1)
        printf("Orders full! Cannot accept more.\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = order;
        printf("Order %d accepted.\n", order);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("No orders to serve.\n");
    else
        printf("Order %d served.\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear)
        printf("No pending orders.\n");
    else {
        printf("Pending orders: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, order;
    while (1) {
        printf("\n1.Accept Order  2.Serve Order  3.Display Orders  4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter order number: ");
                scanf("%d", &order);
                enqueue(order);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
