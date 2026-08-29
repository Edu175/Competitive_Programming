#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 2e5+5;
vv g[MAXN];
vv val;

bool wins(ii a, ii b){
	if(a.snd!=b.snd)return a.snd<b.snd;
	return a.fst>b.fst;
}
ll owns[MAXN],rival[MAXN];
ii dfs(ll x){
	owns[x]=x; rival[x]=-1;
	if(!SZ(g[x]))return {x,val[x]};
	ll y1=g[x][0];
	ll y2=g[x][1];
	auto got1=dfs(y1);
	auto got2=dfs(y2);
	if(wins(got1,got2))swap(got1,got2);
	ll sum=got1.snd+got2.snd;
	ll res=got1.fst;
	owns[x]=res; rival[got2.fst]=x;
	return {res,sum};
}
ll n,rt,h;
void query(){
	auto got=dfs(rt);
	// fore(i,0,n)cout<<owns[i]<<" ";;cout<<"\n";
	// fore(i,0,h)cout<<rival[i]<<" ";;cout<<"\n";
	cout<<got.fst+1<<"\n";
}
int main(){
	JET
	
	cin>>n;
	h=n;
	n=2*h-1;
	rt=n-1;
	val=vv(h);
	fore(i,0,h) cin>>val[i];
	fore(i,h,n){
		ll x,y; cin>>x>>y;x--,y--;
		g[i] = {x,y};
	}
	query();
	ll q; cin>>q;
	while(q--){
		ll x,w; cin>>x>>w; x--;
		val[x]+=w;
		query();
	}
	return 0;
}

