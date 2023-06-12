#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=511000,MAXT=505;
/*struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
};*/
ll t;
ll cv(ii x){return i*t+j;}
//ii cvi
struct data{
	ll sz,ty;
	vector<ll>q(3);
	vector<ll>nodes;
	data(ll x):(sz(1),ty(0),nodes(1,x)){}
};

ii operator+(ii a, ii b){return{a.fst+b.fst,a.snd+b.snd};}
map<pair<ll,ll>,ll>mp;
vector<ii>dir {{-1,0},{0,-1},{0,1},{1,0}};
vector<ll>dirx{-t,     -1,    1,    t};
//              ^       <     >     v
vector<pair<ll,ll>>tab;

ll id[MAXT*MAXT]; vector<node>comp[MAXT*MAXT];
void uf_init(){
	fore(i,0,(t+3)*(t+3))id[i]=i,comp[i]=data(i);
}
void join(ll a, ll b){
	if(id[a]==id[b])return;
	if(id[a].sz>id[b].sz)swap(a,b);
	ll c=id[a],d=id[b];
	ll ty=comp[c].ty;
	comp[c].ty=max(comp[c].ty,comp[d].ty);
	comp[c].sz+=comp[d].sz;
	for(auto i:)
}
//y=i , x=j
int establo(int T, vector<int> &tx1, vector<int> &ty1, vector<int> &tx2, vector<int> &ty2, int ex, int ey) {
	ll n=SZ(tx1);
	t=T;
	fore(i,0,n){
		ii a={tx1[i],ty1[i]}, b={tx2[i],ty2[i]};
		if(a>b)swap(a,b);
		ii c=b,d;
		if(a.fst==b.fst)d=c+dir[3];	//tablon horizontal v
		else d=c+dir[2];			//tablon vertical >
		if(c>d)swap(c,d);
		//cout<<a.fst<<","<<a.snd<<" "<<b.fst<<","<<b.snd<<": "<<c.fst<<","<<c.snd<<" "<<d.fst<<","<<d.snd<<"\n";
		mp[{cv(c),cv(d)}]=i;
		tab[i]={cv(c),cv(d)};
	}
	ll res=n+5;
	
	return n-res;
}
