#include <string>
#include <iomanip>
#include <fstream>

//#pragma warning(disable : 4996) // this can allow compilation, using ctime, ctime_s, iomanip, etc. For dates.

void konce(int length, std::fstream& fout); // using reference for sharing object (fstream)
void hello(std::fstream& fout);

int main(int argc, char* argv[]) {

    std::string name;
    if (argc == 1) name = "NOT_DEFINED"; // creating pre-defined use name
    else {
        for (int j = 1; j < argc; j++) { // this statement (condicion) j < argc, can´t be <= because the last argv is pointer
            name += argv[j];
            name += " ";
        }
    }
    auto time = std::time(nullptr); // using manipulators
    int length = name.length() + 1;

//printing message box
std::fstream fout("hello.cpp", std::ios::out);

    for (int i = 0; i <= 4; i++) {
        switch  (i){

            case 1:
            fout << "/";
                konce(length, fout);
                fout << "\\\n";
                break;

            case 2:
                fout << "* Hello world - Generated " << std::put_time(std::localtime(&time), "%F");
                if (length > 38) {
                for (int i = 0; i <= length-36; i++) fout << " "; //length of (36) is date
                }
                else fout << "   ";
                    fout << "*\n";
                    break;

            case 3:
            if (length + 7 > 38) {
                fout << "*@" << name;
                if (length < 38) {
                    for(int j = 0; j <= 37-length; j++) { // 37 is the maximum length of the name which can fit in the bar
                        fout << " ";
                    }
                }
                fout << "*"; // if it´s bigger than 37, it adds *
            }
            else {
                fout << "*       @" << name; // 7 spaces
                for (int j = 0; j <= 37-(length+7); ++j) fout << " "; //seven represents the total count of spaces
                fout << "*";
            }
                 break;
        
            case 4:
                fout << "\n\\";
                 konce(length, fout);
                 fout << "/\n";
                break;
        }
    }
    hello(fout);
    fout.close();

    return 0;
}

   void konce(int length, std::fstream& fout) { //another function can´t be defined in funcion

        if ( length < 38) length = 38;

        for (int i = 0; i < length; ++i) {
            fout << "*";
        }
    }


    void hello(std::fstream& fout){ // printing hello syntax
        fout << "\n" << "#include <iostream>\n\n";
        fout << "using namespace std;\n\n";
        fout << "int main() {\n";
        fout << "\tcout << \"Hello World!\"\n";
        fout << "\treturn 0;\n}";
    }


/*
* To better uderstanding of reference in fstream: https://stackoverflow.com/questions/13231730/how-do-i-use-fstream-specifically-ofstream-through-a-functions-parameters
*/

// Made by: Andreas Nosal