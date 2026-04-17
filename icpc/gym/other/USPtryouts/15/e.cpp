#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll MAXN=1e3+5;
ll n,m;
vector<ii> dir={{1,0},{-1,0},{0,1},{0,-1}};
ll cv(ii x){return x.fst*m+x.snd;}
ii cv(ll x){return {x/m,x%m};}
char a[MAXN*MAXN];
ll go(ll d, ll _x){
	ii x=cv(_x);
	x={x.fst+dir[d].fst,x.snd+dir[d].snd};
	if(x.fst<0||x.fst>=n)return -1;
	if(x.snd<0||x.snd>=m)return -1;
	if(a[cv(x)]=='#')return -1;
	return cv(x);
}
vv dijkstra(ll s){
	vv d(n*m,-1);
	d[s]=0;
	queue<ll>q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(di,0,SZ(dir)){
			auto y=go(di,x);
			if(y==-1||d[y]!=-1)continue;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}


int main(){
	JET
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		ll p=-1;
		vv fs,ss;
		fore(i,0,n*m){
			cin>>a[i];
			if(a[i]=='E')p=i;
			if(a[i]=='F')fs.pb(i);
			if(a[i]=='S')ss.pb(i);
		}
		auto d=dijkstra(p);
		ll mn=n*m+5;
		for(auto i:fs)if(d[i]!=-1)mn=min(mn,d[i]);
		ll dis=d[ss[0]];
		if(dis!=-1&&dis<mn)cout<<"Y\n";
		else cout<<"N\n";
	}	
	return 0;
}