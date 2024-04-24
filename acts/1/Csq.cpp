#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5,INF=1e10;

ll a[MAXN],h[MAXN],L[MAXN],R[MAXN],ini,fin;
void pop(ll x){
	L[R[x]]=L[x];
	R[L[x]]=R[x];
	L[x]=R[x]=-1;
}
ll n;
void init(){
	fore(i,0,n){
		L[i]=i-1;
		R[i]=i+1;
	}
	R[ini]=0,L[0]=ini;
	R[n-1]=fin,L[fin]=n-1;
	//L[ini]=-1,R[fin]=-1;
}
ll s,e;
bool can(ll x){
	if(x<s||x>=e)return 0;
	//if(a[x]-h[x]<a[0])return 0;
	//if(a[x]+h[x]>a[n-1])return 0;
	return a[L[x]]<=a[x]-h[x]||a[x]+h[x]<=a[R[x]];
}
int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n)cin>>a[i]>>h[i];
	ini=n,fin=n+1;
	a[ini]=a[0]; a[fin]=a[n-1];
	while(q--){
		cin>>s>>e; s--;
		init();
		queue<ll>q;
		//vector<ll>vis(n);
		fore(i,s,e)if(can(i)){
			q.push(i);
			//vis[i]=1;
		}
		ll res=0;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			if(L[x]==-1)continue;
			ll l=L[x],r=R[x];
			//cout<<x<<": "<<l<<" "<<r<<"\n";
			pop(x);
			if(can(l))q.push(l);
			if(can(r))q.push(r);
			res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
