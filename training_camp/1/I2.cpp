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

const ll MAXN=500005;
pair<ll,ll> aska[MAXN];
bool vis[MAXN];

pair<ll,ll> ask(ll q){
	if(vis[q])return aska[q];
	else vis[q]=1;
	pair<ll,ll>p;
	cout<<"? "<<q<<endl;
	cin>>p.fst>>p.snd;
	return aska[q]=p;
}

int main(){FIN;
	ll n,s,x; cin>>n>>s>>x;
	vector<ll>v;
	ll resx=-1;
	fore(i,0,n)v.pb(i+1);
	srand(time(0));
	random_shuffle(ALL(v));
	pair<ll,ll> maxi={-3,s};
	ll res;
	fore(i,0,min(n,ll(1000))){
		pair<ll,ll>p=ask(v[i]);
		if(p.fst==x)resx=x;
		if(p.fst<x)maxi=max(maxi,p);
	}
	if(resx>-1)res=resx;
	else {
		fore(i,0,1000){
			if(maxi.fst>=x||maxi.snd==-1)break;
			maxi=ask(maxi.snd);
		}
		res=maxi.fst;
		if(maxi.fst<x)res=-1;
	}
	cout<<"! "<<res<<endl;
	return 0;
}
