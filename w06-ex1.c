 #include<stdio.h>

 int main(int argc, char** argv) {
    int value = 23;
    int* pointer = &value;
    printf("Value: %d\n", *pointer);
    *(pointer+1) = 0;
    printf("Follow-up value: %d\n", *(pointer+1));
}