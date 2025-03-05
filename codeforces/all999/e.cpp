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

const ll B=32;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vv a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		vv ops(1ll<<m);
		fore(mk,0,1<<m){
			ll v=-1;
			fore(i,0,m)if(mk>>i&1)v&=b[i];
			ops[mk]=v;
		}
		vector<vv>as(n,vv(m+1));
		fore(i,0,n)fore(j,0,SZ(as[i]))as[i][j]=a[i];
		fore(i,0,n){
			fore(mk,0,1<<m){
				ll cnt=__builtin_popcount(mk);
				as[i][cnt]=min(as[i][cnt],a[i]&ops[mk]);
			}
			// imp(as[i])
			for(ll j=m;j>=1;j--)as[i][j]-=as[i][j-1];
			as[i][0]=0;
			// imp(as[i])
			for(auto &j:as[i])j=-j;
			// imp(as[i])
		}
		ll res=accumulate(ALL(a),0ll);
		vv po(n,1);
		priority_queue<ii>pq;
		auto put=[&](ll i){if(po[i]<=m)pq.push({as[i][po[i]],i});};
		fore(i,0,n)put(i);
		while(k>0&&SZ(pq)){
			auto [d,i]=pq.top(); pq.pop();
			k--;
			res-=d;
			po[i]++;
			put(i);
		}
		cout<<res<<"\n";
	}
	return 0;
}
