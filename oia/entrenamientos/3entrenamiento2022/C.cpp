#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

int main(){
	ll n; cin>>n;
	pair<ll,ll>c; cin>>c.fst>>c.snd;
	vector<pair<pair<ll,ll>,ll>> a(n);
	fore(i,0,n){
		cin>>a[i].fst.fst>>a[i].fst.snd;
		a[i].fst.snd*=(-1);
		a[i].snd=i;
	}
	sort(ALL(a));
	vector<pair<ll,ll>>b;
	for(auto& i:a){
		i.fst.snd*=(-1);
		if(i.fst.fst>c.fst&&i.fst.snd>c.snd)b.pb({i.fst.snd,i.snd});
	}
	/*for(auto i:a){
		cout<<"{"<<i.fst.fst<<","<<i.fst.snd<<"},"<<i.snd<<" ";
	}
	cout<<"\n";*/
	/*for(auto i:b){
		cout<<i.fst<<","<<i.snd<<" ";
	}
	cout<<"\n";*/
	ll lis[n],p[n];
	mset(lis,-1);
	mset(p,-1);
	vector<pair<ll,ll>>v;
	for(auto i:b){
		pair<ll,ll>clitoris={i.fst,-1};
		ll lwb=lower_bound(ALL(v),clitoris)-v.begin();//   POV: buscando el clitoris
		lis[i.snd]=lwb+1;
		if(lwb==SZ(v)){
			if(SZ(v))p[i.snd]=v.back().snd;
			v.pb(i);
		}
		else {
			p[i.snd]=p[v[lwb].snd];
			if(i.fst<v[lwb].fst)v[lwb]=i;
		}
	}
	ll x=-1;
	fore(i,0,n){
		if(lis[i]==-1)continue;
		if(x==-1||lis[x]<lis[i])x=i;
	}
	/*for(auto i:v){
		cout<<i.fst<<","<<i.snd<<" ";
	}
	cout<<"\n";
	imp(lis);
	imp(p);*/
	vector<ll>res;
	while(x!=-1){
		res.pb(x+1);
		x=p[x];
	}
	reverse(ALL(res));
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}

