#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

map<string, int> string_to_int;
map<pair<pair<int, int>, int>, bool> is_predicted;
int num_words = 0;

int get_word_id (string s) {
    if (!string_to_int[s]) {
        string_to_int[s] = num_words + 1;
        num_words++;
    }
    return string_to_int[s];
}

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int id1, id2, idr;
    // cout << r1.size() << endl;
    for (int i = 0; i < r1.size(); i++) {
        id1 = get_word_id(r1[i]);
        id2 = get_word_id(r2[i]);
        idr = get_word_id(r3[i]);

        is_predicted[{{id1, id2}, idr}] = true;
        // cout << i << "  " << id1 << " " << id2 << " - " << idr << endl << endl;
        
    }

    vector<int> cadena;
    int point = 0;
    string temp;
    int k;
    for (k = 0; k < 2; k++) {
        temp = "";
        while (texto[point] != ' ') {
            temp += texto[point];
            point++;
        }
        point++;
        cadena.push_back(get_word_id(temp));
    }

    int possible = 1;
    for (int i = 2; point < texto.size(); i++) {
        temp = "";
        while (texto[point] != ' ' && point != texto.size()) {
            temp += texto[point];
            point++;
        }
        point++;
        cadena.push_back(get_word_id(temp));

        if (!is_predicted[{{cadena[i-2], cadena[i-1]}, cadena[i]}]) k++;

        if (k > K) break;
    }

    if (k > K) possible = 0;

    // for (auto t : cadena) cout << t << endl;


    return possible;

}
