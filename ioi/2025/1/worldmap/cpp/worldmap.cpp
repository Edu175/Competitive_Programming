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

vv col(2*MAXK,-1);
const ll MAXN=50,MAXM=MAXN*MAXN;
vector<ii> g[MAXN];
ll vis[MAXN];
ll vised[MAXM];
ll cnt=0,cnt2=0;
vv back[MAXN];
ll wh[MAXN];
void dfs(ll x){
	vis[x]=1;
	col[cnt]=col[cnt+1]=col[cnt+2]=x;
	ll j=cnt+1;
	wh[x]=j;
	cnt2=cnt;
	cnt+=3;
	ll ba=0;
	for(auto [y,idx]:g[x])if(!vised[idx]){
		vised[idx]=1;
		if(!vis[y]){ // tree
			dfs(y);
			col[cnt++]=x;
		}
		else { // back
			back[x].pb(y);
		}
	}
	// ans[ba][j]=x;
}

vector<vector<int>> create_map(int N, int M, vector<int> A, vector<int> B) {
	col=vv(MAXK,-1);
	ll n=N;
	cnt2=0;
	fore(i,0,n){
		g[i].clear();
		vis[i]=0;
		back[i].clear();
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
	
	auto cant=[&](ll j, ll k){
		if(j<k)return j+1;
		ll d=j-(k-1);
		return k-d;
	};
	ll k=0;
	while(cant(cnt2,k)<1)k++;
	// cerr<<cnt2<<" "<<k<<" "<<cant(cnt2,k)<<endl;
	fore(x,0,n){
		ll w=wh[x];
		while(SZ(back[x])>cant(w,k))k++;
	}
	
	vector<vector<ii>> diag(2*MAXK);
	fore(i,0,k)fore(j,0,k)diag[i+j].pb({i,j});
	
	vector<vector<int>> ans(k,vector<int>(k,-1));
	fore(x,0,n){
		ll c=wh[x],idx=0;
		
		auto [i1,j1]=diag[c-1][0];
		ans[i1][j1]=x;
		
		for(auto i:back[x]){
			assert(idx<SZ(diag[c]));
			auto [i1,j1]=diag[c][idx];
			idx++; // xd
			ans[i1][j1]=i;
		}
	}
	// achica(ans);
	// cerr<<k<<"\n";
	ll ult=-1;
	fore(i,0,k)fore(j,0,k){
		if(ans[i][j]==-1){
			ans[i][j]=col[i+j];
		}
		if(ans[i][j]!=-1)ult=ans[i][j];
	}
	
	fore(i,0,k)fore(j,0,k)if(ans[i][j]==-1)ans[i][j]=ult;
	
	fore(i,0,k)fore(j,0,k){
		ans[i][j]++; // 1-indexed
	}
	return ans;
}
