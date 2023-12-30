#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* insertFront(node* head, int x) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

node* deleteNode(node* head, int x) {
    if (head == NULL) {
        return head;
    } else {
        node* temp = head;
        if (head->data == x) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            free(temp);
        } else {
            while (temp != NULL && temp->data != x) {
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Element not found in the list\n");
                return head;
            }

            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
        return head;
    }
}

void printList(node* head) {
    printf("List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    node* myList = NULL;

    myList = insertFront(myList, 10);
    myList = insertFront(myList, 20);
    myList = insertFront(myList, 30);
    myList = insertFront(myList, 40);
    myList = insertFront(myList, 50);

    printf("Initial list:\n");
    printList(myList);

    myList = deleteNode(myList, 30);
    printf("List after deleting 30:\n");
    printList(myList);

    return 0;
}

