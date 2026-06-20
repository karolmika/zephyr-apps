#include <iostream>
#include <string>

using namespace std;

void show_array(const int *array, size_t s);
int *apply_all(const int *array1, size_t s1, const int *array2, size_t s2);

void multiply_arrays(void)
{
    const size_t  array1_size { 5 };
    const size_t  array2_size { 3 };

    int array1[array1_size] { 1, 2, 3, 4, 5 };
    int array2[array2_size] { 10, 20, 30 };

    cout << "Array 1: ";
    show_array(array1, array1_size);

    cout << "Array 2: ";
    show_array(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    size_t results_size = array1_size * array2_size;

    if(NULL != results)
    {
        cout << "Result: ";
        show_array(results, results_size);
        delete [] results;
    }
    
    cout << endl;
}

void show_array(const int *array, size_t s)
{
    cout << "[ ";
    for (size_t i = 0; i < s; ++i)
    {
        cout << array[i] << " ";
    }
    cout << "]";
    cout << endl;
}

int *apply_all(const int *array1, size_t s1, const int *array2, size_t s2)
{
    int *array3 {};
    array3 = new int[s1*s2];

    if (NULL == array3) {
        cout << "Error when allocating memory" << endl;
        return NULL;
    }

    int p {0};
    for(size_t i=0; i < s2; i++){
        for(size_t j=0; j < s1; j++){
            array3[p++] = array1[j] * array2[i];
        }
    }
    return array3;
}