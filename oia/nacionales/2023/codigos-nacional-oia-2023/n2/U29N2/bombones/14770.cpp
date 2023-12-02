#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

long long bombones(int K, vector<int> &x) {
    priority_queue<pair<int,int> > pq;
    for (int i=0; i<x.size(); i++) {
    	pq.push({x[i], i});
    }
    long long cnt = 0, res = 0;
    queue<pair<int,int> > tmp;
    while (!pq.empty() && pq.top().first != 0) {
    	auto a = pq.top();
    	tmp.push({a.first-1,a.second});
    	pq.pop();
    	if ((++cnt)%K == 0) {
    		cnt = 0; ++res;
    		while (!tmp.empty()) {
    			a = tmp.front();
    			pq.push(a);
    			tmp.pop();
    		}
    	}
    }
    return res;
}
