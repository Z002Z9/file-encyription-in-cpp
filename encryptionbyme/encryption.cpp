#include "encryption.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <list>

using namespace std;


//bool performCeaserChiper(string& content, bool encryption)
//{
//    int shift = encryption ? 3 : -3;
//    for (char& c : content) {
//        if (isalpha(c)) {
//            char base = islower(c) ? 'a' : 'A';
//            c = static_cast<char>((((c - base) + shift + 26) % 26) + base);
//        }
//    }
//    return true;
//}
//
bool Hillencryption(string& content, bool encryption)
{

	bool encrypt = encryption ? true : false;
    int matrix[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9} 
    };

    list<char> letters;

    for (char& c : content)
    {
        if (isalpha(c) || c == ' ' || c == '.' || c == ',')
        {
            if (isupper(c)) {
            c = tolower(c);  
            }
			letters.push_back(c);
            

        }
    }
    if (letters.size() % 3 == 1)
    {
        letters.push_back('#');
        letters.push_back('#');
    }
    else if (letters.size() % 3 == 2)
    {
        letters.push_back('#');
    }

    for (char& c : letters)
    {
        cout << c;
    }

    cout << endl;

    list<int> chartonumber;

    for (char& c : letters)
    {
		if (c == ' ')
		{
			c = '26';
		}
		else if (c == '.')
		{
			c = '27';
		}
		else if (c == ',')
		{
			c = '28';
		}
        else
        {
			int tmp = (int)c - 97;
            chartonumber.push_back(tmp);
        }
        
    }
    for (int& c : chartonumber)
    {
        cout << c <<endl;
    }

    list<int> matrixtimes;

    for (int i = 0; i < chartonumber.size() / 3; i++)
    {
		chartonumber(0) * matrix[0][0] + chartonumber[i + 1] * matrix[0][1] + chartonumber[i + 2] * matrix[0][2];

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

    if (Hillencryption(content, encrypt))
    {
        /*ofstream outFile(encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if (!outFile)
        {
            return false;
        }
        outFile << content;
        cout << content << endl;
        outFile.close();*/
        return true;
    }
}

