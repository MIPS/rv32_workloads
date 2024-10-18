#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1000000

int main() {
    char *src = (char *)malloc(SIZE);
    char *dest = (char *)malloc(SIZE);

    if (src == NULL || dest == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    memset(src, 'A', SIZE);

    clock_t start = clock();
    memcpy(dest, src, SIZE);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("memcpy took %f seconds to copy %d bytes\n", time_taken, SIZE);

    free(src);
    free(dest);

    return 0;
}
