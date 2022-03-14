#include "pch.h"
#include "../Lab-Polynomials/TPolinom.h"
#include "../Lab-Polynomials/TMonom.h"
#include <iostream>

//+=+=+=+=+=+=+=+=+=+=+=+ - - - Tests for TPolinom - - - +=+=+=+=+=+=+=+=+=+=+=+//
TEST(TPolinom, Created_polinom_is_empty) {
	TPolinom TPolinom;

	EXPECT_TRUE(TPolinom.IsEmpty());
}


TEST(TPolinom, can_pack_similar_degrees) {
	TPolinom TPolinom;
	TPolinom.AddMonom(TMonom(1, 1, 1, 1));
	TPolinom.AddMonom(TMonom(2, 1, 1, 1));
	TPolinom.AddMonom(TMonom(3, 1, 1, 1));
	TPolinom.Reset();
	EXPECT_TRUE(TPolinom.GetLength() == 1 && TPolinom.GetCurr().coef == 6);
}

TEST(TPolinom, can_dont_pack_if_degrees_are_different) {
	TPolinom TPolinom;
	TPolinom.AddMonom(TMonom(1, 1, 1, 1));
	TPolinom.AddMonom(TMonom(2, 2, 1, 1));
	TPolinom.AddMonom(TMonom(3, 3, 1, 1));
	TPolinom.Reset();
	EXPECT_TRUE(TPolinom.GetLength() == 3);
}

TEST(TPolinom, can_pack_similar_and_delete) {
	TPolinom TPolinom;
	TPolinom.AddMonom(TMonom(1, 1, 1, 1));
	TPolinom.AddMonom(TMonom(-1, 1, 1, 1));
	EXPECT_TRUE(TPolinom.IsEmpty());
}

TEST(TPolinom, can_not_get_monom_from_empty_polinom) {
	TPolinom TPolinom;

	EXPECT_ANY_THROW(TPolinom.GetCurr());
}

TEST(TPolinom, can_make_a_copy_of_polinom) {
	bool result = true;
	TPolinom copiable;
	copiable.AddMonom(TMonom(-1, 1, 1, 1));
	copiable.AddMonom(TMonom(2, 1, 1, 2));
	copiable.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom copied(copiable);
	EXPECT_TRUE(copied == copiable);
}


TEST(TPolinom, can_sum_polinoms) {
	TPolinom _res; _res.AddMonom(TMonom(4, 1, 1, 2)); _res.AddMonom(TMonom(6, 1, 2, 1));
	TPolinom polinom1;
	polinom1.AddMonom(TMonom(-1, 1, 1, 1));
	polinom1.AddMonom(TMonom(2, 1, 1, 2));
	polinom1.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom polinom2;
	polinom2.AddMonom(TMonom(1, 1, 1, 1));
	polinom2.AddMonom(TMonom(2, 1, 1, 2));
	polinom2.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom result = polinom1 + polinom2;
	

	EXPECT_TRUE(result==_res);
}

TEST(TPolinom, can_mult_const_to_polinom) {
	TPolinom p;
	p.AddMonom(TMonom(-1, 1, 1, 1));
	p.AddMonom(TMonom(2, 1, 1, 2));
	TPolinom res;
	res.AddMonom(TMonom(-2, 1, 1, 1));
	res.AddMonom(TMonom(4, 1, 1, 2));
	EXPECT_TRUE(p * 2 == res);
}

TEST(TPolinom, can_monom_multiply) {
	TPolinom p;
	p.AddMonom(TMonom(1, 1, 1, 1));
	p.AddMonom(TMonom(-1, 2, 2, 2));
	TPolinom res;
	res.AddMonom(TMonom(2, 2, 3, 4));
	res.AddMonom(TMonom(-2, 3, 4, 5));
	EXPECT_TRUE(p.MultMonom(TMonom(2, 1, 2, 3)) == res);
}


TEST(TPolinom, can_mult_polinom) {

	TPolinom p;
	p.AddMonom(TMonom(1, 1, 2, 0));
	TPolinom res;
	res.AddMonom(TMonom(1, 2, 4, 0));
	
	EXPECT_TRUE(p * p == res);
}
//+=+=+=+=+=+=+=+=+=+=+=+ - - - Tests for TMonom - - - +=+=+=+=+=+=+=+=+=+=+=+//

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, can_ins_monom_with_pos_coef)
{
	TMonom m;
	m.x = 0;
	m.y = 0;
	m.z = 0;
	ASSERT_NO_THROW(m.coef = 1);
}

TEST(TMonom, can_ins_monom_with_neg_coef)
{
	TMonom m;
	m.x = 0;
	m.y = 0;
	m.z = 0;
	ASSERT_NO_THROW(m.coef = -1);
}



TEST(TMonom, can_compare_the_monom)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;
	m2.coef = 7;
	m2.x = 1;
	m2.y = 1;
	m2.z = 1;
	EXPECT_EQ(m1 == m2, 1);
}

TEST(TMonom, can_compare_the_monoms)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;
	m2.coef = 7;
	m2.x = 1;
	m2.y = 2;
	m2.z = 3;
	EXPECT_EQ(m1 != m2, true);
}

TEST(TMonom, can_compare)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;
	m2.coef = 7;
	m2.x = 1;
	m2.y = 2;
	m2.z = 3;
	EXPECT_EQ(m1 < m2, true);
	EXPECT_EQ(m1 > m2, false);
}

//+=+=+=+=+=+=+=+=+=+=+=+ - - - Tests for THeadList - - - +=+=+=+=+=+=+=+=+=+=+=+//


TEST(THeadList, can_create_list)
{
	ASSERT_NO_THROW(true, THeadList<int> list);
}
TEST(THeadList, can_insert_first)
{
	THeadList<int> list;

	ASSERT_NO_THROW(true, list.InsFirst(1));
}
TEST(THeadList, can_del_first)
{
	THeadList<int> list;
	list.InsFirst(1);
	ASSERT_NO_THROW(true, list.DeleteFirst);
}
TEST(THeadList, can_insert_last)
{
	THeadList<int> list;

	ASSERT_NO_THROW(true, list.InsLast(1));
}
TEST(THeadList, can_del_last)
{
	THeadList<int> list;
	list.InsFirst(1);
	ASSERT_NO_THROW(true, list.DeleteLast);
}
TEST(THeadList, can_insert_current)
{
	THeadList<int> list;
	list.InsFirst(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsLast(4);

	ASSERT_NO_THROW(true, list.InsCurrent(0));
}
TEST(THeadList, can_delete_current)
{
	THeadList<int> list;
	list.InsFirst(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsLast(4);
	ASSERT_NO_THROW(true, list.DelCurr());
}
TEST(THeadList, cant_delete_first_in_empty_list)
{
	THeadList<int> list;
	ASSERT_ANY_THROW(list.DelFirst());
}
TEST(THeadList, cant_delete_current_in_empty_list)
{
	THeadList<int> list;
	ASSERT_ANY_THROW(list.DelCurr());
}