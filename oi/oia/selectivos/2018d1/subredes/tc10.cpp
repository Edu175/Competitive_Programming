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

const ll MAXN=40;
LL res=0;
bool sg[10][10],g[MAXN][MAXN];
vector<ll> ad[10];
ll n;
vector<ll>v;
bool vis[MAXN];
void f(){
	if(SZ(v)==10){res++;return;}
	fore(x,0,n)if(!vis[x]){
		bool flag=1;
		for(auto i:ad[SZ(v)])if(!g[x][v[i]]){flag=0;break;}
		if(flag){
			v.pb(x);
			vis[x]=1;
			f();
			v.pop_back();
			vis[x]=0;
		}
	}
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
		if(sg[i][j]&&j<i)ad[i].pb(j);
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
	//cerr<<sym<<" sym"<<endl;
	ll t; get(t);
	vector<ll>ns(t),ms(t);
	fore(i,0,t)get(ns[i]),get(ms[i]);
	fore(_,0,t){
		n=ns[_]; ll m=ms[_];
//		cerr<<"caso "<<int(_)<<endl;
		res=0;
		fore(i,0,m){
			ll u,v; get(u),get(v); u--,v--;
			g[u][v]=g[v][u]=1;
		}
		f();
//		cerr<<res<<"\n";
		cout<<res/sym<<endl;
	}
}

