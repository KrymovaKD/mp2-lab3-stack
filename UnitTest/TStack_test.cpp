#include "pch.h"
#include "Stack/TStack.h"


//—тэк
//может создать
TEST(TStack, Can_Create_Stack)
{

	ASSERT_NO_THROW(TStack<int> a);

}
//может создать с положительной длиной
TEST(TStack, Can_Create_Stack_with_positive_length)
{
	
	ASSERT_NO_THROW(TStack<int> a(5));

}
//не может создать с отрицательной длиной
TEST(TStack, Cant_Create_Stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> a(-3));
}
//создание по умолчанию
TEST(TStack, can_create_a_default_stack)
{
	ASSERT_NO_THROW(TStack <int> a());
}

TEST(TStack, can_create_copied_stack)
{
	TStack <int> a(3);
	ASSERT_NO_THROW(TStack <int> b(a));
}
//создание копии
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
	{
		a.push(i);
	}
	TStack <int> b(a);
	while(!(a.empty()))
	{
		EXPECT_EQ(a.pop(), b.pop());
	}
}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack <int> *a;
	a = new TStack<int>(2);
	a->push(1);
	a->push(2);
	TStack <int> b(*a);
	delete a;
	EXPECT_EQ(2, b.pop());
	EXPECT_EQ(1, b.pop());
	EXPECT_EQ(1, b.empty());
}
TEST(Tstack, new_stack_is_empty)
{
	TStack <int> a(3);
	EXPECT_EQ(1, a.empty());
}
TEST(TStack, can_push_and_pop)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
	{
		a.push(i);
	}
	int j = 2;
	while (!(a.empty()))
	{
		EXPECT_EQ(j, a.pop());
		j--;
	}

}
//неккоректные действи€ с push и pop
TEST(TStack, throws_when_push_on_full_stack)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
	{
		a.push(i);
	}
	ASSERT_ANY_THROW(a.push(7));
}
TEST(TStack, throws_when_use_pop_on_empty_stack)
{
	TStack <int> a(1);
	ASSERT_ANY_THROW(a.pop());
}
TEST(TStack, throws_when_use_top_on_empty_stack)
{
	TStack <int> a(3);
	ASSERT_ANY_THROW(a.top());
}
TEST(TStack, return_true_when_use_full_on_full_stack)
{
	TStack <int> a(3);
	for (int i = 0; i < 3; i++)
	{
		a.push(i);
	}
	EXPECT_EQ(1, a.full());
}

TEST(TStack, return_false_when_use_full_on_full_stack)
{
	TStack <int> a(3);
	for (int i = 0; i < 2; i++)
	{
		a.push(i);
	}
	EXPECT_EQ(0, a.full());
}
TEST(TStack, return_true_when_use_empty_on_empty_stack)
{
	TStack <int> a(3);
	EXPECT_EQ(1, a.empty());
}
TEST(TStack, return_false_when_use_empty_on_empty_stack)
{
	TStack <int> a(3);
	for (int i = 0; i < 2; i++)
	{
		a.push(i);
	}
	EXPECT_EQ(0, a.empty());
}
TEST(TStack, can_clear_stack)
{
	TStack <int> a(2);
	for (int i = 0; i < 2; i++)
	{
		a.push(i);
	}
	a.clear();
	EXPECT_EQ(1, a.empty());
}
TEST(TStack, can_assign_stack_to_itself)
{
	TStack <int> a(2);
	ASSERT_NO_THROW(a = a);
}
TEST(TStack, can_assign_stack_of_equal_size)
{
	TStack <int> a(2);
	for (int i = 0; i < 2; i++)
	{
		a.push(i);
	}
	TStack <int> b(2);
	for (int i = 0; i < 2; i++)
	{
		b.push(i+2);
	}
	b = a;
	EXPECT_EQ(1,b.pop());
	EXPECT_EQ(0, b.pop());
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack <int> a(2);
	for (int i = 0; i < 2; i++)
	{
		a.push(i);
	}TStack <int> b(3);
	for (int i = 0; i < 3; i++)
	{
		b.push(i);
	}
	b = a;
	EXPECT_EQ(1, b.pop());
	EXPECT_EQ(0, b.pop());
}


// алькул€тор

