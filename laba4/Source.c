#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void per(int arr[100][100], int size) {
    int ans[100];
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i][j] < 0 && arr[i][j] % 2 == 0)
                sum += arr[i][j];
        }
        ans[i] = sum;
    }
    for (int i = 0; i < size; ++i)
        printf("Характеристика %d-й строки = %d\n", i + 1, ans[i]);

    for (int i = 0; i < size - 1; ++i) {
        int ind = i;
        int mx = ans[i];
        for (int j = i + 1; j < size; ++j) {
            if (ans[j] > mx) {
                mx = ans[j];
                ind = j;
            }
        }
        if (i != ind) {
            int temp;
            for (int j = 0; j < size; ++j) {
                temp = arr[ind][j];
                arr[ind][j] = arr[i][j];
                arr[i][j] = temp;
            }
            temp = ans[ind];
            ans[ind] = ans[i];
            ans[i] = temp;
        }
    }
    printf("Отсортированный массив:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

int chek_minus(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        if (mass[i] < 0) return 1;
    }
    return 0;
}

void vtor(int arr[100][100], int size) {
    int counter = 0;
    int mass[100];
    for (int i = 0; i < size; i++) mass[i] = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int number = arr[i][j];
            mass[j] = number;
        }
        if (chek_minus(mass, size) == 1) {
            counter += 1;
        }
        for (int i = 0; i < size; i++) mass[i] = 0;
    }
    if (counter == size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                arr[i][j] *= -1;
            }
        }
    }
    printf("Новый массив равен:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

void tret(int arr[100][100], int size) {
    int i = size / 2;
    int j = size / 2;
    int sum = 0;
    if (size % 2 != 0) {
        j += 1;
        printf("Нечётный размер массива!\n");
    }
    for (i; i < size; i++) {
        for (int t = 0; t < j; t++) {
            sum += arr[i][t];
            printf("%5d", arr[i][t]);
        }
        printf("\n");
    }
    printf("Сумма = %d", sum);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int arr[100][100];
    int size, choice, tasks;
    printf("Введите размер массива: ");
    while (scanf_s("%d", &size) != 1 || getchar() != '\n' || size > 100)
    {
        printf("Некорректный ввод!\n");
        rewind(stdin);
    }
    printf("Выберите способ заполнения массива\n1.Рандомно\n2.Вручную\n");
    while (scanf_s("%d", &choice) != 1 || getchar() != '\n' || choice < 0 || choice > 2)
    {
        printf("Некорректный ввод!\n");
        rewind(stdin);
    }
    system("cls");
    switch (choice) {
    case 1:
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                arr[i][j] = rand() % 201 - 100;
            }
        }
        break;
    case 2:
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("Введите элемент [%d] [%d]: ", i + 1, j + 1);
                while (scanf_s("%d", &arr[i][j]) != 1 || getchar() != '\n' || arr[i][j] < -100 || arr[i][j] > 100)
                {
                    printf("Некорректный ввод!\n");
                    rewind(stdin);
                }
            }
        }
        break;
    }
    system("cls");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("Выберите задание: ");
    while (scanf_s("%d", &tasks) != 1 || getchar() != '\n' || tasks < 0 || tasks > 3)
    {
        printf("Некорректный ввод!\n");
        rewind(stdin);
    }
    switch (tasks) {
    case 1:
        per(arr, size);
        break;
    case 2:
        vtor(arr, size);
        break;
    case 3:
        tret(arr, size);
        break;
    }
}