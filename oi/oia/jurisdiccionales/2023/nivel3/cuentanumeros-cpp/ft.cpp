#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

ll ft[MAXN+1];

void upd(ll p, ll v){
	for(int i=p+1;i<MAXN;i+=i&-i)ft[i]+=v;
}

ll get(ll p){
	ll res=0;
	for(int i=p;i;i-=i&-i)res+=ft[i];
	return res;
}

ll query(ll a, ll b){
	return get(b)-get(a);
}

void inicializar() {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}

void nuevoNumero(int x) {
    upd(x,1);
}

int contar(int a, int b) {
    return query(a,b+1);
}
