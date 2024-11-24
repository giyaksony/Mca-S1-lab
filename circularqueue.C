#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int item, item2, i, front = -1, rear = -1, a[20], c = 0;

void enqueue(int n) {
    printf("Enter the item: ");
    scanf("%d", &item);
    if (front == -1 && rear == -1) {
        front = rear = 0;
        a[rear] = item;
        c++;
    } else if ((front == 0 && rear == n - 1) || (rear == front - 1)) {
        printf("Overflow\n");
    } else if (rear == n - 1) {
        rear = 0;
        a[rear] = item;
        c++;
    } else {
        rear++;
        a[rear] = item;
        c++;
        printf("%d is inserted\n", item);
    }
}

void dequeue(int n) {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
        return;
    }
    item2 = a[front];
    if (front == rear) {
        front = rear = -1; // Queue becomes empty
    } else if (front == n - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
    c--;
    printf("Dequeued element is: %d\n", item2);
}

int sumNode(int n) {
    int sum = 0, i = front;
    if (front == -1 && rear == -1) {
        return 0; // Empty queue
    }
    while (1) {
        sum += a[i];
        if (i == rear) break; // Stop after reaching the rear
        i = (i + 1) % n;      // Move to the next element in a circular manner
    }
    return sum;
}

/*int min(int n) {
    int min = a[front];
    int i = front;
    while (1) {
        if (a[i] < min) {
            min = a[i];
        }
        if (i == rear) break; // Stop after reaching the rear
        i = (i + 1) % n;      // Move to the next element in a circular manner
    }
    return min;
} */

void display(int n) {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (1) {
        printf("%d\t", a[i]);
        if (i == rear) break; // Stop after reaching the rear
        i = (i + 1) % n;      // Move to the next element in a circular manner
    }
    printf("\n");
    printf("Sum = %d\n", sumNode(n));
    printf("Count = %d\n", c); // Use the global count variable
   // printf("Min = %d\n", min(n));
}

void main() {
    int n, ch;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do {
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue(n);
                break;
            case 2:
                dequeue(n);
                break;
            case 3:
                display(n);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 4);

    getch();
}
