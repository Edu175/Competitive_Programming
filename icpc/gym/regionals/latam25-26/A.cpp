#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005;

ll hay[MAXN][MAXN];
ll vis[MAXN];
ll n,used=0;
void dfs(ll x){
	vis[x]=1;
	fore(y,0,n)if(!hay[x][y]){
		hay[x][y]++;
		used=1;
		if(!vis[y])dfs(y);
	}
}
void say(bool b){
	cout<<"NY"[b]<<"\n";
	exit(0);
	assert(0);
}
int main(){FIN;
	cin>>n;
	ll p,q;
	vv l,r;
	cin>>p; l.resize(p); fore(i,0,p)cin>>l[i],l[i]--;
	cin>>q; r.resize(q); fore(i,0,q)cin>>r[i],r[i]--;
	fore(i,0,p-1){
		hay[l[i]][l[i+1]]++;
		hay[l[i+1]][l[i]]++;
	}
	fore(i,0,q-1){
		hay[r[i]][r[i+1]]++;
		hay[r[i+1]][r[i]]++;
	}
	fore(i,0,n)hay[i][i]++;
	vv deg(n);
	fore(i,0,n)fore(j,0,n)deg[i]^=!hay[i][j];
	if(!p&&!q)say((n&1)||n==2);
	ll s=p?l.back():-1;
	ll t=q?r[0]:-1;
	if(s!=-1)deg[s]^=1;
	if(t!=-1)deg[t]^=1;
	ll ods=0;
	fore(i,0,n)ods+=deg[i];
	ll fg=s==-1||t==-1;
	if(ods!=fg)say(0);
	dfs(s==-1?t:s);
	fore(i,0,n)fore(j,0,n)if(hay[i][j]!=1)say(0);
	if(!used&&!fg)say(0);
	say(1);
	return 0;
}