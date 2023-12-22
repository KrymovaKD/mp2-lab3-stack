#include "pch.h"
#include "Stack/TCalc.h"
TEST(TCalc, can_create_calculator)
{
	ASSERT_NO_THROW(TCalc math1("1+1"));
}
TEST(TCalc, cant_create_calculator_with_incorrect_brackets)
{
	ASSERT_ANY_THROW(TCalc math1("(1+1"));
}
TEST(TCalc, cant_create_calculator_with_incorrect_symbol)
{
	ASSERT_ANY_THROW(TCalc math1("%+1"));
}
TEST(TCalc, can_create_calculator_with_large_num)
{
	ASSERT_NO_THROW(TCalc math1("10000+250"));
}
TEST(TCalc, can_create_a_default_calculator)
{
	ASSERT_NO_THROW(TCalc math1());
}
TEST(TCalc, can_get_and_set_infix_form_of_calculator)
{
	TCalc math1("1");
	ASSERT_NO_THROW(math1.SetInfix("2+3-4"));
	EXPECT_EQ("2+3-4", math1.GetInfix());
}
TEST(TCalc, can_get_correct_postfix)
{
	TCalc math1("(1+2)*3");
	ASSERT_NO_THROW(math1.ToPostfix());
	EXPECT_EQ("12+3*", math1.GetPostfix());
}
/*TEST(TCalc, cant_get_correct_postfix_with_inccorect_brackets)
{
	TCalc math1("(1+2))*3");
	ASSERT_ANY_THROW(math1.ToPostfix());
	EXPECT_NE("12+3*", math1.GetPostfix());
}*/
TEST(TCalc, can_to_count_the_expression)
{
	TCalc math1("(1+2)*3");
	double res = 0;
	ASSERT_NO_THROW(res = math1.Calc());
	EXPECT_EQ(9, res);
}
TEST(TCalc, can_to_count_an_expression_with_large_numbers)
{
	TCalc math1("(18+200)*30");
	double res = 0;
	ASSERT_NO_THROW(res = math1.Calc());
	EXPECT_EQ(6540, res);
}
TEST(TCalc, cant_to_count_an_expression_divided_by_zero)
{
	TCalc math1("(18+200)/0");
	ASSERT_ANY_THROW(math1.Calc());
}
TEST(TCalc, can_to_count_an_postfix_expression)
{
	TCalc math1("(1+2)*3");
	math1.ToPostfix();
	double res = 0;
	ASSERT_NO_THROW(res=math1.CalcPostfix());
	EXPECT_EQ(9, res);
}