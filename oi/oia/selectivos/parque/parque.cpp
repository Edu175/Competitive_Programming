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
const ll MAXN=1e3+5;

struct pt{
	ll x,y;
};
ll fqrt(ll x){
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}
ll dis(pt a, pt b){
	return fqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))+2;
}
ll is[MAXN],n;
pt a[MAXN];
vector<ll>g[MAXN];
ll prim(){
	ll res=0,q=n;
	priority_queue<pair<ll,pair<ll,ll>>>pq;
	fore(i,0,n)pq.push({-dis(a[0],a[i]),{0,i}});
	is[0]=1; q--;
	while(SZ(pq)&&q){
		ll d=-pq.top().fst,u=pq.top().snd.fst,v=pq.top().snd.snd;
		pq.pop();
		if(is[u]&&is[v])continue;
		is[v]=1; q--;
		fore(i,0,n)pq.push({-dis(a[v],a[i]),{v,i}});
		g[u].pb(v);
		g[v].pb(u);
		res+=d;
	}
	return res;
}
int main(){FIN;
	ifstream cin;   cin.open("parque.in", ios::in);
	ofstream cout; cout.open("parque.out", ios::out);
	cin>>n;
	a[0].x=0,a[0].y=0;
	fore(i,0,n){
		ll id; cin>>id;
		cin>>a[id].x>>a[id].y;
	}
	n++;
	cout<<prim()<<"\n";
	fore(i,1,n){
		cout<<i<<" ";
		for(auto j:g[i])cout<<j<<" ";
		cout<<"\n";
	}
	//fore(i,0,n+1)cout<<is[i]<<" ";
	return 0;
}
