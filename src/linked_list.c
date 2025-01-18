//Clair (Wantong) Yu 251350213
//Implements a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct Node* createNode(const char* reminder) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->reminder, reminder);
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node** head, const char* reminder) {
    struct Node* newNode = createNode(reminder);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf(" - %s\n", head->reminder);
        head = head->next;
    }
}
