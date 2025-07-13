#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll CANT=500;

ll mem[CANT];
string cv(ll mk, ll w){
	string s;
	fore(i,0,w)s.pb('0'+(mk>>i&1));
	return s;
}
ll get(ll V){
	vector<ll>w(__lg(V)+2); // width of ith column
	ll num=1,cant=0;
	fore(e2,0,35){
		if(num>V)break;
		ll v=num;
		fore(e3,0,35){ // amortized O(n)
			if(v>V)break;
			cant++;
			v*=3;
			w[e2]++;
		}
		num*=2;
	}
	auto &res=mem[cant];
	if(res!=-1)return res;
	// cout<<"\nget "<<V<<":\n";
	ll n=SZ(w)-1,m=w[0];
	// imp(w)
	// cout<<n<<" "<<m<<"\n";
	ll mxmk=1ll<<m;
	// vector<int> dp[n+1][m+1];
	// fore(i,0,n+1)fore(j,0,w[i]+1)dp[i][j].resize(1<<w[i],n*m+5);
	int dp[2][m+1][mxmk];
	#define f(a,b,c) dp[(a)&1][b][c]
	f(n,0,0)=0;
	for(ll i=n-1;i>=0;i--)for(ll j=w[i];j>=0;j--)fore(mk,0,1ll<<w[i]){
		auto &res=f(i,j,mk);
		if(j==w[i]){res=f(i+1,0,mk&((1ll<<w[i+1])-1));continue;}
		res=n*m+5;
		ll mki=mk/2;
		if(mk&1)res=f(i,j+1,mki);
		res=min(res,1+f(i,j+1,mki|(j+1<w[i])|(1<<(w[i]-1))));
		// cout<<i<<" "<<j<<" "<<cv(mk,w[i])<<": "<<cv(mk1,w[i])<<": "<<go0<<" "<<go1<<": "<<res<<"\n";
	}
	return res=f(0,0,0);
	#undef f
}


int main(){FIN;
	mset(mem,-1);
	ll n; cin>>n;
	ll res=0;
	fore(i,1,n+1)if(i%2&&i%3){
		// cout<<"+= "<<i<<": "<<n/i<<": "<<get(n/i)<<"\n";
		res+=get(n/i);
	}
	cout<<res<<"\n";
	return 0;
}
