#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
   int age;
   char name [25];
   char birthplace [20]; /* data */
}Person;

Person *new_person(char name []; int age; char bithplace[]){
    Person *p = malloc(sizeof(Person));
    strcpy(p -> name, name);
    strcpy(p -> birthplace, birthplace);
    p -> age = age;

    return p;
}




int main (){
    const int SIZE = 20;
    Person *people[SIZE]:

    for(int i = 0; i < SIZE; i++){
        
    }
}
