#include <stdio.h>
#include <stdlib.h>

int main (){
    int numbers [10] = {1024,1023,3,4,5,6,769,8,9,10};
     //NOTE: Unsigned char = 1 byte of memory. In C, it is the guaranteed smallest addressable unit of data.
    // The pointer type now tells the compiler that the data *it points to* is 1 byte wide.
    unsigned char* var = (unsigned char*)numbers;

    for(int i = 0; i < 10; i++){
        /*
        * (int*)byte_ptr: This is the type cast. It momentarily tells the compiler, "Hey, treat this memory address as if it points to a 4-byte integer."
        * ( ... ): Get's the content that the pointer is pointing to 
        */
        int current_value = *( (int*)var);
        printf("Current value is %d\n", current_value);

        /*Correctly advance the pointer (Pointer Arithmetic)
         * An 'unsigned char*' pointer increments by 1 byte when using '++'
         *Since we read an 'int' (typically 4 bytes), we must
         * explicitly advance the pointer by 'sizeof(int)' bytes to move to the
         * start of the next integer element.
        */
        var = var + sizeof(int);
    }
}