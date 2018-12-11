#include "stdafx.h"
#include "../alg_lab3/TreeClass.h"
#include "CppUnitTest.h"
#include <stdexcept>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
	
	TEST_CLASS(Iterator_tests)
	{
		
	public:
		TreeClass * tree;
		//Iterator * iterator;
		//Iterator * iterator = tree->create_dft_iterator();
		TEST_METHOD_INITIALIZE(SetUp)
		{
			tree = new TreeClass;
			//Iterator * iterator = tree->create_dft_iterator();
		}
		TEST_METHOD_CLEANUP(CleanUp)
		{
			//delete tree;
			//delete iterator;
		}
		
		TEST_METHOD(Dft_iterator_test_1)
		{
			tree->insert(5);
			tree->insert(3);
			tree->insert(1);
			tree->insert(4);
			tree->insert(6);
			tree->insert(8);
			tree->insert(1);
			tree->insert(2);
			tree->insert(0);
			tree->insert(6);
			tree->insert(7);
			
			int right_result[11] = { 0,2,1,1,4,3,7,6,8,6,5 };
			bool is_right = 1;
			
			Iterator * iterator = tree->create_dft_iterator();
			
			for (int i = 0; iterator->has_next(), i<11; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}
			
			Assert::IsTrue(is_right);
			delete iterator;
		}
		TEST_METHOD(Dft_iterator_test_2)
		{
			tree->insert(10);
			tree->insert(13);
			tree->insert(12);
			tree->insert(3);
			tree->insert(2);
			tree->insert(1);
			tree->insert(5);
			tree->insert(4);
			tree->insert(8);

			int right_result[9] = { 1,2,4,8,5,3,12,13,10 };
			bool is_right = 1;

			Iterator * iterator = tree->create_dft_iterator();

			for (int i = 0; iterator->has_next(), i < 9; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}

			Assert::IsTrue(is_right);
			delete iterator;
		}
		TEST_METHOD(Dft_iterator_test_oneStick)
		{
			tree->insert(5);
			tree->insert(6);
			tree->insert(7);
			tree->insert(8);
			tree->insert(9);
			tree->insert(10);

			int right_result[6] = { 10,9,8,7,6,5 };
			bool is_right = 1;

			Iterator * iterator = tree->create_dft_iterator();

			for (int i = 0; iterator->has_next(), i < 6; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}

			Assert::IsTrue(is_right);
			delete iterator;
		}

		TEST_METHOD(Bft_iterator_test_1)
		{
			tree->insert(5);
			tree->insert(3);
			tree->insert(1);
			tree->insert(4);
			tree->insert(6);
			tree->insert(8);
			tree->insert(2);
			tree->insert(0);
			tree->insert(7);

			int right_result[9] = {5,3,6,1,4,8,0,2,7 };
			bool is_right = 1;

			Iterator * iterator = tree->create_bft_iterator();

			for (int i = 0; iterator->has_next(), i < 9; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}


			Assert::IsTrue(is_right);
		}
		TEST_METHOD(Bft_iterator_test_oneStick)
		{
			tree->insert(5);
			tree->insert(4);
			tree->insert(3);
			tree->insert(2);
			tree->insert(1);

			int right_result[5] = {5,4,3,2,1};
			bool is_right = 1;

			Iterator * iterator = tree->create_bft_iterator();

			for (int i = 0; iterator->has_next(), i < 5; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}


			Assert::IsTrue(is_right);
		}

		TEST_METHOD(Bft_iterator_test_2)
		{
			tree->insert(10);
			tree->insert(13);
			tree->insert(12);
			tree->insert(3);
			tree->insert(2);
			tree->insert(5);
			tree->insert(1);
			tree->insert(4);
			tree->insert(8);

			int right_result[9] = { 10,3,13,2,5,12,1,4,8};
			bool is_right = 1;

			Iterator * iterator = tree->create_bft_iterator();

			for (int i = 0; iterator->has_next(), i < 9; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}


			Assert::IsTrue(is_right);
		}

		TEST_METHOD(iterator_noMoreElem_exception)
		{
			tree->insert(5);
			Iterator * iterator = tree->create_dft_iterator();
			try
			{
				iterator->next();
				iterator->next();
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "Tree is over");
			}
		}
		TEST_METHOD(iterator_emptyTree_exception)
		{
			
			try
			{
				Iterator * iterator = tree->create_dft_iterator();
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "Tree is empty");
			}
		}

	};
	TEST_CLASS(TreeMethods_tests)
	{
	public:
		TreeClass * tree;
		TEST_METHOD_INITIALIZE(SetUp)
		{
			tree = new TreeClass;
		}
		TEST_METHOD_CLEANUP(CleanUp)
		{
			//delete tree;
			//delete iterator;
		}
		TEST_METHOD(insert_head_test)
		{
			tree->insert(5);

			Assert::IsTrue(tree->head->key == 5);
		}
		TEST_METHOD(insert_leftNode_test)
		{
			tree->insert(5);
			tree->insert(4);

			Assert::IsTrue(tree->head->key == 5 && tree->head->left->key == 4);
		}

		TEST_METHOD(insert_rightNode_test)
		{
			tree->insert(5);
			tree->insert(6);

			Assert::IsTrue(tree->head->key == 5 && tree->head->right->key == 6);
		}

		TEST_METHOD(insert_multipleTimes_test)
		{
			tree->insert(5);
			tree->insert(3);
			tree->insert(1);
			tree->insert(4);
			tree->insert(6);
			tree->insert(7);

			Assert::IsTrue(tree->head->key == 5 && tree->head->left->key == 3 && tree->head->left->right->key == 4 
				&& tree->head->left->left->key == 1 && tree->head->right->key == 6 && tree->head->right->right->key == 7);
		}
		TEST_METHOD(contains_oneNode)
		{
			tree->insert(5);

			Assert::IsTrue(tree->contains(5));

		}
		TEST_METHOD(contains_multipleNodes)
		{
			tree->insert(5);
			tree->insert(4);
			tree->insert(3);
			tree->insert(7);

			Assert::IsTrue(tree->contains(5)&& tree->contains(7)&& tree->contains(3)&& tree->contains(4));
		}

		TEST_METHOD(contains_wrongKey)
		{
			tree->insert(5);

			Assert::IsFalse(tree->contains(3));
		}

		TEST_METHOD(remove_head)
		{
			tree->insert(5);
			tree->remove(5);

			Assert::IsTrue(tree->head == nullptr);
		}
		TEST_METHOD(remove_leftLeaf)
		{
			tree->insert(5);
			tree->insert(4);
			tree->remove(4);

			Assert::IsTrue(tree->head->left == nullptr);
		}
		TEST_METHOD(remove_rightLeaf)
		{
			tree->insert(5);
			tree->insert(6);
			tree->remove(6);

			Assert::IsTrue(tree->head->right == nullptr);
		}
		TEST_METHOD(remove_Node)
		{
			tree->insert(10);
			tree->insert(13);
			tree->insert(12);
			tree->insert(3);
			tree->insert(2);
			tree->insert(1);
			tree->insert(5);
			tree->insert(4);
			tree->insert(8);

			tree->remove(3);
			int right_result[8] = {1,2,4,8,5,12,13,10};
			bool is_right = 1;
			Iterator * iterator = tree->create_dft_iterator();
			for (int i = 0; iterator->has_next(), i < 8; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}

			Assert::IsTrue(tree->head->left->key == 5 && is_right && tree->head->left->left->left->key == 2 
				&& tree->head->left->left->left->up == tree->head->left->left);
		}
		TEST_METHOD(remove_HeadNode)
		{
			tree->insert(10);
			tree->insert(13);
			tree->insert(12);
			tree->insert(3);
			tree->insert(2);
			tree->insert(1);
			tree->insert(5);
			tree->insert(4);
			tree->insert(8);

			tree->remove(10);
			int right_result[8] = { 1,2,4,8,5,3,12,13 };
			bool is_right = 1;
			Iterator * iterator = tree->create_dft_iterator();
			for (int i = 0; iterator->has_next(), i < 8; i++)
			{
				if (iterator->next() != right_result[i])
					is_right = 0;
			}

			Assert::IsTrue(tree->head->key == 13 &&tree->head->left->left->key == 3 && is_right && tree->head->left->left->up == tree->head->left);
		}
		TEST_METHOD(remove_oneLeftStick)
		{
			tree->insert(5);
			tree->insert(4);
			tree->insert(3);

			tree->remove(4);
			Assert::IsTrue(tree->head->left->key == 3 && tree->head->left->up == tree->head);
		}

		TEST_METHOD(remove_oneRightStick)
		{
			tree->insert(5);
			tree->insert(6);
			tree->insert(7);

			tree->remove(6);
			Assert::IsTrue(tree->head->right->key == 7 && tree->head->right->up == tree->head);
		}
		
		TEST_METHOD(remove_ElemDoesntExist_exception)
		{
			tree->insert(5);
			try
			{
				tree->remove(9);
			}
			catch (const char * exception)
			{
				Assert::IsTrue(exception == "No equal key");
			}
		}
	};
