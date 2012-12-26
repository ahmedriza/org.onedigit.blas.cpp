/*
 * dgemm.cpp
 *
 *  Created on: Dec 25, 2012
 *      Author: ahmed
 */

#include <stdlib.h>
#include <iostream>
#include <cblas.h>

int main(int argc, char** argv)
{
	int N = 20000;
	size_t size = N * N * sizeof(double);
	std::cout << size << std::endl;

	double* a = (double*)malloc(size);
	double* b = (double*)malloc(size);
	double* c = (double*)malloc(size);

	for (int i = 0; i < N * N; i++) {
		a[i] = i;
		b[i] = i;
	}

	cblas_dgemm(CblasRowMajor, /* const enum CBLAS_ORDER Order */
			CblasNoTrans, /* const enum CBLAS_ORDER Order */
			CblasNoTrans, /* const enum CBLAS_TRANSPOSE TransA */
			N, /* const int M */
			N, /* const int N, */
			N, /* const int K */
			1.0, /* const double alpha */
			a, /* const double *A */
			N, /* const int lda */
			b, /* const double *B */
			N, /* const int ldb */
			0.0, /* const double beta */
			c, /* const double *C */
			N); /* const double int ldc */

	std::cout << c[N * N - 1] << std::endl;
}

