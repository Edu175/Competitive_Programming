#include <bits/stdc++.h>

using namespace std;

bool Pr(int cajas, vector<int> cant){
	vector<set<int>> v(cajas);
	for(int i=0; i<(int)cant.size(); ++i){
		for(int j=0; j<(int)v.size(); ++j){
			if(v[j].count(i)==0){
				if(cant[i]!=0){
					cant[i]--;
					v[j].insert(i);
				}
			}
		}
	}
	bool esPosible=true;
	for(int i=0; i<(int)cant.size(); ++i){
		for(int j=0; j<(int)v.size(); ++j){
			if(v[j].count(i)==0){
				esPosible=false;
			}
		}
	}
	return esPosible;
}

long long bombones(int K, vector<int> &x){
	if(K==1){
		int sum=0;
		for(int i=0; i<x.size(); ++i){
			sum+=x[i];
		}
		return sum;
	}
	else{
		int ini=1; 
		int fin=100000;
	for(int i=0; i<(int)x.size(); ++i){
		while(ini-fin!=1){
			int m=(ini+fin)/2;
			if(!Pr(m, x)){
				fin=m;
			}
			else if(Pr(m, x)){
				ini=m;
			}
		}
	}
	if(ini==K)
			return ini;
		else
			return fin;
	}
}
