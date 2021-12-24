// Практическая работа 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int numberInt, intSize = sizeof(int) * 8, floatSize = sizeof(float) * 8;
	unsigned int maskInt = 1 << intSize - 1;
	unsigned int maskFloat = 1 << floatSize - 1;
	unsigned int order = 32;
	unsigned int maskDouble = 1 << order - 1;
	cout << " The [int] type occupies <"<< sizeof(int) <<"> bytes in memory" <<endl;
	cout << " The [short int] type occupies <" << sizeof(short int) << "> bytes in memory" << endl;
	cout << " The [long int] type occupies <" << sizeof(long int) << "> bytes in memory" << endl;
	cout << " The [float] type occupies <" << sizeof(float) << "> bytes in memory" << endl;
	cout << " The [double] type occupies <" << sizeof(double) << "> bytes in memory" << endl;
	cout << " The [long double] type occupies <" << sizeof(long double) << "> bytes in memory" << endl;
	cout << " The [char] type occupies <" << sizeof(char) << "> bytes in memory" << endl;
	cout << " The [bool] type occupies <" << sizeof(bool) << "> bytes in memory" << endl;
	cout << "Enter an [int] number:" <<endl;
	cin >> numberInt;
	for (int i = 1; i <= intSize; i++)
	{
		putchar(numberInt & maskInt ? '1' : '0');
		numberInt <<= 1;
		if (i % 8 == 0 || i == 1)
			cout << " ";
	}
	cout <<endl;
	union
	{
		float numberFloat;
		int numberFloatUseful;
	};
	cout << "Enter an [float] number:" << endl;
	cin >> numberFloat;

	for (int i = 1; i <= floatSize; i++)
	{
		putchar(numberFloatUseful & maskFloat ? '1' : '0');
		maskFloat = maskFloat >> 1;
		if (i % 8 == 0 || i == 1)
			cout << " ";
	}
	cout << endl;


	union
	{
		double numberDouble;
		int ArrInt[2];
	};
	cout << "Enter an [double] number:" << endl;
	cin >> numberDouble;
	for (int k = 1; k >= 0; k--)
	{
		maskDouble = 1 << order - 1;
		for (int i = 1; i <= order; i++)
		{
			putchar(ArrInt[k] & maskDouble ? '1' : '0');
			maskDouble >>= 1;
			if ((k == 1 && i == 1) || (k == 1 && i == 12))
			{
				cout << " ";
			}
		}
	}
	cout << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
