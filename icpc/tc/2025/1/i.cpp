#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105,MAXM=65;
vector<int> g[MAXN];
int n,m;
int mat[MAXM]; bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
ll mm(){
	mset(mat,-1);
	fore(i,0,n)mset(vis,0),match(i);
	ll res=0;
	fore(i,0,m)if(mat[i]>=0)res++;
	return res;
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		fore(i,0,MAXN) g[i].clear();
		cin>>n;
		fore(i,0,n){
			ll x; cin>>x;
			fore(j,0,62){
				if(x>>j&1)g[i].pb(j);
			}
		}
		m=MAXM;
		ll k=mm();
		// cout<<k<<": ";
		cout<<n-k<<"\n";
	}
	return 0;
}