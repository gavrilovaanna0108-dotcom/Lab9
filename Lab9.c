#include <stdio.h>
#include <locale.h>

int task1(void);
int task2(long long number);
int task3(char sym, int size);

int main(void)
{
    setlocale(LC_CTYPE, "RUS");

    long long number;
    char sym;
    int size;
    char replay;

    printf("Задание 1:\n");
    task1();
    printf("\n");

    printf("Задание 2:\n");
    do
    {
        printf("Введите целое число: ");
        if (scanf("%lld", &number) == 1)
        {
            int result2 = task2(number);
            printf("Сумма нечетных цифр: %d\n", result2);
        }
        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &replay);
    } while (replay == 'y' || replay == 'Y');
    printf("\n");

    printf("Задание 3:\n");
    printf("Введите символ: ");
    if (scanf(" %c", &sym) == 1)
    {
        printf("Введите размер: ");
        if (scanf("%d", &size) == 1 && size >= 2)
        {
            task3(sym, size);
        }
    }

    return 0;
}

int task1(void)
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 5; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%2d", 1);
        }
        printf("\n");
    }
    return 0;
}

int task2(long long number)
{
    long long temp = number < 0 ? -number : number;
    int odd_sum = 0;
    if (temp == 0)
    {
        return 0;
    }
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 != 0)
        {
            odd_sum += digit;
        }
        temp /= 10;
    }
    return odd_sum;
}

int task3(char sym, int size)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == size || j == 1 || j == i)
            {
                printf("%c", sym);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}