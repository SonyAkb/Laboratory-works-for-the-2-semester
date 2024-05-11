#ifndef OTHER_FUNCTOINS_H
#define OTHER_FUNCTOINS_H

#include <sstream>
#include <QString>
#include <iostream>
#include <iomanip>
#include <vector>

bool can_convert_to_string_double(const QString &string) {
    if (string == '0'){
        return 1;
    }
    return string.toDouble() != 0; // Проверяем, что преобразование прошло успешно
}

double string_to_double(const QString &str) {// Функция для перевода из строки в double
    return str.toDouble();
}

QString double_to_string(double value) {
    std::ostringstream oss;// Создаем временный поток для записи чисел в строку с фиксированной точностью
    oss << std::fixed << std::setprecision(2) << value;// Устанавливаем точность (количество знаков после запятой) равным двум
    return QString::fromStdString(oss.str());// Возвращаем QString из полученной строки
}

int getting_data(std::vector<bool> bool_vector){//получаю индекс выбранного варианта
    int size_vector = static_cast<unsigned int>(bool_vector.size()); // Приводим размер вектора к беззнаковому типу
    for(int i=0; i < size_vector ; i++){
        if (bool_vector[i]){
            return i;
        }
    }
    return 0;
}

std::vector<int> all_list_index(std::vector<std::vector<bool>> all_bool_vect){//вектор избранных
    std::vector<int> list_index;//сам вектор
    int size_vector = static_cast<unsigned int>(all_bool_vect.size()); // Приводим размер вектора к беззнаковому типу
    for(int i=0; i < size_vector ; i++){
        list_index.push_back(getting_data(all_bool_vect[i]));
    }
    return list_index;
}

#endif // OTHER_FUNCTOINS_H
