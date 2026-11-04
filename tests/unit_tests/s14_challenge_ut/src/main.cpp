#include <zephyr/ztest.h>
#include <cstring>
#include <utility>
#include "MyStrings.h"

ZTEST(s14_challenge_test, test_no_args_constructor) {
    MyString ms;
    zassert_is_null(ms.get_str(), "No arg constructor failed");
}

ZTEST(s14_challenge_test, test_overloaded_constructor) {
    MyString ms {"Karol"};
    zassert_equal(std::strcmp(ms.get_str(), "Karol"), 0, "Overloaded constructor failed");
}

ZTEST(s14_challenge_test, test_copy_constructor) {
    MyString ms1{"Hello"};
    MyString ms2{ms1};
    zassert_equal(std::strcmp(ms2.get_str(), "Hello"), 0, "Copy constructor failed");
}

ZTEST(s14_challenge_test, test_move_constructor) {
    MyString s1{"Program"};
    const char* origin = s1.get_str();
    MyString s2{std::move(s1)};

    zassert_equal(std::strcmp(s2.get_str(), origin), 0, "Move constructor did not transfer ownership");
    zassert_is_null(s1.get_str(), "Src ptr was not cleard");
    zassert_equal(std::strcmp(s2.get_str(), "Program"), 0, "Moved string contents are incorrect");
}

/* Set string make deep copy*/
ZTEST(s14_challenge_test, test_set_string) {
    MyString s{"Jack"};
    s.set_str("Ryan");

    int res = std::strcmp(s.get_str(), "Ryan");
    zassert_equal(res, 0, "Set string is not working");
}

/* unary minus returns the lowercase version of the object's string*/
ZTEST(s14_challenge_test, test_unary_minus_operator) {
    MyString s1{"TEST"};
    MyString s2;

    s2 = -s1;
    int res1 = std::strcmp(s1.get_str(), "TEST");
    int res2 = std::strcmp(s2.get_str(), "test");
    zassert_equal(res1, 0, "Unary minus operator should not modify the origin string");
    zassert_equal(res2, 0, "Unary minus operator not working");
}

/* equal (==): returns true if two string are equal [s1 == s2] */
ZTEST(s14_challenge_test, test_equal_operator) {
    MyString s1{"cpp"};
    MyString s2{"cpp"};
    MyString s3{"ppc"};

    bool res1 = (s1 == s2);
    bool res2 = (s1 == s3);

    zassert_true(res1,"Strings should be equal");
    zassert_false(res2, "Strings are not equal");
}

/* NOT equal (!=): returns true if two string are NOT equal [s1 != s2] */
ZTEST(s14_challenge_test, test_not_equal_operator) {
    MyString s1{"test"};
    MyString s2{"test"};
    MyString s3{"hello"};

    bool res1 = (s1 != s2);
    bool res2 = (s1 != s3);

    zassert_false(res1,"Strings should be equal");
    zassert_true(res2, "Strings are not equal");
}
/* less than (<): returns true if the lhs string is lexically less than the rhs string [s1 < s2] */
ZTEST(s14_challenge_test, test_less_than_operator) {
    MyString s1{"Adam"};
    MyString s2{"Beata"};
    MyString s3{"Henryk"};

    bool res1 = (s1 < s2);
    bool res2 = (s3 < s2);

    zassert_true(res1, "Less than should succed.");
    zassert_false(res2, "Less than should fail.");
}
/* greater than (>): returns true if the string is lexically greater than the rhs string */
ZTEST(s14_challenge_test, test_greater_than_operator) {
    MyString s1{"Kuba"};
    MyString s2{"Dawid"};
    MyString s3{"Cezary"};

    bool res1 = (s1 > s2);
    bool res2 = (s3 > s2);

    zassert_true(res1, "Greater than should succed.");
    zassert_false(res2, "Greater than should fail.");
}
/* concatenation (+): returns object that concatenates both strings [s1 + s2] */
ZTEST(s14_challenge_test, test_concatenation_operator) {
    MyString first_part{"hello"};
    MyString second_part{"world"};

    MyString both = first_part + second_part;

    int res = std::strcmp(both.get_str(), "helloworld");
    zassert_equal(res, 0, "Concatenation is not working");
}

/* concatenation and store (+=): concatenate the rhs string to the lhs string and store the result in lhs object */
ZTEST(s14_challenge_test, test_concatenation_and_store) {
    MyString first_part{"one"};
    MyString second_part{"two"};

    first_part += second_part;
    int res = std::strcmp(first_part.get_str(), "onetwo");
    zassert_equal(res, 0, "Concatenation and store is not working");
}

/* repeat (*): return string that is copied n times [s1*n] */
ZTEST(s14_challenge_test, test_repeat_n_times) {
    MyString test_str{"abcd"};
    MyString result{};

    result = test_str * 3;
    int res = std::strcmp("abcdabcdabcd", result.get_str());
    zassert_equal(res, 0, "Multiplication is not working");
}

/* repeat and store (*=): copy the rhs string n times and store the result in lhs object */
ZTEST(s14_challenge_test, test_repeat_and_store) {
    MyString test_str{"abcd"};

    test_str *= 3;
    int res = std::strcmp("abcdabcdabcd", test_str.get_str());
    zassert_equal(res, 0, "Multiplication is not working");
}

ZTEST_SUITE(s14_challenge_test, NULL, NULL, NULL, NULL, NULL);