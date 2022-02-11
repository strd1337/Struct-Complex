#include "var1_header_lab1_1.h"


//��������� ������
void InitialComplex(Complex*& ComplexPointer, int* ComplexSize, bool* ExistComplex)
{
	//���� ������ �� ���� ��������
	if (!*ExistComplex) {

		cout << "\n�� �������: ��������� ������.\n";

		//���� ������������
		cout << "\n������� ���������� ����������� �����: ";
		cin >> *ComplexSize;

		//��������� ������
		ComplexPointer = new Complex[*ComplexSize];
		cout << "\n������ ��� ������ ��������!\n";

		cout << "\n���� ������:\n\n";

		//���� ������
		for (int i = 0; i < *ComplexSize; ++i)
		{
			cout << "�������������� ����� " << i + 1 << " ������������ �����: ";
			cin >> (ComplexPointer + i)->Re;

			cout << "������ ����� " << i + 1 << " ������������ �����: ";
			cin >> (ComplexPointer + i)->Im;

			cout << endl;
		}

		//����� ����������
		*ExistComplex = true;

		cout << "\n�� ������� ����� ������!\n";
	} else { //����� ��������� �� ������
		cout << "\n������. ������ ��� ��������.\n";
	}
}


//����� ������ �� �����
void PrintDataComplex(Complex*& ComplexPointer, int ComplexSize, bool ExistComplex)
{
	//���� ����������� ����� ����������
	if (ExistComplex) {

		cout << "\n�� �������: ����� ������ �� �����.\n";

		cout << "\n|------------------";
		cout << "---------------------|\n";
		cout << "| " << "����� ���������� ����������� �����: " << ComplexSize << " |";
		cout << "\n|------------------";
		cout << "---------------------|\n";
		
		//����� ������
		for (int i = 0; i < ComplexSize; ++i)
		{
			cout << "| �" << i + 1 << " | Z = " << (ComplexPointer + i)->Re;
			cout << " + i*(" << (ComplexPointer + i)->Im << ")\t\t\t|";
			cout << "\n|------------------";
			cout << "---------------------|\n";
		}

	} else { //����� ��������� �� ������
		cout << "\n������. �� �������� ������.\n";
	}
}


//�������� ��� ������������ �������
void ActionsOnNumbers(Complex*& ComplexPointer, int ComplexSize, bool ExistComplex)
{
	//���� ����������� ����� ����������
	if (ExistComplex) {

		int ChoiceNumberOne = 0;		//������ ����������� �����
		int ChoiceNumberTwo = 1;		//������ ����������� �����
		int ChoiceType = 0;				//�������� ��� ������������ �������
		bool ChoiceContinue = true;		//��������� ��

		cout << "\n�� �������: �������� ��� ������������ �������.\n";

		//����� �� ������������ ��������� ���������
		while (ChoiceContinue) {
			do
			{
				//����
				cout << "\n�������� �������� ��� ������������ �������:\n";
				cout << "1.��������;\n";
				cout << "2.���������;\n";
				cout << "3.���������;\n";
				cout << "4.�������.\n";

				//���� ������������
				cout << "\n������� �����: ";
				cin >> ChoiceType;

				//�������� �� �������� ����
				if ((ChoiceType < 1) || (ChoiceType > 4))
					cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";

			} while ((ChoiceType < 1) || (ChoiceType > 4));

			do
			{
				cout << "\n�������� ����� ������� ������������ �����:\n";

				//����� ������
				for (int i = 0; i < ComplexSize; i++) {
					cout << "�" << i << ": " << i + 1 << " ����������� �����";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//���� ������������
				cout << "\n������� �����: ";
				cin >> ChoiceNumberOne;

				//�������� �� �������� ����
				if ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1))
					cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";

			} while ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1));

			do
			{
				cout << "\n�������� ����� ������� ������������ �����:\n";

				//����� ������
				for (int i = 0; i < ComplexSize; i++) {
					cout << "�" << i << ": " << i + 1 << " ����������� �����";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//���� ������������
				cout << "\n������� �����: ";
				cin >> ChoiceNumberTwo;

				//�������� �� �������� ����
				if ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1))
					cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";

			} while ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1));

			//������������ �� ���������� �������� ����� ����������� case
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

			//����
			cout << "\n������ ��������� ��� ��������� � ������� ����?\n";
			cout << "0.����� � ������� ����.\n";
			cout << "1.���������;\n";
			
			//���� ������������
			cout << "\n������� �����: ";
			cin >> ChoiceContinue;
		}

	} else { //����� ��������� �� ������
		cout << "\n������. �� �������� ������.\n";
	}
}


//��������� ����������� �����
void CompareComplex(Complex*& ComplexPointer, int ComplexSize, bool ExistComplex)
{
	//���� ����������� ����� ����������
	if (ExistComplex) {

		int ChoiceNumberOne = 0;		//������ ����������� �����
		int ChoiceNumberTwo = 1;		//������ ����������� �����
		int ChoiceType = 0;				//��� ���������
		bool ChoiceContinue = true;		//��������� ��

		cout << "\n�� �������: ��������� ����������� �����.\n";

		cout << "\n�����! ��������� ����� ��������� ��� ������� ������������ �����.\n";

		//����� �� ������������ ��������� ���������
		while (ChoiceContinue) {
			do
			{
				//����
				cout << "\n�������� �������� ��� ������������ �������:\n";
				cout << "1.������(>);\n";
				cout << "2.������(<);\n";
				cout << "3.�����(=);\n";
				cout << "4.�������(!=);\n";
				cout << "5.������ ��� �����(>=);\n";
				cout << "6.������ ��� �����(<=);\n";

				//���� ������������
				cout << "\n������� �����: ";
				cin >> ChoiceType;

				//�������� �� �������� ����
				if ((ChoiceType < 1) || (ChoiceType > 6))
					cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";

			} while ((ChoiceType < 1) || (ChoiceType > 6));

			do
			{
				cout << "\n�������� ����� ������� ������������ �����:\n";

				//����� ������
				for (int i = 0; i < ComplexSize; i++) {
					cout << "�" << i << ": " << i + 1 << " ����������� �����";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//���� ������������
				cout << "\n������� �����: ";
				cin >> ChoiceNumberOne;

				//�������� �� �������� ����
				if ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1))
					cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";

			} while ((ChoiceNumberOne < 0) || (ChoiceNumberOne > ComplexSize - 1));

			do
			{
				cout << "\n�������� ����� ������� ������������ �����:\n";

				//����� ������
				for (int i = 0; i < ComplexSize; i++) {
					cout << "�" << i << ": " << i + 1 << " ����������� �����";
					cout << " | Z = " << (ComplexPointer + i)->Re;
					cout << " + i*(" << (ComplexPointer + i)->Im << ")\n";
				}

				//���� ������������
				cout << "\n������� �����: ";
				cin >> ChoiceNumberTwo;

				//�������� �� �������� ����
				if ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1))
					cout << "\n������������ ����. ����������, ������� ����� �� ����.\n";

			} while ((ChoiceNumberTwo < 0) || (ChoiceNumberTwo > ComplexSize - 1));

			//������� ������
			double ModulR1 = sqrt(pow((ComplexPointer + ChoiceNumberOne)->Re, 2) + pow((ComplexPointer + ChoiceNumberOne)->Im, 2));
			double ModulR2 = sqrt(pow((ComplexPointer + ChoiceNumberTwo)->Re, 2) + pow((ComplexPointer + ChoiceNumberTwo)->Im, 2));

			//������������ �� ���������� �������� ����� ����������� case
			switch (ChoiceType)
			{
			case 1:
				if (ModulR1 > ModulR2)
					cout << "\n������ ����������� ����� ������ �������.\n";
				else
					cout << "\n������ ����������� ����� ������ �������.\n";
				break;
			case 2:
				if (ModulR1 < ModulR2)
					cout << "\n������ ����������� ����� ������ �������.\n";
				else
					cout << "\n������ ����������� ����� ������ �������.\n";
				break;
			case 3:
				if (ModulR1 == ModulR2)
					cout << "\n������ ����������� ����� ����� �������.\n";
				else
					cout << "\n������ ����������� ����� ������� �������.\n";
				break;
			case 4:
				if (ModulR1 != ModulR2)
					cout << "\n������ ����������� ����� ������� �������.\n";
				else
					cout << "\n������ ����������� ����� ����� �������.\n";
				break;
			case 5:
				if (ModulR1 >= ModulR2)
					cout << "\n������ ����������� ����� ������ ��� ����� �������.\n";
				else
					cout << "\n������ ����������� ����� ������ ��� ����� �������.\n";
				break;
			case 6:
				if (ModulR1 <= ModulR2)
					cout << "\n������ ����������� ����� ������ ��� ����� �������.\n";
				else
					cout << "\n������ ����������� ����� ������ ��� ����� �������.\n";
				break;
			}

			//����
			cout << "\n������ ��������� ��� ��������� � ������� ����?\n";
			cout << "0.����� � ������� ����.\n";
			cout << "1.���������;\n";

			//���� ������������
			cout << "\n������� �����: ";
			cin >> ChoiceContinue;
		}

	} else { //����� ��������� �� ������
		cout << "\n������. �� �������� ������.\n";
	}
}


//������������ ������
void FreeMemoryComplex(Complex*& ComplexPointer, int* ComplexSize, bool* ExistComplex)
{
	//���� ������ ��������
	if (*ExistComplex) {

		cout << "\n�� �������: ������������ ������.\n";

		//������������
		delete[] ComplexPointer;

		//��������� ���������
		ComplexPointer = NULL;

		//��������� ���������� �����
		*ComplexSize = 0;

		//����� �� ����������
		*ExistComplex = false;

		cout << "\n������ �������!\n";

	} else {
		cout << "\n������. ������ �� ��������.\n";
	}
}
