#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <string>

int main() {
    // Open the file using wide character stream (wifstream)
    std::wifstream wif("C:\\mehbarah\\FCAI\\Task1\\cmake-build-debug\\arabic_text.txt");

    // Check if the file was opened correctly
    if (!wif.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }

    // Set the locale to handle UTF-8 encoded input
    wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

    // Read and output the file content line by line
    std::wstring line;
    while (std::getline(wif, line)) {
        std::wcout << line << std::endl;  // Output Arabic text
    }

    wif.close();
    return 0;
}