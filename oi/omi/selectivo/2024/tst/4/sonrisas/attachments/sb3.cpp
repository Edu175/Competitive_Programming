#include "Sonrisas.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

const ll MAXN=1005;
ll my_cnt__=0,my_limit__;

ll mem[MAXN][MAXN];

ll ask(ll u, ll v){
	if(u>v)swap(u,v);
	if(u==v)return -1;
	ll &res=mem[u][v];
	if(res!=-5)return res;
	my_cnt__++;
	assert(my_cnt__<my_limit__);
	res=Dispositivo_Miku(u,v);
	cout<<"ask "<<u<<","<<v<<": "<<res<<"\n";
	return res;
}


pair<int, int> Equipo_Sonrisas(int N, int K) {
	my_cnt__=0; my_limit__=(2*N*N+K-1)/K;
	assert(N%2==0&&K==N/2&&K>=1);
	ll n=N,k=K;
	fore(i,0,n)fore(j,0,n)mem[i][j]=-5;
	ll rt=rng()%n;
	set<ll>st;
	fore(i,0,n)st.insert(i);
	ll did=0;
	fore(i,0,n){
		ll rq=ask(rt,i);
		if(rq==0&&!did){
			did=1;
			fore(j,0,n)if(ask(i,j)!=1)st.erase(j);
		}
		if(rq!=1)st.erase(i);
	}
	ii res={-1,-1};
	if(SZ(st))res={*st.begin(),rt};
	return res;
	
}
