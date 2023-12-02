#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    const int N = SIZE(r1);
    int lastPos = 0;
    string ante = "", ulti = "";
    int fails = 0;
    forn(i,SIZE(texto)+1)
    if (i == SIZE(texto) || texto[i] == ' ')
    {
        string pal = texto.substr(lastPos, i-lastPos);
        bool ok = false;
        forn(j,N)
        if (r1[j] == ante && r2[j] == ulti && r3[j] == pal)
            ok = true;
        if (!ok)
            fails++;
        lastPos = i+1;
        ante = ulti;
        ulti = pal;
    }
    return fails <= K;
}
