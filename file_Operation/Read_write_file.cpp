#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


/*******  19d014f0-df38-47cb-9a61-9214966b466f  *******/
int main() {
    fstream file("data.txt", ios::in | ios::out | ios::app);
    file << "Extra data" << endl;
    string s1 =  "Extra data_appendded\n";
    file.write(s1.c_str() , strlen(s1.c_str()));

    file.seekg(0); // Move to start for reading
    string word;
    while (getline(file, word) ) {
        cout << word << endl;
    }
    file.close();
}