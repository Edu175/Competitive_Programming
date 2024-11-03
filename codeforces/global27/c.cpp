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

ll get(vv a){
	ll k=0;
	fore(i,0,SZ(a)){
		if(i%2)k|=a[i];
		else k&=a[i];
	}
	return k;
}

int main(){FIN;
	// cout<<get({2,1,3,4,5})<<"\n";
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv res(n);
		ll al=(1ll<<20)-1;
		priority_queue<ii>pq;
		fore(i,0,n)pq.push({i+1,i+1});
		for(ll i=n-1;i>=0;i--){
			atras:
			auto [x,y]=pq.top(); pq.pop();
			if((x&al)!=x){pq.push({x&al,y});goto atras;}
			res[i]=y;
			fore(j,0,20)if((al>>j&1)&&(x>>j&1)==i%2)al^=1ll<<j;
		}
		cout<<get(res)<<"\n";
		imp(res);
	}
	return 0;
}
