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
    long long res = 0;
    queue<pair<int,int> > tmp;
    while (pq.size() >= K) {
		pair<int, int> a;
    	for (int i=0; i<K; i++) {
    		a = pq.top(); pq.pop();
    		tmp.push(a);
    	}
    	res++;
    	for (int i=0; i<K; i++) {
    		a = tmp.front(); tmp.pop();
    		if (a.first-1 == 0) continue;
    		pq.push({a.first-1, a.second});
    	}
    }
    return res;
}
