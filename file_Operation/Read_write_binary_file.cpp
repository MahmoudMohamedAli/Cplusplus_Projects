#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Define a simple struct
struct Data {
    int id;
    double value;
};

int main() {
    // --- Writing binary data ---
    {
        Data d1 = {42, 3.14};
        fstream file("data.bin", ios::binary | ios::out | ios::trunc);

        if (!file.is_open()) {
            cout << "Failed to open file for writing." << endl;
            return 1;
        }

        file.write(reinterpret_cast<char*>(&d1), sizeof(d1));
        cout << "Binary data written to data.bin" << endl;
    }

    // --- Reading binary data ---
    {
        Data d2;
        fstream file("data.bin", ios::binary | ios::in);

        if (!file.is_open()) {
            cout << "Failed to open file for reading." << endl;
            return 1;
        }

        file.read(reinterpret_cast<char*>(&d2), sizeof(d2));
        cout << "Read binary data:" << endl;
        cout << "id = " << d2.id << ", value = " << d2.value << endl;
    }

    return 0;
}
