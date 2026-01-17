#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>


typedef struct Node
    {
       int data; // The data stored in the node
       struct Node* next; // Pointer to the next node in the list
    }Node;
    //*Now every node has a pointer next
Node* createNode (int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        // Handle memory allocation failure
        return NULL;
    }

    newNode -> data = data;
    newNode -> next = NULL; // New node is always the last, initially
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* invertNode(Node* head) {
    Node* prev = NULL;       
    Node* curr = head;       
    Node* next = NULL;

    while (curr != NULL) {
         next = curr->next;   // Save the original next node
        curr->next = prev;   // Reverse the pointer of the current node
        prev = curr;         // Move prev to the current node
        curr = next;         // Move curr to the next original node
    }

    return prev;  // New head of the list
}

int main (){
     Node* head = NULL;
    Node* tail = NULL;
    int size;
    printf("Please insert a size for your list: ");
    scanf("%d", &size);
    
    for(int i = 0; i < size; i++){
        int numb;
        printf("Please insert the %dth number: ", (i + 1));
        scanf("%d", &numb);
        Node* newNode = createNode (numb);

        if (head == NULL) {
            // first node becomes the head
            head = newNode;
            tail = newNode;
        } else {
            // attach at the end
            tail->next = newNode; // The pointer next starts to point to the new node
            tail = newNode;
    }
}
    printf("Your list: ");
    printList(head);
    head = invertNode(head);
    // Now head = prev (because it is what was returned in the invertNode function)

    printf("Your inverted list: ");
    printList(head);

    return 0; 
}
