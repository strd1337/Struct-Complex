#include <Windows.h>	
#include <math.h>   					
#include <iomanip> 
#include <iostream>	


using namespace std;


struct Complex
{
    double Re;                                          //�������������� �����
    double Im;                                          //������ ����� 
};


void InitialComplex(Complex*&, int*, bool*);            //��������� ������
void PrintDataComplex(Complex*&, int, bool);            //����� ������ �� �����
void ActionsOnNumbers(Complex*&, int, bool);            //�������� ��� ������������ �������
void CompareComplex(Complex*&, int, bool);              //��������� ����������� �����
void FreeMemoryComplex(Complex*&, int*, bool*);         //������������ ������