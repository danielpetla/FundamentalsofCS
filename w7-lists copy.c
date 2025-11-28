#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
	int data;
	struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;//head is a ListElement struct, so "inside" it there is int data and a pointer next
} List;

ListElement* new_list_element(int value, ListElement* ptr) {
    ListElement* new_element = malloc(sizeof(ListElement));
    new_element->data = value;
    new_element->next = ptr;
    return new_element;
}

List* new_list() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void free_list(List* list) {
    ListElement* head = list->head;
    list->head = NULL;
    ListElement* previous = NULL;
    while (head != NULL) {
        previous = head;
        head = head->next;
        free(previous);
    }
    free(list);
}

int size (List* list) {
    ListElement* current = list->head;
    int count =0;
    while(current !=NULL) {
        current = current->next;
        count++;
    }
    return count;
}

void append (List* list, int value) {
    ListElement* current = list->head;
    if (current == NULL) {
            current = new_list_element(value,NULL);
            list->head = current;
        return;
    }
    while(current->next !=NULL) {
        current = current->next;
    }
    ListElement* new_element = new_list_element(value, NULL);
    current->next = new_element;
}

int get(List* list, int pos) {
    if ((pos < 0) || (pos >= size(list))) {
        return 0;
    }
    ListElement* current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->data;
}

void insert(List* list, int pos, int value) {
    if ((list == NULL )|| (pos < 0) || (pos >size(list))) {
        return;
    }
    ListElement* current = list->head;
    if (pos == 0) {
          list->head = new_list_element(value, current);
        return;
    }
    for(int i = 0; i < pos-1; i++) {
        current = current->next;
    }
    ListElement* holder = current->next;
    ListElement* new_element = new_list_element(value,holder);
    current->next = new_element;
    return;
}

void remove_from(List* list, int pos) {
    if ((list == NULL )||(pos < 0) || (pos >=size(list))) {
        return;
    }
    ListElement* current = list->head;
    // Special case: element at beginning of list
    if (pos == 0) {
        list->head = current->next;
        current->next = NULL;
        free(current);
        return;
    }
    // find element before the one to remove
    for(int i = 0; i < pos-1; i++) {
        current = current->next;
    }
    // remove element from list, but safe it first to free memory
    ListElement* to_remove = current->next;
    current->next = (current->next)->next;
    free(to_remove);
}

void print_list(List* list) {
    if (list == NULL) {
        printf("NULL\n");
    }
    ListElement* curr = list->head;
    printf("[");
    while(curr != NULL) {
        printf("(%p, %d)", curr->next, curr->data);
        if (curr->next != NULL) {
            printf(", ");
        }
        curr = curr->next;
    }
    printf("]\n");
}

int sum(List* list) {
    ListElement* current = list->head;
    int add;
    while(current != NULL){
        add = add + current->data;
        current = current->next;
    }
    return add;
}

void concat(List* list1, List* list2) {
    if(list1->head == NULL){
        list1->head = list2->head;
    }
     ListElement* curr = list2->head;//arrow operator because list2 is a pointer to the struct list in the malloc (look at the function new_list)
     while(curr != NULL){
        append(list1, curr->data);
        curr = curr->next;
     }
}

List* init(int array[], int length) {
    List* list3 = new_list();
    if(length > 0){
        ListElement* current = new_list_element(array[0], NULL);
        list3->head = current;
        for(int i = 1; i < length; i++){
            current->next = new_list_element(array[i], NULL);
            current = current->next;
        }
    }
    return list3;
}

void reverse(List* list) {
     ListElement* prev = NULL;       
    ListElement* curr = list->head;       
    ListElement* next = NULL;

    while (curr != NULL) {
         next = curr->next;   // Save the original next node
        curr->next = prev;   // Reverse the pointer of the current node
        prev = curr;         // Move prev to the current node
        curr = next;         // Move curr to the next original node
    }
    list->head = prev; // New head of the list
}



int main() {
    List* list = new_list();
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    insert(list, 1, 5);
    insert(list, 3, 6);
    insert(list, 0, 7);
    insert(list, size(list),8);
// Test sum:
    printf("Sum: %d\n", sum(list));

// Test concatenation
    List* list2 = new_list();
    append(list2, 255);
    concat(list, list2);
    printf("concatenation:\n");
    print_list(list);

// Test init:
    int test[] = {14,15,2,4};
    List* list3= init(test, 4);
    printf("list3:\n");
    print_list(list3);

    //Test reverse
    printf("reverse:\n");
        reverse(list);
    print_list(list);

    printf("reverse:\n");
    reverse(list);
   print_list(list);

}
