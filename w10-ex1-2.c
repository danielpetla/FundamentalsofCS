#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    int data;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
} List;

ListElement* new_list_element(int value, ListElement* ptr) {
    ListElement* new_element = malloc(sizeof(ListElement));
    new_element->data = value;
    new_element->next = ptr;
return new_element;
}

int get(List* list, int pos) {
    ListElement* current = list->head; // 1
    for (int i = 0; i < pos; i++) { // false = 1, true = 2
        current = current->next; // 1
    }
    return current->data; // 1
    }

List* create01list() {
    List* list = malloc(sizeof(List)); // 1 
    list->head = new_list_element(0, NULL); // 1 (assignment) + 4
    list->head->next = new_list_element(1, NULL); // 1 (assignment) + 4
    // list->head->next->next = new_list_element(2, NULL); // 1 (assignment) + 4
    // list->head->next->next->next = new_list_element(3, NULL); // 1 (assignment) + 4
    return list; // 1
}