#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> inout(vector<int> &t, vector<int> &e) {
    vector<int> r = {1,-1};
    int change1 = 0, change2 = 1;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == 1) {
            r.push_back(0);
            change1 = i;
        }
        else if(t[i] == 2) {
            r[change1]++;
            r[change2]--;
            r.push_back(0);
        }
    }
    return r;

}
