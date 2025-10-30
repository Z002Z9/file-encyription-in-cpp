#include <iostream>
#include "encryption.h"
using namespace std;
//tmp

int main() {
    string filename;
    char mode;

    cout << "Enter filename: ";
    getline(cin >> ws, filename);

    cout << "Encrypt (e) or Decrypt (d)?: ";
    cin >> mode;
    if (mode == 'e') {
        if (encryptFile(filename, true))
        {
            cout << "File encrypted successfully." << endl;
        }
        else
        {
            cerr << "Error encrypting file." << endl;
        }
    }
    else if (mode == 'd') {
        if (encryptFile(filename, false))
        {
            cout << "File decrypted successfully." << endl;
        }
        else
        {
            cerr << "Error decrypting file." << endl;
        }
    }
    else {
        cerr << "Invalid mode selected." << endl;
    }

    return 0;
}