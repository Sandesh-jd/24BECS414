#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


struct Node* createList(int data) {
    return createNode(data);  
}


void insertLeft(struct Node** head, int refData, int newData) {
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == refData) {
            struct Node* newNode = createNode(newData);
            newNode->next = temp;
            newNode->prev = temp->prev;

            if (temp->prev != NULL)
                temp->prev->next = newNode;

            temp->prev = newNode;

           
            if (temp == *head)
                *head = newNode;
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", refData);
}


void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;

   
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }


    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            if (temp == *head)
                *head = temp->next;

            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", data);
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;


    head = createList(10);
    display(head);

   
    insertLeft(&head, 10, 5);
    display(head);

    insertLeft(&head, 10, 7);
    display(head);

    deleteNode(&head, 5);
    display(head);

    deleteNode(&head, 15);

   
    display(head);

    return 0;
}
