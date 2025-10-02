#include <stdio.h>
#include <locale>

#define MAX_ITERATIONS 50
#define PI 3.14159265358979323846

int main()
{
    setlocale(LC_ALL, "Rus");
    double X;                                                   //входные данные
    char ans;                                                   //ввод от пользователя (да\нет)
    double EPSILON;                                             //точность
    double cosX;                                                //значиение функции cos(x)
    double p;                                                   //начальное значение дроби
    double z;                                                   //начальное значение числителя
    double y;                                                   //начальное значение знаменателя
    int n;                                                      //вспомогательная переменная для подсчета знаменателя
    int periods;                                                //для сбрасывания периодов
    printf("%s", "Введите точность: ");
    scanf_s("%lf", &EPSILON);                                   //ввод значения точности
    while (1) {
        cosX = 0.0;                                             //объявление начальных значений переменных
        p = 1.0;
        z = 1.0;
        y = 1.0;
        n = 0;
        printf("Продолжить расчет?(y/n)\n");
        scanf_s(" %c", &ans);                                     //Ввод и проверка ответа пользователя
        if (ans == 'y') {
            printf("%s", "Введите число: ");
            scanf_s("%lf", &X);                                    //ввод значения входного числа
            if (fabs(X) >= 30) {                                   //сброс оборотов
                periods = X / (2 * PI);
                X -= 2 * PI * periods;
            }
            for (int j = 0; j < MAX_ITERATIONS; j++) {              //вычисление косинуса
                cosX += p;
                n += 2;
                z *= -X * X;                                        //вычисление числителя
                y *= (n - 1) * n;                                   //вычисление знаменателя
                p = z / y;                                          //вычисление значения дроби
                if (fabs(p) <= EPSILON) {                           //проверка чтобы дробь была <= epsilon
                    printf("%s%f%s", "cos(x) = ", cosX, "\n");
                    break;
                }
            }
        }
        else if (ans == 'n') break;
        else {
            printf("введите один из предложенных ответов\n");
            continue;
        }
    }
}

