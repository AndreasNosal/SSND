#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

#define MAXIMUM 1000000;

double ladicka(std::unordered_map<std::string, double> TONES, double frequency, std::string note, std::string& MAX_NAME);

int main(int argc, char* argv[]) {

    switch (argc) {

        case 1:
            std::cerr << "\nToo little arguments.\n\n";
            std::cerr << "First time using it?    Enter your frequency and tone.\n";
            std::cerr << "NOTE: Use '.' dot for decimal numbers.\n";
            return EXIT_FAILURE;
            break;

        case 2:
            break; // SUCCES

        case 3:
            break; // SUCCES

        default:
            std::cerr << "\nToo MUCH arguments.\n\n";
            std::cerr << "First time using it?    Enter your frequency and tone.\n";
            std::cerr << "NOTE: Use '.' dot for decimal numbers.\n";
            return EXIT_FAILURE;
            break;
    }

    std::unordered_map<std::string, double> TONES = {{"E2" ,82.4068892282175}, {"A2", 110}, {"D3", 146.832383958704},
    {"G3", 195.997717990875}, {"H3", 246.941650628062}, {"E4", 329.62755691287}};

    std::string MAX_NAME;

    std::stringstream temp(argv[1]);
    double freqvency = 0.;
    //double frekvency = atoi(argv[1]);
    temp >> freqvency;
    std::string note = "none";

    if (argc == 3) note = argv[2]; // condition used for 2 arguments

    std::cout << ladicka(TONES, freqvency, note, MAX_NAME) << "  " << MAX_NAME;
}

double ladicka(std::unordered_map<std::string, double> TONES, double frequency, std::string note, std::string& MAX_NAME) {

    auto simular_note = TONES.find(note);
    if (simular_note != TONES.end()) {
        int temp = simular_note->second;

        return (temp - frequency);
        /*if (temp == frequency) return 0;
        if (temp > frequency) return (temp - frequency);
        return (frequency - temp);*/
    }

    /*int TONES_size = TONES.size();
    for (int i = 0; i < TONES_size; i++) {
        auto temp_map = TONES.end()
    }*/


    bool minus = false;
    double MAX = MAXIMUM;
    //std::string MAX_NAME;

    for (auto it = TONES.begin(); it != TONES.end();) { // going through elements by initiators
        double temp_int = it->second; // taking each elements
        std::string temp_string = it->first;
        bool temp_bool = true;

        if (temp_int < 0) temp_int * -1;

        if ((temp_int - frequency) < 0) {
            temp_int -= frequency;
            temp_int *= -1;
            temp_bool = false;
        }
        else temp_int -= frequency;

        if (temp_int < MAX) {
             // if element is bigger than MAXimum value, its get updated
            MAX = temp_int;
            MAX_NAME = temp_string;
            minus = temp_bool; // chcecks if the number is negative
        }

        it = TONES.erase(it); // it has to erase each element to go through elements
    }
    //std::cout << MAX << "  " << MAX_NAME;
if (!minus) MAX *= -1;

    return MAX;
}