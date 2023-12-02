#include <string>
#include <vector>

using namespace std;

int serieparalelo(vector<int> &t, vector<int> &e) {
    if ((int)t.size() == 1){
		return 1;
	}
	if ((int)t.size() == 2){
		if (t[0] == 1){
			return 1;
		}
		else if (t[0] == 2 && t[1] == 1){
			return 0;
		}
		else {
			return 2;
		}
	}
}
