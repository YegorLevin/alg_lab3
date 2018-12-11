#pragma once

class TreeNode
{
public:
	TreeNode(int);
	~TreeNode();

	int key;
	TreeNode * left;
	TreeNode * right;
	TreeNode * up;
	int order_num;
private:

};

class List {
private:
	//Класс элемента очереди
	class ListNode {
	public:
		ListNode(TreeNode *node);
		TreeNode *tree_node;
		ListNode *next;
	};

public:
	List(TreeNode *node);
	void push_back(TreeNode *node); //добавление элемента в конец очереди
	TreeNode* pop_front(); //Удаление элемента из начала очереди
	ListNode *head; //Указатель на начало очереди
	ListNode *tail; // Указатель на конец очереди
//	ListNode *cur; //указатель на текущий элемент
	int size; //Размер очереди
};


	class Iterator // родительский класс итератора 
	{
	public:
		Iterator();
		~Iterator();
		virtual int next() = 0;
		virtual bool has_next() = 0;
		TreeNode * current;
	protected:
		
	};
	
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
			int next() override; //Переопредленная функция перехода к следующему элементу
			bool has_next() override; //Переопределенная функция проверки наличия следующего элемента
			int* keys_bft; //Массив ключей дерева (очереди)
			int size_of_keys_bft; //Размер массива ключей (количество элементов дерева (очереди))
			int i_of_keys_bft; //Номер (индекс) элемента (ключа)
		};

	public:
		TreeClass();
		~TreeClass();
		void print_Tree(TreeNode * p, int level);


	void insert(int); // добавление элемента в дерево по ключу
	bool contains(int); // поиск элемента в дереве по ключу
	void remove(int); // удаление элемента дерева по ключу
	Iterator * create_dft_iterator(); // создание итератора, реализующего методы обхода в глубину (depth-first traverse)
	Iterator * create_bft_iterator(); // создание итератора, реализующего методы обхода в ширину


	TreeNode * head;
		
};


	
