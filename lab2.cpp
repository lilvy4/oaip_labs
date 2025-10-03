#include <stdio.h>
#include <locale>

void init_array(int array[], int size)                                             //функция ввода массива
{
    for (int i = 0; i < size; i++) scanf_s("%d", &array[i]);
}

void print_array(int array[], int size)                                           //фунцкия вывода массива
{
    for (int i = 0; i < size; i++) printf("%d", array[i]);
}

int decode_sequence(int sequence[], int size, int decoded[])                      //функция для расшифровки массива
{
    for (int i = 0; i < size; i += 3)
    {
        int count0 = 0, count1 = 0;                                              //счётчики
        for (int j = i; j < i + 3; j++)
        {
            if (sequence[j] == 1) count1++;                                     //поссчёт количества нулей и единиц
            else if (sequence[j] == 0) count0++;
            else return 1;
        }
        if (count0 >= 2) decoded[i / 3] = 0;                                   //заполнение расшифрованного массива
        else decoded[i / 3] = 1;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    while (1)
    {
        int length;                                                                                        //длина массива
        printf("%s", "Введите длину массива ");
        scanf_s("%d", &length);
        int err = 0;                                                                                       //код ошибки(0 или 1)
        int* sequence = (int*)malloc(length * sizeof(int));                                                //выделение памяти под динамические массивы
        int* decoded = (int*)malloc(length * sizeof(int));
        char answer;                                                                                       //переменная для ответа пользователя
        if (length % 3 != 0)                                                                               //проверка на кратность 3
        {
            printf("%s", "Длина массива должна быть кратна 3\n");
            continue;
        }
        printf("%s", "Введите массив ");
        init_array(sequence, length);                                                                    //ввод массива
        err = decode_sequence(sequence, length, decoded);                                                //расшифровка массива с возвращением кода ошибки
        if (err == 0) print_array(decoded, length / 3);                                                  //проверка на ввод 0 или 1
        else
        {
            printf("%s", "Нужно вводить 0 или 1\n");
            continue;
        }
        free(sequence);                                                                                  //освобождение памяти
        free(decoded);
        printf("%s", "\nЖелаете продолжить?(y/n) ");
        scanf_s(" %c", &answer);
        if (answer == 'y') continue;                                                                    //продолжение программы по команде пользователя
        else break;
    }
    return 0;
}
