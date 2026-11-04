# Section 14 challenge

Operator overloading.
Overload the following operators in the provided MyString class.
Do this challenge twice. First, overload the operators using member
functions and then in another project overload the same operators 
again using non-member functions.

Please do it once using member metods and then using non-member function.

Here is a list of some of the operators that you can overload for this class:
- unary minus(-): returns the lowercase version of the object's string [-s1]
- equal (==): returns true if two string are equal [s1 == s2]
- not equal (!=): returns true if the two string are not equal [s1 != s2]
- less than (<): returns true if the lhs string is lexically less than the rhs string [s1 < s2]
- greater than (>): returns true if the string is lexically greater than the rhs string
- concatenation (+): returns object that concatenates both strings [s1 + s2]
- concatenation and store (+=): concatenate the rhs string to the lhs string and store the result in lhs object
- repeat (*): return string that is copied n times [s1*n]
- repeat and store (*=): copy the rhs string n times and store the result in lhs object

Hints:
- take advantage of the std::strcmp function for the equality operators
- the += and *= operators should return a Mystring &
- rather than duplicate code in the += and *= functions, use the + and * operator which you have already overloaded