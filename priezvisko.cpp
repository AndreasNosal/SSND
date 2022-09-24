#include <string>
#include <iomanip>
#include <fstream>

//#pragma warning(disable : 4996) // this can allow compilation, using ctime, ctime_s, iomanip, etc. For dates.

void konce(int length, std::fstream& fout); // using reference for sharing object (fstream)
void hello(std::fstream& fout);

int main(int argc, char* argv[]) {

    std::string name; //

    for (int j = 1; j < argc; j++) { // this statement (condicion) j < argc, can´t be <= because the last argv is pointer
        name;
        name += argv[j];
        name += " ";
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
            if (length > 38)   fout << "*@" << name << "*";
            else {
                fout << "*\t@" << name;
                for (int j = 0; j <= 38-(length+4); ++j) fout << " ";
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

    return 0;
}

   void konce(int length, std::fstream& fout) { //another function can´t be defined in funcion

        if ( length < 38) length = 38;

        for (int i = 0; i < length; ++i) {
            fout << "*";
        }
    }


    void hello(std::fstream& fout){
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