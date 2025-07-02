#include <stdio.h>

typedef struct com
{
	float real;
	float imaginary;
} Complex;

Complex complex_add(Complex a, Complex b);

int main(void)
{
	Complex a = { 2,3 };
	Complex b = { 3,4 };
	Complex c = complex_add(a, b);
	printf("%lf + %lfi\n", c.real, c.imaginary);

	return 0;
}

Complex complex_add(Complex a, Complex b)
{
	Complex result;
	result.imaginary = a.imaginary + b.imaginary;
	result.real = a.real + b.real;
	return result;
}