/* student name : Islam Waleed Salah
 * Id: 20230062
 * version: 2.0
 * */

#include "iostream"
#include "sstream"
#include "fstream"
#include "codecvt"
#include "locale"
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;

int main(){

    //utf-8
    locale::global(locale(""));
#ifdef _WIN32 //because windows doesn't love utf-8
    _setmode(_fileno(stdout), _O_U8TEXT);
#endif

    //opening the files we need
    wifstream dictionary("dictionary.txt");
    wfstream text("arabic.txt");
    wofstream output_file("arabic_edited.txt");

    //convert from utf-8 to wide string
    text.imbue(locale(text.getloc(), new codecvt_utf8<wchar_t>));
    dictionary.imbue(locale(text.getloc(), new codecvt_utf8<wchar_t>));
    output_file.imbue(locale(text.getloc(), new codecvt_utf8<wchar_t>));;

    //check if open correctly
    if(text.is_open() and dictionary.is_open()){
        //we continue to append word to the output file unless it exists in the dictionary file, in that case we put it's substitute
        wstring word;
        bool is_a_new_line_after;
        while(is_a_new_line_after = (text.peek() == '\n'), text >> word){ //take a word
            //check if it's in the dictionary
            wstring target_word;
            wstring substitute;
            bool is_in_dictionary = false;
            while(dictionary >> target_word, dictionary >> substitute){ //continue taking words from dictionary until EOF
                if(word == target_word){
                    if(is_a_new_line_after)
                        output_file << '\n';

                    output_file << substitute << ' ';
                    is_in_dictionary = true;
                    break;
                }
            }
            if(is_a_new_line_after)
                output_file << '\n';

            if(!is_in_dictionary){
                output_file << word << ' ';
            }

            //remove the EOF flag
            dictionary.clear();
            //move the cursor to the beginning
            dictionary.seekg(0, ios::beg);
        }
        //close all the files
        dictionary.close();
        text.close();
        output_file.close();
    }
    else{
        wcout << L"\nلم يتم فتح الملفات بشكل سليم من فضلك تأكد من وجود وصحة الملفات";
    }
    wcout << L"\nتمت العملية بنجاح تفقد الملف لرؤية النتيجة";
}