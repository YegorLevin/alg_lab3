// alg_lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "TreeClass.h"
#include <iostream>

using namespace std;

int main()
{
	TreeClass * Tree = new TreeClass;
	Tree->insert(5);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(4);
	Tree->insert(6);
	Tree->insert(8);
	Tree->insert(1);
	Tree->insert(2);
	Tree->insert(0);
	Tree->insert(6);
	Tree->insert(7);
	Tree->print_Tree(Tree->head,0);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	Iterator * iterator = Tree->create_dft_iterator();
	while (iterator->has_next())
	{
		cout << iterator->next();
	}
	cout << endl;
	Tree->print_Tree(Tree->head, 0);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	Iterator * siterator = Tree->create_dft_iterator();
	while (siterator->has_next())
	{
		cout << siterator->next();
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	for (int i = 0; i < 12; i++)
	{

		cout << i << ": " <<Tree->contains(i)<< endl;
	}
	
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
