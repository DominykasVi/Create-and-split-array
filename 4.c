#include <stdio.h>
#include <stdlib.h>

int splitData(int *array, int size, int splitPosition, int **array_1, int **array_2){
    if(*array_1 != NULL || array == NULL || *array_2 != NULL){
        return -1;
    }
    if (size <= 0 || splitPosition < 0 || splitPosition > size){
        return -1;
    }

    int *temp_1 = (int *) calloc(splitPosition, sizeof(int));

    int *temp_2 = (int *) calloc((size-splitPosition), sizeof(int));
    for(int i = 0; i < size; ++i){
        if(i < splitPosition){
            *(temp_1 + i) = *(array+i);
        } else {
            *(temp_2 + i - splitPosition) = *(array+i);
        }
    }
    *array_1 = temp_1;
    *array_2 = temp_2;
    return 0;
}

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int *array = NULL;
    int size = 10;
    int split = 6;
    int *array_1 = NULL;
    //int *array_1 = malloc(20);
    int *array_2 = NULL;
    int var = splitData(array, size, split, &array_1, &array_2);
    printf("%d\n", var);
    for(int i = 0; i < split; ++i){
        printf("%d ", *(array_1+i));
    }
    printf("\n");
    for(int i = 0; i < size - split; ++i){
        printf("%d ", *(array_2+i));
    }
}
