/*
Вариант 1 

а) Создать абстрактный тип данных, для комплексных чисел используя структуру. 
Определить функции установки/чтения значений реальной и мнимой части, сложения, 
вычитания, умножения, деления, сравнения (меньше, больше, и т.д.). 
Определить функциюнорму комплексных чисел. Все функции должны быть определены, 
как глобальные и быть переносимыми.

*/


#include "var1_functions_lab1_1.cpp"


int main(void) {

    setlocale(LC_ALL, "Rus");

    int UserChoice = 0; 				//выбор пользователя
    int ComplexSize = 0;   			  	//кол-во комплексных чисел
    Complex* ComplexPointer = NULL;		//указатель на структуру
    bool ExistComplex = false;          //выделена ли память и иниц.данные

    do
    {
        cout << "\nМеню:\n";
        cout << "1.Установка данных;\n";
        cout << "2.Вывод данных на экран;\n";
        cout << "3.Действия над комплексными чиселами;\n";
        cout << "4.Сравнение комплексных чисел;\n";
        cout << "5.Освобождение памяти;\n";
        cout << "6.Завершение программы.\n";

        cout << "\n\nВыберите номер из меню: ";
        cin >> UserChoice;

        switch (UserChoice)
        {
        case 1://Установка данных
            InitialComplex(ComplexPointer, &ComplexSize, &ExistComplex);
            break;
        case 2://Вывод данных на экран
            PrintDataComplex(ComplexPointer, ComplexSize, ExistComplex);
            break;
        case 3://Действия над комплексными чиселами
            ActionsOnNumbers(ComplexPointer, ComplexSize, ExistComplex);
            break;
        case 4://Сравнение комплексных чисел
            CompareComplex(ComplexPointer, ComplexSize, ExistComplex);
            break;
        case 5://Освобождение памяти
            FreeMemoryComplex(ComplexPointer, &ComplexSize, &ExistComplex);
            break;
        case 6://Завершение программы
            if (ExistComplex) {
                FreeMemoryComplex(ComplexPointer, &ComplexSize, &ExistComplex);
            }
            cout << "Завершение программы....\n";
            break;
        default:
            cout << "\nОшибка. Пожалуйста, выберите номер из меню!\n";
            break;
        }

    } while (UserChoice != 6);
    
    return 0;
}
