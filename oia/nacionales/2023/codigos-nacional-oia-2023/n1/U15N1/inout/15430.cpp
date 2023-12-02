#include <string>
#include <vector>

using namespace std;

vector<int> inout(vector<int> &t, vector<int> &e) {
    vector<int> r = {1,-1};
    for(int i = 0; i < t.size(); i++){
        if(t[i] == 1) {
            r.push_back(0);
        };
    }
    return r;

}
