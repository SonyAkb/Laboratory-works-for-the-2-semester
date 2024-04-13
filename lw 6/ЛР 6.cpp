#include <iostream>
#include <string>

using namespace std;

char replace_space(char symbol);
void print_the_sine_wave(string row);

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); //подключение русского при выводе
    system("cls");

    string a_set_of_letters;

    cout << "Введите предложение" << endl;
    getline(cin, a_set_of_letters); //ввод предложения в  переменную a_set_of_letters
    cout << endl;

    //Благоуханна и светла Уж с февраля весна в сады вошла — И вот миндаль мгновенно зацвела, И белизна всю зелень облила.
    //Дни настают борьбы и торжества, Достигнет Русь завещанных границ, И будет старая Москва Новейшею из трех ее столиц.
    //Умом — Россию не понять, Аршином общим не измерить. У ней особенная стать — В Россию можно только верить.

    cout << "Ваше предложение будет выведено в виде синусоиды " << endl << endl;
    print_the_sine_wave(a_set_of_letters); //вывод предложения в виде синусоида

    return 0;
}

char replace_space(char symbol) { //замена пробела на _
    if (symbol == 32) { //если символ равен пробелу
        symbol = '_'; //заменяю символ на _
    }
    return symbol;
}

void print_the_sine_wave(string row) {
    int mirror_mas[] = { 1, 5, 8, 10, 8, 5, 1 }; //массив для зеркального отображения
    int index_mas[] = { 4, 2, 1, 0, 11, 12, 14 }; //сдвиг по x слева

    for (int y = 0; y < 7; y++) { //переход по строкам
        for (int x = 0; x < row.size(); x++) { //переход по столбцам
            if (y == 0 || y == 6) {
                if ((x - index_mas[y]) % 20 == 0 || (x - index_mas[y] - 1) % 20 == 0 || (x - index_mas[y] - 2) % 20 == 0) {
                    cout << replace_space(row[x]);
                }
                else {
                    cout << ' ';
                }
            }
            else if (y == 1 || y == 5) {
                if ((x - index_mas[y]) % 20 == 0 || (x - index_mas[y] - 1) % 20 == 0 || (x - index_mas[y] - mirror_mas[y]) % 20 == 0 || (x - index_mas[y] - 1 - mirror_mas[y]) % 20 == 0) {
                    cout << replace_space(row[x]);
                }
                else {
                    cout << ' ';
                }
            }
            else {
                if ((x - index_mas[y]) % 20 == 0 || (x - index_mas[y] - mirror_mas[y]) % 20 == 0) {
                    cout << replace_space(row[x]);
                }
                else {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }
}