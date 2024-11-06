/*
math.h sinf(), single precision, 800MHz, 71 cycles 

math.h cosf(), single precision, 800MHz, 81 cycles

math.h sin() (double), double precision, 800MHz, 296 cycles

math.h atanf(), single precision, 800MHz, 90 cycles

math.h atan2f(), single precision, 800MHz, 171 cycles
*/

#include <stdio.h>
#include <math.h>

int main() {
    double angles_d[] = {0, M_PI / 6, M_PI / 4, M_PI / 3, M_PI / 2, M_PI, 2 * M_PI / 3, 3 * M_PI / 4, 5 * M_PI / 6, 7 * M_PI / 6, 5 * M_PI / 4, 4 * M_PI / 3, 3 * M_PI / 2, 5 * M_PI / 3, 7 * M_PI / 4, 11 * M_PI / 6, 2 * M_PI};

    float angles_f[] = {0.0f, (float)(M_PI / 6), (float)(M_PI / 4), (float)(M_PI / 3), (float)(M_PI / 2), (float)(M_PI), (float)(2 * M_PI / 3), (float)(3 * M_PI / 4), (float)(5 * M_PI / 6), (float)(7 * M_PI / 6), (float)(5 * M_PI / 4), (float)(4 * M_PI / 3), (float)(3 * M_PI / 2), (float)(5 * M_PI / 3), (float)(7 * M_PI / 4), (float)(11 * M_PI / 6), (float)(2 * M_PI)};
    int num_angles = 17;

    for (int i = 0; i < num_angles; i++) {
        double angle_d = angles_d[i];
        float angle_f = angles_f[i];
	
	#ifdef SIN
        // Double precision calculations
        printf("IN SIN\n");
        asm volatile("xor x0,x0,x0");
        double sin_d = sin(angle_d);
	//printf("sin_d: %f\n", sin_d);
                // Single precision calculations
        asm volatile("xor x0,x0,x0");
        
	asm volatile("xor x1,x1,x1");
	float sin_f = sinf(angle_f);
	asm volatile("xor x1,x1,x1");
	#endif

	#ifdef COS
	printf("IN COS\n");
	asm volatile("xor x0,x0,x0");
        float cos_f = cosf(angle_f);
	asm volatile("xor x0,x0,x0");
	#endif

	#ifdef ATAN
	printf("IN ATAN\n");
	float tan_f = tanf(angle_f);	
	asm volatile("xor x0,x0,x0");
        float atan_f = atanf(tan_f);
	asm volatile("xor x0,x0,x0");

	float sin_f = sinf(angle_f);
	float cos_f = cosf(angle_f);
	asm volatile("xor x1,x1,x1");
	float atan2_f = atan2f(sin_f, cos_f);
	asm volatile("xor x1,x1,x1");
	#endif
    }

    return 0;
}

