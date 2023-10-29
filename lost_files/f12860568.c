#include "mushrooms.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto dfh:v)cout<<dfh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll ask(vector<ll>a){
	vector<int>ai;
	for(auto i:a)ai.pb(i);
	return use_machine(ai);
}
int count_mushrooms(int n){
	ll res=1;
	fore(i,1,n){
		res+=!ask({0,i});
	}
	return res;
}
