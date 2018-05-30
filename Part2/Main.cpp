#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>



using namespace std;

int main() {
	string text;
	string test = "*<>?|\"";
	bool flag;
	do {
		cout << "\nEnter the file location "<<endl;
		flag = false;
		getline(cin, text, '\n');
		for (size_t i = 0; i < text.size(); i++) {
			for (size_t j = 0; j < test.size(); j++) {
				if (text[i] == test[j]) {
					cout << "\nContains bad characters!" << endl;
					flag = true;
					break;
				}
			}
		}


		if (text[1] == ':') {
			if (test[2] != '\\' || test[3] != '\\') {
				cout << "\nWrong location" << endl;
				flag = true;
				break;
			}
		}


		if (text.substr(text.size() - 4, 4) != ".txt") {
			cout << "\nInvalid file format" << endl;
			flag = true;
			break;
		}

	} while (flag);

    /* char textst[30];
     for(int i=0; i<30;i++){
         textst[i]=text[i];
     }*/
	ifstream FILE(text);
    if(FILE.is_open()) {
        FILE.seekg(0, ios_base::end);
        int the_size_of_the_data_in_the_file = FILE.tellg();
        char* text_from_file = new char[the_size_of_the_data_in_the_file + 1];
        FILE.seekg(0, ios_base::beg);
        FILE.read(text_from_file, the_size_of_the_data_in_the_file);
        string text_from_file1(text_from_file);
        cout << "\nEnter string"<<endl;
        string stroka;
        getline(cin, stroka);
        size_t kol_sovpdeni = 0;
       /* for (std::string::size_type i = text_from_file1.find(stroka); i < text_from_file1.rfind(stroka); i++) {
            if(text_from_file1[i])
            kol_sovpdeni++;
        }*/
       int i;
       while((i=text_from_file1.find(stroka, i))!=text_from_file1.npos){
           kol_sovpdeni++;
           i++;
       }

        cout << endl << kol_sovpdeni;
        delete[]text_from_file;
    }
    FILE.close();
	return 0;
}
