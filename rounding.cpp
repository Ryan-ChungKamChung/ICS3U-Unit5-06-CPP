// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in January 2021
// Program rounds numbers

#include <iostream>
#include <string>
#include <cmath>


void rounding(float &number, int decimal) {
    // Rounds user input to chosen amount of decimal values

    // https://userweb.cs.txstate.edu/~br02/cs1428/SupportFiles/
    // Programming/TypeCasting.htm#:~:text=When%20converting%20
    // a%20floating%2Dpoint,int(17.6)%20%3D%2017.
    number = (static_cast<float>(static_cast<int>(number * pow(10, decimal)
              + 0.5)) / pow(10, decimal));
}


int main() {
    // Takes user input, passes it to functions and calls them

    std::string number_string;
    std::string decimal_string;
    float number;
    int decimal;

    std::cout << "I round off numbers!" << std::endl;

    // Input
    while (true) {
        std::cout << "Enter number: ";
        std::cin >> number_string;
        try {
            // https://www.cplusplus.com/reference/string/stof/
            number = std::stof(number_string);
            break;
        } catch (std::invalid_argument) {
            std::cout << "This isn't a valid input" << std::endl;
        }
    }

    while (true) {
        std::cout << "How many decimals would you like me to round to? ";
        std::cin >> decimal_string;
        try {
            decimal = std::stoi(decimal_string);

            if (decimal <= 0) {
                throw std::invalid_argument("This isn't a valid input");
            }
            break;
        } catch (std::invalid_argument) {
            std::cout << "This isn't a valid input" << std::endl;
        }
    }

    // Calls functions
    rounding(number, decimal);

    // Output
    std::cout << number << std::endl;
}
