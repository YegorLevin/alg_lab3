#include "stdafx.h"
#include "CppUnitTest.h"
#include "../alg_lab3/TreeClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	
	TEST_CLASS(Iterator)
	{
	public:
		TreeClass * tree;
		//Iterator * iterator = tree->create_dft_iterator();
		TEST_METHOD_INITIALIZE(SetUp)
		{
			tree = new TreeClass();
		}
		TEST_METHOD_CLEANUP(CleanUp)
		{
			delete tree;
		}
		TEST_METHOD(Dft_iterator)
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

			int result[11] = { 0,2,1,1,4,3,7,6,8,6,5 };
			bool is_right = 1;
			Iterator * iterator = tree->create_dft_iterator();
			while (iterator->has_next()
			{
				
			}


			// TODO: Разместите здесь код своего теста
		}

	};
