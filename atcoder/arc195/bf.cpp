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

ll pref(vv a){
	reverse(ALL(a));
	ll n=SZ(a);
	ll res=0;
	fore(i,0,n){
		if(a[i]==a[0])res++;
		else break;
	}
	return res;
}

ll bfs(vv a){
	if(!SZ(a))return {};
	reverse(ALL(a));
	set<vv>st;
	queue<pair<ll,vv>>q;
	st.insert(a);
	q.push({0,a});
	while(SZ(q)){
		auto [d,x]=q.front(); q.pop();
		// cout<<d<<": "; imp(x)
		ll n=SZ(x);
		ll p=pref(x);
		auto y=x;
		y.resize(n-p);
		if(!SZ(y))return d+1;
		if(!st.count(y)){st.insert(y);q.push({d+1,y});}
		fore(i,0,n-1){
			auto y=x;
			swap(y[i],y[i+1]);
			if(!SZ(y))return d+1;
			if(!st.count(y)){st.insert(y);q.push({d+1,y});}
		}
	}
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		cout<<bfs(a)<<"\n";
	}
	return 0;
}
