#include "Sonrisas.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;

ll ask(ll u, ll v){
	ll ret=Dispositivo_Miku(u,v);
	// cout<<"ask "<<u<<","<<v<<": "<<ret<<"\n";
	return ret;
}

pair<int, int> Equipo_Sonrisas(int N, int K) {
	set<ll>st;
	ll n=N,k=K;
	fore(i,0,n)st.insert(i);
	//bfs
	queue<ll>q;
	q.push(0);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(!st.count(x))continue;
		st.erase(x);
		vector<ll>pop;
		for(auto y:st){
			ll rq=ask(x,y);
			if(rq==-1)pop.pb(y);
			if(rq==0)q.push(y);
		}
		// cout<<x<<" saco a "; imp(pop);
		for(auto i:pop)st.erase(i);
	}
	ii res={-1,-1};
	if(SZ(st))res={*st.begin(),0};
	// cout<<res.fst<<","<<res.snd<<"\n";
	return res;
	
}
