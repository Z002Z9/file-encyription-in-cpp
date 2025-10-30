#include "encryption.h"
#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;


bool performCeaserChiper(string& content, bool encryption)
{
    int shift = encryption ? 3 : -3;
    for (char& c : content) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = static_cast<char>((((c - base) + shift + 26) % 26) + base);
        }
    }
    return true;
}

bool encryptFile(const string& filename, bool encrypt) {
    ifstream inFile(filename);
    if (!inFile)
    {
        return false;
    }
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCeaserChiper(content, encrypt))
    {
        ofstream outFile(encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if (!outFile)
        {
            return false;
        }
        outFile << content;
        cout << content << endl;
        outFile.close();
        return true;
    }
}