#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	ll r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}

int main(){
	JET
	ll m,n; cin>>m>>n>>MOD;
	vv a(n);
	fore(i,0,n)	cin>>a[i];
	vector<ii> rans={{0,(a[0]+1)/2-1}}; // [l,r], smallest rep
	
	fore(i,1,n){
		ll z=a[i];
		ll e=a[i-1];
		e=z-1-e;
		// dejo los <= e
		while(SZ(rans)&&rans.back().fst>e)rans.pop_back();
		if(SZ(rans)&&rans.back().snd>e)rans.back().snd=e;
		ll u=a[i-1];
		ll tam=z-2*u;
		if(tam>0){
			tam=(tam+1)/2;
			rans.pb({u,u+tam-1});
		}
	}
	for(auto [x,y]:rans) cerr<<"("<<x<<","<<y<<")"<<" ";
	cerr<<"\n";
	ll res=0;
	for(auto [l,r]:rans)res+=r-l+1;
	res+=m-a.back();
	cerr<<res<<"\n";
	cout<<fpow(2,res)<<"\n";
	return 0;
}