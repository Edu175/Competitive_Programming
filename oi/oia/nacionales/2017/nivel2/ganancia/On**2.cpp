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
	/*ll cf[n],pf[n];
	fore(i,0,n)cf[i]=fabricantes[i].cantidad,pf[i]=fabricantes[i].precio;
	ll cc[n],pc[n];
	fore(i,0,m)cc[i]=compradores[i].cantidad,pc[i]=compradores[i].precio;*/
	vector<pair<pair<ll,ll>,ll>>fab,com;
	fore(i,0,n)fab.pb({{fabricantes[i].precio,facricantes[i].cantidad},i});
	fore(i,0,n)com.pb({{compradores[i].precio,compradores[i].cantidad},i});
	ll res=-1;
	/*cout<<"fab:\n";
	for(auto i:fab)cout<<i.snd<<": "<<i.fst.fst<<" "<<i.fst.snd<<"\n";
	cout<<"com:\n";
	for(auto i:com)cout<<i.snd<<": "<<i.fst.fst<<" "<<i.fst.snd<<"\n";
	cout<<"\n";*/
	for(auto i:fab){
		if(i.fst.fst*i.fst.snd>p)continue;
		//cout<<"\n"<<i.snd+1<<": "<<i.fst.fst<<" "<<i.fst.snd<<" = "<<i.fst.fst*i.fst.snd<<"\n";
		for(auto j:com){
			if(i.fst.fst*j.fst.snd>p)continue;
			//cout<<j.snd+1<<" = "<<i.fst.fst*j.fst.snd<<"\n";
			ll resi=-1;
			if(i.fst.snd>j.fst.snd)resi=j.fst.fst*j.fst.snd-i.fst.fst*i.fst.snd;
			else{
				resi=(j.fst.fst-i.fst.fst)*j.fst.snd;
			}
			if(resi>res){
				res=resi;
				Fab=i.snd+1;
				Comp=j.snd+1;
			}
		}
	}
	return res;
}
