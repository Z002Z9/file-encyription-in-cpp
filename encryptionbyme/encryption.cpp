#include "encryption.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
//updated


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


    int matrix[3][3] =
    {
        {17, 17, 5},
        {21, 18, 21},
        {2, 2, 19}
    };
    if (!encryption)
    {


        list<char> letters;

        for (char& c : content)
        {
            if (isalpha(c))// || c == ' ' || c == '.' || c == ','
            {
                if (isupper(c))
                {
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

        /*for (char& c : letters)
        {
            cout << c;
        }*/

        cout << endl;

        list<int> chartonumber;

        for (char& c : letters)
        {
            /*if (c == ' ')
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
            }*/
            int tmp = (int)c - 97;
            chartonumber.push_back(tmp);

        }


        list<int> matrixtimes;
        vector<int> convtovector(chartonumber.begin(), chartonumber.end());


        //for (int i = 0; i < chartonumber.size()/3-1; i+=3)
        for (int i = 0; i < (int)chartonumber.size(); i += 3)
        {
            int tmp1 = convtovector[i] * matrix[0][0] + convtovector[i + 1] * matrix[1][0] + convtovector[i + 2] * matrix[2][0];
            tmp1 = tmp1 % 26;
            int tmp2 = convtovector[i] * matrix[0][1] + convtovector[i + 1] * matrix[1][1] + convtovector[i + 2] * matrix[2][1];
            tmp2 = tmp2 % 26;
            int tmp3 = convtovector[i] * matrix[0][2] + convtovector[i + 1] * matrix[1][2] + convtovector[i + 2] * matrix[2][2];
            tmp3 = tmp3 % 26;

            matrixtimes.push_back(tmp1);
            matrixtimes.push_back(tmp2);
            matrixtimes.push_back(tmp3);

        }

        content.clear();
        char mychar = 'n';
        for (int n : matrixtimes)
        {
            mychar = n + 'a';

            content += mychar;
        }
    }
    else
    {
        //decript
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

