/*
������� 1 

�) ������� ����������� ��� ������, ��� ����������� ����� ��������� ���������. 
���������� ������� ���������/������ �������� �������� � ������ �����, ��������, 
���������, ���������, �������, ��������� (������, ������, � �.�.). 
���������� ������������ ����������� �����. ��� ������� ������ ���� ����������, 
��� ���������� � ���� ������������.

*/


#include "var1_functions_lab1_1.cpp"


int main(void) {

    setlocale(LC_ALL, "Rus");

    int UserChoice = 0; 				//����� ������������
    int ComplexSize = 0;   			  	//���-�� ����������� �����
    Complex* ComplexPointer = NULL;		//��������� �� ���������
    bool ExistComplex = false;          //�������� �� ������ � ����.������

    do
    {
        cout << "\n����:\n";
        cout << "1.��������� ������;\n";
        cout << "2.����� ������ �� �����;\n";
        cout << "3.�������� ��� ������������ ��������;\n";
        cout << "4.��������� ����������� �����;\n";
        cout << "5.������������ ������;\n";
        cout << "6.���������� ���������.\n";

        cout << "\n\n�������� ����� �� ����: ";
        cin >> UserChoice;

        switch (UserChoice)
        {
        case 1://��������� ������
            InitialComplex(ComplexPointer, &ComplexSize, &ExistComplex);
            break;
        case 2://����� ������ �� �����
            PrintDataComplex(ComplexPointer, ComplexSize, ExistComplex);
            break;
        case 3://�������� ��� ������������ ��������
            ActionsOnNumbers(ComplexPointer, ComplexSize, ExistComplex);
            break;
        case 4://��������� ����������� �����
            CompareComplex(ComplexPointer, ComplexSize, ExistComplex);
            break;
        case 5://������������ ������
            FreeMemoryComplex(ComplexPointer, &ComplexSize, &ExistComplex);
            break;
        case 6://���������� ���������
            if (ExistComplex) {
                FreeMemoryComplex(ComplexPointer, &ComplexSize, &ExistComplex);
            }
            cout << "���������� ���������....\n";
            break;
        default:
            cout << "\n������. ����������, �������� ����� �� ����!\n";
            break;
        }

    } while (UserChoice != 6);
    
    return 0;
}
