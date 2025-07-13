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

auto cont=[](ii a, ii b){
	return a.fst<=b.fst&&b.snd<=a.snd;
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		vector<vv>g(n); // this is already transposed
		vv ind(n);
		fore(i,0,n)fore(j,0,n)if(i!=j&&cont(a[i],a[j])){
			g[i].pb(j),ind[j]++;
		}
		vv res(n);
		priority_queue<ll>pq;
		fore(i,0,n)if(!ind[i])pq.push(i);
		for(ll i=n-1;i>=0;i--){
			auto x=pq.top(); pq.pop();
			res[x]=i+1;
			for(auto y:g[x]){
				ind[y]--;
				if(!ind[y])pq.push(y);
			}
		}
		imp(res)
	}
	return 0;
}
