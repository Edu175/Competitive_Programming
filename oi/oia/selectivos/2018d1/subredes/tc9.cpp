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
typedef uint8_t ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

const ll MAXN=30;
LL res=0;
int has[MAXN];
unordered_map<int,LL>dp[12];
bool sg[10][10];
ll n;
string bin(int x){
	string s;
	fore(i,0,n)s.pb('0'+(x>>i&1));
	return s;
}
LL f(int mk, ll k){
	//cerr<<bin(mk)<<" "<<int(k)<<": "<<res<<endl;
	if(dp[k].count(mk))return dp[k][mk];
	auto &res=dp[k][mk];
	if(k==10)return res=1;
	fore(i,0,n)if(mk>>i&1){
		int mki=mk^(1ll<<i);
		if(!(k&1))mki&=has[i];
		res+=f(mki,k+1);
//		cout<<bin(mk)<<" "<<(int)k<<" "<<int(i)<<" --> "<<bin(mki)<<"\n";
	}
	return res;
}

void get(ll& v){
	int n; cin>>n;
	v=n;
//	cerr<<"got "<<n<<" "<<int(v)<<endl;
}
int main(){FIN;
	ll asd; get(asd);
	fore(i,0,asd)fore(j,0,asd){
		char qwe; cin>>qwe;
		sg[i][j]=(qwe=='1');
	}
	LL sym=0;
	vector<ll>p;
	fore(i,0,asd)p.pb(i);
	do{
		fore(i,0,10)fore(j,0,10)if(sg[i][j]!=sg[p[i]][p[j]])goto bad;
		sym++;
		//imp(p);
		bad:
		;
	}
	while(next_permutation(ALL(p)));
	//cerr<<sym<<" sym\n";
	ll t; get(t);
	vector<ll>ns(t),ms(t);
	fore(i,0,t){
		get(ns[i]),get(ms[i]);
//		imp(ms);
	}
	fore(_,0,t){
		n=ns[_]; ll m=ms[_];
//		cerr<<"caso "<<int(_)<<endl;
//		cerr<<(int)n<<" "<<(int)m<<"\n";
		fore(i,0,12)dp[i].clear();
		mset(has,0);
		res=0;
		fore(i,0,m){
			ll u,v; get(u),get(v); u--,v--;
			has[u]|=1ll<<v;
			has[v]|=1ll<<u;
//			cerr<<(int)u<<","<<(int)v<<"\n";
		}
//		fore(i,0,n)cerr<<bin(has[i])<<" ";;cout<<"\n";
		auto res=f((1ll<<n)-1,0);
//		cerr<<res<<"\n";
		cout<<res/sym<<"\n";
	}
}

