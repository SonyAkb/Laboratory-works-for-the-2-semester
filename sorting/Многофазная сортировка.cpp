#include <iostream>
#include <vector>
using namespace std;

void creature_mas_rand(vector<int>& ptr) { //создаю массив через датчик случайных чисел
    for (int i = 0; i < ptr.size(); i++) {
        ptr[i] = rand() % 1000 + 1; //случайное число от 1 до 1000
    }
}
void creature_mas_hands(vector<int>& ptr) { //создание массива с клавиатуры
    cout << endl;
    for (int i = 0; i < ptr.size(); i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

void print(vector<int>& ptr) { //вывод текущего массива
    cout << endl << "Текущий массив:" << endl;
    for (int i = 0; i < ptr.size(); i++) { //прохожу по массиву
        cout << ptr[i] << ' ';
    }
    cout << endl << endl;
}

void Quick_Sort(vector<int>& vect, int start_Index, int pivot_Index) { //быстрая сортировка
    if (start_Index < pivot_Index) {
        int current_Index = start_Index;
        for (int i = current_Index; i < pivot_Index; i++) { //иду до опорного элемента
            if (vect[i] <= vect[pivot_Index]) {
                swap(vect[i], vect[current_Index++]); //меняю элементы местами
            }
        }
        swap(vect[current_Index], vect[pivot_Index]); //меняю элементы местами
        Quick_Sort(vect, start_Index, current_Index - 1);
        Quick_Sort(vect, current_Index + 1, pivot_Index);
    }
}

int mx_ind(vector < vector <int>>& A, vector < vector <int>>& B, vector < vector <int>>& C, int zero) {
    if (zero == 2) {
        if (A.size() > B.size()) {
            return 0;
        }
        return 1;
    }
    if (zero == 1) {
        if (A.size() > C.size()) {
            return 0;
        }
        return 2;
    }
    else {
        if (B.size() > C.size()) {
            return 1;
        }
        return 2;
    }
}

int mn_ind(vector < vector <int>>& A, vector < vector <int>>& B, vector < vector <int>>& C, int zero) {
    if (zero == 2) {
        if (A.size() <= B.size()) {
            return 0;
        }
        return 1;
    }
    if (zero == 1) {
        if (A.size() <= C.size()) {
            return 0;
        }
        return 2;
    }
    else {
        if (B.size() <= C.size()) {
            return 1;
        }
        return 2;
    }
}

void clear_vector(vector < vector <int>>& vec) { //очищаю двумерный вектор
    for (auto& inner_vec : vec) {
        inner_vec.clear();
    }
    vec.clear();
}
void clear_vector(vector < vector < vector <int>>>& vec) { //очищаю трехмерный вектор
    for (auto& innerVec : vec) {
        for (auto& innerInnerVec : innerVec) {
            innerInnerVec.clear();
        }
        innerVec.clear();
    }
    vec.clear();
}

vector<int> new_ser(vector<int>& A, vector<int>& B) {//новая серия из двух серий
    int A_ind = 0, B_ind = 0;
    int ABsize = A.size() + B.size();
    vector<int> temp;

    while (A_ind + B_ind != ABsize) {
        if (A_ind == A.size()) {
            temp.push_back(B[B_ind++]);
        }
        else if (B_ind == B.size()) {
            temp.push_back(A[A_ind++]);
        }
        else {
            if (A[A_ind] < B[B_ind]) {
                temp.push_back(A[A_ind++]);
            }
            else {
                temp.push_back(B[B_ind++]);
            }
        }
    }
    return temp;
}

int empty_ind(vector < vector <int> > A, vector < vector <int> > B, vector < vector <int> > C) {//нахожу пустую голову
    if (A.empty()) {
        return 0;
    }
    if (B.empty()) {
        return 1;
    }
    return 2;
}

vector<int> not_an_empty_head(vector < vector <int> > A, vector < vector <int> > B, vector < vector <int> > C) {
    if (A.empty() && B.empty()) {//ищу не пусткю последовательность
        return C[0];
    }
    if (A.empty() && C.empty()) {
        return B[0];
    }
    return A[0];
}

void multiphase_sorting(vector<int>& vect) { //многофазная сортировка
    vector < vector <int> > vect_of_series;
    int size_series = 5;//размер серии
    bool flag = true;
    int count = 0;

    for (int i = 0; i < size_series; ++i) { //5 серий
        vector<int> temp;
        for (int j = 0; j < size_series; ++j)//по 5 элементов
            temp.push_back(vect[i * size_series + j]);
        vect_of_series.push_back(temp);
    }

    for (int i = 0; i < size_series; ++i) { //сортирую каждую серию отдельно
        Quick_Sort(vect_of_series[i], 0, size_series - 1);
    }
    vector < vector < vector <int> > > stack_of_series; //вектор векторов серий

    for (int k = 0; k < 2; ++k) { //рассовываю по головам последовательности серий
        vector < vector <int> > pointer_1;
        for (int i = 0 + k; i < 3; ++i) {//пихаю последовательности в головы
            pointer_1.push_back(vect_of_series[count++]);
        }
        stack_of_series.push_back(pointer_1);
    }

    clear_vector(vect_of_series); //освобождаю память
    vector < vector <int> > pointer_1;
    stack_of_series.push_back(pointer_1);//пустая голова с пустой серией
    clear_vector(pointer_1); //освобождаю память

    while (flag) { //пока не солью все серии в одну
        int zero_index = empty_ind(stack_of_series[0], stack_of_series[1], stack_of_series[2]); //индекс пустой головы
        int min_index = mn_ind(stack_of_series[0], stack_of_series[1], stack_of_series[2], zero_index);//индекс с меньшим числом серий
        int max_index = mx_ind(stack_of_series[0], stack_of_series[1], stack_of_series[2], zero_index);//индекс с большим числом серий
        int cur_min_sequence = stack_of_series[min_index].size(); //по сколько серий сплавлять
        for (int i = 0; i < cur_min_sequence; i++) {//запись сплавленных серий в запасную голову
            vector<int> temp = new_ser(stack_of_series[min_index][stack_of_series[min_index].size() - 1],
                stack_of_series[max_index][stack_of_series[max_index].size() - 1]); //сплав серий
            if (temp.size() == 25) {
                flag = false; //все серии слиты в одну отсортированную
            }
            stack_of_series[zero_index].push_back(temp);//добавляю отсортированную серию
            stack_of_series[min_index].erase(stack_of_series[min_index].end() - 1); //убираю сплавленную серию
            stack_of_series[max_index].erase(stack_of_series[max_index].end() - 1); //убираю сплавленную серию
        }
    }
    vect = not_an_empty_head(stack_of_series[0], stack_of_series[1], stack_of_series[2]);
    clear_vector(stack_of_series); //освобождаю память
}

int main() {
    system("chcp 1251 > Null");
    srand(time(0));

    int choice;
    int mas_size = 25;

    vector<int> vect(mas_size);

    do {
        cout << "Каким способом вы хотите создать массив? " << endl;
        cout << "1 - Ввести ручками" << endl;
        cout << "2 - Создать случайно" << endl;
        cin >> choice;
    } while (choice < 1 || choice > 2);

    switch (choice) { //выбор способа создания массива
    case 1: {
        creature_mas_hands(vect);
        break;
    }
    default: {
        creature_mas_rand(vect); //создание массива случайно
        break;
    }
    }

    cout << endl << "Создан массив!" << endl;
    print(vect); //вывод массива

    multiphase_sorting(vect);//многофазная сортировка
    cout << "Массив отсортирован!" << endl;
    print(vect);

    return 0;
}