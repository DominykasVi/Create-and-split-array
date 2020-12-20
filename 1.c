#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int size, int low, int high){
     int *array = calloc(size, sizeof(int));

    int random_value;
    srand(time(NULL));
    for(int i =0; i < size; ++i){
        int good_value = 1;
        while (good_value){
            random_value = rand();
            if(random_value >= low && random_value <= high){
                *(array + i) = random_value;
                good_value = 0;
            }
        };
    }

    if( array == NULL){
        return NULL;
    } else {
        return array;
    }
}

int main() {
    int *array= NULL;
    array = create_array(10, 1, 20);
    for(int i = 0; i < 10; ++i){
        printf("%d ", *(array+i));
    }
}
