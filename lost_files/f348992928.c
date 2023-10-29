#include "aplusb.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e10;

std::vector<int> smallest_sums(int N, std::vector<int> A, std::vector<int> B) {
	ll n=N;
	vector<ll>a=A,b=B;
	a.pb(INF);
	ll p[n]={};
	prioritiy_queue<ii>pq;
	fore(i,0,n)pq.push({a[0]+b[i],i});
	vector<ll>res;
	fore(i,0,n){
		auto f=pq.front(); pq.pop();
		res.pb(f.fst);
		ll idx=pq.snd;
		pq.push({a[++p[idx]]+b[idx],idx})
	}
	return {};
}
