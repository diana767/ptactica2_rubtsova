// practika2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "practika2.h"

//int main()
//{
//
//    setlocale(LC_ALL, "Russian");
//
//    // 20.1 одномерный массив
//
//     srand(time(NULL));
//     int ch=0;
//     int nech=0;
//     int res;
//     int massiv[10];
//
//     for (int i = 0; i < 10; i++)
//     {
//         massiv[i] = rand() % 100;
//         std::cout << massiv[i] << " " << std::endl;
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         if (i % 2 == 0)
//         {
//             ch += massiv[i];
//         }
//         else {
//             nech += massiv[i];
//         }
//     }
//     std::cout << "Cумма элементов с четными индексами равна:" << ch << std::endl;
//     std::cout << "Cумма элементов с нечетными индексами равна:" << nech << std::endl;
//     std::cout << "Разница между между суммой элементов с четными и нечетными индексами равна:" << ch - nech;
//
//     //20.2 двумерный массив
//
//    srand(time(NULL));
//    int sum = 1;
//    int massiv2[3][3];
//
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            massiv2[i][j] = rand() % 100;
//            std::cout << massiv2[i][j] << "\t ";
//            sum *= massiv2[i][j];
//        }
//        std::cout << std::endl;
//    }
//
//    std::cout << "произведение всех элементов в каждой строке многомерного массива равна:" << sum << std::endl;
//
//
//
//}
// 



//20.3 структура

//struct Invoice {
//    char number[50];
//    char description[255];
//   float amount;
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    Invoice invoices[5];
//    int count = 0;
//
//    while (true) {
//        std::cout << std::endl << "Добро пожаловать в систему учета счетов! Выберите действие: 1) Добавить счет 2) Найти сумму счетов по номеру 3) Выйти." << std::endl;
//        int a;
//        std::cin >> a;
//
//        switch (a) {
//        case 1:
//            if (count < 5) {
//                std::cout << "Введите номер счета:" << std::endl;
//                std::cin >> invoices[count].number;
//                std::cout << "Введите описание счета:" << std::endl;              
//                std::cin.getline(invoices[count].description, 255);
//                std::cout << "Введите сумму счета:" << std::endl;
//                std::cin >> invoices[count].amount;
//                count++;
//            }
//            else {
//                std::cout << "Максимальное количество счетов достигнуто!" << std::endl;
//            }
//            break;
//
//        case 2: {
//            char num[50];
//            std::cout << "Введите номер счета для поиска:" << std::endl;
//            std::cin >>num;
//
//            float b = 0.0;
//            bool found = false;
//
//            for (int i = 0; i < count; i++) {
//                if (strcmp(invoices[i].number, num) == 0) {
//                    b += invoices[i].amount;
//                    found = true;
//                }
//            }
//
//            if (found) {
//                std::cout << "Сумма счетов с номером " << num << ": " << b << std::endl;
//            }
//            else {
//                std::cout << "Счета с номером " << num << " не найдены." << std::endl;
//            }
//            break;
//        }
//
//        case 3:
//            std::cout << "Выход из программы." << std::endl;
//
//        default:
//            std::cout << "Такое действие не найдено!" << std::endl;
//            break;
//        }
//    }
//}







    //20.4

class Dictionary {
private:
    static const int MAX_WORDS = 100;
    std::string words[MAX_WORDS];      
    int size;                           

public:
   
    Dictionary() : size(0) {}

    void addWord(const std::string& word) {
       
        for (int i = 0; i < size; i++) {
            if (words[i] == word) {
                std::cout << "Слово '" << word << "' уже есть в словаре." << std::endl;
                return;
            }
        }

    
        if (size >= MAX_WORDS) {
            std::cout << "Словарь переполнен. Невозможно добавить слово '" << word << "'." << std::endl;
            return;
        }
        else
        {
            words[size++] = word;
            std::cout << "Слово '" << word << "' добавлено в словарь." << std::endl;
        }
       
       
    }

    
    void removeWord(const std::string& word) {
        for (int i = 0; i < size; i++) {
            if (words[i] == word) {
               
                for (int j = i; j < size - 1; j++) {
                    words[j] = words[j + 1];
                }
                size--; 
                std::cout << "Слово '" << word << "' удалено из словаря." << std::endl;
                return;
            }
            else
            {
                std::cout << "Слово '" << word << "' не найдено в словаре." << std::endl;
            }
        }

        
    }

 
    void printWords() const {
        if (size == 0) {
            std::cout << "Словарь пуст." << std::endl;
            return;
        }
        std::cout << "Слова в словаре:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << "- " << words[i] << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Dictionary dict;

    dict.addWord("С++");
    dict.addWord("banana");
    dict.addWord("orange");
    dict.printWords();
    dict.removeWord("banana");
    dict.printWords();
    dict.addWord("apple"); 
    dict.removeWord("grape"); 
  
}

