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
const ll MAXV=1e5+5;
ll bfs(ll s, ll t){
	vv d(MAXV,-1);
	queue<ll>q; d[s]=0; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		auto vec=[&](ll y){
			if(y<=0||y>=SZ(d))return;
			if(d[y]==-1)d[y]=d[x]+1,q.push(y);
		};
		vec(2*x);
		vec(x-1);
	}
	return d[t];
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	cout<<bfs(n,m)<<"\n";
	return 0;
}