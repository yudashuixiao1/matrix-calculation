#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define fs 48000
#define M_PI 3.141592654

float* expSineSweep(float f1, float f2,float duration,  size_t samplerate) {
	// Generate the exponential sine sweep signal
	float w1 = 2 * M_PI*f1;
	float w2 = 2 * M_PI*f2;
	size_t length = duration * samplerate;
	float* timeIndex = (float*)malloc(sizeof(float) * length);

	float K = duration * w1 / logf(w2 / w1);
	float L = duration / logf(w2 / w1);
	float* expSineSweep = (float*)malloc(sizeof(float) * length);

	for (size_t n = 0; n < length; n++)
	{
		timeIndex[n] = n * 1.0f / samplerate;//t = 0:1 / samplerate : (duration*samplerate - 1) / samplerate;
	}

	for (size_t n = 0; n < length; n++)
	{
		expSineSweep[n] = sinf(K * (expf(timeIndex[n] / L) - 1));
	}

	free(timeIndex);
	return expSineSweep;
}


float *vi;
//float be ;
//float si1;
//float si2;
//float si3;
//float si;
//float al;
//float mu;
//float la;
//float nu;
//float ka;
//float om;

int main()
{

    //int fs = 48000;

    vi = expSineSweep(2,20000,1.5,48000 );

    // gauss functions elimination

/*
   for(int i = 0; i<2000; i++){
       printf("%e\n", vi[i]);
   }
*/
    return 0;
}
