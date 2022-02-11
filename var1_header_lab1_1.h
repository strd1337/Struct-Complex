#include <Windows.h>	
#include <math.h>   					
#include <iomanip> 
#include <iostream>	


using namespace std;


struct Complex
{
    double Re;                                          //действительная часть
    double Im;                                          //мнимая часть 
};


void InitialComplex(Complex*&, int*, bool*);            //Установка данных
void PrintDataComplex(Complex*&, int, bool);            //Вывод данных на экран
void ActionsOnNumbers(Complex*&, int, bool);            //Действия над комплексными числами
void CompareComplex(Complex*&, int, bool);              //Сравнение комплексных чисел
void FreeMemoryComplex(Complex*&, int*, bool*);         //Освобождение памяти