#include <zephyr/ztest.h>
#include <cstring>
#include "MyStrings.h"

/* Add new movie, read it back and check if the data are correct (movie sucesfully added)*/
ZTEST(s14_challenge_test, test_init)
{
    MyString ms {"Karol"};
    zassert_equal(std::strcmp(ms.get_str(), "Karol"), 0, "Add movie return error!");
}

ZTEST_SUITE(s14_challenge_test, NULL, NULL, NULL, NULL, NULL);