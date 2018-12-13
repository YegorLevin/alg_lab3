#include "pch.h"
#include "TreeClass.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TreeClass::TreeClass()
{
	head = nullptr;
}

TreeClass::~TreeClass()
{
	if (!is_empty())
	{
		Iterator * iterator = create_dft_iterator();
		TreeNode * before;
	while (iterator->has_next())
	{
		before = iterator->current;
		iterator->next();
		delete before;
	}
	delete iterator;
	}
	
}

void TreeClass::insert(int key) {
	if (head == nullptr) //если дерево пустое, создаём первый элемент
	{
		head = new TreeNode(key);

	}
	else
	{
		TreeNode * current = head;
		bool end = 0; //достигли ли мы конца дерева

		while (!end) { //двигаемся вниз до конца, сравнивая ключ нашего элемента с ключами в дереве
			if (key < current->key)// если наш ключ меньше указанного ключа дерева, то спускаемся влево
			{

				if (current->left != nullptr) //если не конечный элемент, то спускаемся ниже
					current = current->left;
				else // если конечный, создаём слева от него элемент с нашим ключом 
				{
					current->left = new TreeNode(key);
					current->left->up = current;
					end = 1;
				}

			}
			else // если наш ключ больше или равен указанному ключу дерева, то спускаемся вправо
			{

				if (current->right != nullptr) //если не конечный элемент, то спускаемся ниже
					current = current->right;
				else // если конечный, создаём справа от него элемент с нашим ключом
				{
					current->right = new TreeNode(key);
					current->right->up = current;
					end = 1;
				}


			}
		}

	}
}

TreeNode::TreeNode(int key)
{
	this->key = key;
}

TreeNode::~TreeNode()
{
	left = nullptr;
	right = nullptr;
	up = nullptr;
}


void TreeClass::print_Tree(TreeNode * p, int level)
{
	if (p)
	{
		print_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "     ";
		cout << p->key << "<" << endl;
		print_Tree(p->left, level + 1);
	}
}



Iterator::Iterator()
{
}
Iterator::~Iterator()
{	
}

TreeClass::Dft_iterator::Dft_iterator(TreeClass* tree)
{
	if (tree->head == nullptr)
	{
		throw "Tree is empty";
	}
	else
	{
	current = tree->head; // проход к самому левому элементу дерева для начала обратного обхода в глубину
	while ((current->left != nullptr) || (current->right != nullptr))
	{
		if (current->left == nullptr)
		{
			current = current->right;
		}
		else
			current = current->left;
	}
	// вспомогательный элемент, чтобы первый вызов has_next() возвращал первый элемент итератора
	
	/*
	TreeNode * temp = new TreeNode(0);
	temp->up = current;
	current = temp;
	*/
	}
}

TreeClass::Dft_iterator::~Dft_iterator()
{
	
}

bool TreeClass::Dft_iterator::has_next() 
{
	return (current != nullptr);
}
int TreeClass::Dft_iterator::next()
{
	int key = current->key;
	if (current->up) // если есть куда идти
	{

		if ((current->up->right != nullptr) && (current->up->right != current)) //если можно пройти на правую ветку, то проходим
		{
			current = current->up->right;
			while ((current->left != nullptr) || (current->right != nullptr)) // идём в самый нижний элемент ветки (по возможности левый)
			{
				if (current->left == nullptr)
				{
					current = current->right;
				}
				else
					current = current->left;
			}
		}
		else // если справа веток нет, поднимаемся вверх
			current = current->up;
	}
	else // если обошли всё дерево
		//throw "Tree is over";
		current = nullptr;

	return key; //возвращаем ключ элемента
}


Iterator * TreeClass::create_dft_iterator()
{
	Dft_iterator * dft_iterator = new Dft_iterator(this);
	return dft_iterator;
}


bool TreeClass::contains(int key)
{
	Iterator * iterator = create_dft_iterator(); // создание итератора в глубину (обратный)
	bool contains = 0; // содержит ли дерево этот элемент
	while (!contains && iterator->has_next()) // пока не нашли или не закончилось дерево
	{

		if (iterator->next() == key) // перемещаем итератор и сравниваем с требуемым ключом
		{
			contains = 1; // если нашли нужный ключ
		}
	}
	return contains;
	delete iterator;
}
/*
там же итератор в глубину и он всегда только листья удаляет и не перестраивает дерево
*/

void TreeClass::remove(int key)
{
	
	while (!is_empty()&&contains(key)) // если такой элемент есть в дереве
	{
		bool found = 0; 
		Iterator * iterator = create_dft_iterator();
		while (iterator->has_next()) // пока не нашли или не закончилось дерево
		{
			
			if (iterator->current->key == key) // перемещаем итератор и сравниваем с требуемым ключом
			{
				break; // если нашли нужный ключ
			}
			iterator->next();
		}

		TreeNode* deleting_node = iterator->current;
		if ((deleting_node->left != nullptr) && (deleting_node->right != nullptr)) // если у удаляемого есть обе подветки
		{
			TreeNode* left_stick = deleting_node->left;
			TreeNode* right_stick = deleting_node->right;
			//присоединение правой подветки 
			if (deleting_node != head) // если удаляемый элемент не голова
			{
				right_stick->up = deleting_node->up; //соединяем верх правой подветки снизу вверх с верхним элементом удаляемого элемента
				if (deleting_node->key >= deleting_node->up->key) // удаляемый элемент является правым или левым
				{
					deleting_node->up->right = right_stick; //делаем соединение сверху вниз				
				}
				else // если это левый элемент верхнего элемента
					deleting_node->up->left = right_stick; //делаем соединение сверху вниз
			}
			else // если удаляемый элемент - голова
			{
				right_stick->up = nullptr;
				head = right_stick; // верхушка правой подветки становится головой
				

			}

				while (right_stick->left != nullptr) // находим самый левый элемент правой подветки
				{
					right_stick = right_stick->left;
				}
				right_stick->left = left_stick; //присоединяем левую подветку к этому концу правой подветки
				left_stick->up = right_stick;
			

			
		}
		else if (deleting_node->left != nullptr) // если есть только левая подветка
		{
			if (deleting_node != head) // если удаляемый элемент не голова
			{
				TreeNode* left_stick = deleting_node->left;
				left_stick->up = deleting_node->up; //привязываем левую ветку снизу вверх к верхнему элементу удаляемого 
				if (deleting_node->key >= deleting_node->up->key) // удаляемый элемент является правым или левым
					deleting_node->up->right = left_stick; //привязываем левую ветку сверху вниз к верхнему элементу удаляемого
				else
					deleting_node->up->left = left_stick; //привязываем левую ветку сверху вниз к верхнему элементу удаляемого
			}
			else // если удаляемый элемент - голова
			{ 
				head = deleting_node->left; //делаем головой верхушку этой подветки
				deleting_node->left->up = nullptr;
			}

		}
		else if (deleting_node->right != nullptr) // если есть только правая подветка
		{
			if (deleting_node != head) // если удаляемый элемент не голова
			{
				TreeNode* right_stick = deleting_node->right;
				right_stick->up = deleting_node->up; //привязываем правую ветку снизу вверх к верхнему элементу удаляемого 
				if (deleting_node->key >= deleting_node->up->key) // удаляемый элемент является правым или левым
					deleting_node->up->right = right_stick; //привязываем правую ветку сверху вниз к верхнему элементу удаляемого
				else
					deleting_node->up->left = right_stick; //привязываем правую ветку сверху вниз к верхнему элементу удаляемого
			}
			else // если удаляемый элемент - голова
			{
				head = deleting_node->right;  //делаем головой верхушку этой подветки
				deleting_node->right->up = nullptr;
			}
				
			
		}
		else // если нет подветок
		{
			if (deleting_node != head) // если удаляемый элемент не голова
			{
				if (deleting_node->key >= deleting_node->up->key) // удаляемый элемент является правым или левым
					deleting_node->up->right = nullptr; //удаляем к нему путь
				else
					deleting_node->up->left = nullptr;
			}
			else // если удаляемый элемент - голова
				head = nullptr; //обнуляем указатель на голову
		}
					
		delete deleting_node;
		delete iterator;
		/*if (contains(key))
			remove(key);*/
	}
	/*else
		throw "No equal key";*/
	
}


//Конструктор элемента очереди
Queue::QueueNode::QueueNode(TreeNode *node) {
	tree_node = node;
	next = nullptr;
}
//Деструктор элемента очереди
Queue::QueueNode::~QueueNode() {
	tree_node = nullptr;
	next = nullptr;
}
//Конструктор очереди
//Queue::Queue(TreeNode *node) {
//	tail = head = new QueueNode(node);
//	size = 1;
//}
//Конструктор пустой очереди
Queue::Queue() {
	tail = head = nullptr;
}
//Деструктор очереди
Queue::~Queue() {
	while (tail) {
		this->pop_front();
	}
}
//Добавление элемента в конец очереди
void Queue::push_back(TreeNode *node) {
	if (head == nullptr)
		head = tail = new QueueNode(node);
	else {
		tail->next = new QueueNode(node);
		tail = tail->next;
	}
}
//Удаление элемента с начала очереди
TreeNode* Queue::pop_front() {
	TreeNode* temp = head->tree_node;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	return temp;
}
//Создание итератора для обхода в ширину
Iterator* TreeClass::create_bft_iterator() {
	Bft_iterator * bft_iterator = new Bft_iterator(this);
	return bft_iterator;
}
//Конструктор итератора обхода в ширину
TreeClass::Bft_iterator::Bft_iterator(TreeClass *tree) {
	current = tree->head;
	tree_Queue->push_back(current);
}
//Деструктор итератора обхода в ширину
TreeClass::Bft_iterator::~Bft_iterator() {
	current = nullptr;
	delete tree_Queue;
	tree_Queue = nullptr;
}
//Переопределенная функция перехода к следующему элементу
int TreeClass::Bft_iterator::next() {
	if (!has_next()) { //
		throw out_of_range("The next element does not exist!");
	}
	int key = current->key; //Получение ключа текущего узла
	if (current->left)
		tree_Queue->push_back(current->left); //Добавление в очередь левого потомка текущего узла
	if (current->right)
		tree_Queue->push_back(current->right); //Добавление в очередь правого потомка текущего узла
	if (tree_Queue->head->next)
		current = tree_Queue->head->next->tree_node; //Переход к следующему элементу в очереди
	else
		current = nullptr;
	tree_Queue->pop_front(); //Удаление элемента из очереди
	return key;
}

bool TreeClass::Bft_iterator::has_next() {
	return current != nullptr;
}

bool TreeClass::is_empty()
{
	return head == nullptr;
}