#include <iostream>
#include <cstring>
#include <string>

int main() {
    std::string str("String type string...");

    // Create a C string and copy the C++ string there
    char *cstr = new char[str.length() + 1];
    std::strcpy(cstr, str.c_str());

    // Keep tokenizing the C string to output
    char *p = std::strtok(cstr, " ");
    while (p != 0) {
        std::cout << p << "\n";
        p = std::strtok(NULL, " ");
    }

    delete[] cstr;
    return EXIT_SUCCESS;
}
