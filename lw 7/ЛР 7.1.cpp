#include <iostream>
using namespace std;

int create_mas(int* ptr, int n, int m); //создаю ДВУМерный массив, заполнение клавиатуры
int create_mas(int* ptr, int m); //создаю ОДНОмерный массив, заполнение клавиатуры
void print_mas(int* ptr, int n, int m); //вывод массива
int del_mas_el(int* ptr, int n, int m); //для ДВУМерного массива удаляет четные строки
int del_mas_el(int* ptr, int m); // для ОДНОмерного массива удаляет элементы между нулями
void create_mas_rand(int* ptr, int n, int m); //создание двумерного массива случайных чисел

int main() {
    setlocale(LC_ALL, "Russian");
    int size_m, n = 1, m = 1, choice; //размерность и вид массива
    int mas[100][100]; //сам массив
    srand(time(0));

    do {
        cout << "Какой массив вы хотите создать? " << endl;
        cout << "1 - Одномерный" << endl << "2 - Двумерный" << endl;
        cin >> size_m;
    } while (size_m < 1 || size_m > 2);

    if (size_m == 1) {
        do {
            cout << endl << "Сколько элементов будет в массиве? "; //размерность массива
            cin >> m;
        } while (m < 2 || m > 99);
        create_mas((int*)mas, m);
    }
    else {
        do {
            cout << endl << "Сколько строк будет в массиве? "; //размерность массива
            cin >> n;
        } while (n < 2 || n > 99);
        do {
            cout << "Сколько столбцов будет в массиве? "; //размерность массива
            cin >> m;
        } while (m < 1 || m > 99);

        do {
            cout << endl << "Как создать массив? " << endl;
            cout << "1 - Ввести элементы с клавиатуры" << endl << "2 - Заполнить массив случайно" << endl;
            cin >> choice;
        } while (choice < 1 || choice > 2);

        if (choice == 1) create_mas((int*)mas, n, m);
        else create_mas_rand((int*)mas, n, m);
    }

    cout << endl << "Текущий массив" << endl; //вывожу созданный массив
    print_mas((int*)mas, n, m);

    if (size_m == 1) {
        cout << "Из массива будут удалены все элементы, заключенные между двумя первыми нулевыми элементами" << endl << endl;
        m = del_mas_el((int*)mas, m);
    }
    else {
        cout << "Из массива будут удалены все четные строки" << endl << endl;
        n = del_mas_el((int*)mas, n, m);
    }

    cout << "Результат" << endl;
    print_mas((int*)mas, n, m); //вывожу измененный массив
   
    return 0;
}

int create_mas(int* ptr, int n, int m) {  //создаю ДВУМерный массив, заполнение клавиатуры
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Введите число num - элемент массива с индексом " << i << " " << j << endl;
            cin >> ptr[i * 100 + j];
        }
    }
    return 0;
}

void create_mas_rand(int* ptr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ptr[i * 100 + j] = rand() % 90 + 10;
        }
    }
}

int create_mas(int* ptr, int m) {  //создаю ОДНОмерный массив, заполнение клавиатуры
    for (int i = 0; i < m; i++) {
        cout << "Введите число num - элемент массива с индексом " << i << endl;
        cin >> ptr[i];
    }
    return 0;
}


void print_mas(int* ptr, int n, int m) { //вывожу массив
    for (int i = 0; i < n; i++) { //прохожу по сторокам
        for (int j = 0; j < m; j++) { //прохожу по столбцам
            cout << ptr[i * 100 + j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int del_mas_el(int* ptr, int n, int m) { //для ДВУМерного массива удаляет четные строки
    int num, count = 0;
    if (n % 2 == 0) num = n - 3; //проверяю с какой строки начать, если строки четные/нечетные
    else num = n - 2;
    for (int i = num; i > 0; i -= 2) { //переход по четным строкам
        ++count;
        for (int j = 0; j < m; j++) { //передвигаю строки, затирая четные строки
            for (int k = 0; k < count; k++) { //передвигаю каждый элемент в строке
                ptr[(i + k) * 100 + j] = ptr[(i + 1 + k) * 100 + j]; 
            }
        }
    }
    return (n / 2) + (n % 2); //новой количество строк в массиве
}

int del_mas_el(int* ptr, int m) { //для ОДНОмерного массива удаляет элементы между нулями
    int zero_1 = -1, zero_2 = -1;
    for (int i = 0; i < m && (zero_1 == -1 || zero_2 == -1); i++) {
        if (ptr[i] == 0) { //поиск индексов нулевых элементов
            if (zero_1 == -1) zero_1 = i; //индекс первого нуля
            else zero_2 = i; //индекс второго нуля
        }
    }
    if (zero_1 != -1 && zero_2 != -1 && zero_2 - zero_1 != 1 && m != 2) { //проверяю, что точно есть 2 нулевых элемента
        for (int i = zero_2 - 1; i > zero_1; i--) { //прохожу от одного нулевого элемента до другого
            for (int j = i; j < m; j++) {
                ptr[j] = ptr[j + 1]; //убираю элементы между нулями
            }
        }
        return m - (zero_2 - zero_1) + 1; //новая длина массива
    }
    return m;
}