#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_map<string, unordered_set<string>>> rules;


int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    for (int i = 0; i < r1.size(); ++i) rules[r1[i]][r2[i]].insert(r3[i]);


    texto += ' ';

    vector<string> words;

    int i = 0, wst = 0;
    int cnt = 2;

    for (int i = 0; i < texto.size(); ++i) {
        char c = texto[i];
        if (c == ' ') {
            words.push_back(texto.substr(wst, i - wst));
            int w = words.size() - 1;

            if (w >= 2) {
                // cout << "by bot: " << texto.substr(wst, i - wst) << endl;
                auto rule = rules[words[w - 2]][words[w - 1]];
                bool can = rule.count(words[w]);
                if (!can) cnt++;

                // cout << "rule: " << words[w - 2] << " -> " << words[w - 1] << endl;
                // cout << " w sz = " << rule.size() << endl;
                // if (can) cout << " can." << endl;
                // else cout << " can't." << endl;

            }

            wst = i + 1;
        }

    }

    return cnt <= K;
    
}
