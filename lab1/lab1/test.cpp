#include <stdio.h>
#include <locale>
#include <math.h>

#define MAX_ITERATIONS 50
#define EPSILON 1e-6
void main(void)
{
    setlocale(LC_ALL, "Rus");
    double x;
    for (int i = 0; i < 15; i++) {
        scanf_s("%lf", &x);
        double cosX = 0.0; // значиение функции cos(x)
        //int j = 1; //счетчик количества элементов
        double p = 1.0; //начальное значение дроби
        double z = 1.0; //начальное значение числителя
        double y = 1.0; //начальное значение знаменателя
        int n = 0;
        for (int j = 0; j < MAX_ITERATIONS; j++)
        {
            cosX += p;
            n += 2;
            z *= -X * X;
            y *= (n - 1) * n;
            p = z / y;
            if (fabs(p) <= EPSILON) {
                //printf("%f", cosX);
                break;
            }
        }
        double exact = cos(X);
        double error = fabs(cosX - exact);
        printf("%.4f\t%.8f\t%.8\t\t%.2e\n", X, cosX, exact, error);
    }

}