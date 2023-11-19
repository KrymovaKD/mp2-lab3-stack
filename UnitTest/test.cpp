#include "pch.h"
#include "Stack/TStack.h"
TEST(TStack, Can_Create_Stack)
{

	ASSERT_NO_THROW(TStack<int> a);

}
TEST(TStack, Can_Create_Stack_with_positive_length)
{
	
	ASSERT_NO_THROW(TStack<int> a(5));

}
TEST(TStack, Cant_Create_Stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> a(-3));
}

