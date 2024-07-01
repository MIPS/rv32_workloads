#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main() {
	float* A = (float*)malloc(ARRAY_SIZE*sizeof(float));
	float* B = (float*)malloc(ARRAY_SIZE*sizeof(float));
	float* C = (float*)malloc(ARRAY_SIZE*sizeof(float));

	if (A == NULL || B == NULL || C == NULL) {
		printf("Mem allocation failed");
		return 1;
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = (float)(i+1);
		B[i] = (float)A[i] * 2.0;
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		C[i] = A[i] * B[i];
	}

	free(A);
	free(B);
	free(C);

	return 0;
}
