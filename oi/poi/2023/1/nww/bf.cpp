#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,szokput=b;i<szokput;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll MOD;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}
const ll MAXV=1e6+5;
int cr[MAXV];
void criba(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=i*i;j<MAXV;j+=i)cr[j]=i;
}
vector<ii> fact(ll n){
	vector<ii>ret;
	while(n>1){
		ll p=cr[n]==-1?n:cr[n];
		ll c=0;
		while(n%p==0)c++,n/=p;
		ret.pb({p,c});
	}
	return ret;
}

int main(){FIN;
	criba();
	ll n,q; cin>>n>>q>>MOD;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<vector<ll>>b(n,vector<ll>(n));
	fore(l,0,n){
		ll val=1;
		map<ll,ll>mp;
		fore(r,l,n){
			for(auto [p,e]:fact(a[r])){
				ll &now=mp[p];
				ll old=now;
				now=max(now,e);
				val=mul(val,fpow(p,now-old));
			}
			b[l][r]=val;
			// cout<<l<<" "<<r<<": "<<val<<"\n";
		}
	}
	// fore(i,0,n){
	// 	imp(b[i]);
	// }
	vector<vector<ll>>sp(n,vector<ll>(n));
	fore(i,0,n)fore(j,0,n){
		sp[i][j]=b[i][j];
		if(j)sp[i][j]=add(sp[i][j-1],b[i][j]);
	}
	// cout<<"\n";
	// fore(i,0,n){
	// 	imp(sp[i]);
	// }
	for(ll i=n-2;i>=0;i--)fore(j,0,n){
		sp[i][j]=add(sp[i][j],sp[i+1][j]);
	}
	// cout<<"\n";
	// fore(i,0,n){
	// 	imp(sp[i]);
	// }
	while(q--){
		ll l,r; cin>>l>>r; l--,r--;
		cout<<sp[l][r]<<"\n";
	}
	return 0;
}