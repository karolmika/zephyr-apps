#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString {
    private:
        char *str;

    public:
        MyString();                         // Constructor
        MyString(const char *s);            // Overloaded constructor
        MyString(const MyString& src);      // Copy constructor
        MyString(MyString&& src);           // Move constructor
        ~MyString();                        // Destructor

        MyString operator-() const;                     // unary minus (lowercase)
        bool operator==(const MyString& rhs) const;     // Equal operator
        bool operator!=(const MyString& rhs) const;     // NOT Equal operator
        bool operator<(const MyString& rhs) const;      // Less than
        bool operator>(const MyString& rhs) const;      // Greater
        MyString operator+(const MyString& rhs) const;  // Concatenation
        MyString& operator+=(const MyString& rhs);      // Concatenation and store
        MyString operator*(int n) const;                // Multiplication n times
        MyString operator*=(int n);                // Multiplication and store

        MyString &operator=(const MyString &rhs);   // Copy assignment
        MyString &operator=(MyString &&rhs);        // Move assignment

        void display() const;               // const allows call display() on const objects
        const char *get_str() const;
        int get_length() const;
        void set_str(const char* s);
};

#endif //_MYSTRING_H_