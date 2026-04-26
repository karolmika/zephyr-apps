#include <iostream>
#include <vector>

using namespace std;

void vectors_challenge()
{
    // Declare 2 empty vectors of integers
    vector<int> vector1;
    vector<int> vector2;

    // Add 10 and 20 to vector1 dynamically 
    vector1.push_back(10);
    vector1.push_back(20);

    // Display the elements in vector 1 using at() and size()
    cout << "Elements in vector1:" << endl;
    for (size_t i = 0; i < vector1.size(); ++i) {
        cout << "Element " << (i + 1) << ": " << vector1.at(i) << endl;
    }

    // Add 100 and 200 to vector2 dynamically
    vector2.push_back(100);
    vector2.push_back(200);

    // Display the elements in vector 2 using at() and size()
    cout << "Elements in vector2:" << endl;
    for (size_t i = 0; i < vector2.size(); ++i) {
        cout << "Element " << (i + 1) << ": " << vector2.at(i) << endl;
    }

    // Declare an empty 2D vector of integers
    vector <vector<int>> vector_2d;

    // Add vector1 and vector2 to the 2D vector
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);   

    // Display the elements in the 2D vector using at() and size()
    cout << "Elements in vector_2d:" << endl;
    for (size_t i = 0; i < vector_2d.size(); ++i) {
        cout << "Vector " << (i + 1) << ":" << endl;
        for (size_t j = 0; j < vector_2d.at(i).size(); ++j) {
            cout << "Element " << (j + 1) << ": " << vector_2d.at(i).at(j) << endl;
        }
    }

    // Change vector1.at(0) to 1000
    vector1.at(0) = 1000;   

    // Display the elements of vector1 and check what happend
    cout << "Elements in vector1 after modification:" << endl;
    for (size_t i = 0; i < vector1.size(); ++i) {
        cout << "Element " << (i + 1) << ": " << vector1.at(i) << endl;
    }

    // Display the elements in the 2D vector using at() and size()
    cout << "Elements in vector_2d after modification:" << endl;
    for (size_t i = 0; i < vector_2d.size(); ++i) {
        cout << "Vector " << (i + 1) << ":" << endl;
        for (size_t j = 0; j < vector_2d.at(i).size(); ++j) {
            cout << "Element " << (j + 1) << ": " << vector_2d.at(i).at(j) << endl;
        }
    }
}