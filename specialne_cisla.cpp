//
// Created by Andreas N on 10/19/2022.
//
/**
 * This project checks if integral number with numbers (4,7), are divisible by input 'n'
 * Output: Number from 47 to 974
 */

#include <iostream>
#include <string>

int main() {
    int n = 0;
    std::cin >> n;

    for ( int i = 1; i <= 974; i++) { // main cycle

        std::string tempS = std::to_string(i); // int to string
        int dlzka = tempS.length();

        for (int j = 0; j < dlzka; j++) { // if it founds 4, it goes to another for loop
            bool kontrola = false; // control for condition
            if (tempS[j] == '4') {

                for (int l = 0; l < dlzka; l++) {
                    if (tempS[l] == '7') {
                        kontrola = true;
                        break;
                    }
                }
                if (kontrola) { // if success, it checks for 0, divisibility integral numbers
                    if ( i % n == 0) {
                        std::cout << tempS << std::endl;
                        return 0;
                    }
                    break; // not success, it repeats the main cycle
                }
            }
        }

        if (1000 == i) { std::cout << "Nenasiel" << std::endl; } // no matching number
    }

    return 0;
}