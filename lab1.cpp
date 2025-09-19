#include <stdio.h>
#include <locale>

#define MAX_ITERATIONS 50
#define EPSILON 1e-6
#define N 15
#define PI 3.14159265358979323846

int main()
{
    setlocale(LC_ALL, "Rus");
    double X; //входные данные
    int periods; //для сбрасывания оборотов
    double cosX; // значиение функции cos(x)
    double p; //начальное значение дроби
    double z; //начальное значение числителя
    double y; //начальное значение знаменателя
    int n; //вспомогательная переменная для подсчета знаменателя
    for (int i = 0; i < N; i++) {
        cosX = 0.0; //инициализация переменных
        p = 1.0;
        z = 1.0;
        y = 1.0;
        n = 0;
        scanf_s("%lf", &X);
        if (X >= 30) { //сброс оборотов
            periods = X / (2 * PI);
            X -= 2 * PI * periods;
        }
        for (int j = 0; j < MAX_ITERATIONS; j++) { //вычисление косинуса
            cosX += p;
            n += 2;
            z *= -X * X; //числитель
            y *= (n - 1) * n; //знаменатель
            p = z / y;
            if (fabs(p) <= EPSILON) { //проверка чтобы дробь была <= epsilon
                printf("%s%f%s", "cos(x) = ", cosX, "\n");
                break;
            }
        }
    }
    fflush(stdin); //очистка потока ввода
}
