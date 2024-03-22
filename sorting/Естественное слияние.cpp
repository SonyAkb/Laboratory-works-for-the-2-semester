#include <iostream>
#include <vector>
using namespace std;

void creature_mas_rand(int* ptr, int n) { //������ ������ ����� ������ ��������� �����
    for (int i = 0; i < n; i++) {
        ptr[i] = rand() % 1000 + 1; //��������� ����� �� 1 �� 1000
    }
}
void creature_mas_hands(int* ptr, int n) { //�������� ������� � ����������
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "������� ������� " << i + 1 << ": ";
        cin >> ptr[i];
    }
}
void print(int* ptr, int n) { //����� �������� �������
    cout << endl << "������� ������:" << endl;
    for (int i = 0; i < n; i++) { //������� �� �������
        cout << ptr[i] << ' ';
    }
    cout << endl << endl;
}

void Merge_Sort_Recursion(int* mas, int r, int t) {
    int p = 1; // ���-0 ��������� � ������ �����
    int k = 1; // ���-0 ��������� �� ������ �����
    int i = 0;
    bool flag = false; //����������� ���������� ������ �����

    while (mas[i] <= mas[i + 1] && i < r - 1) { //������� ���-� ��������� ������ �����
        p++;
        i++;
    }
    if (mas[i] > mas[i + 1] && i < r - 1) {
        i++;
        flag = true;
        while (mas[i] <= mas[i + 1] && i < r - 1) { //������� ���-� ��������� ������ �����
            k++;
            i++;
        }
    }
    int num = i + 1; // ���������� ��������� � 2� ������

    int* a = new int[p];//����� 1
    int* b = new int[k];//����� 2

    for (i = 0; i < p; i++) { //���������� ������ �����
        a[i] = mas[i];
    }

    int count = 0;//�������
    if (flag == true) { //���� ���� ������ �����
        for (i = p; i < p + k; i++) { //���������� ������ �����
            b[count] = mas[i];
            count++;
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
        Merge_Sort_Recursion(mas, r, i);//����������
        Merger_Sort(mas, r, i + 1);//��������
    }
}

int main() {
    system("chcp 1251 > Null");
    srand(time(0));

    int choice;
    int mas_size = 25;
    int* mas = new int[mas_size]; //�������� �������

    do {
        cout << "����� �������� �� ������ ������� ������? " << endl;
        cout << "1 - ������ �������" << endl;
        cout << "2 - ������� ��������" << endl;
        cin >> choice;
    } while (choice < 1 || choice > 2);


    switch (choice) { //����� ������� �������� �������
    case 1: {
        creature_mas_hands(mas, mas_size);
        break;
    }
    default: {
        creature_mas_rand(mas, mas_size); //�������� ������� ��������
        break;
    }
    }

    cout << endl << "������ ������!" << endl;
    print(mas, mas_size); //����� �������
    
    Merger_Sort(mas, mas_size, 0);
    print(mas, mas_size);

    return 0;
}