#include "wiring.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXC=205,INF=1e15;

ll dp[MAXN][MAXC][6];
ll n,is[MAXN],d[MAXN];
ll f(ll i, ll c, ll c2, ll w){
	ll &res=dp[i][c][w];
	if(res!=-1)return res;
	if(i==n)return w==0?0:INF;
	if(w==0){
		res=
	}
}

long long min_total_length(vector<int> a, vector<int> b){
	vector<ii>h;
	for(auto i:a)h.pb({i,0});
	for(auto i:b)h.pb({i,1});
	sort(ALL(h));
	n=SZ(h);
	fore(i,0,n)is[i]=h[i].snd,d[i]=h[i].fst;
	
}
