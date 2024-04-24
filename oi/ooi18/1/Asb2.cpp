#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,rus=b;i<rus;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdkjg:v)cout<<sdkjg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<ll>> lis(vector<ii>a){ //minimum partition
	ll n=SZ(a);
	vector<pair<ii,ll>>b;
	fore(i,0,n)b.pb({a[i],i});
	sort(ALL(b));
	sort(ALL(a));
	vector<ll>nxt(n);
	vector<ii>v;
	fore(i,0,n){
		ll lwb=lower_bound(ALL(v),ii({a[i].snd,-1}))-v.begin();
		if(lwb>=SZ(v))nxt[i]=-1,v.pb({a[i].snd,i});
		else nxt[i]=v[lwb].snd,v[lwb]={a[i].snd,i};
	}
	vector<vector<ll>>r;
	for(auto [dfg,x]:v){
		vector<ll>ri;
		while(x!=-1)ri.pb(b[x].snd),x=nxt[x];
		reverse(ALL(ri));
		r.pb(ri);
	}
	return r;
}
int main(){FIN;
	ll task,group; cin>>task>>group;
	assert(task==2);
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	ll c; cin>>c;
	//assert(n==80000&&c==800);
	auto r=lis(a);
	fore(mk,0,4){
		auto ai=a;
		fore(i,0,n){
			if(mk&1)ai[i].snd*=-1;
			if(mk&2)ai[i].fst*=-1;
		}
		auto ri=lis(ai);
		if(SZ(ri)<SZ(r))r=ri;
	}
	assert((SZ(r)-1)*2<=c);
	//for(auto i:r){imp(i);}
	for(auto v:r){
		for(auto i:v)cout<<i+1<<" ";
	}
	cout<<endl;
	return 0;
}
