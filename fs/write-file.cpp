#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ofstream file;

    file.open("file.txt");
    file << "A line of text ...\n";
    file.close();
    
    return EXIT_SUCCESS;
}
