#include "var1_header_lab1_1.h"


//Установка данных
void InitialComplex(Complex*& ComplexPointer, int* ComplexSize, bool* ExistComplex)
{
	//если память не была выделена
	if (!*ExistComplex) {

		cout << "\nВы выбрали: установка данных.\n";

		//ввод пользователя
		cout << "\nВведите количество комплексных чисел: ";
		cin >> *ComplexSize;

		//выделение памяти
		ComplexPointer = new Complex[*ComplexSize];
		cout << "\nПамять для данных выделена!\n";

		cout << "\nВвод данных:\n\n";

		//ввод данных
		for (int i = 0; i < *ComplexSize; ++i)
		{
			cout << "Действительная часть " << i + 1 << " комплексного числа: ";
			cin >> (ComplexPointer + i)->Re;

			cout << "Мнимая часть " << i + 1 << " комплексного числа: ";
			cin >> (ComplexPointer + i)->Im;

			cout << endl;
		}

		//числа существуют
		*ExistComplex = true;

		cout << "\nВы успешно ввели данные!\n";
	} else { //иначе сообщение об ошибки
		cout << "\nОшибка. Память уже выделена.\n";
	}
}


//Вывод данных на экран
void PrintDataComplex(Complex*& ComplexPointer, int ComplexSize, bool ExistComplex)
{
	//если комплексные числа существуют
	if (ExistComplex) {

		cout << "\nВы выбрали: вывод данных на экран.\n";

		cout << "\n|------------------";
		cout << "---------------------|\n";
		cout << "| " << "Общее количество комплексных чисел: " << ComplexSize << " |";
		cout << "\n|------------------";
		cout << "---------------------|\n";
		
		//вывод данных
		for (int i = 0; i < ComplexSize; ++i)
		{
			cout << "| №" << i + 1 << " | Z = " << (ComplexPointer + i)->Re;
			cout << " + i*(" << (ComplexPointer + i)->Im << ")\t\t\t|";
			cout << "\n|------------------";
			cout << "---------------------|\n";
		}

	} else { //иначе сообщение об ошибки
		cout << "\nОшибка. Не выделена память.\n";
	}
}


//Действия над комплексными числами
void ActionsOnNumbers(Complex*& ComplexPointer, int ComplexSize, bool ExistComplex)
{
	//если комплексные числа существуют
	if (ExistComplex) {

		int ChoiceNumberOne = 0;		//первое комплексное число
		int ChoiceNumberTwo = 1;		//второе комплексное число
		int ChoiceType = 0;				//действие над комплексными числами
		bool ChoiceContinue = true;		//повторить ли

		cout << "\nВы выбрали: действия над комплексными числами.\n";

		//хочет ли пользователь повторить процедуру
		while (ChoiceContinue) {
			do
			{
				//меню
				cout << "\nВыберите действие над комплексными числами:\n";
				cout << "1.Сложение;\n";
				cout << "2.Вычитание;\n";
				cout << "3.Умножение;\n";
				cout << "4.Деление.\n";

				//ввод пользователя
				cout << "\nВведите номер: ";
				cin >> ChoiceType;

				//проверка на неверный ввод
				if ((ChoiceType < 1) || (ChoiceType > 4))
					cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";

			} while ((ChoiceType < 1) || (ChoiceType > 4));

			do
			{
				cout << "\nВыберите номер первого комплексного числа:\n";

				//вывод данных
				for (int i = 0; i < ComplexSize; i++) {
					cout << "№" << i << ": " << i + 1 << " комплексное число";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//ввод пользователя
				cout << "\nВведите номер: ";
				cin >> ChoiceNumberOne;

				//проверка на неверный ввод
				if ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1))
					cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";

			} while ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1));

			do
			{
				cout << "\nВыберите номер второго комплексного числа:\n";

				//вывод данных
				for (int i = 0; i < ComplexSize; i++) {
					cout << "№" << i << ": " << i + 1 << " комплексное число";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//ввод пользователя
				cout << "\nВведите номер: ";
				cin >> ChoiceNumberTwo;

				//проверка на неверный ввод
				if ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1))
					cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";

			} while ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1));

			//взависимости от выбранного действия будет выполняться case
			switch (ChoiceType)
			{
			case 1:
				cout << "R = " << (ComplexPointer + ChoiceNumberOne)->Re + (ComplexPointer + ChoiceNumberTwo)->Re;
				cout << " + i*" << (ComplexPointer + ChoiceNumberOne)->Im + (ComplexPointer + ChoiceNumberTwo)->Im << endl;
				break;
			case 2:
				cout << "R = " << (ComplexPointer + ChoiceNumberOne)->Re - (ComplexPointer + ChoiceNumberTwo)->Re;
				cout << " + i*" << (ComplexPointer + ChoiceNumberOne)->Im - (ComplexPointer + ChoiceNumberTwo)->Im << endl;
				break;
			case 3:
				cout << "R = " << (ComplexPointer + ChoiceNumberOne)->Re * (ComplexPointer + ChoiceNumberTwo)->Re -
					(ComplexPointer + ChoiceNumberOne)->Im * (ComplexPointer + ChoiceNumberTwo)->Im;
				cout << " + i*" << (ComplexPointer + ChoiceNumberOne)->Im * (ComplexPointer + ChoiceNumberTwo)->Re +
					(ComplexPointer + ChoiceNumberOne)->Re * (ComplexPointer + ChoiceNumberTwo)->Im << endl;
				break;
			case 4:
				cout << "R = " << ((ComplexPointer + ChoiceNumberOne)->Re * (ComplexPointer + ChoiceNumberTwo)->Re +
					(ComplexPointer + ChoiceNumberOne)->Im * (ComplexPointer + ChoiceNumberTwo)->Im) /
					((ComplexPointer + ChoiceNumberTwo)->Re * (ComplexPointer + ChoiceNumberTwo)->Re +
						(ComplexPointer + ChoiceNumberTwo)->Im * (ComplexPointer + ChoiceNumberTwo)->Im);
				cout << " + i*" << ((ComplexPointer + ChoiceNumberOne)->Im * (ComplexPointer + ChoiceNumberTwo)->Re -
					(ComplexPointer + ChoiceNumberOne)->Re * (ComplexPointer + ChoiceNumberTwo)->Im) /
					((ComplexPointer + ChoiceNumberTwo)->Re * (ComplexPointer + ChoiceNumberTwo)->Re +
						(ComplexPointer + ChoiceNumberTwo)->Im * (ComplexPointer + ChoiceNumberTwo)->Im) << endl;
				break;
			}

			//меню
			cout << "\nХотите повторить или вернуться в главное меню?\n";
			cout << "0.Выйти в главное меню.\n";
			cout << "1.Повторить;\n";
			
			//ввод пользователя
			cout << "\nВведите номер: ";
			cin >> ChoiceContinue;
		}

	} else { //иначе сообщение об ошибки
		cout << "\nОшибка. Не выделена память.\n";
	}
}


//Сравнение комплексных чисел
void CompareComplex(Complex*& ComplexPointer, int ComplexSize, bool ExistComplex)
{
	//если комплексные числа существуют
	if (ExistComplex) {

		int ChoiceNumberOne = 0;		//первое комплексное число
		int ChoiceNumberTwo = 1;		//второе комплексное число
		int ChoiceType = 0;				//тип сравнения
		bool ChoiceContinue = true;		//повторить ли

		cout << "\nВы выбрали: сравнение комплексных чисел.\n";

		cout << "\nВажно! Сравнение будет проходить над модулем комплексного числа.\n";

		//хочет ли пользователь повторить процедуру
		while (ChoiceContinue) {
			do
			{
				//меню
				cout << "\nВыберите действие над комплексными числами:\n";
				cout << "1.Больше(>);\n";
				cout << "2.Меньше(<);\n";
				cout << "3.Равно(=);\n";
				cout << "4.Неравно(!=);\n";
				cout << "5.Больше или равно(>=);\n";
				cout << "6.Меньше или равно(<=);\n";

				//ввод пользователя
				cout << "\nВведите номер: ";
				cin >> ChoiceType;

				//проверка на неверный ввод
				if ((ChoiceType < 1) || (ChoiceType > 6))
					cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";

			} while ((ChoiceType < 1) || (ChoiceType > 6));

			do
			{
				cout << "\nВыберите номер первого комплексного числа:\n";

				//вывод данных
				for (int i = 0; i < ComplexSize; i++) {
					cout << "№" << i << ": " << i + 1 << " комплексное число";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//ввод пользователя
				cout << "\nВведите номер: ";
				cin >> ChoiceNumberOne;

				//проверка на неверный ввод
				if ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1))
					cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";

			} while ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1));

			do
			{
				cout << "\nВыберите номер второго комплексного числа:\n";

				//вывод данных
				for (int i = 0; i < ComplexSize; i++) {
					cout << "№" << i << ": " << i + 1 << " комплексное число";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//ввод пользователя
				cout << "\nВведите номер: ";
				cin >> ChoiceNumberTwo;

				//проверка на неверный ввод
				if ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1))
					cout << "\nНеправильный ввод. Пожалуйста, введите номер из меню.\n";

			} while ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1));

			//рассчёт модуля
			double ModulR1 = sqrt(pow((ComplexPointer + ChoiceNumberOne)->Re, 2) + pow((ComplexPointer + ChoiceNumberOne)->Im, 2));
			double ModulR2 = sqrt(pow((ComplexPointer + ChoiceNumberTwo)->Re, 2) + pow((ComplexPointer + ChoiceNumberTwo)->Im, 2));

			//взависимости от выбранного действия будет выполняться case
			switch (ChoiceType)
			{
			case 1:
				if (ModulR1 > ModulR2)
					cout << "\nПервое комплексное число больше второго.\n";
				else
					cout << "\nВторое комплексное число больше первого.\n";
				break;
			case 2:
				if (ModulR1 < ModulR2)
					cout << "\nВторое комплексное число больше первого.\n";
				else
					cout << "\nПервое комплексное число больше второго.\n";
				break;
			case 3:
				if (ModulR1 == ModulR2)
					cout << "\nПервое комплексное число равно второму.\n";
				else
					cout << "\nПервое комплексное число неравно второму.\n";
				break;
			case 4:
				if (ModulR1 != ModulR2)
					cout << "\nПервое комплексное число неравно второму.\n";
				else
					cout << "\nПервое комплексное число равно второму.\n";
				break;
			case 5:
				if (ModulR1 >= ModulR2)
					cout << "\nПервое комплексное число больше или равно второму.\n";
				else
					cout << "\nВторое комплексное число больше или равно первому.\n";
				break;
			case 6:
				if (ModulR1 <= ModulR2)
					cout << "\nПервое комплексное число меньше или равно второму.\n";
				else
					cout << "\nВторое комплексное число меньше или равно первому.\n";
				break;
			}

			//меню
			cout << "\nХотите повторить или вернуться в главное меню?\n";
			cout << "0.Выйти в главное меню.\n";
			cout << "1.Повторить;\n";

			//ввод пользователя
			cout << "\nВведите номер: ";
			cin >> ChoiceContinue;
		}

	} else { //иначе сообщение об ошибки
		cout << "\nОшибка. Не выделена память.\n";
	}
}


//Освобождение памяти
void FreeMemoryComplex(Complex*& ComplexPointer, int* ComplexSize, bool* ExistComplex)
{
	//если память выделена
	if (*ExistComplex) {

		cout << "\nВы выбрали: освобождение памяти.\n";

		//освобождение
		delete[] ComplexPointer;

		//зануление указателя
		ComplexPointer = NULL;

		//зануление количества чисел
		*ComplexSize = 0;

		//числа не существуют
		*ExistComplex = false;

		cout << "\nПамять очищена!\n";

	} else {
		cout << "\nОшибка. Память не выделена.\n";
	}
}
