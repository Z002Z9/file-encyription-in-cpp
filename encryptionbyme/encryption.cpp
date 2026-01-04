#include "encryption.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <list>
#include <vector>

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


    int matrix[3][3] =
    {
        {17, 17, 5},
        {21, 18, 21},
        {2, 2, 19}
    };
    if (encryption)
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
        int detk = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) +
            matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

        detk = detk % 26;

        if (detk < 0)
        {
            detk += 26;
        }

        double detkdouble =(double)detk;

        /*int matrix[3][3] =
        {
            {17, 17, 5},
            {21, 18, 21},
            {2, 2, 19}
        };*/

        int adjkmatrix[3][3] =
        {
            {17, 17, 5},
            {21, 18, 21},
            {2, 2, 19}
        };

		adjkmatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];

        adjkmatrix[0][1] = matrix[2][1] * matrix[0][2] - matrix[0][1] * matrix[2][2];

        adjkmatrix[0][2] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];

        adjkmatrix[1][0] = matrix[1][2] * matrix[2][0] - matrix[2][2] * matrix[1][0];

        adjkmatrix[1][1] = matrix[2][2] * matrix[0][0] - matrix[0][2] * matrix[2][0];

        adjkmatrix[1][2] = matrix[0][2] * matrix[1][0] - matrix[1][2] * matrix[0][0];

        adjkmatrix[2][0] = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];

        adjkmatrix[2][1] = matrix[2][0] * matrix[0][1] - matrix[0][0] * matrix[2][1];

        adjkmatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                adjkmatrix[i][j] = adjkmatrix[i][j] % 26;
                if (adjkmatrix[i][j] < 0)
                {
                    adjkmatrix[i][j] += 26;
                }
			}
        }

        int makeitone = 0;
        for (int db = 1; db < 26; db++)
        {
            if ((detk * db) % 26 == 1)
            {
                makeitone = db;
                break;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                adjkmatrix[i][j] = (adjkmatrix[i][j] * makeitone) % 26;
                
            }
        }

        list<char> letters;

        for (char& c : content)
        {
            
              letters.push_back(c);
            
        }       
        

        list<int> chartonumber;

        for (char& c : letters)
        {
            
            int tmp = (int)c - 97;
            chartonumber.push_back(tmp);

        }
        
        list<int> matrixtimes;
        vector<int> convtovector(chartonumber.begin(), chartonumber.end());

        for (int i = 0; i < (int)chartonumber.size(); i += 3)
        {
            int tmp1 = convtovector[i] * adjkmatrix[0][0] + convtovector[i + 1] * adjkmatrix[1][0] + convtovector[i + 2] * adjkmatrix[2][0];
            tmp1 = tmp1 % 26;
            int tmp2 = convtovector[i] * adjkmatrix[0][1] + convtovector[i + 1] * adjkmatrix[1][1] + convtovector[i + 2] * adjkmatrix[2][1];
            tmp2 = tmp2 % 26;
            int tmp3 = convtovector[i] * adjkmatrix[0][2] + convtovector[i + 1] * adjkmatrix[1][2] + convtovector[i + 2] * adjkmatrix[2][2];
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

