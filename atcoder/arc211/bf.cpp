#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool good(vv h){
	vv a;
	fore(i,1,10)fore(_,0,h[i])a.pb(i);
	do{
		ll bad=0;
		fore(i,0,SZ(a)-1)bad|=a[i]+a[i+1]==10;
		if(!bad)return 1;
	}while(next_permutation(ALL(a)));
	return 0;
}

set<vv> st;

ll bfs(vv h){
	queue<pair<ll,vv>> q;
	st.insert(h);
	q.push({0,h});
	if(good(h))return 0;
	while(SZ(q)){
		auto [d,x]=q.front(); q.pop();
		fore(i,1,10){
			auto y=x;
			y[i]++;
			if(st.count(y))continue;
			if(good(y))return d+1;
			q.push({d+1,y});
		}
	}
	assert(0);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		st.clear();
		vv h(10);
		fore(i,1,10)cin>>h[i];
		cout<<bfs(h)<<"\n";
	}
	return 0;
}
