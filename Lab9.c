#include <stdio.h>
#include <locale.h>

int task1_table1_val(int i, int j);
int task1_table2_val(int i, int j);
int task1_table3_val(void);
int task2(long long number);
char task3_get_char(char sym, int i, int j, int size);

int main(void)
{
    setlocale(LC_CTYPE, "RUS");
    
    long long number;
    char sym;
    int size;
    char replay;

    printf("Задание 1:\n");
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            printf("%4d", task1_table1_val(i, j));
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%4d", task1_table2_val(i, j));
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 5; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%2d", task1_table3_val());
        }
        printf("\n");
    }
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
    do
    {
        printf("Введите символ: ");
        if (scanf(" %c", &sym) == 1)
        {
            printf("Введите размер: ");
            if (scanf("%d", &size) == 1 && size >= 2)
            {
                for (int i = 1; i <= size; i++)
                {
                    for (int j = 1; j <= i; j++)
                    {
                        putchar(task3_get_char(sym, i, j, size));
                    }
                    putchar('\n');
                }
            }
        }
        printf("Повторить рисунок? (Да - y, нет - n): ");
        scanf(" %c", &replay);
    } while (replay == 'y' || replay == 'Y');

    return 0;
}

int task1_table1_val(int i, int j)
{
    return i * j;
}

int task1_table2_val(int i, int j)
{
    return i * j;
}

int task1_table3_val(void)
{
    return 1;
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

char task3_get_char(char sym, int i, int j, int size)
{
    if (i == size || j == 1 || j == i)
    {
        return sym;
    }
    return ' ';
}
