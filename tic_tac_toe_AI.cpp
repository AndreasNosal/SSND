//
// Created by Andreas N on 10/25/2022.
//
//
// Never forget to analyze the problem!

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
void AI_tic_tac_toe(int &pocet, bool &polozil, struct tic_tac_toe& game);

int main() {

    struct tic_tac_toe game;

    bool koniec = false;        // end of game
    bool ukoncenie = false;     // breaks algorithm for end
    bool polozil;               // checks AI if position is free to use
    char temp;                  // player sign
    int hodnota;                // player input
    int pocet;                  // warning for AI


    for (int i = 0; i < 5; i++) {

        table(game);

        //if (i > 4) { break; } // game begins here, four times
        if (!koniec) {

            while (true) { // input
                std::cout << "Zadaj volnu poziciu [1-9] pre X: ";
                std::cin >> hodnota;
                if (!game.place[hodnota - 1] && (9 >= hodnota && hodnota > 0)) {
                    game.place[hodnota - 1] = true;
                    game.signature[hodnota - 1] = 'X';
                    break;
                }
            }
            std::cout << std::endl;

            polozil = false; // must be set to false, after AI has chosen the place

            for (int k = 0; k < 2; k++) { // swaping character
                if (ukoncenie) { break; } // ends cycle
                else if (k == 0) { temp = 'O'; } // character swap
                else { temp = 'X'; }

                for (int j = 0; j < 8; j++) { // 8 masks
                    int kontrolovanie = game.mask[j];

                    pocet = 0;

                    for (int l = 0; l < 9; l++) {
                        if (game.signature[l] == temp) {                            // checks for same character
                            if ((game.mask[j] ^ game.points[l]) < game.mask[j]) {   // mask matches if lower (0)
                                pocet++;  // warning for AI
                                kontrolovanie = (kontrolovanie ^ game.points[l]);
                                if (kontrolovanie == 0) { // mask matches with location of character (X,O)
                                    koniec = true;
                                    ukoncenie = true;
                                    break;
                                }
                            }
                        }
                        if (temp == 'X') {
                            if (pocet == 2 && !polozil) { // if warning 2, algorithm tries to block the player (from win)
                                for (int p = 0; p < 9; p++) {
                                    if (0 == (game.points[p] ^ kontrolovanie)) {
                                        if (!game.place[p]) {
                                            game.place[p] = true;
                                            game.signature[p] = 'O';
                                            polozil = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (pocet == 2 && !polozil) { // if warning 2, algorithm tries to WIN
                                for (int p = 0; p < 9; p++) {
                                    if (0 == (game.points[p] ^ kontrolovanie)) {
                                        if (!game.place[p]) {
                                            game.place[p] = true;
                                            game.signature[p] = 'O';

                                            polozil = true;
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
        }
        // AI algorithm
        AI_tic_tac_toe(pocet, polozil, game);
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

void AI_tic_tac_toe(int &pocet, bool &polozil, struct tic_tac_toe& game) {
    // AI algorithm
    // all masks checked
    if (!game.place[4] && !polozil) {   // checks if most important position is empty
        game.place[4] = true;           // most important position '5'
        game.signature[4] = 'O';
        polozil = true;
    }
    else if (game.signature[4] == 'O') { // if position 5 is taken by O
        if (((game.signature[0] == 'X') || (game.signature[8] == 'X')) && !polozil) {
            if (!game.place[5]) {
                game.place[5] = true;
                game.signature[5] = 'O';
                polozil = true;
            }
            else if (!game.place[7]) {
                game.place[7] = true;
                game.signature[7] = 'O';
                polozil = true;
            }
        }
        if ((game.signature[3] == 'X') || (game.signature[8] == 'X') && !polozil) {
            if (!game.place[0]) {
                game.place[0] = true;
                game.signature[0] = 'O';
                polozil = true;
            }
            else if (!game.place[8]) {
                game.place[8] = true;
                game.signature[8] = 'O';
                polozil = true;
            }
        }
        else if (!game.place[1] && !polozil) {
            game.place[1] = true;
            game.signature[1] = 'O';
            polozil = true;
        }
        else if (!game.place[7] && !polozil) {
            game.place[7] = true;
            game.signature[7] = 'O';
            polozil = true;
        }
        else if (!polozil) {
            for (int c = 0; c < 9; c++) { // no more tactical places
                if (!game.place[c]) {
                    game.place[c] = true;
                    game.signature[c] = 'O';
                    polozil = true;
                    break;
                }
            }
        }
    }
    else {                      // if position 5 is taken by X
        if (!game.place[0] && !polozil) {
            game.place[0] = true;
            game.signature[0] = 'O';
            polozil = true;
        }
        else if (!game.place[2] && !polozil) {
            game.place[2] = true;
            game.signature[2] = 'O';
            polozil = true;
        }
        else if (!game.place[8] && !polozil) {
            game.place[8] = true;
            game.signature[8] = 'O';
            polozil = true;
        }
        else if (!polozil) {
            for (int c = 0; c < 9; c++) { // no more tactical places
                if (!game.place[c]) {
                    game.place[c] = true;
                    game.signature[c] = 'O';
                    polozil = true;
                    break;
                }
            }
        }
    }
}
