#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void arrayGenerator(int arr[10][10], int sizeOfArray)
{
    int* end = &arr[sizeOfArray - 1][sizeOfArray - 1];
    for (int* pa = &arr[0][0]; pa <= end; pa++)
    {
        *pa = rand() % (sizeOfArray * sizeOfArray) + 1;
    }
}

void spiralOutput(int oldArr[10][10], int arr[10][10], int sizeOfArray, int spaceY)
{
    const int space = spaceY;
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    destCoord.X = 0;
    destCoord.Y = spaceY;
    SetConsoleCursorPosition(hStdout, destCoord);
    int* pOldArr = &oldArr[0][0];
    int spaceX = 0;
    int left = 0, right = sizeOfArray - 1, bottom = sizeOfArray - 1, top = 0, count = 0;
    while (count < (sizeOfArray * sizeOfArray))
    {
        spaceX = 5;
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = *(pOldArr + count);
            destCoord.X += spaceX;
            SetConsoleCursorPosition(hStdout, destCoord);
            Sleep(10);
            cout << *(pOldArr + count);
            count++;
        }
        spaceY = 3;
        for (int j = top + 1; j <= bottom; j++)
        {
            arr[j][right] = *(pOldArr + count);
            destCoord.Y += spaceY;
            SetConsoleCursorPosition(hStdout, destCoord);
            Sleep(10);
            cout << *(pOldArr + count);
            count++;
        }
        spaceX = -5;
        for (int i = right - 1; i >= left; i--)
        {
            arr[bottom][i] = *(pOldArr + count);
            destCoord.X += spaceX;
            SetConsoleCursorPosition(hStdout, destCoord);
            Sleep(10);
            cout << *(pOldArr + count);
            count++;
        }
        spaceY = -3;
        for (int j = bottom - 1; j >= top + 1; j--)
        {
            arr[j][left] = *(pOldArr + count);
            destCoord.Y += spaceY;
            SetConsoleCursorPosition(hStdout, destCoord);
            Sleep(10);
            cout << *(pOldArr + count);
            count++;
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    destCoord.X = 0;
    destCoord.Y = space + sizeOfArray * 3 + 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void snakeOutput(int oldArr[10][10], int arr[10][10], int sizeOfArray, int spaceY)
{
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    destCoord.X = 0;
    destCoord.Y = 0;
    SetConsoleCursorPosition(hStdout, destCoord);
    int column = 0, spaceX = 0;
    int* pOldArr = &oldArr[0][0];

    for (int i = 0; i < sizeOfArray; i++)
    {
        if (column % 2 == 0)
        {
            for (int j = 0; j < sizeOfArray; j++)
            {
                arr[j][column] = *pOldArr;
                destCoord.X = column + spaceX;
                destCoord.Y = j + j + spaceY;
                SetConsoleCursorPosition(hStdout, destCoord);
                Sleep(100);
                cout << *pOldArr;
                pOldArr++;
            }
            spaceX += 5;
        }
        else
        {
            for (int j = sizeOfArray - 1; j >= 0; j--)
            {
                arr[j][column] = *pOldArr;
                destCoord.X = column + spaceX;
                destCoord.Y = j + j + spaceY;
                SetConsoleCursorPosition(hStdout, destCoord);
                Sleep(100);
                cout << *pOldArr;
                pOldArr++;
            }
            spaceX += 5;
        }
        column++;
    }
    destCoord.X = 0;
    destCoord.Y = spaceY + sizeOfArray * 2 + 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void swapOutput(int arr[10][10], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        for (int j = 0; j < sizeOfArray; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

void swapA(int arr[10][10], int sizeOfArray)
{
    cout << "Сортировака A\n";
    for (int i = 0; i < sizeOfArray / 2; i++)
    {
        for (int j = 0; j < sizeOfArray / 2; j++)
        {
            swap(*(*(arr + i) + j), *(*(arr + i + sizeOfArray / 2) + j + sizeOfArray / 2));
        }
    }
    for (int i = 0; i < sizeOfArray / 2; i++)
    {
        for (int j = 0; j < sizeOfArray; j++)
        {
            swap(*(*(arr + i) + j), *(*(arr + i + sizeOfArray / 2) + j));
        }
    }

    swapOutput(arr, sizeOfArray);
}

void swapB(int arr[10][10], int sizeOfArray)
{
    cout << "Сортировка B\n";
    for (int i = 0; i < sizeOfArray / 2; i++)
    {
        for (int j = 0; j < sizeOfArray / 2; j++)
        {
            swap(*(*(arr + i) + j), *(*(arr + i + sizeOfArray / 2) + j + sizeOfArray / 2));
            swap(*(*(arr + i + sizeOfArray / 2) + j), *(*(arr + i) + j + sizeOfArray / 2));
        }
    }
    swapOutput(arr, sizeOfArray);
}

void swapC(int arr[10][10], int sizeOfArray)
{
    cout << "Сортировка C\n";
    for (int i = 0; i < sizeOfArray / 2; i++)
    {
        for (int j = 0; j < sizeOfArray; j++)
        {
            swap(*(*(arr + i) + j), *(*(arr + i + sizeOfArray / 2) + j));
        }
    }
    swapOutput(arr, sizeOfArray);
}

void swapD(int arr[10][10], int sizeOfArray)
{
    cout << "Сортировка D\n";
    for (int i = 0; i < sizeOfArray; i++)
    {
        for (int j = 0; j < sizeOfArray / 2; j++)
        {
            swap(*(*(arr + i) + j), *(*(arr + i) + j + sizeOfArray / 2));
        }
    }
    swapOutput(arr, sizeOfArray);
}

int arr6[6][6], arr8[8][8];
void newArray6Generator(int arr[10][10], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
        for (int j = 0; j < sizeOfArray; j++)
            arr6[i][j] = arr[i][j];
}

void quickSort6(int arr[10][10], int sizeOfArray, int left, int right)
{
        
        int* p6End = &arr6[sizeOfArray - 1][sizeOfArray - 1];
        int* p6 = &arr6[0][0];
        int mid;
        int l = left;
        int r = right;
        mid = *(p6 + (l + r) / 2);

        while (l < r)
        {
            while (*(p6 + l) < mid)
                l++;
            while (*(p6 + r) > mid)
                r--;
            if (l <= r)
            {
                swap(*(p6 + l), *(p6 +r));
                l++;
                r--;
            }
        }
        if (left < r)
            quickSort6(arr, sizeOfArray, left, r);
        if (right > l)
            quickSort6(arr, sizeOfArray, l, right);

        for (int i = 0; i < sizeOfArray; i++)
            for (int j = 0; j < sizeOfArray; j++)
                arr[i][j] = arr6[i][j];
   
}
    
void newArray8Generator(int arr[10][10], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
        for (int j = 0; j < sizeOfArray; j++)
            arr8[i][j] = arr[i][j];
}

void quickSort8(int arr[10][10], int sizeOfArray, int left, int right)
{
    int* p8End = &arr8[sizeOfArray - 1][sizeOfArray - 1];
    int* p8 = &arr8[0][0];
    int mid;
    int l = left;
    int r = right;
    mid = *(p8 + (l + r) / 2);

    while (l < r)
    {
        while (*(p8 + l) < mid)
            l++;
        while (*(p8 + r) > mid)
            r--;
        if (l <= r)
        {
            swap(*(p8 + l), *(p8 + r));
            l++;
            r--;
        }
    }
    if (left < r)
        quickSort8(arr, sizeOfArray, left, r);
    if (right > l)
        quickSort8(arr, sizeOfArray, l, right);

    for (int i = 0; i < sizeOfArray; i++)
        for (int j = 0; j < sizeOfArray; j++)
            arr[i][j] = arr8[i][j];
}

void quickSort10(int arr[10][10], int sizeOfArray, int left, int right)
{
    int* p10End = &arr8[sizeOfArray - 1][sizeOfArray - 1];
    int* p10 = &arr[0][0];
    int mid;
    int l = left;
    int r = right;
    mid = *(p10 + (l + r) / 2);

    while (l < r)
    {
        while (*(p10 + l) < mid)
            l++;
        while (*(p10 + r) > mid)
            r--;
        if (l <= r)
        {
            swap(*(p10 + l), *(p10 + r));
            l++;
            r--;
        }
    }
    if (left < r)
        quickSort10(arr, sizeOfArray, left, r);
    if (right > l)
        quickSort10(arr, sizeOfArray, l, right);
}

int main()
{
        setlocale(0, "");
        srand(time(NULL));
        int matrix[10][10];
        int spaceY = 10, size;
        while (true)
        {
            cout << "Введите порядок квадратной матрицы (6, 8, 10)\n";
            cin >> size;
            if ((size != 6) && (size != 8) && (size != 10))
            {
                cout << "Неудачное число, попробуйте еще!";
                spaceY += 5;
            }
            else break;
        }
        arrayGenerator(matrix, size);
        cout << "Как нам заполнить матрицу?\n1. Спиралью\n2. Змейкой\n";
        int c;
        cin >> c;
        switch (c)
        {
        case(1):
            spiralOutput(matrix, matrix, size, spaceY);
            break;
        case(2):
            snakeOutput(matrix, matrix, size, spaceY);
            break;
        default:
            cout << "Не знаем такого способа\n";
            break;
        }
        
        short menu;
        while (true)
        {
            cout << "2. Перестановка блоков\n3. Сортировка\n4. Арифметические операции\n5. ИДЗ\n0. Выход\n";
            cin >> menu;
            switch (menu)
            {
            case(2):
                cout << "Второе задание\n1. По кругу\n2. Крест-накрест\n3. Нижние с верхними\n4. Левые с правыми\n";
                short choise;
                cin >> choise;
                switch (choise)
                {
                case(1):
                    swapA(matrix, size);
                    break;
                case(2):
                    swapB(matrix, size);
                    break;
                case(3):
                    swapC(matrix, size);
                    break;
                case(4):
                    swapD(matrix, size);
                    break;
                default:
                    break;
                }
                break;
            case(3):
                cout << "Третье задание\n";
                if (size == 6)
                {
                    newArray6Generator(matrix, size);
                    quickSort6(matrix, size, 0, size * size - 1);
                    swapOutput(matrix, size);
                    break;
                }
                if (size == 8)
                {
                    newArray8Generator(matrix, size);
                    quickSort8(matrix, size, 0, size * size - 1);
                    swapOutput(matrix, size);
                    break;
                }
                if (size == 10)
                {
                    quickSort10(matrix, size, 0, size * size - 1);
                    swapOutput(matrix, size);
                    break;
                }
            case(4):
                cout << "Четвертое задание\nВыберите арифметическую операцию:\n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n";
                short choise1;
                cin >> choise1;
                switch (choise1)
                {
                case(1):
                    cout << "Какое число будем прибавлять?\n";
                    int num1;
                    cin >> num1;
                    for (int i = 0; i < size; i++)
                        for (int j = 0; j < size; j++)
                            matrix[i][j] += num1;
                    break;
                case(2):
                    cout << "Какое число будем вычитать?\n";
                    int num2;
                    cin >> num2;
                    for (int i = 0; i < size; i++)
                        for (int j = 0; j < size; j++)
                            matrix[i][j] -= num2;
                    break;
                case(3):
                    cout << "На какое число будем умножать?\n";
                    int num3;
                    cin >> num3;
                    for (int i = 0; i < size; i++)
                        for (int j = 0; j < size; j++)
                            matrix[i][j] *= num3;
                    break;
                case(4):
                    cout << "На какое число будем делить?\n";
                    int num4;
                    cin >> num4;
                    for (int i = 0; i < size; i++)
                        for (int j = 0; j < size; j++)
                            matrix[i][j] /= num4;
                    break;
                default:
                    cout << "Пока не знаем такой операции\n";
                    break;
                }
                swapOutput(matrix, size);
                break;
            case(5):
                cout << "Пятое задание\n";
                int matrix2[10][10];
                arrayGenerator(matrix2, size);
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        cout << matrix[i][j] << '\t';
                    }
                    if (i == size / 2)
                    {
                        cout << "---    ";
                    }
                    else
                    {
                        cout << "       ";
                    }
                    for (int k = 0; k < size; k++)
                    {
                        cout << matrix2[i][k] << '\t';
                    }
                    cout << '\n';
                }
                cout << "\n\n";

                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        cout << matrix[i][j] << "-" << matrix2[i][j] << '\t';
                    }
                    cout << '\n';
                }
                cout << "\n\n";

                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        cout << matrix[i][j] - matrix2[i][j] << '\t';
                    }
                    cout << '\n';
                }
                cout << '\n';
                break;
            default:
                cout << "Выполнение программы завершено";
                exit(0);
            }
        }
    return 0;
}
