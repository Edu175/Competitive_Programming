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
const ll MAXN=17,MAXT=12;
/*struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
};*/
ii operator+(ii a, ii b){return{a.fst+b.fst,a.snd+b.snd};}
set<pair<pair<ii,ii>,ll>>st;
ll t;
ll vis[MAXT][MAXT];
ll flag=1,mk;
vector<ii>dir{{-1,0},{0,-1},{0,1},{1,0}};
//              ^       <     >     v
bool allowed(ii a, ii b){
	if(vis[b.fst][b.snd])return 0;
	if(a>b)swap(a,b);
	auto lwb=st.lower_bound({{a,b},-1});
	pair<ii,ii>tab={a,b};
	if(lwb!=st.end()&&(*lwb).fst==tab&&(mk&(1ll<<((*lwb).snd))))
		return 0;
	return 1;
}
bool out(ii a){
	if(a.fst<1||a.fst>t||a.snd<1||a.snd>t)return 1;
	return 0;
}
void dfs(ii x){
	vis[x.fst][x.snd]=1;
	//cout<<x.fst<<","<<x.snd<<"\n";
	for(auto i:dir){
		ii y=x+i;
		if(!allowed(x,y))continue;
		if(out(y)){
			flag=0;
			return;
			//,cout<<y.fst<<","<<y.snd<<" out\n";
		}
		else dfs(y);
	}
}
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
		st.insert({{c,d},i});
	}
	ll res=n+5;
	fore(i,0,1ll<<n){	
		mset(vis,0);
		mk=i;
		//cout<<mk<<":\n";
		flag=1;
		dfs({ey,ex});
		if(flag)res=min(res,(ll)__builtin_popcountll(mk));
		//cout<<"\n";
	}
	return n-res;
}
