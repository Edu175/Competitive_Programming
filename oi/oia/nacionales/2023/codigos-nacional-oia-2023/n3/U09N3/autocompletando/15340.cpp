#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << x << endl << endl;

using namespace std;

vector<string> conseguirPalabras(string &texto) {
    vector<string> res(0, "");
    string curres = "";
    for(char x : texto) {
        if(x == ' ') {
            res.push_back(curres);
            curres = "";
        } else {
            curres += x;
        }
    }
    res.push_back(curres);
    return res;
}

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    unordered_map<string, vector<pair<string, string>>> mapaPredictor;
    
    for(int i = 0; i < r1.size(); i++) {
        mapaPredictor[r1[i]].push_back({r2[i], r3[i]});
    }

    vector<string> palabras = conseguirPalabras(texto);

    bool sePuede = true;

    int posibilidades = K - 2;

    //yo se que K es por lo menos = 2
    for(int i = 2; i < palabras.size() && sePuede; i++) {
        vector<pair<string, string>> matches = mapaPredictor[palabras[i-2]];
        bool unaSePudo = false;
        for(auto x : matches) {
            if(x.first == palabras[i-1] && x.second == palabras[i]) {unaSePudo=true;break;}
        }
        if(!unaSePudo) posibilidades--;
        if(posibilidades == -1) sePuede = false;
    }

    return sePuede;
}
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string texto;
    getline(cin,texto);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<string> r1;
    vector<string> r2;
    vector<string> r3;
    r1.resize(N);
    r2.resize(N);
    r3.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> r1[i];
        cin >> r2[i];
        cin >> r3[i];
    }
    int returnedValue;
    returnedValue = autocompletando(K, r1, r2, r3, texto);
    cout << returnedValue << "\n";
    return 0;
}
*/