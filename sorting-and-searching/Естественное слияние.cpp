#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void creature_mas_rand(int* ptr, int n);
void creature_mas_hands(int* ptr, int n);
void print(int* ptr, int n);
void Merge_Sort_Recursion(int* mas, int r, int t);
void Merger_Sort(int* mas, int r, int i);

int main() {
    system("chcp 1251 > Null");
    srand(time(0));

    int choice;
    int mas_size = 25;
    int* mas = new int[mas_size]; //создание массива

    do {
        cout << "Каким способом вы хотите создать массив? " << endl;
        cout << "1 - Ввести ручками" << endl;
        cout << "2 - Создать случайно" << endl;
        cin >> choice;
    } while (choice < 1 || choice > 2);

    switch (choice) { //выбор способа создания массива
    case 1: {
        creature_mas_hands(mas, mas_size);
        break;
    }
    default: {
        creature_mas_rand(mas, mas_size); //создание массива случайно
        break;
    }
    }

    cout << endl << "Создан массив!" << endl;
    print(mas, mas_size); //вывод массива
    auto start_time_recursive = chrono::steady_clock::now();  // начальное время
    Merger_Sort(mas, mas_size, 0);
    auto end_time_recursive = chrono::steady_clock::now(); // конечное время
    auto diff_time = end_time_recursive - start_time_recursive; //разница между начальным и конечным временем

    print(mas, mas_size);
    cout << "Сортировка выполнена за " << chrono::duration <double, milli>(diff_time).count() << " ms" << endl << endl;

    return 0;
}

void creature_mas_rand(int* ptr, int n) { //создаю массив через датчик случайных чисел
    for (int i = 0; i < n; i++) {
        ptr[i] = rand() % 1000 + 1; //случайное число от 1 до 1000
    }
}
void creature_mas_hands(int* ptr, int n) { //создание массива с клавиатуры
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> ptr[i];
    }
}
void print(int* ptr, int n) { //вывод текущего массива
    cout << endl << "Текущий массив:" << endl;
    for (int i = 0; i < n; i++) { //прохожу по массиву
        cout << ptr[i] << ' ';
    }
    cout << endl << endl;
}

void Merge_Sort_Recursion(int* mas, int r, int t) {
    int p = 1; // кол-0 элементов в первой серии
    int k = 1; // кол-0 элементов во второй серии
    int i = 0;
    bool flag = false; //определение надобности второй серии

    while (mas[i] <= mas[i + 1] && i < r - 1) { //подсчет кол-а элементов первой серии
        p++; //увеличиваю кол-о элементов в 1 серии
        i++;
    }
    if (mas[i] > mas[i + 1] && i < r - 1) {
        i++;
        flag = true; //есть вторая серия
        while (mas[i] <= mas[i + 1] && i < r - 1) { //подсчет кол-а элементов второй серии
            k++; //увеличиваю кол-о элементов в 2 серии
            i++;
        }
    }
    int num = i + 1; // количество элементов в 2х сериях

    int* a = new int[p];//серия 1
    int* b = new int[k];//серия 2

    for (i = 0; i < p; i++) { //заполнение первой серии
        a[i] = mas[i];
    }

    int count = 0;//счетчик
    if (flag == true) { //если есть вторая серия
        for (i = p; i < p + k; i++) { //заполнение второй серии
            b[count++] = mas[i];
        }
    }

    int j = 0;
    int l = 0;

    if (flag) {
        for (i = 0; i < num; i++) {
            if ((a[l] < b[j] || j >= k) && l < p) {
                mas[i] = a[l];
                l++;
            }
            else if ((a[l] > b[j] || l >= p) && j < k) {
                mas[i] = b[j];
                j++;
            }
            else if (a[l] == b[j] && j < k && l < p) {
                mas[i] = a[l];
                mas[i + 1] = b[j];
                l++;
                j++;
                i++;
            }
        }
    }

}
void Merger_Sort(int* mas, int r, int i) {
    if (i < r) {
        Merge_Sort_Recursion(mas, r, i);//сортировка
        Merger_Sort(mas, r, i + 1);//рекурсия
    }
}