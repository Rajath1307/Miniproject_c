

#include "unity.h"
#include "testlog.h"


void setUp()
{

}
void tearDown()
{

}

void test_login_correct(void)
{
    TEST_ASSERT_EQUAL(1,login(105305,105305));
}

void test_login_wrong(void)
{
    TEST_ASSERT_EQUAL(2,login(105305,105304));
}

void rent_correct_fir(void)
{
     TEST_ASSERT_EQUAL(1,addrecord(9,"Raj","23","male","60","120a"));
     TEST_ASSERT_EQUAL(1,addrecord(10,"tej","42","male","120","304c"));
     TEST_ASSERT_EQUAL(1,addrecord(11,"sham","47","male","78","420"));
}

void search_correct_fir(void)
{
    TEST_ASSERT_EQUAL(1,search(9));
}

void search_wrong_fir(void)
{
    TEST_ASSERT_EQUAL(2,search(25));
}

void delete_correct_fir(void)
{
    TEST_ASSERT_EQUAL(1,addrecord(6,"roj","34","fem","77","44"));
    TEST_ASSERT_EQUAL(1,delet(9));
}
void delete_wrong_fir(void)
{
    TEST_ASSERT_EQUAL(2,delet(25));
}

void edit_correct_fir(void)
{
    TEST_ASSERT_EQUAL(1,edit(6,"rj","34","fem","77","44"));

}

void edit_wrong_fir(void)
{
    TEST_ASSERT_EQUAL(2,edit(25,"old","77","fem","69","777"));
}

void view_correct(void)
{
    TEST_ASSERT_EQUAL(1,view(9));
}
int test_main(void)
{

    UNITY_BEGIN();
    RUN_TEST(test_login_correct);
    RUN_TEST(test_login_wrong);
    RUN_TEST(rent_correct_fir);
    RUN_TEST(search_correct_fir);
    RUN_TEST(delete_correct_fir);
    RUN_TEST(delete_wrong_fir);
    RUN_TEST(edit_correct_fir);
    RUN_TEST(edit_wrong_fir);
    RUN_TEST(view_correct);
    return UNITY_END();
}
