#include<stdio.h>
#include<stdalign.h>

int main (){
    int numbers[10] = {1024,1023,3,4,5,6,769,8,9,10};
    int* ptr = numbers;

    for (int i = 0; i < 10; i++){
        printf("Index: %d, Current number is: %d, Address: %d\n", i, ptr[i], ptr);
    }
}