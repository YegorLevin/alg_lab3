#pragma once
#include "TreeNode.h"
#include"Iterator.h"
#include "QueueClass.h"	


	
	class TreeClass
	{
	private:
		

		class Dft_iterator : public Iterator // класс итератора обратного обхода в глубину
		{
		public:
			Dft_iterator(TreeClass* tree);
			~Dft_iterator();
			int next() override;
			bool has_next() override;
			
			
		private:
			

		};

		//Класс итератора для обхода в ширину
		class Bft_iterator : public Iterator //Наследует от класса итератор
		{
		public:
			Bft_iterator(TreeClass* tree);
			~Bft_iterator(); //Не знаю, насколько он необходим
			int next() override; //
			bool has_next() override; //
			Queue* tree_Queue = new Queue;

		};

		TreeNode * head;

	public:
		
		friend void Tree_Sort(int* arr, int arr_size); //Сортировка массива с помощью бинарного дерева поиска

		TreeClass();
		~TreeClass();
		void print_Tree(TreeNode * p, int level = 0);

	void insert(int); // добавление элемента в дерево по ключу
	bool contains(int); // поиск элемента в дереве по ключу
	void remove(int); // удаление элемента дерева по ключу
	Iterator * create_dft_iterator(); // создание итератора, реализующего методы обхода в глубину (depth-first traverse)
	Iterator * create_bft_iterator(); // создание итератора, реализующего методы обхода в ширину
	bool is_empty();

};


	
