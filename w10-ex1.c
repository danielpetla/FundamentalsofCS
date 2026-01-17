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
    ListElement* current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->data;
    }

List* create01list() {
    List* list = malloc(sizeof(List));
    list->head = new_list_element(0, NULL);
    list->head->next = new_list_element(1, NULL);
    return list;
}