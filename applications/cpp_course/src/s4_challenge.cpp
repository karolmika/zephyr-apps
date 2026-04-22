#include <iostream>

void favorite_number_challenge()
{
    int favorite_number;

    std::cout << "Enter your favorite number from 1 to 100: ";
    std::cin >> favorite_number;

    bool is_valid = (favorite_number >= 1) && (favorite_number <= 100);
    
    if (!is_valid) {
        std::cout << "Sorry, that's not a valid number. Please enter a number between 1 and 100." << std::endl;
        return;
    }
    std::cout << "Amazing!! That's my favorite number too!" << std::endl;
    std::cout << "No really! " << favorite_number << " is my favorite number too!" << std::endl;
}