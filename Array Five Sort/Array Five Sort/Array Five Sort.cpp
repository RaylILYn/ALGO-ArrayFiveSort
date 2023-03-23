#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	const int SIZE = 100;
	int x[SIZE], y[SIZE], w[SIZE], v[SIZE];
	int n, m, j, t = 0, p = 0;

	// ввод первого массива

	cout << "Введите размер первого массива (макс.100): ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		x[i] = rand() % 90 - 45;
	}
	cout << "Первый случайный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}

	// ввод второго массива

	cout << endl << endl << "Введите размер второго массива (макс.100): ";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		y[i] = rand() % 45;
	}
	cout << "Второй случайный массив: ";
	for (int i = 0; i < m; i++)
	{
		cout << y[i] << " ";
	}

	w[n + m];		//новый пустой массив
	int z;
	cout << endl << endl << "Введите метод сортировки 1-5:" << endl << endl <<
		"1. Получение упорядоченного по убыванию массива методом слияния двух упорядоченных по убыванию массивов." << endl << endl <<
		"2. Метод сортировки по возрастанию обменом рядом стоящих элементов с переменным числом просмотров, направленных справа налево." << endl << endl <<
		"3. Шейкерная сортировка по возрастанию" << endl << endl <<
		"4. Сортировка расчёской по убыванию" << endl << endl <<
		"5. Метод сортировки по возрастанию извлечением минимального элемента, извлечение минимального элемента проводить справа налево" << endl << endl;
	cin >> z;
	int left = 0, right = n - 1, flag = 1; //case 3
	int flag1 = 1, step = n - 1;          //case 4
	double	g = 1.2473309;  //case 4
	int f = 0;
	switch (z)
	{

	case 1:

		cout << "Первый упорядоченный массив по убыванию: ";
		sort(x, x + n);
		for (int i = n - 1; i >= 0; i--)
		{
			cout << x[i] << "  ";
		}
		cout << endl;

		cout << "Второй упорядоченный массив по убыванию: ";
		sort(y, y + m);
		for (int i = m - 1; i >= 0; i--)
		{
			cout << y[i] << "  ";
		}
		cout << endl;

		for (int i = 0; i < n + m; i++)		// Создание нового массива
		{
			if (i < n)
			{
				w[i] = x[i];
			}
			else
			{
				w[i] = y[i - n];
			}
		}

		cout << "Новый полученный массив со значениями по убыванию: ";
		sort(w, w + n + m);
		for (int i = n + m - 1; i >= 0; i--)
		{
			cout << "[" << w[i] << "] ";
		}
		cout << endl;
		break;

	case 2:

		cout << "Сортировка первого массива по возрастанию методом обмена рядом стоящих элементов: ";
		for (int i = 0; i < n; i++)
		{
			j = i;
			for (t = i; t < n; t++)
			{
				if (x[j] > x[t])
				{
					j = t;
				}
			}
			swap(x[i], x[j]);
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "]" << x[i] << "  ";
		}
		cout << endl;
		break;

	case 3:

		cout << "Шейкерная сортировка первого массива по возрастанию: ";
		int temp;
		while ((left < right) && flag > 0)
		{
			flag = 0;
			for (int i = 0; i < right; i++)
			{
				if (x[i] > x[i + 1])
				{
					temp = x[i];
					x[i] = x[i + 1];
					x[i + 1] = temp;
					flag = 1;
				}
			}
			right--;
			for (int i = right; i > left; i--)
			{
				if (x[i - 1] > x[i])
				{
					temp = x[i];
					x[i] = x[i - 1];
					x[i - 1] = temp;
					flag = 1;
				}
			}
			left++;
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "]" << x[i] << "  ";
		}
		cout << endl;
		break;

	case 4:

		cout << "Сортировка расчёской по убыванию: ";
		int temp1;

		while (step > 1)
		{
			for (int i = 0; i + step < n; i++)
			{
				if (x[i] > x[i + step])
				{
					temp1 = x[i];
					x[i] = x[i + step];
					x[i + step] = temp1;

				}
			}
			step /= g;
		}
		while (flag1)
		{
			flag1 = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (x[i] > x[i + 1])
				{
					temp1 = x[i];
					x[i] = x[i + 1];
					x[i + 1] = temp1;
					flag1 = 1;
				}
			}
		}

		for (int i = n - 1; i != -1; i--)
		{
		}
		for (int i = n - 1; i != -1; i--)
		{
			v[f] = x[i];
			f = f + 1;
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "]" << v[i] << " ";
		}
		cout << endl;
		break;

	case 5:

		cout << "Cортировка по возрастанию методом извлечением минимального элемента [<--]: ";

		for (int i = 0; i < n - 1; i++)
		{
			int nMin = i;
			for (int f = i + 1; f < n; f++)
			{
				if (x[f] < x[nMin])
				{
					nMin = f;
				}
			}
			int temp = x[i];
			x[i] = x[nMin];
			x[nMin] = temp;
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "]" << x[i] << " ";
		}
		cout << endl;
		break;
	}
	cout << endl;
	system("pause");
}