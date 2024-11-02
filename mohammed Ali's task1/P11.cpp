#include <bits/stdc++.h>
using namespace std;

string getNextWord(ifstream &file, int &line) {
    char c;
    string word;

    while(file.get(c)) {
        if(c == '\n')
            line++;
        if(!isspace(c))
            word += c;
        else {
            if(!word.empty())
                return word;
        }
    }
    return word;
}
string getFileLine(ifstream &file, int numberLine, string name) {
    string line; file.close(); file.open(name);
    for(int i = 0; i < numberLine; i++)
        getline(file, line);
    return line;
}
void fileComparison() {
    string name1, name2;
    regex pattern(".*\\.txt$"), choicePattern("^(A|B)$");

    string a, b;
    int line1 = 1, line2 = 1;
    int count = 0;
    bool diff = false, eof_1 = false, eof_2 = false;

    cout << "Enter name file 1 and ends with (.txt):\n"; getline(cin, name1);
    while(!regex_match(name1, pattern)) {
        cout << "Please enter valid text file name that ends with (.txt).\n";
        cout << "Enter name file 1:\n";
        getline(cin, name1);
    }

    cout << "Enter name file 2 and ends with (.txt):\n"; getline(cin, name2);
    while(!regex_match(name2, pattern)) {
        cout << "Please enter valid text file name that ends with (.txt).\n";
        cout << "Enter name file 2:\n";
        getline(cin, name2);
    }

    ifstream file1(name1), file2(name2);

    if(file1.is_open() && file2.is_open())
        cout << "Files are opened." << endl;
    else {
        cout << "There is an error in opening Files.\n"
        << "Please check if the files are exist.\n";
        return;
    }

    cout << "Choose between A for char or B for word:\n";

    string choice; getline(cin, choice);

    while(!regex_match(choice, choicePattern)) {
        cout << "Please enter a valid choice.\n" << "A or B:\n";
        getline(cin, choice);
    }
    if(choice == "A"){
        while(!eof_1 && !eof_2)
        {
            count++;
            getline(file1, a);
            if(file1.eof())
                eof_1 = true;
            getline(file2, b);
            if(file2.eof())
                eof_2 = true;
            if(a != b) {
                diff = true;
                break;
            }
            if(eof_1 != eof_2) {
                cout << "Files are different in size.\n";
                file1.close(), file2.close();
                return;
            }
        }
    }
    if(choice == "B") {
        while(true)
        {
            a = getNextWord(file1, line1);
            b = getNextWord(file2, line2);
            if(a != b) {
                diff = true;
                break;
            }
            if(a.empty() && b.empty() && file1.eof() && file2.eof())
                break;
        }
    }

    if(diff) {
        if(choice == "A") {
            if(a.empty()) a = "(empty line)";
            if(b.empty()) b = "(empty line)";

            cout << "Files are not identical.\n"
            << "Difference on line number: " << count << "\n"
            << "File 1: " << a
            << "\nFile 2: " << b << endl;
        }
        else {
            cout << "Files are different.\n";
            cout << "Word in file 1:\n" << a << endl;
            cout << "In line no." << line1 << ":\n" << getFileLine(file1, line1, name1) << endl;
            cout << "Word in file 2:\n" << b << endl;
            cout << "In line no." << line2 << ":\n" << getFileLine(file2, line2, name2) << endl;
        }
    }
    else
        cout << "Files are identical\n";

    file1.close(), file2.close();
}

int main() {
    fileComparison();
    return 0;
}
