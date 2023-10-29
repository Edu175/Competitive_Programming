#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v) cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;
// *********** IMPORTANTE!!!!!! ********************
// NO MODIFICAR DE NINGUNA MANERA ESTE STRUCT!!!!!**
struct PQ{ int precio, cantidad; } ; //  ***********
// *************************************************
// *************************************************

int ganancia( int p, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp )
{
	Fab=-1,Comp=-1;
	ll n=SZ(fabricantes),m=SZ(compradores);
	//assert(n<=5000&&m<=5000);
	vector<pair<pair<ll,ll>,ll>>fab,com;
	fore(i,0,n)fab.pb({{fabricantes[i].precio,fabricantes[i].cantidad},i});
	fore(i,0,m)com.pb({{compradores[i].precio,compradores[i].cantidad},i});
	ll res=-1;
	fore(i,0,SZ(fabricantes)){
		PQ f=fabricantes[i];
		ll fp=f.precio,fq=f.cantidad;
		fore(j,0,SZ(compradores)){
			PQ c=compradores[j];
			ll cp=c.precio,cq=c.cantidad;
			if(fp*max(fq,cq)>p)continue;
			ll resi=cp*cq-fp*max(fq,cq);
			if(resi>res){
				res=resi;
				Fab=i+1;
				Comp=j+1;
			}
		}
	}
	return res;
}
