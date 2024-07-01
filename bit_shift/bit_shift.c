#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ARRAY_SIZE 1000000

int main() {
	uint32_t* A = (uint32_t*)malloc(ARRAY_SIZE*sizeof(uint32_t));
	if (A == NULL) {
		printf("Mem allocation failed");
		return 1;
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = (uint32_t) i;
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = (A[i] << 1) | (A[i] >> 31);
	}
	free(A);
	return 0;
}
