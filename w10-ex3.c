#include <stdio.h>
#include <stdlib.h>

int getMax(int array[], int length) {
    int max = -1; // 1
    for (int i=0; i<length; i++) { // false = 1, true = 2  | 1 - initialize i (constant -> one time only)
        if (array[i] > max) { // false = 1, true = 2
            max = array[i];
        }
    }
    return max; // 1
}