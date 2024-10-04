#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5;
vector<ll> g[MAXN];
ll n,c[MAXN];
ll mat[MAXN];
bool vis[MAXN];

bool match(ll x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:g[x])if(mat[y]==-1||match(mat[y])){
		mat[y]=x;
		return 1;
	}
	return 0;
}

ll mm(ll n){
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	imp(g[i]);
	// }
	mset(mat,-1);
	ll res=0;
	fore(i,0,n)mset(vis,0),res+=match(i);
	return res;
}
int findSample(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	vector<ll>col(n);
	vector<ll>myg[n];
	fore(i,1,n){
		if(t[i]==0){
			// myg[p[i]].pb(i);
			myg[i].pb(p[i]);
			col[i]=col[p[i]]^1;
		}
		else {
			myg[i]=myg[p[i]];
			col[i]=col[p[i]];
		}
		for(auto j:myg[i])myg[j].pb(i);
	}
	// imp(col);
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	imp(myg[i]);
	// }
	ll ids[2]={0,0};
	vector<ll>idx(n);
	fore(i,0,n)idx[i]=ids[col[i]]++;
	fore(i,0,n)if(!col[i]){
		for(auto j:myg[i])g[idx[i]].pb(idx[j]);
	}
	ll res=mm(ids[0]);
	// cout<<"mm: "<<res<<"\n";
	res=n-res;
	return res;
}
