#include "worldmap.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define imp1(v) {for(auto i:v)cout<<i+1<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXK=240;

void achica(vector<vector<int>> &a){
	ll mxv=-1,mxh=-1;
	fore(i,0,SZ(a))fore(j,0,SZ(a[i]))if(a[i][j]!=-1){
		mxv=max(mxv,i);
		mxh=max(mxh,j);
	}
	ll k=max(mxv,mxh)+1;
	a.resize(k);
	fore(i,0,k)a[i].resize(k);
}

vector<vector<int>> ans(MAXK,vector<int>(MAXK,-1));
vv col(MAXK,-1);
const ll MAXN=50,MAXM=MAXN*MAXN;
vector<ii> g[MAXN];
ll vis[MAXN];
ll vised[MAXM];
ll cnt=0;
void dfs(ll x){
	vis[x]=1;
	col[cnt]=col[cnt+1]=col[cnt+2]=x;
	ll j=cnt+1;
	cnt+=3;
	ll ba=0;
	for(auto [y,idx]:g[x])if(!vised[idx]){
		vised[idx]=1;
		if(!vis[y]){ // tree
			dfs(y);
			col[cnt++]=x;
		}
		else { // back
			ans[ba][j]=y;
			ba+=2;
		}
	}
	// ans[ba][j]=x;
}

vector<vector<int>> create_map(int N, int M, vector<int> A, vector<int> B) {
	ans=vector<vector<int>> (MAXK,vector<int>(MAXK,-1));
	col=vv(MAXK,-1);
	ll n=N;
	
	fore(i,0,n){
		g[i].clear();
		vis[i]=0;
	}
	cnt=0;
	fore(i,0,M){
		vised[i]=0;
		A[i]--,B[i]--;
		g[A[i]].pb({B[i],i});
		g[B[i]].pb({A[i],i});
	}
	
	dfs(0);
	ll fg=1;
	fore(i,0,n)fg&=vis[i];
	assert(fg);
	ll k=cnt;
	// cerr<<k<<"\n";
	fore(i,0,k)fore(j,0,k){
		if(ans[i][j]==-1)ans[i][j]=col[j];
	}
	
	achica(ans);
	assert(k==SZ(ans));
	fore(i,0,k)fore(j,0,k){
		ans[i][j]++; // 1-indexed
	}
	return ans;
}
