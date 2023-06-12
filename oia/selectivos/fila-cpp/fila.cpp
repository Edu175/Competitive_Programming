#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
struct Fecha
{
    int dia, mes,anno;
};
const ll MAXN=3e5+5,INF=MAXN*2;
vector<ll>ft(MAXN,INF);
void upd(ll p, ll v){
	for(ll i=p+1;i<MAXN;i+=i&-i)ft[i]=min(ft[i],v);
}
ll get(ll p){ //[0,p)
	ll res=INF;
	for(ll i=p;i;i-=i&-i)res=min(res,ft[i]);
	return res;
}
int fila(vector<Fecha> orden, vector<int> &enojados)
{
	//cout<<"\n";
	ll n=SZ(orden);
	vector<ll>a(n);
	vector<pair<ll,ll>>b;
	fore(i,0,n)b.pb({orden[i].dia+100*orden[i].mes+10000*orden[i].anno,i});
	sort(ALL(b)); reverse(ALL(b));
	fore(i,0,n)a[b[i].snd]=i;//,cout<<b[i].fst<<","<<b[i].snd<<" ";
	//cout<<"\n";
	//imp(a);
	vector<pair<ll,ll>>res;
	fore(i,0,n)res.pb({i-get(a[i]),-i}),upd(a[i],i);
	sort(ALL(res)); reverse(ALL(res));
	enojados.clear();
	fore(i,0,n)if(res[i].fst>0)enojados.pb(-res[i].snd+1);
	//cout<<"\n";
	return max(ll(0),res[0].fst);
}
