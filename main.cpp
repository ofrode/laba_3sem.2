#include <iostream>
#include <limits>
#include "string.h"

using namespace std;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menu()
{
    int choice;
    cout << "1 - Ввести первую строку\n";
    cout << "2 - Сложить строки\n";
    cout << "3 - Сложить строку саму с собой\n";
    cout << "4 - Выход\n";
    cout << "Выберите действие: ";
    cin >> choice;
    clearInputBuffer();
    return choice;
}

int main()
{
    int choice;
    int count;
    String str1;
    String str2;
    String str3;

    while (true)
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            cout << "\nВведите первую строку: ";
            cin >> str1;
            clearInputBuffer();
            
            cout << "\nВы хотите скопировать первую строку (1) или написать что-то другое (2): ";
            cin >> choice;
            clearInputBuffer();
            
            if (choice == 1)
            {
                str2 = str1;
                cout << "Вторая строка скопирована из первой.\n";
            }
            else
            {
                cout << "\nВведите вторую строку: ";
                cin >> str2;
            }
            cout << "\nСтроки введены!!!\n";
            break;

        case 2:
            cout << "Выберите как складывать строки: 1 - С пробелом, 2 - Без пробела: ";
            cin >> choice;
            clearInputBuffer();
            
            if (choice == 1)
            {
                str3 = str1 + " " + str2;
            }
            else
            {
                str3 = str1 + str2;
            }
            cout << "\nСтроки сложены!!!\n";
            cout << "Ваша итоговая строка: " << str3 << "\n";
            break;

        case 3:
            cout << "Какую строку хотите просуммировать (1 или 2): ";
            cin >> choice;
            clearInputBuffer();
            cout << "\nСколько раз надо просуммировать: ";
            cin >> count;
            clearInputBuffer();
            
            if (choice == 1)
            {
                String temp = str1;
                for (int i = 1; i < count; i++)
                {
                    str1 += temp;
                }
                cout << "\nСтрока сложена сама с собой " << count << " раз!!!\n";
                cout << "Ваша итоговая строка: " << str1 << "\n";
            }
            else
            {
                String temp = str2;
                for (int i = 1; i < count; i++)
                {
                    str2 += temp;
                }
                cout << "\nСтрока сложена сама с собой " << count << " раз!!!\n";
                cout << "Ваша итоговая строка: " << str2 << "\n";
            }
            break;

        case 4:
            return 0;

        default:
            cout << "Неверный выбор!\n";
            break;
        }
        clearInputBuffer();
        cout << "\nНажмите Enter для продолжения\n";
    }
}