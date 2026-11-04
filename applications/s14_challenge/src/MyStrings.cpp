#include <iostream>
#include <cstring>
#include <cctype>
#include "MyStrings.h"

// No-args constructor
MyString::MyString() 
    : str{nullptr} {
}

// Overloaded constructor
MyString::MyString(const char *sin) : str{nullptr} {
    str = new char[std::strlen(sin) + 1];
    std::strcpy(str, sin);
}

// Copy constructor
MyString::MyString(const MyString& src) {
    int len = std::strlen(src.str) + 1;
    str = new char[len];
    std::strcpy(str, src.str);
}

// Move constructor
MyString::MyString(MyString&& src) noexcept
    : str {src.str} {
    src.str = nullptr;
}

// Destructor
MyString::~MyString() {
    delete [] str;
}

// Unary minus (lowercase)
MyString MyString::operator-() const{
    MyString res;

    if(this->str == nullptr) {
        return res;
    }

    res.set_str(this->str);           // Makes deep copy of origin string

    for(char *s = res.str; *s != 0; s++) {
        *s = std::tolower(*s);
    }

    return res;
}

/** @brief Equal operator
 *
 *  @param rhs right-hand side operand
 *  @return True if strings are equals, otherwise false
 */
bool MyString::operator==(const MyString& rhs) const {
    if (this->str == rhs.str) {
        return true;
    }

    if (this->str == nullptr || rhs.str == nullptr) {
        return false;
    } 

    if (std::strcmp(this->str, rhs.str)) {
        return false;
    }
    else {
        return true;
    }
}

/** @brief NOT Equal operator
 *
 *  @param rhs right-hand side operand
 *  @return True if strings are NOT equals, otherwise false
 */
bool MyString::operator!=(const MyString& rhs) const {
    return !(*this == rhs);
}

/** @brief Less than operator
 *
 *  @param rhs right-hand side operand
 *  @return true if the lhs string is lexically less than the rhs string [s1 < s2]
 */
bool MyString::operator<(const MyString& rhs) const {
    const char* s1 = this->str;
    const char* s2 = rhs.str;
    int l1 = std::strlen(s1);
    int l2 = std::strlen(s2);
    for (int i=0; i < std::min(l1, l2); i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] < s2[i]) {
                return true;
            } 
            else {
                return false;
            }
        }
    }
    return false;
}

/** @brief Greater than operator
 * 
 * @param rhs righ-hand side operand
 * @return true if the string is lexically greater than the rhs string
 */
bool MyString::operator>(const MyString& rhs) const {
    if (this->str != rhs.str) {
        int len_rhs = std::strlen(rhs.str);
        int len_this = std::strlen(this->str);

        int limit = (len_rhs >= len_this) ? len_rhs : len_this;

        for (int i=0; i<limit; i++) {
            if (this->str[i] > rhs.str[i]) {
                return true;
            }
            else if (this->str[i] < rhs.str[i]) {
                return false;
            }
        }
    }
    return false;
}

/** @brief Concatenation operator
 * 
 * @param rhs reference to MyString object ()
 * @return MyString object that concatenates both strings [s1 + s2]
 */
 MyString MyString::operator+(const MyString& rhs) const {
    const std::size_t lhs_len = (str != nullptr) ? std::strlen(str) : 0;
    const std::size_t rhs_len = (rhs.str != nullptr) ? std::strlen(rhs.str) : 0;

    MyString result;
    result.str = new char[lhs_len + rhs_len + 1];

    if (lhs_len > 0) {
        std::memcpy(result.str, str, lhs_len);
    }
    if (rhs_len > 0) {
        std::memcpy(result.str + lhs_len, rhs.str, rhs_len);
    }
    result.str[lhs_len + rhs_len] = '\0';

    return result;
 }

/** @brief Concatenate rhs and store the result in this object.
 *
 * @param rhs right-hand side operand
 * @return this object after concatenation
 */
MyString& MyString::operator+=(const MyString& rhs) {
    *this = *this + rhs;
    return *this;
}

/** @brief Multiplication for string n times
 *
 * @param n right-hand side operand
 * @return this object after concatenation
 */
MyString MyString::operator*(int n) const{
    if (n <= 0) {
        return MyString{""};
    }
    int l = std::strlen(this->str);
    char* s = new char [l * n + 1];
    for (int i=0; i<n; i++) {
        std::memcpy(s + (i*l), this->str, l);
    }
    s[l * n ] = '\0';
    MyString result{s};
    delete[] s;
    return result;
}

MyString MyString::operator*=(int n) {
    *this = *this * n;
    return *this;
}

// Copy assigment
MyString& MyString::operator=(const MyString &rhs) {
    if (this == &rhs) {
        return *this;
    }
    
    delete [] this->str;                                // delete old pointer (deallocate memory)
    (*this).str = new char[std::strlen(rhs.str) + 1];      // allocate new memory
    std::strcpy(this->str, rhs.str);                  // copy data

    return *this;
}

// Move assigment
MyString& MyString::operator=(MyString &&rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] str; 
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

// Display method
void MyString::display() const{
    std::cout << str << std::endl;
}

// Getters
const char *MyString::get_str() const{
    return this->str;
}

/** @brief Function set new string. It also handles the situation where the caller
 *        wants to replace string using old (the same) value. 
 *
 *  @param s new value for the string
 */
void MyString::set_str(const char* s) {
    char *replacement = new char[std::strlen(s) + 1];       // allocate new memory
    std::strcpy(replacement, s);                            // copy current value

    delete [] str;          // deallocate previous memory
    str = replacement;      // set new string
    
}