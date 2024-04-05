#include <iostream>
using namespace std;

void print(int* ptr, int line, int col, int max_size); //вывод двумерного массива
void print_one_array(int* ptr, int line, int col); //вывод одномерного массива
void array_restoring(int* ptr_old_one, int* ptr_new_two, int line, int col, int max_size); 
                                                //распутываю одномерный массив


int main() {
    setlocale(LC_ALL, "Russian");

    const int max_size = 50; //максимальный размер массива
    int mas[max_size][max_size], line, column;
    int a, count_one_array_line=0, count_one_array_all = 0, count_one_array_col = 0;
    int new_two_array[max_size][max_size]; //новый распутанный двумерный массив
    int one_array[max_size * max_size * 2]; //одномерный запутанный массив

    do {
        cout << "Введите число строк line (line > 1 и line <= " << max_size << ")  "; 
        cin >> line; //ввод строк матрицы
    } while (line <= 1 && line > max_size);
    do {
        cout << "Введите число столбцов column (column > 1 и column <= " << max_size << ")  "; 
        cin >> column; //ввод столбцов матрицы
    } while (column <= 1 && column > max_size);

    for (int i = 0; i < line; ++i) { //заполняю двумерный массив (ввод элементов массива)
        for (int j = 0; j < column; ++j) {
            cout << "Введите число num - элемент массива с индексом " << i << " " << j << endl;
            cout << "Числа не должны повторяться!" << endl;
            cin >> mas[i][j];
        }  
    }
    cout << endl << "Первоначальный двумерный массив" << endl;  
    print((int*)mas, line, column, max_size); //вывожу двумерный массив

    //пользователь вводит в каком порядке в одномерный массив записали сначала строки, а потом столбцы
    cout << "Введите, в каком порядке записать строки двумерного массива в одномерный массив" << endl;
    do {
        cout << "Введите новый НОМЕР СТРОКИ  "; //перемешиваю массив по строкам
        cin >> a;
        count_one_array_col++; //подсчитываю сколько строк уже записано
        for (int i = 0; i < column; i++) { 
            one_array[count_one_array_all] = mas[a - 1][i]; //записываю новый элемент в одномерный массив
            count_one_array_all++; //индекс слудующего элемента в одномерном массиве
        }
    } while (count_one_array_col < line);

    cout << "Введите, в каком порядке записать столбцы двумерного массива в одномерный массив" << endl;
    do {
        cout << "Введите новый НОМЕР СТОЛБЦА  "; //перемешиваю массив по столбцам
        cin >> a;
        count_one_array_line++; //подсчитываю сколько столбцов уже записано
        for (int i = 0; i < line; i++) { 
            one_array[count_one_array_all] = mas[i][a - 1]; //записываю новый элемент в одномерный массив
            count_one_array_all++; //индекс слудующего элемента в одномерном массиве
        }
    } while (count_one_array_line < column);

    cout << endl << "В одномерный массив записали сначала строки в произвольном порядке, затем столбцы в произвольном порядке" << endl;
    print_one_array(one_array, line, column); //вывожу запутанный одномерный массив

    array_restoring(one_array, (int*)new_two_array, line, column, max_size); //распутываю одномерный массив
    cout << endl << "Восстановленный двумерный массив " << endl;
    print((int*)new_two_array, line, column, max_size); //вывожу распутанный двумерный массив

    return 0;
}

void print(int* ptr, int line, int col, int max_size) { //вывод двумерного массива
    for (int i = 0; i < line; ++i) { //проход по строкам
        for (int j = 0; j < col; ++j) { //проход по столбцам
            cout << ptr[i * max_size + j] << ' '; //вывод элемента
        }
        cout << endl;
    }
    cout << endl;
}

void print_one_array(int* ptr, int line, int col) { //вывод одномерного запутанного массива
    for (int i = 0; i < line * col * 2; ++i) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

void array_restoring(int* ptr_old_one, int* ptr_new_two, int line, int col, int max_size) { //распутываю одномерный массив
    int a;
    for (int i = 0; i < line * col; i += col) { //прохожу по одномерному массиву (по строкам первоначального двумерного массива) 
        //с шагом равным длине строки двумерного массива
        for (int j = line * col; j < line * col * 2; j ++) { //прохожу по одномерному массиву (по столбцам первоначального двумерного массива)
            if (ptr_old_one[i] == ptr_old_one[j]) { //проверяю совпадение первого элемента к-л строки и превого элемента к-л столбца
                a = (j - line * col) % line; //индекс, с которого необходимо вставить строку 
                for (int z = 0; z < col; z++) { //поэлементно записываю всю строку в новый двумерный массив
                    ptr_new_two[a * max_size + z] = ptr_old_one[z + i]; //переставляю элемент из одномерного массива в двумерный
                }
            }
        }
    }
}