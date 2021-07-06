//unittest will be added here
#include"unity_internals.h"
#include"unity.h"
#include"bank.h"

void setUp(void)
{
}
void tearDown(void)
{
}

void test_interest(){
    TEST_ASSERT_EQUAL(10, interest(1,1000,1));
}
int main(){
    UNITY_BEGIN();
    RUN_TEST(test_interest);
    return (UNITY_END());
}