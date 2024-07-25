#include <stdio.h>
#define MAX 20

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, p, e, pos, i;

void main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid Location:");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }
    printf("\nThe Elements after deletion:");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
}

void search() {
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is at position %d\n", i);
            return;
        }
    }
    printf("Value %d is not in the list\n", e);
}

void insert() {
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid Location:");
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
    }
    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    printf("\nThe Elements of the list ADT are:");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}
