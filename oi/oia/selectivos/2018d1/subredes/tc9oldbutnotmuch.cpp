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
typedef char ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
//only gives first case (probably wrong) 8335978
const ll MAXN=30;
int g[MAXN];
vector<ll> ad[MAXN];
LL res=0;
LL to2(LL n){
	return n*(n-1)/2;
}
LL to3(LL n){
	//cerr<<"to3 "<<n<<" = "<<n*(n-1)*(n-2)/6<<"\n";
	//if(n<0)return
	return n*(n-1)*(n-2)/6;
}
vector<ll>deg(10);
ll ppc(int n){return __builtin_popcount(n);}
vector<ll>p,h,b;
bool vis[MAXN];
bool sg[10][10];
void check(){
	//cerr<<"check "; imp(p);
	fore(i,0,10)fore(j,0,10){
		bool a=g[p[i]]>>p[j]&1,b=sg[i][j];
		//cout<<int(i)<<","<<(int)j<<": "<<a<<" "<<b<<endl;
		if(a<b)return;
	}
	//cout<<"++\n";
	res++;
}
void f(ll i){
	if(i==10){check();return;}
	fore(j,0,10)if(!vis[h[j]]&&b[j]>=deg[i]){
		auto x=h[j];
		vis[x]=1;
		p.pb(x);
		f(i+1);
		p.pop_back();
		vis[x]=0;
	}
}
void get(ll& v){
	int n; cin>>n;
	v=n;
	//cout<<"got "<<int(v)<<endl;
}
int main(){FIN;
	ll n; get(n);
	fore(i,0,n)fore(j,0,n){
		char qwe; cin>>qwe;
		sg[i][j]=(qwe=='1');
		if(sg[i][j])deg[i]++;
	}
	//imp(deg); cerr<<"deg ^"<<endl;
	ll t; get(t);
	vector<ll>ns(t),ms(t);
	fore(i,0,t)get(ns[i]),get(ms[i]);
	fore(_,0,t){
		//cerr<<"caso "<<int(_)<<endl;
		ll n=ns[_],m=ms[_];
		mset(g,0);
		fore(i,0,n){
			ad[i].clear();
		}
		//imp(g);
		res=0;
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; get(u),get(v); u--,v--;
			ed.pb({u,v});
			g[u]|=1<<v;
			g[v]|=1<<u;
			ad[u].pb(v);
			ad[v].pb(u);
		}
		vector<ll>per(n-10);
		fore(i,0,10)per.pb(1);
		do{
			int mk=0;
			h.clear();
			fore(i,0,n)if(per[i]){
				mk|=1<<i;
				h.pb(i);
			}
			b.clear();
			for(auto x:h)b.pb(ppc(g[x]&mk));
			/*for(auto x:h)v[ppc(g[x]&mk)].pb(x),b.pb(ppc(g[x]&mk));
			auto sd=deg;
			sort(ALL(sd));
			sort(ALL(b));
			if(b==sd)cerr<<"==\n";*/
			f(0);
		}
		while(next_permutation(ALL(per)));
		cout<<(int)res<<endl;
	}
}

