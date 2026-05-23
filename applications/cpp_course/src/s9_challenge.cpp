#include <iostream>
#include <vector>

using namespace std;

/* -----------------------
 * Function prototypes
 ------------------------*/

/** @brief Finds the minimum number in a vector 
*   @param numbers A reference to a vector of integers from which the minimum number will be found
*/
void min_number(const vector<int> &numbers);

/** @brief Finds the maximum number in a vector 
*   @param numbers A reference to a vector of integers from which the maximum number will be found
*/
void max_number(const vector<int> &numbers);

/** @brief Adds a new number to the vector
*   @param numbers A reference to a vector of integers from which the maximum number will be found
*/
void add_number(vector<int> &numbers);

/** @brief Calculates the average value of the numbers in the vector
*   @param numbers A reference to a vector of integers for which the average will be calculated
*/
void average_value(const vector<int> &numbers);

/** @brief Prints all numbers in the vector
*   @param numbers A reference to a vector of integers from which the maximum number will be found
*/
void print_numbers(const vector<int> &numbers);

/** @brief Checks the user input and calls the corresponding function
*   @param letter The user input character that will be checked
*   @param numbers A reference to a vector of integers that will be passed to the corresponding function based on the user input
*/
void check_input(char letter, vector<int> &numbers);

/** @brief Runs the list challenge, allowing the user to interact with a list of numbers */
void run_list_challenge();

/** @brief Handles the quit option, setting the quit_selected flag to true to exit the program */
void handle_quit_option();

/* -----------------------
 * Function definitions
 ------------------------*/ 

void run_list_challenge()
{
    bool quit_selected = false;
    vector<int> list_of_numbers;

    list_of_numbers.push_back(1);
    list_of_numbers.push_back(2);
    list_of_numbers.push_back(3);

    while(false == quit_selected)
    {
        cout << "Select you option:" << endl << endl;

        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit"  << endl << endl;

        cout << "Enter your choice: ";

        char input;
        cin >> input;
        // cout << "input(debug): " << input << endl;

        check_input(toupper(input), list_of_numbers);
    }
}

void min_number(const vector<int> &numbers)
{
    int min_val = numbers.at(0);

    for (size_t i = 0; i < numbers.size(); ++i) {
        if( numbers.at(i) < min_val)
        {
            min_val =  numbers.at(i);
        }
    };
    cout << "Min value: " << min_val << endl;
}

void max_number(const vector<int> &numbers)
{
    int max_val = numbers.at(0);

    for (size_t i = 0; i < numbers.size(); ++i) {
        if( numbers.at(i) > max_val)
        {
            max_val =  numbers.at(i);
        }
    };
    cout << "Max value: " << max_val << endl;
}

void add_number(vector<int> &numbers)
{
    int new_number;

    cout << "Inser new number: ";
    cin >> new_number;
    numbers.push_back(new_number);
    cout << "New number was added!" << endl;
}

void average_value(const vector<int> &numbers)
{
    int sum = 0;
    int cnt = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        sum += numbers.at(i);
        cnt++;
    };

    int avg = (sum / cnt);
    cout << "Average value: " << avg << "." << (avg%10) << endl;
}

void print_numbers(const vector<int> &numbers)
{
    cout << "Printing numbers: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers.at(i) << " ";
    };
    cout << endl;
}

void check_input(char letter, vector<int> &numbers)
{
    switch(letter){
        case 'P':
            print_numbers(numbers);
            break;
        case 'A':
            add_number(numbers);
            break;
        case 'M':
            average_value(numbers);
            break;
        case 'S':
            min_number(numbers);
            break;
        case 'L':
            max_number(numbers);
            break;
        case 'Q':
            handle_quit_option();
            break;
        default:
            cout << "Unknown option!" << endl;
    }
}

void handle_quit_option()
{
    cout << "Quitting the program. Goodbye!" << endl;
    exit(0);
}

