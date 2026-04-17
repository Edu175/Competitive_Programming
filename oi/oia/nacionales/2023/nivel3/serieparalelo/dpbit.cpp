#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=26,MOD=1e9+7;

ll out[MAXN];
ll dp[1<<MAXN];

inline ll add(ll a, ll b){
	ll res=a+b;
	if(res<MOD)return res;
	return res-MOD;
}

int serieparalelo(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<ii>A={{0,1}};
    fore(i,0,SZ(e)){
    	e[i]--;
    	ll a=A[e[i]].fst,b=A[e[i]].snd;
    	ll j=i+2;
    	if(t[i]==1){
    		A.pb({a,j});
    		A[e[i]]={j,b};
    	}
    	else {
    		A.pb({a,j});
    		A.pb({j,b});
    	}
    }
    for(auto [u,v]:A){
    	u-=2,v-=2;
    	if(u>=0&&v>=0)out[u]|=1<<v;
    }
    ll n=SZ(e);
    dp[(1<<n)-1]=1;
    for(ll mk=(1<<n)-1;mk>=0;mk--)fore(x,0,n){
    	if((mk&(1<<x))||(out[x]&mk))continue;
    	dp[mk]=add(dp[mk],dp[mk|(1<<x)]);
    }
    return dp[0];
}
