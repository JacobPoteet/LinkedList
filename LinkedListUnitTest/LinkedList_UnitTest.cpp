#include "pch.h"
#include "../LinkedListClass/LinkedList.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedList_Test
{
	TEST_CLASS(LinkedListHelpers)
	{
	public:

		TEST_METHOD(GetSize_EmptyList)
		{
			LinkedList* testList = new LinkedList();

			Assert::IsTrue(testList->GetSize() == 0);

		}

		TEST_METHOD(GetSize_WithElements)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(1);

			Assert::IsTrue(testList->GetSize() == 1);

		}
		TEST_METHOD(IsEmpty_EmptyList)
		{
			LinkedList* testList = new LinkedList();

			Assert::IsTrue(testList->IsEmpty());

		}

		TEST_METHOD(IsEmpty_WithElements)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(1);

			Assert::IsFalse(testList->IsEmpty());

		}

		TEST_METHOD(FindNode_WithElements)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(1);
			testList->PushBack(10);
			testList->PushBack(300);
			testList->PushBack(400);

			Assert::IsTrue(testList->FindNode(400) == 1);

		}

		TEST_METHOD(GetHeadNode_GetValidHead)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(25);
			
			Node* testNode = testList->GetHeadNode();

			Assert::IsTrue(testNode->data == 25);

		}
	};


	TEST_CLASS(Concatenate)
	{
	public:

		TEST_METHOD(Concatenate_Base_Example_L1IsCorrectSize)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(1);
			testList1->PushBack(3);
			testList1->PushBack(2);

			testList2->PushBack(5);
			testList2->PushBack(4);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 5);

		}

		TEST_METHOD(Concatenate_Base_Example_L1IsCorrectOrder)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(3);
			testList1->PushBack(2);
			testList1->PushBack(1);

			testList2->PushBack(5);
			testList2->PushBack(4);

			testList1->ConcatenateList(testList2);

			//proves testList1 is now [1,2,3,4,5]
			Assert::IsTrue((testList1->FindNode(4) == 4) 
				&& (testList1->FindNode(5) == 5)
				);

		}

		TEST_METHOD(Concatenate_Base_Example_L1IsACopyNotReference)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(1);
			testList1->PushBack(3);
			testList1->PushBack(2);

			testList2->PushBack(5);
			testList2->PushBack(4);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->FindNode(4) != testList2->FindNode(4));

		}
		TEST_METHOD(Concatenate_BothEmptyList)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 0);

		}
		TEST_METHOD(Concatenate_GivenEmptyList)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(1);
			testList1->PushBack(3);
			testList1->PushBack(2);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 3);

		}
		TEST_METHOD(Concatenate_SelfEmptyList)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList2->PushBack(5);
			testList2->PushBack(4);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 2);

		}
		TEST_METHOD(Concatenate_SingleElementInBothLists)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(1);
			testList2->PushBack(2);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 2);

		}
		TEST_METHOD(Concatenate_SingleElementInSelf)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(1);
			testList2->PushBack(2);
			testList2->PushBack(3);
			testList2->PushBack(4);
			testList2->PushBack(5);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 5);

		}
		TEST_METHOD(Concatenate_SingleElementInGiven)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(1);
			testList1->PushBack(2);
			testList1->PushBack(3);
			testList1->PushBack(4);
			testList2->PushBack(5);

			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 5);

		}
		TEST_METHOD(Concatenate_EqualElementsInBothLists)
		{
			LinkedList* testList1 = new LinkedList();
			LinkedList* testList2 = new LinkedList();

			testList1->PushBack(3);
			testList1->PushBack(2);
			testList1->PushBack(1);

			testList2->PushBack(4);
			testList2->PushBack(5);
			testList2->PushBack(6);


			testList1->ConcatenateList(testList2);

			Assert::IsTrue(testList1->GetSize() == 6);

		}
	};

TEST_CLASS(GetMaxElem)
{
public:

TEST_METHOD(maxElem_MaxAtEnd)
{
	LinkedList* testList = new LinkedList();

	testList->PushBack(1);
	testList->PushBack(2);

			

	Assert::IsTrue(testList->GetMaxElem() == 2);

}
TEST_METHOD(maxElem_MaxAtBeginning)
{
	LinkedList* testList = new LinkedList();

	testList->PushBack(5);
	testList->PushBack(2);



	Assert::IsTrue(testList->GetMaxElem() == 5);

}

TEST_METHOD(maxElem_EmtpyList)
{
	LinkedList* testList = new LinkedList();

	Assert::IsTrue(testList->GetMaxElem() == -1);

}

TEST_METHOD(maxElem_Base_Example)
{
	LinkedList* testList = new LinkedList();


	testList->PushBack(5);
	testList->PushBack(1);
	testList->PushBack(9);
	testList->PushBack(3);
	testList->PushBack(2);

	Assert::IsTrue(testList->GetMaxElem() == 9);

}
};

	TEST_CLASS(RemoveDuplicateEntries)
	{
	public:

		TEST_METHOD(RemoveDuplicateEntries_Base_Example)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(5);
			testList->PushBack(2);
			testList->PushBack(2);
			testList->PushBack(5);
			testList->PushBack(3);
			testList->PushBack(9);
			testList->PushBack(2);

			testList->RemoveDuplicateEntries();

			Assert::IsTrue(testList->GetSize() == 4);

		}

		TEST_METHOD(RemoveDuplicateEntries_EmptyList)
		{
			LinkedList* testList = new LinkedList();

			testList->RemoveDuplicateEntries();


			Assert::IsTrue(testList->GetSize() == 0);

		}

		TEST_METHOD(RemoveDuplicateEntries_AllTheSame)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(2);
			testList->PushBack(2);
			testList->PushBack(2);
			testList->PushBack(2);
			testList->PushBack(2);


			testList->RemoveDuplicateEntries();

			Assert::IsTrue(testList->GetSize() == 1);

		}

		TEST_METHOD(RemoveDuplicateEntries_AllDifferent)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(1);
			testList->PushBack(2);
			testList->PushBack(3);
			testList->PushBack(4);
			testList->PushBack(5);
			testList->PushBack(6);
			testList->PushBack(7);

			testList->RemoveDuplicateEntries();

			Assert::IsTrue(testList->GetSize() == 7);

		}
	};

	TEST_CLASS(InsertNode)
	{
	public:

		TEST_METHOD(InsertNode_EmptyList)
		{
			LinkedList* testList = new LinkedList();

			testList->InsertNode(0, 100);

			Assert::IsTrue(testList->GetSize());

		}
		TEST_METHOD(InsertNode_InsertAtIndex0)
		{
			LinkedList* testList = new LinkedList();

			testList->PushBack(9);
			testList->InsertNode(0, 800);



			Assert::IsTrue(testList->FindNode(800) == 1);

		}
		TEST_METHOD(InsertNode_InsertBeyondList)
		{
			LinkedList* testList = new LinkedList();

			
			testList->PushBack(9);
			testList->InsertNode(5, 800);

			Assert::IsTrue(testList->FindNode(800) == 2);

		}
		TEST_METHOD(InsertNode_InsertNegativeIndex)
		{
			LinkedList* testList = new LinkedList();

			testList->InsertNode(-1, 800);

			Assert::IsTrue(testList->head == NULL);

		}
		TEST_METHOD(InsertNode_5Entries)
		{
			LinkedList* testList = new LinkedList();

			testList->InsertNode(0, 0);
			testList->InsertNode(1, 1);
			testList->InsertNode(2, 2);
			testList->InsertNode(3, 3);
			testList->InsertNode(4, 4);


			Assert::IsTrue((testList->GetSize() == 5)
			&& (testList->FindNode(3) == 4)
			);

		}
	};
}

