#include <iostream>
using namespace std;

void moving_the_ring(int* ptr_tower, int start, int end, int max_size, int n); //передвигаю кольцо с одной башни на другую
void one_layer_of_the_tower(int* ptr_tower, int n, int layer, int num_tower); //вывожу один слой ВСЕХ башен
void print_tower(int* ptr_tower, int n, int max_size); //вывод всех 3х башен
int Han(int n, int start, int end, int point, int* ptr_tower, int max_size, int constant_n);

int main() {
    setlocale(LC_ALL, "Russian");
    const int max_size = 100;
    int start, end, point, n, tower_list[max_size * 3];

    cout << "Ханойская башня " << endl << "Даны 3 стержня" << endl;
    do {
        cout << "Введите номер СТАРТОВОГО стержня (1, 2 или 3) ";
        cin >> start;
    } while (start < 1 || start > 3);
    do {
        cout << "Введите номер КОНЕЧНОГО стержня (1, 2 или 3) ";
        cin >> end;
    } while (end < 1 || end > 3 || start == end);

    switch (start + end) { //нахожу номер промежуточного стержня
    case 3: point = 3; break;
    case 4: point = 2; break;
    default: point = 1; break;
    }

    do {
        cout << "Введите количество дисков ";
        cin >> n;
    } while (n < 2 || n > max_size);

    for (int i = 0; i < max_size * 3; i++) { //заполняю нулями перечень башен
        tower_list[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        tower_list[max_size * (start - 1) + i] = i; //заполняю дисками стартовый стержень
    }
    tower_list[max_size * (start - 1)] = 1; //номер верхнего диска на стартовой башне

    cout << "Необходимо переместить диски со стержня " << start << " на стержень " << end << endl << endl;

    print_tower(tower_list, n, max_size);
    Han(n, start, end, point, tower_list, max_size, n);

    return 0;
}

void moving_the_ring(int* ptr_tower, int start, int end, int max_size, int n) { //передвигаю кольцо с одной башни на другую
    if (ptr_tower[(end - 1) * max_size] == 0) { //добавляю кольцо
        ptr_tower[(end - 1) * max_size] = n; //меняю верхнее кольцо конечной башни если на башне нет колец
    }
    else {
        ptr_tower[(end - 1) * max_size] -= 1; //меняю верхнее кольцо конечной башни если на башне есть кольца
    }
    ptr_tower[(end - 1) * max_size + ptr_tower[(end - 1) * max_size]] = ptr_tower[(start - 1) * max_size + ptr_tower[(start - 1) * max_size]]; 
    //ставлю новое кольцо

    ptr_tower[(start - 1) * max_size + ptr_tower[(start - 1) * max_size]] = 0; //убираю верхнее кольцо с начальной башни
    if (ptr_tower[(start - 1) * max_size] == n) {
        ptr_tower[(start - 1) * max_size] = 0; //меняю верхнее кольцо начальной башни если на башне нет колец
    }
    else {
        ptr_tower[(start - 1) * max_size] += 1; //меняю верхнее кольцо начальной башни если на башне есть кольца
    }
    //ptr_tower список, где хранятся кольца всех башен
    //start номер башни, С КОТОРОЙ надо ПЕРЕДВИНУТЬ кольцо
    //end номер башни, НА КОТОРУЮ надо ПЕРЕДВИНУТЬ кольцо
    //max_size сколько ячеек отведено на описание одной башни в массиве
    //n сколько всего ВСЕХ колец
}

void one_layer_of_the_tower(int* ptr_tower, int n, int layer, int num_tower) { //вывожу один слой ВСЕХ башен
    for (int i = num_tower; i <= num_tower + n - ptr_tower[num_tower + layer]; i++) { //пробелы до кольца
        cout << ' ';
    }
    for (int i = num_tower; i < num_tower + ptr_tower[num_tower + layer]; i++) { //кольцо
        cout << (ptr_tower[num_tower + layer] - 1) % 9 + 1;
    }
    cout << '|'; //стержень башни
    for (int i = num_tower; i < num_tower + ptr_tower[num_tower + layer]; i++) { //кольцо
        cout << (ptr_tower[num_tower + layer] - 1) % 9 + 1;
    }
    for (int i = num_tower; i <= num_tower + n - ptr_tower[num_tower + layer]; i++) { //пробелы после кольца
        cout << ' ';
    }
    cout << "  "; //пробел между башен
    //ptr_tower список, где хранятся кольца всех башен
    //n сколько всего ВСЕХ колец
    //layer слой башни, где 1 - верхний, n - нижний
    //num_tower индекс, с которого начинаются ячейки очередной башни
}

void print_tower(int* ptr_tower, int n, int max_size) { //вывод всех 3х башен
    for (int j = 1; j <= n; j++) {
        one_layer_of_the_tower(ptr_tower, n, j, 0); //слой башни 1
        one_layer_of_the_tower(ptr_tower, n, j, 1 * max_size); //слой башни 2
        one_layer_of_the_tower(ptr_tower, n, j, 2 * max_size); //слой башни 3
        cout << endl;
        //ptr_tower список, где хранятся кольца всех башен
        //n сколько всего ВСЕХ колец
        //max_size сколько ячеек отведено на описание одной башни в массиве
    }
    cout << endl;
}

void print_parameters(int n, int start, int end, int point, int* ptr_tower, int max_size, int constant_n) {
    cout << "Параметры функции" << endl; //вывод параметров
    cout << "Han(" << n << ", " << start << ", " << end << ", " << point << ", " << "[";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < constant_n + 1; j++) {
            cout << ptr_tower[i * max_size + j];
            if (i != 2 || j != constant_n) {
                cout << ", ";
            }
        }
        if (i != 2) {
            cout << "... , ";
        }
    }
    cout << "], " << max_size << ", " << constant_n << ") " << endl;
    if (n != 0) {
        cout << "Необходимо переложить со стержня " << start << " на стержень " << end << " диск радиуса " << n << endl << endl;
    }
    else cout << endl;
}

int Han(int n, int start, int end, int point, int* ptr_tower, int max_size, int constant_n) { //перекладываю кольца рекурсией
    //print_parameters(n, start, end, point, ptr_tower, max_size, constant_n); //вывод параметров
    if (n > 0) {
        Han(n - 1, start, point, end, ptr_tower, max_size, constant_n);
        moving_the_ring(ptr_tower, start, end, max_size, constant_n); //передвигаю кольцо с одной башни на другую

        cout << "Перекладываем верхний диск со стержня " << start << " на стержень " << end << endl;
        cout << start << " -> " << end << endl; //с какой башни на какую передвинули кольцо
        print_tower(ptr_tower, constant_n, max_size); //вывожу башни

        Han(n - 1, point, end, start, ptr_tower, max_size, constant_n);
    }
    //n текущее кольцо, с которым проводятся операции
    //start стержень с которого надо переместить кольцо
    //end стержень, на который надо переместить кольцо
    //point промежуточный стержень
    //ptr_tower список, где хранится расположение всех колец  всех башен
    //max_size сколько ячеек отведено на описание одной башни в массиве
    //constant_n сколько всего ВСЕХ колец
    return 0;
}