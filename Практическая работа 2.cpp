// Практическая работа 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <string.h>
//1 + rand() % 3
using namespace std;
using namespace chrono;

int main()
{
	const int num = 100;
	int A[num], i = 0, a = 0, k = 1, random, min, max, c, b, NofA, NofB, key, mid, j,m=1;
	float kk = 1.247, S = num - 1;
	unsigned u;
	//----------------------------------(1)Создание массива
	while (i < num)
	{
		A[i] = 1 + rand() % (num-1);
		random = 1 + rand() % 2;
		if (random == 1)
			A[i] *= -1;
		i++;
	}
	i = 0;
	cout << "Source array:"<<endl;
	while (i < num)
	{
		cout << A[i] << " ";
		i++;
	}
	cout << endl << "----------------------" << endl;
	i -= 1;
	//----------------------------------(*)Нахождение максимума и минимума до сортировки
	system_clock::time_point start = system_clock::now();
	max = A[0];
	min = A[0];
	for (i = 0; i < num; i++)
	{
		if (max < A[i])
			max = A[i];
		if (min > A[i])
			min = A[i];
	}
	system_clock::time_point end = system_clock::now();
	//----------------------------------(*)Меню выбора сортировки
	cout << "Select sorting: \n 0)Buble sort; \n 1)Shaker sort; \n 2)Comb sort; \n 3)Insert sort; \n";
	cin >> u;
	while (u < 0 or u>3)
	{
		cout << "The number is too large/small.\n ";
		cin >> u;
	}
	cout << endl << "----------------------" << endl;
	cout << "Sorted array:"<<endl;
	system_clock::time_point startA = system_clock::now();
	switch (u)

	{
		//----------------------------------(2.1)Сортировка "buble sort"
	case 0:
		while (k != 0)
		{
			k = 0;
			i = num - 1;
			while (i > 0)
			{
				if (A[i] < A[i - 1])
				{
					a = A[i];
					A[i] = A[i - 1];
					A[i - 1] = a;
					k += 1;
				}
				i--;
			}
		}
		break;
		//----------------------------------(2.2)Сортировка "shaker sort"
	case 1:
		while (k != 0)
		{
			k = 0;
			i = num - 1;
			while (i > 0)
			{
				if (A[i] < A[i - 1])
				{
					a = A[i];
					A[i] = A[i - 1];
					A[i - 1] = a;
					k += 1;
				}
				i--;
			}
			k = 0;
			while (i < num - 1)
			{
				if (A[i] > A[i + 1])
				{
					a = A[i];
					A[i] = A[i + 1];
					A[i + 1] = a;
					k += 1;
				}
				i++;
			}
		}
		break;
		//----------------------------------(2.3)Сортировка "comb sort"
	case 2:
		while (S >= 1)
		{
			for (i = 0; i + S < num; i++)
			{
				j = i + S;
				if (A[i] > A[j])
				{
					a = A[j];
					A[j] = A[i];
					A[i] = a;
				}
			}
			S /= kk;
		}
		while (true)
		{
			for (int i = 0; i < num - 1; i++)
			{
				if (A[i] > A[i + 1])
				{
					a = A[i + 1];
					A[i + 1] = A[i];
					A[i] = a;
				}
				else k++;
			}
			if (k == num - 1)
				break;
			else
				k = 0;
		}
		j = 0;
		break;
		//----------------------------------(2.4)Сортировка "insert sort"
	case 3:
		k = 0;
		for (i = 1;i < num;i++) {
			for (j = i; j > 0 && A[j - 1] > A[j];j--) {
				k++;
				a = A[j - 1];
				A[j - 1] = A[j];
				A[j] = a;
			}
		}
		break;
	}
	i = 0;
	//----------------------------------(3)Вывод результата сортировки
	system_clock::time_point endA = system_clock::now();
	while (i < num)
	{
		cout << A[i] << " ";
		i++;
	}
	duration<double> secA = endA - startA;
	cout << endl << "Time spent sorting:: " << secA.count() << "s" << endl;
	cout << "----------------------" << endl;
	//----------------------------------(4)Нахождение максимума и минимума
	system_clock::time_point startE = system_clock::now();
	max = A[num-1];
	min = A[0];
	//for (i = 0; i < num; i++)
	//{
	//	if (max < A[i]) 
	//		max = A[i];
	//	if (min > A[i]) 
	//		min = A[i];
	//}
	system_clock::time_point endE = system_clock::now();
	duration<double> secE = endE - startE;
	duration<double> sec = end - start;
	cout <<"Time spent searching BEFORE sorting: "<< sec.count() << "s" << endl;
	cout << "Time spent searching AFTER sorting: " << secE.count() << "s" << endl;
	cout << "max: "<<max<< endl << "min: " << min <<endl << "----------------------" << endl;
	//----------------------------------(5)Нахождение ср.знач и схожих в массиве с ним значений
	int Nmax = 0, Nmin = 0, Nmid = 0, midN = 0;
	for (i = 0; i < num; i++)
	{
		if (A[i] == min)
			Nmin += 1;
		if (A[i] == max)
			Nmax += 1;
	}
	cout << "Num of max: " << Nmax << endl << "Num of min: " << Nmin << endl;
	midN = (max*Nmax+min*Nmin)/(Nmin+Nmax);
	cout << "midNumber = " <<midN<< endl;
	cout << "indexes:";
	for (i = 0; i < num; i++)
	{
		if (A[i] == midN)
		{
			Nmid += 1;
			cout << i << " ";
		}
	}
	if (Nmid == 0)
		cout << " note";
	cout <<endl<< "Num of midN: " << Nmid << endl;
	cout << "----------------------" << endl;
	//----------------------------------(6) Поиск кол-ва чисел, которые меньше и больше числа, которое вводит пользователь
	m = 1;
	while (m != 0)
	{
		cout << "Enter your number:" << endl;
		NofB = 0;
		NofA = 0;
		cin >> c;
		for (i = 0; i < num; i++)
		{
			if (A[i] < c)
			{
				NofA += 1;
			}
		}
		cout << "The number of numbres in the array that are less than your number: " << NofA;
		cout << endl << "To repeat, dial <1>, and to finish, dial <0>.";
		cin >> m;
		cout << endl << endl;
	}
	cout << endl << "----------------------" << endl;
	m = 1;
	while (m != 0)
	{
		cout << "Enter your number:" << endl;
		cin >> b;
		for (i = 0; i < num; i++)
		{
			if (A[i] > b)
			{
				NofB += 1;
			}
		}
		cout << "The number of numbres in the array that are bigger than your number: " << NofB;
		cout << endl << "To repeat, dial <1>, and to finish, dial <0>.";
		cin >> m;
		cout << endl << endl;
	}
	cout << endl << "----------------------" << endl;
	//----------------------------------(7) Поиск числа, которое вводит пользователь, бинарным поиском и обычным перебором
	m = 1;
	while (m != 0)
	{
		cout << "Enter the desired number:" << endl;
		cin >> key;
		system_clock::time_point startC = system_clock::now();
		bool flag = false;
		int l = min; // левая граница
		int r = max; // правая граница
		while ((l <= r) && (flag != true)) {
			mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
			if (A[mid] == key) flag = true; //проверяем ключ со серединным элементом
			if (A[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
			else l = mid + 1;
		}
		if (flag)
			cout << "The index of the number " << key << " is <" << mid << ">" << endl;
		else
			cout << "Sorry, nothing found" << endl;
		system_clock::time_point endC = system_clock::now();
		duration<double> secC = endC - startC;
		//--
		mid = 0;
		system_clock::time_point startD = system_clock::now();
		for (i = 0; i < num; i++)
		{
			if (key == A[i])
			{
				mid = i;
			}
		}
		system_clock::time_point endD = system_clock::now();
		duration<double> secD = endD - startD;
		if (secC > secD)
			cout << endl << "BINARY SEARCH was faster and counted for: " << secC.count() << "s" << endl;
		else
			cout << endl << "BRUTE FORCE was faster and counted for: " << secD.count() << "s" << endl;
		cout << endl<<"To repeat, dial <1>, and to finish, dial <0>.";
		cin >> m;
		cout << endl << endl;
	}
	cout<< "----------------------" << endl;
	//----------------------------------(8) Поиск числа, которое вводит пользователь, бинарным поиском и обычным перебором
	int P, Z, Q;
	m = 1;
	while (m != 0)
	{
		cout << "Enter the first index:" << endl;
		cin >> P;
		cout << "Enter the second index:" << endl;
		cin >> Z;
		system_clock::time_point startB = system_clock::now();
		Q = A[P];
		A[P] = A[Z];
		A[Z] = Q;
		i = 0;
		system_clock::time_point endB = system_clock::now();
		duration<double> secB = endB - startB;
		cout << endl << "Time spent swapping: " << secB.count() << "s" << endl;
		cout << endl << endl << "Result:" << endl;
		while (i < num)
		{
			cout << A[i] << " ";
			i++;
		}
		cout << endl << endl;
		cout << endl<<"To repeat, dial <1>, and to finish, dial <0>.";
		cin >> m;
		cout << endl << endl;
	}
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
