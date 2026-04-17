#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfjg:v)cerr<<(int)kdfjg<<" ";cerr<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef short ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef unsigned __int128 bitmask;
// 1 minute
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

const ll MAXN=128;
LL res=0;
bitmask has[MAXN];
ll n;
string bin(bitmask x){
	string s;
	fore(i,0,n)s.pb('0'+(x>>i&1));
	return s;
}

void get(ll& v){
	int n; cin>>n;
	v=n;
//	cerr<<"got "<<n<<" "<<int(v)<<endl;
}
ll ppc(bitmask b){
	//cerr<<"ppc "<<bin(b)<<" = "<<__builtin_popcountll(b)+__builtin_popcountll(b>>64)<<"\n";
	return __builtin_popcountll(b)+__builtin_popcountll(b>>64);
}
bitmask mk=0;
void f(ll i){
	if(ppc(mk)==10){res++;return;}
	if(i==n)return;
	if((has[i]&mk)==mk){
		mk|=bitmask(1)<<i;
		f(i+1);
		mk^=bitmask(1)<<i;
	}
	f(i+1);
}
int main(){FIN;
	ll asd; get(asd);
	fore(i,0,asd)fore(j,0,asd){
		char qwe; cin>>qwe;
	}
	ll t; get(t);
	vector<ll>ns(t),ms(t);
	fore(i,0,t)get(ns[i]),get(ms[i]);
	fore(_,0,t){
		n=ns[_]; ll m=ms[_];
		mset(has,0);
		res=0;
		fore(i,0,m){
			ll u,v; get(u),get(v); u--,v--;
			has[u]|=bitmask(1)<<v;
			has[v]|=bitmask(1)<<u;
		}
		f(0);
		//fore(i,0,n)cerr<<bin(has[i])<<" ";;cerr<<"\n";
		cout<<res<<endl;
	}
}

