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



int ganancia( int pp, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp )
{
	Fab=-1,Comp=-1;
	ll n=SZ(fabricantes),m=SZ(compradores);
	ll c[n],p[n];
	fore(i,0,n)c[i]=fabricantes[i].cantidad,p[i]=fabricantes[i].precio;
	vector<pair<ll,ll>>v;
	fore(i,0,n)v.pb({c[i],i});
	sort(ALL(v));
	pair<ll,ll> mint[n];
	mint[n-1]={v[n-1].fst*p[v[n-1].snd],n-1};
	for(ll i=n-2;i>=0;i--){
		ll ahora=v[i].fst*p[v[i].snd];
		if(ahora<=pp&&ahora<mint[i+1].fst)mint[i]={ahora,i};
		else mint[i]=mint[i+1];
	}
	ll minp[n];
	minp[0]=v[0].snd;
	fore(i,1,n){
		if(p[v[i].snd]<p[minp[i-1]])minp[i]=v[i].snd;
		else minp[i]=minp[i-1];
	}
	//imp(minp);
	ll res=-1;
	vector<pair<pair<ll,ll>,ll>>com;
	fore(i,0,m)com.pb({{compradores[i].cantidad,compradores[i].precio},i});
	sort(ALL(com));
	/*for(auto i:v)cout<<i.fst<<","<<p[i.snd]<<" ";
	cout<<"\n";
	for(auto i:com)cout<<i.fst.fst<<","<<i.fst.snd<<" ";
	cout<<"\n\n";
	cout<<"mint: ";
	for(auto i:mint)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\nminp: ";
	for(auto i:minp)cout<<i<<" ";
	cout<<"\n\n";*/
	ll lwb=0;
	for(auto i:com){
		ll pi=i.fst.snd,ci=i.fst.fst;
		while(lwb<n&&v[lwb].fst<ci)lwb++;
		//cout<<i.snd+1<<" ("<<ci<<","<<pi<<") : "<<lwb<<"\n";
		//cout<<"gano: "<<ci*pi<<"\n";
		ll resi=-1,fabi=-1;
		if(lwb<n&&mint[lwb].fst<=pp){
			//cout<<"mint: "<<mint[lwb].fst<<"\n";
			resi=ci*pi-mint[lwb].fst,fabi=mint[lwb].snd;
		}
		if(lwb>0&&ci*p[minp[lwb-1]]<=pp){
			//cout<<"minp: "<<ci<<" "<<p[minp[lwb-1]]<<" = "<<ci*p[minp[lwb-1]]<<"\n";
			ll resii=ci*pi-ci*p[minp[lwb-1]];
			if(resii>resi)fabi=minp[lwb-1],resi=resii;
		}
		if(resi>res){
			res=resi;
			Fab=fabi+1;
			Comp=i.snd+1;
		}
	}
	return res;
}
