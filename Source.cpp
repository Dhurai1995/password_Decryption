#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;



/*
 * Complete the 'decryptPassword' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string decryptPassword(string s) {
    int n = s.length();
    char c[n];
    strcpy_s(c, s.c_str());
    int temp = 0;
    vector<int> num;
    int i = 0;

    while (isdigit(c[i]))
    {
        num.push_back(c[i]);
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (isupper(c[i]) & islower(c[i + 1]))
        {
            temp = c[i];
            c[i] = c[i + 1];
            c[i + 1] = temp;

            // Delete *
            for (int j = (i + 2); i <= n - 1; i++)
            {
                c[j] = c[j + 1];
            }
            c[n - 1] = {};
        }

        else if (c[i] == 0)
        {
            c[i] = num.back();
        }

        else {}
    }

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; i < n; i++)
        {
            c[j] = c[j + 1];
        }
        c[n] = {};
    }

    string str;
    for (int i =0; i< n ;i++)
    {
        str.push_back(c[i] + '0');
    }

    return str;
}

int main()
{

    string s;
    getline(cin, s);

    string result = decryptPassword(s);

    std::cout << result << "\n";


    return 0;
}
