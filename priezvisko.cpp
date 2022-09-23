#include <iostream>
#include <string>
#include <iomanip>
//#pragma warning(disable : 4996) // this can allow compilation, using ctime, ctime_s, iomanip, etc. For dates.

void konce(int length);

int main(int argc, char* argv[]) {

    std::string name;

    for (int j = 1; j < argc; j++) { // this statement (condicion) j < argc, can´t be <= because the last argv is pointer
        name;
        name += argv[j];
        name += " ";
    }

    auto time = std::time(nullptr); // using manipulators
    int length = name.length() + 1;

//printing message box
    for (int i = 0; i <= 4; i++) {
        switch  (i){

            case 1:
            std::cout << std::endl << "/";
                konce(length);
                std::cout << "\\" << std::endl;
                break;

            case 2:
                std::cout << "* Hello world - Generated " << std::put_time(std::localtime(&time), "%F");
                if (length > 38) {
                for (int i = 0; i <= length-36; i++) std::cout << " "; //length of (36) is date
                }
                else std::cout << "   ";
                    std::cout << "*" << std::endl;
                    break;

            case 3:
            if (length > 38)   std:: cout << "* " << name << "*";
            else {
                std::cout << "*\t" << name;
                for (int j = 0; j <= 38-(length+7); j++) std::cout << " ";
                std::cout << "*";
            }
                 break;
        
            case 4:
                std::cout << std::endl << "\\";
                 konce(length);
                 std::cout << "/" << std::endl;
                break;
        }
    }
    return 0;
}

   void konce(int length) { //another function can´t be defined in funcion
        if ( length < 38) length = 38;

        for (int i = 0; i < length; ++i) {
            std::cout << "*";
        }
    }