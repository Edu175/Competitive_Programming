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
const ll MAXN=6e5,MAXT=505;

ii operator+(ii a, ii b){return{a.fst+b.fst,a.snd+b.snd};}
set<pair<ii,ii>,ll>mp;
ll t; ll vis[MAXT][MAXT];
ll cv (ii x){return i*t+j;}
ii cvi(ll v){return {v/t,v%t};}
vector<ii>dir{{-1,0},{0,-1},{0,1},{1,0}};
//              ^       <     >     v
bool allowed(ii a, ii b){
	if(a.fst<0||a.fst>t+1||a.snd<0||a.snd>t+1)return 0;
	if(vis[b.fst][b.snd])return 0;
	if(a>b)swap(a,b);
	auto lwb=st.lower_bound({{a,b},-1});
	pair<ii,ii>tab={a,b};
	if(mp.count(tab))return 0;
	return 1;
}
bool out(ii a){
	if(a.fst<1||a.fst>t||a.snd<1||a.snd>t)return 1;
	return 0;
}
struct data{
	ll sz,ty;
	vector<ii>nodes;
	ll q1=0,q=0;
	data(ii x):(sz(1),ty(0),nodes(1,x)){}
};
vector<data>cm;
ll id[MAXT*MAXT]
ll ix=0;
ii e;
void dfs(ii x){
	vis[x.fst][x.snd]=1;
	if(out(x))cm[ix].ty=2;
	if(x==e)cm[ix].ty=1;
	cm[ix].nodes.pb(x);
	id[cv(x)]=ix;
	cm[ix].sz++;
	//cout<<x.fst<<","<<x.snd<<"\n";
	for(auto i:dir){
		ii y=x+i;
		ii s={min(x,y),max(x,y)};
		if(mp.count(s)){
			if(vis[y]){
				ll iy=id[cv(y)];
				if(iy!=ix){
					cm[ix].q++;
					cm[iy].q++;
					if(cm[iy].ty==1)cm[ix].q1++;
					if(cm[ix].ty==1)cm[iy].q1++;
				}
			}
		}
		if(!allowed(x,y))continue;
		dfs(y);
	}
}
void dfs2(ll x){
	vis[x]=1;
	for(auto i:dir){
		ii y=x+i;
		if(a.fst<0||a.fst>t+1||a.snd<0||a.snd>t+1)continue;
		if(vis[b.fst][b.snd])continue;
		ii s={min(x,y),max(x,y)};
		if(mp.count(s)){
			ll iy=id[cv(y)];
			if(cm[iy].q-cm[iy].q1<cm[iy].q1)
		}
	}
}
int establo(int T, vector<int> &tx1, vector<int> &ty1, vector<int> &tx2, vector<int> &ty2, int ex, int ey) {
	ll n=SZ(tx1);
	t=T;
	e={ey,ex};
	fore(i,0,n){
		ii a={ty1[i],tx1[i]}, b={ty2[i],tx2[i]};
		if(a>b)swap(a,b);
		ii c=b,d;
		if(a.fst==b.fst)d=c+dir[3];	//tablon horizontal v
		else d=c+dir[2];			//tablon vertical >
		if(c>d)swap(c,d);
		//cout<<a.fst<<","<<a.snd<<" "<<b.fst<<","<<b.snd<<": "<<c.fst<<","<<c.snd<<" "<<d.fst<<","<<d.snd<<"\n";
		mp[{c,d}]=i;
	}
	dfs(e);
	fore(i,0,t+2)fore(j,0,t+2)if(!vis[i][j]){
		++ix;
		cm.pb(data({i,j}));
		dfs({i,j});
	}
	mset(vis,0);
	dfs2(x);
	return n-res;
}
//mbappe la tenés adentro
