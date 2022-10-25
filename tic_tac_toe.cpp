//
// Created by Andreas N on 10/24/2022.
//

#include <iostream>

struct tic_tac_toe {
    int points[9] = { 0b000000001, 0b000000010, 0b000000100,
                      0b000001000, 0b000010000, 0b000100000,
                      0b001000000, 0b010000000, 0b100000000 };

    bool place[9] = { false, false, false, false, false,
                      false, false, false, false };

    char signature[9] = { '1', '2', '3', '4',  '5',  '6',
                          '7',  '8', '9' };

    int mask[8] = { 0b100010001, 0b001010100, 0b001001001, 0b010010010, 0b100100100, 0b000000111,
                    0b000111000, 0b111000000 };
};

void table(struct tic_tac_toe& game);

int main() {

    struct tic_tac_toe game;

    bool koniec = false;
    bool ukoncenie = false;
    char temp;
    int hodnota;


    for (int i = 0; i < 10; i++) {

        table(game);

        if (i > 8) { break; }
        else if (!koniec) {

            if (i % 2 == 0) { // X is always first
                while (true) {
                    std::cout << "Zadaj volnu poziciu [1-9] pre X: ";
                    std::cin >> hodnota;
                    if (!game.place[hodnota - 1] && (9 >= hodnota && hodnota > 0)) {
                        game.place[hodnota - 1] = true;
                        game.signature[hodnota - 1] = 'X';
                        break;
                    }
                }
                std::cout << std::endl;
            }
            else {
                while (true) {
                    std::cout << "Zadaj volnu poziciu [1-9] pre O: ";
                    std::cin >> hodnota;
                    if (!game.place[hodnota - 1] && (9 >= hodnota && hodnota > 0)) {
                        game.place[hodnota - 1] = true;
                        game.signature[hodnota - 1] = 'O';
                        break;
                    }
                }
                std::cout << std::endl;
            }
            for (int k = 0; k < 2; k++) {
                if (ukoncenie) { break; } // ends cycle
                else if (k == 0) { temp = 'O'; } // character swap
                else { temp = 'X'; }

                for (int j = 0; j < 8; j++) {
                    int kontrolovanie = game.mask[j];

                    for (int l = 0; l < 9; l++) {
                        if (game.signature[l] == temp) {                            // checks for same character
                            if ((game.mask[j] ^ game.points[l]) < game.mask[j]) {   // mask matches if lower
                                kontrolovanie = (kontrolovanie ^ game.points[l]);
                                if (kontrolovanie == 0) { // mask matches with location of character (X,O)
                                    koniec = true;
                                    ukoncenie = true;
                                    break;
                                }
                            }
                        }
                    }

                }
            }
        }
    }

    if (koniec) { // end title
        std::cout << "Vyhral hrac: " << temp << std::endl;
    }
    else { std::cout << "Nikto nevyhral." << std::endl; }

    return 0;
}

void table(struct tic_tac_toe& game) { //function for printing table

    std::cout << game.signature[0] << " | " << game.signature[1] << " | " << game.signature[2] << std::endl;
    std::cout << game.signature[3] << " | " << game.signature[4] << " | " << game.signature[5] << std::endl;
    std::cout << game.signature[6] << " | " << game.signature[7] << " | " << game.signature[8] << std::endl;
    std::cout << std::endl;
}