#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

pair<ll,ll> dist(pair<ll,ll> p1 , pair<ll,ll> p2){
	pair<ll,ll>res;
	res.fst=p2.fst-p1.fst;
	res.snd=p2.snd-p1.snd;
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>>v;
	map<pair<ll,ll>,ll>lad;
	fore(i,0,n){
		pair<ll,ll>p;
		cin>>p.fst>>p.snd;
		for(auto i:v){
			pair<ll,ll>d=dist(min(p,i),max(p,i));
			lad[d]++;
		}
		v.pb(p);
	}
	ll res=0;
	for(auto i:lad){
		if(i.snd>1)res+=(i.snd*(i.snd-1))/2; //cantidad de lados iguales tomados de a 2
	}
	res/=2;//lo divido por 2 porque cada paralelogramo tiene 2 pares de lados iguales
	pres;
	return 0;
}
