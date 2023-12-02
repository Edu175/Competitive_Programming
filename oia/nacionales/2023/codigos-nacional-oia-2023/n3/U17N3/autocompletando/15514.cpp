#include <bits/stdc++.h>


using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto)
{
    vector <char> s;
    for (int i=0; i<texto.size(); i+=2)
    {
        s.push_back(texto[i]);
    }
    char R1=r1[0][0];
    char R2=r2[0][0];
    char R3=r3[0][0];


    if (R1==s[K-2] && R2==s[K-1] /*&& R3==s[K]*/)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    cout << endl;
    return 0;
}
