#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5;

ll k,t;
vector<ii>g[MAXN];
vector<ll>res;
ll c[MAXN];

void dijkstra(ll x){
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	pq.push({0,x});
	while(SZ(pq)&&c[t]<k){
		auto f=pq.top(); pq.pop();
		if(c[f.snd]==k)continue;
		c[f.snd]++;
		//cout<<f.snd<<","<<f.fst<<": "<<c[f.snd]<<"\n";
		if(f.snd==t)res.pb(f.fst);
		for(auto i:g[f.snd]){
			ll w=f.fst+i.fst;
			pq.push({w,i.snd});
		}
	}
}

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
    ll n=N,m=M,s=comienzo;
    t=fin, k=K;
    s--,t--;
    fore(i,0,m){
    	ll u=origen[i],v=destino[i],w=tiempo[i];u--,v--;
    	g[u].pb({w,v});
    }
    dijkstra(s);
    return res;
}
