
#include <stdio.h>
#include <conio.h>
#define Max 5

int que[Max];
int f = -1;
int r = -1;

void insert();
void delete();
void display();

void main() {
    clrscr();
    int ch;
    do {
        printf("\n 1. Insert \n 2. Delete \n 3. Display \n 4. Stop\n");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("\n Bye Bye!!\n");
                    break;
            default: printf("\n Invalid Input!!\n");
        }
    } while (ch != 4);

    getch();
}

void insert() {
    int val;
    if ((f == 0 && r == Max - 1) || (r == f - 1)) {
        printf("\n Queue is Full\n");
    } else {
        if (f == -1 && r == -1) {
            f = 0;
            r = 0;
        } else if (r == Max - 1 && f != 0) {
            r = 0;
        } else {
            r++;
        }
        printf("\n Enter an element: ");
        scanf("%d", &val);
        que[r] = val;
    }
}

void delete() {
    if (f == -1 && r == -1) {
        printf("\n Queue is Empty\n");
    } else {
        printf("\n The Element deleted is %d", que[f]);
        if (f == r) {
            f = -1;
            r = -1;
        } else if (f == Max - 1) {
            f = 0;
        } else {
            f++;
        }
    }
}

void display() {
    int i;
    if (f == -1 && r == -1) {
        printf("\n Queue is Empty\n");
    } else {
        printf("\n Queue elements are: ");
        if (f <= r) {
            for (i = f; i <= r; i++) {
                printf("%d ", que[i]);
            }
        } else {
            for (i = f; i < Max; i++) {
                printf("%d ", que[i]);
            }
            for (i = 0; i <= r; i++) {
                printf("%d ", que[i]);
            }
        }
    }
}