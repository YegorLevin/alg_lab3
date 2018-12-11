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
	//����� �������� �������
	class ListNode {
	public:
		ListNode(TreeNode *node);
		TreeNode *tree_node;
		ListNode *next;
	};

public:
	List(TreeNode *node);
	void push_back(TreeNode *node); //���������� �������� � ����� �������
	TreeNode* pop_front(); //�������� �������� �� ������ �������
	ListNode *head; //��������� �� ������ �������
	ListNode *tail; // ��������� �� ����� �������
//	ListNode *cur; //��������� �� ������� �������
	int size; //������ �������
};


	class Iterator // ������������ ����� ��������� 
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
		

		class Dft_iterator : public Iterator // ����� ��������� ��������� ������ � �������
		{
		public:
			Dft_iterator(TreeClass* tree);
			~Dft_iterator();
			int next() override;
			bool has_next() override;
			
			
		private:
			

		};
		
		//����� ��������� ��� ������ � ������
		class Bft_iterator : public Iterator //��������� �� ������ ��������
		{
		public:
			Bft_iterator(TreeClass* tree);
			int next() override; //��������������� ������� �������� � ���������� ��������
			bool has_next() override; //���������������� ������� �������� ������� ���������� ��������
			int* keys_bft; //������ ������ ������ (�������)
			int size_of_keys_bft; //������ ������� ������ (���������� ��������� ������ (�������))
			int i_of_keys_bft; //����� (������) �������� (�����)
		};

	public:
		TreeClass();
		~TreeClass();
		void print_Tree(TreeNode * p, int level);


	void insert(int); // ���������� �������� � ������ �� �����
	bool contains(int); // ����� �������� � ������ �� �����
	void remove(int); // �������� �������� ������ �� �����
	Iterator * create_dft_iterator(); // �������� ���������, ������������ ������ ������ � ������� (depth-first traverse)
	Iterator * create_bft_iterator(); // �������� ���������, ������������ ������ ������ � ������


	TreeNode * head;
		
};


	
