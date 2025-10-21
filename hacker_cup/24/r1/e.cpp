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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MOD=998244353,MAXM=105,MAXN=26;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
bitset<MAXN> g[MAXN];
bitset<MAXM> wild[MAXN];
ll val(bitset<MAXM> &w, ll m){
	ll res=1,q=0;
	fore(i,0,m){
		q+=w[i];
		res=add(res,fpow(26,q));
	}
	// cout<<"val "<<w<<": "<<res<<"\n";
	return res;
}
ll res=0,n;
ll sz[MAXN];
void f(ll i, ll par, bitset<MAXN> s, bitset<MAXM>w, ll m){
	if(i==n){
		ll q=val(w,m);
		if(par)res=add(res,q);
		else res=sub(res,q);
		// cout<<"res ch "<<par<<": "<<q<<"\n";
		return;
	}
	f(i+1,par,s,w,m);
	if(s[i]){
		f(i+1,par^1,s&g[i],w&wild[i],max(m,sz[i]));
	}
}
int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		// cout<<"\n\n";
		cout<<"Case #"<<_+1<<": ";
		cin>>n;
		vector<string> a(n);
		fore(i,0,n)fore(j,0,MAXM)wild[i][j]=0;
		fore(i,0,n)cin>>a[i],sz[i]=SZ(a[i]);
		fore(i,0,n)fore(j,0,n){
			ll flag=1;
			fore(k,0,SZ(a[i])){
				flag&=
			a[i][k]=='?'||a[j][k]=='?'||a[i][k]==a[j][k];
			}
			g[i][j]=flag;
		}
		fore(i,0,n){
			fore(j,0,SZ(a[i]))wild[i][j]=a[i][j]=='?';
		}
		bitset<MAXN> s;
		bitset<MAXM> w;
		fore(i,0,n)s[i]=1;
		fore(j,0,MAXM)w[j]=1;
		res=0;
		f(0,0,s,w,0);
		cout<<res<<"\n";
	}
	return 0;
}
