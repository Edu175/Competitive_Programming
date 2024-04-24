#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ii a[MAXN];
ll ty[MAXN];

struct ev{
	ll l,r,h,t;
};

ll ver(ll e){
	set<ll>st;
	vector<ev>v;
	fore(i,0,e){
		if(ty[i]&1)v.pb(ev({a[i].snd,a[i+1].snd,a[i].fst,1}));
		else v.pb({a[i].snd,-1,a[i].fst})
		
	}
}
bool hay(ll e){
	if(ty[e-1]&1)return ver(e);
}
int main(){FIN;
	ll x=0,y=0;
	a.pb(x,y);
	char _t='.';
	ll res=0,flag=0;
	fore(i,0,n){
		char t; ll v; cin>>t>>v;
		if(t=='R')x+=v,flag|=_t=='L',ty[i]=0;
		if(t=='U')y+=v,flag|=_t=='D',ty[i]=1;
		if(t=='L')x-=v,flag|=_t=='R',ty[i]=2;
		if(t=='D')y-=v,flag|=_t=='U',ty[i]=3;
		a.pb({x,y});
		if(flag)break;
		res+=v;
		_t=t;
	}
	if(flag){
		cout<<res<<"\n";
		return 0;
	}
	
	
	return 0;
}
