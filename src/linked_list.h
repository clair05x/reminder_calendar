#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    char reminder[100];
    struct Node* next;
};

struct Node* createNode(const char* reminder);
void addNode(struct Node** head, const char* reminder);
void printList(struct Node* head);

#endif
