#include <stdio.h>

int queue[], front = -1, back = -1, SIZE = -1;

void enQueue(int value) {
    if (front == -1)
        front = 0;
    for (int i = front; i <= back; i++) {
        if (value == queue[i]) {
            printf("Value already in the queue");
            return;
        }
    }
    back++;
    queue[back] = value;
    printf("\n:EnQueued : %d", value);
}

void deQueue() {
    if (front == -1)
        printf("\nQueue is Empty!!");
    else {
        printf("\nDeQueued : %d", queue[front]);
        front++;
        if (front > back)
            front = back = -1;
    }
}

void display() {
    if (back == -1)
        printf("\nQueue is Empty!!!");
    else {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= back; i++)
            printf("%d  ", queue[i]);
    }
    printf("\n");
}

void sort() {
    for (int i = front; i < back; i++) {
        for (int j = i + 1; j <= back; j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

void search(int position) {
    if (position > back || position < 1) {
        printf("\nThere is no such position in queue\n");
    } else {
        printf("\n%d\n", queue[position - 1 + front]);
    }
}

void reverse() {
    for (int i = front; i <= (back + front) / 2; i++) {
        int temp = queue[i];
        queue[i] = queue[(back + front) - i];
        queue[(back + front) - i] = temp;
    }
}

void priorityQueue() {
    for (int i = front; i < back; i++) {
        for (int j = i + 1; j <= back; j++) {
            if (queue[i] < queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

void enQueuePriority(int value) {
    if (front == -1) {
        front = 0;
    }
    for (int i = front; i <= back; i++) {
        if (value == queue[i]) {
            printf("Value already in the queue");
            return;
        }
    }
        back++;
        queue[back] = value;
        priorityQueue();
        printf("\n:EnQueued : %d", value);
}

void circularEnQueue(int value) {
    if ((front == back + 1) || (front == 0 && back == SIZE - 1))
        printf("\nQueue is full!! \n");
    else {
//        for (int i = front; i != back; i = (i + 1) % SIZE) {
//            if (value == queue[i]) {
//                printf("Value already in the queue\n");
//                return;
//            }
//        }
        if (front == -1) front = 0;
        back = (back + 1) % SIZE;
        queue[back] = value;
        printf("\nEnQueued : %d\n", value);
    }
}

int circularDeQueue() {
    int value;
    if (front == -1) {
        printf("\nQueue is empty !! \n");
        return (-1);
    } else {
        value = queue[front];
        if (front == back) {
            front = -1;
            back = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeQueued element : %d \n", value);
        return (value);
    }
}

void circularDisplay() {
    int i;
    if (front == -1) {
        printf(" \nEmpty Queue\n");
    } else {
        for (i = front; i != back; i = (i + 1) % SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
    }
}

void displayFile(char file[]) {
    FILE *ptr;
    char ch;

    // Opening file in reading mode
    ptr = fopen(file, "r");

    if (NULL == ptr) {
        printf("\nfile can't be opened \n");
    } else {
        printf("content of this file are \n");
    }

    // Printing what is written in file
    // character by character using loop.
    while (ch != EOF) {
        ch = fgetc(ptr);
        printf("%c", ch);
    }
    // Closing the file
    fclose(ptr);
}

void writeFile(char name[]) {
    char *filename = name;

    // open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening the file %s", filename);
    } else {
        printf("Insert your queue dividing them with a comma\n");
        // write to the text file
        char text[100];
        scanf("%s", text);
        fprintf(fp, "%s", text);
    }
    // close the file
    fclose(fp);
}

int main() {
    int user = -1, priority, circular;
    while (user) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Search\n4. Sort"
               "\n5. Reverse\n6. Priority Queue\n7. Circular Queue"
               "\n8. Export a file\n9. Display a file\n0. Exit\n");
        scanf("%d", &user);
        if (user == 1) {
            printf("Type the value:\n");
            int value;
            scanf("%d", &value);
            enQueue(value);
            display();
        } else if (user == 2) {
            deQueue();
            display();
        } else if (user == 3) {
            printf("Type the position:\n");
            int position;
            scanf("%d", &position);
            search(position);
        } else if (user == 4) {
            sort();
            display();
        } else if (user == 5) {
            reverse();
            display();
        } else if (user == 6) {
            priority = 1;
            priorityQueue();
            display();
            while (priority == 1) {
                printf("\n1. Enqueue\n2. Dequeue\n3. Search\n9. Return to normal queue\n0. Exit\n");
                int userPriority = -1;
                scanf("%d", &userPriority);
                if (userPriority == 1) {
                    printf("Type the value:\n");
                    int value;
                    scanf("%d", &value);
                    enQueuePriority(value);
                    display();
                } else if (userPriority == 2) {
                    deQueue();
                    display();
                } else if (userPriority == 3) {
                    printf("Type the position:\n");
                    int position;
                    scanf("%d", &position);
                    search(position);
                } else if (userPriority == 9) {
                    priority = 0;
                } else if (userPriority == 0) {
                    printf("Exited\n");
                    return 0;
                } else {
                    printf("Invalid Value\n");
                }
            }
        } else if (user == 7) {
            circular = 1;
            printf("Specify the SIZE\n");
            scanf("%d", &SIZE);
            while (circular == 1) {
                printf("\n1. Enqueue\n2. Dequeue\n9. Return to normal queue\n0. Exit\n");
                int userCircular = -1;
                scanf("%d", &userCircular);
                if (userCircular == 1) {
                    printf("Type the value:\n");
                    int value;
                    scanf("%d", &value);
                    circularEnQueue(value);
                    circularDisplay();
                } else if (userCircular == 2) {
                    circularDeQueue();
                    circularDisplay();
                } else if (userCircular == 9) {
                    circular = 0;
                } else if (userCircular == 0) {
                    printf("Exited\n");
                    return 0;
                } else {
                    printf("Invalid Value\n");
                }
            }
        } else if (user == 8) {
            printf("Name of the file:\n");
            char file[20];
            scanf("%s", file);
            writeFile(file);
        } else if (user == 9) {
            printf("Name the file:\n");
            char name[20];
            scanf("%s", name);
            displayFile(name);
        } else if (user == 0) {
            printf("Exited\n");
            return 0;
        } else {
            printf("Invalid value\n");
        }
    }
}
