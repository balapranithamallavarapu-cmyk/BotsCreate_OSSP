#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n = 3, capacity = 3, i;

    arr = (int *)calloc(capacity, sizeof(int));

    if (arr == NULL)
        return 1;

    printf("Initial zero values:\n");
    for (i = 0; i < capacity; i++)
        printf("%d ", arr[i]);

    for (i = 0; i < n; i++)
        arr[i] = (i + 1) * 100;

    printf("\nMarket tick data:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    if (n == capacity) {
        int *temp = (int *)realloc(arr, 6 * sizeof(int));

        if (temp == NULL) {
            free(arr);
            return 1;
        }

        arr = temp;
        capacity = 6;
    }

    arr[n++] = 400;

    printf("\nAfter resizing:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nCapacity: %d\n", capacity);

    free(arr);
    arr = NULL;
printf("Memory freed successfully.\n");
    return 0;
}
