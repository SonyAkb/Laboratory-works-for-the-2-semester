#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

unsigned int Factorial_Recursive(unsigned int n);
unsigned int Factorial_Direct(unsigned int n);
double Direct_Calculation(int n, double x);
double Recursive_Calculation(int n, double x);

int main() {
    setlocale(LC_ALL, "Russian");
    int n; //количество членов ряда
    double x; //переменная

    cout << "Дана такая функция" << endl;
    cout << "        x^3         x^(2*n - 1)" << endl;
    cout << "S = x + --- + ... + -----------" << endl;
    cout << "         3!          (2*n - 1)" << endl;

    do{
        cout << "Введите целое, положительное число n - количество членов ряда: ";
        cin >> n; //ввожу количество членов ряда
    } while (n < 1);
    
    cout << "Введите число x - переменную: ";
    cin >> x; //ввожу переменную

    auto start_time_recursive = chrono::steady_clock::now();  // начальное время
    double result1 = Recursive_Calculation(n - 1, x); //вычисляю рекурсией
    auto end_time_recursive = chrono::steady_clock::now(); // конечное время

    auto diff1 = end_time_recursive - start_time_recursive; 
                            //разница между начальным и конечным временем
  
    auto start_time_direct = chrono::steady_clock::now(); // начальное время
    double result2 = Direct_Calculation(n, x); //вычисляю прямым способом
    auto end_time_direct = chrono::steady_clock::now(); // конечное время

    auto diff2 = end_time_direct - start_time_direct; //разница между начальным и конечным временем

    cout << endl << "Результат через сумму функционального ряда с помощью рекурсивной функции: " << result1 << endl;
    cout << "Функция выполнена за " << chrono::duration <double, milli>(diff1).count() << " ms" << endl << endl;

    cout << "Результат через прямое вычисление значения функции: " << result2 << endl;
    cout << "Функция выполнена за " << chrono::duration <double, milli>(diff2).count() << " ms" << endl;

    if (diff1 < diff2) cout << endl <<  "Вычисление с помощью рекурсии быстрее";
    else cout << endl << "Прямое вычисление значения функции быстрее";

    return 0;
}

unsigned int Factorial_Recursive(unsigned int n) { //вычисление факториала через рекурсию
    if (n == 0)
        return 1;
    return n * Factorial_Recursive(n - 1);
}

unsigned int Factorial_Direct(unsigned int n) { //вычисление факториала через цикл
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}

double Direct_Calculation(int n, double x) { // прямое вычисление значения функции
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(x, 2 * i + 1) / Factorial_Direct(2 * i + 1);
    }
    return sum;
}

double Recursive_Calculation(int n, double x) { // рекурсивное вычисление функции
    if (n == 0) {
        return x; // когда вычисляется первый элемент ряда
    }
    return pow(x, 2 * n + 1) / Factorial_Recursive(2 * n + 1) + Recursive_Calculation(n - 1, x);
    //pow(x, 2 * n + 1)  возвожу в необходимую степень
    //Factorial_Recursive(2 * n + 1)  вычисляю факториал
    //Recursive_Calculation(n - 1, x)  прибавляю предыдущее значение ряда
}