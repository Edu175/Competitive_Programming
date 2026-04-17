#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e4+5;

vector<ll> g[MAXN];
ll n;
void tablero(int N, vector<int> &u, vector<int> &v) {
    n=N;
    fore(i,0,SZ(u)){
    	u[i]--,v[i]--;
    	g[u[i]].pb(v[i]);
    	g[v[i]].pb(u[i]);
    }
}

int con_quien_comercio(vector<int> &A) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<int>a=A;
    sort(ALL(a));
    for(auto &i:a)i--;
    if(SZ(a)==n)return -1;
    if(a[0]!=0)return a[0]-1+1;
    fore(i,0,n){
    	if(i>=SZ(a)||a[i]!=i)return i+1;
    }
    return -1;
}
