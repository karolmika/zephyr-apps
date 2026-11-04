#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString {
    private:
        char *str;

    public:
        MyString();                         // Constructor
        MyString(const char *s);            // Overloaded constructor
        MyString(const MyString &src);      // Copy constructor
        MyString(MyString &&src);           // Move constructor
        ~MyString();                        // Destructor

        void display() const;               // const allows call display() on const objects
        const char *get_str() const;
        int get_length() const;
};

#endif //_MYSTRING_H_