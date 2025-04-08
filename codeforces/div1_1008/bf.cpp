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

bool good(ll n, ll mk){
	vv p;
	fore(i,0,n)if(mk>>i&1)p.pb(i);
	fore(i,0,SZ(p)-1)if((p[i+1]-p[i])%2==0)return 0;
	return 1;
}
vv moves;

ll bfs(vv s){
	ll n=SZ(s);
	set<vv>st; st.insert(s);
	queue<pair<ll,vv>>q;
	q.push({0,s});
	if(s==vv(n))return 0;
	while(SZ(q)){
		auto [d,x]=q.front(); q.pop();
		for(auto mk:moves){
			auto y=x; ll fg=1;
			fore(i,0,n)if(mk>>i&1)fg&=--y[i]>=0;
			if(fg&&!st.count(y)){
				st.insert(y);
				if(y==vv(n))return d+1;
				q.push({d+1,y});
			}
		}
	}
	return -1;
}
ll solve(vv a){
	ll n=SZ(a);
	moves.clear();
	fore(mk,0,1ll<<n)if(good(n,mk))moves.pb(mk);
	// imp(moves)
	ll res=bfs(a);
	// cout<<"solve "; for(auto i:a)cout<<i<<" ";
	// cout<<"= "<<res<<"\n";

	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		cout<<solve(a)<<"\n";
		// ll res=0;
		// fore(l,0,n)fore(r,l+1,n+1){
		// 	vv b; fore(i,l,r)b.pb(a[i]);
		// 	res+=solve(b);
		// }
		// cout<<res<<"\n";
	}
	return 0;
}
