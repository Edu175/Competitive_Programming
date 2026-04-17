#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define SIZE(c) int((c).size())

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    const int N = SIZE(r1);
    int lastPos = 0;
    string ante = "", ulti = "";
    int fails = 0;
    map<pair<string,string>, set<string>> rules;
    forn(i,N)
        rules[make_pair(r1[i], r2[i])].insert(r3[i]);
    forn(i,SIZE(texto)+1)
    if (i == SIZE(texto) || texto[i] == ' ')
    {
        string pal = texto.substr(lastPos, i-lastPos);
        if (rules[make_pair(ante, ulti)].count(pal) == 0)
            fails++;
        lastPos = i+1;
        ante = ulti;
        ulti = pal;
    }
    return fails <= K;
}
