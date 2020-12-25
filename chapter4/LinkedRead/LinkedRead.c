#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node *cur = NULL;
    
    Node *newNode = NULL;
    int readData;

    while(1) {
        scanf("%d", &readData);
        if(readData < 1) break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head->next == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        
        tail = newNode;
    }
    printf("\n");

    if(head == NULL) {
        printf("no data stored!");
    }
    else {
        cur = head;
        printf("%d ", cur->data);

        while(cur->next != NULL) {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }

    if(head == NULL) {
        return 0;
    }
    else {
        Node* delNode = head;
        Node* delNextNode = head->next;

        printf("deallocate %d\n", delNode->data);
        free(delNode);

        while(delNextNode != NULL) {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printF("deallocate %d\n", delNode->data);
            free(delNode);
        }
    }
    
    return 0;
    
}