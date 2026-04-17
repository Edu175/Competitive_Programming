#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e4+5;
vv g[MAXN];
ll grad[MAXN];
ll ests[MAXN];
ll estd[MAXN];
bool s[MAXN];
bool d[MAXN];
ll vis[MAXN];
ll n,m;
bool dfs(ll i, bool b){
	vis[i]=true;
	b=!b;
	if(b){
		bool x=false;
		for(ll v:g[i])if(!vis[v]&&s[v]){
			x=x|dfs(v,b);
		}
		ests[i]=x;
		return x;
	}
	bool x=true;
	for(ll v:g[i])if(!vis[v]){
		x=x&dfs(i,b);
	}
	ests[i]=x;
	if(grad[x]==1) x=1;
	return x;
}
bool dfd(ll i, bool b){
	vis[i]=true;
	b=!b;
	if(b){
		bool x=false;
		for(ll v:g[i])if(!vis[v]&&d[v]){
			x=x|dfd(v,b);
		}
		cout<<"d "<<i<<" "<<x<<"\n";
		estd[i]=x;
		return x;
	}
	bool x=false;
	for(ll v:g[i])if(!vis[v]){
		x=x|dfd(i,b);
	}
	estd[i]=x;
	if(grad[x]==1) x=1;
	cout<<"d "<<i<<" "<<x<<"\n";
	return x;
}
ii cnt={0,0};
void defese(ll i){
	vis[i]=true;
	if(s[i]) cnt.fst++;
	if(d[i]) cnt.snd++;
	for(ll v:g[i])if(!vis[v]&&!ests[v]){
		defese(v);
	}
}
bool isIlegal(){
	fore(i,0,n){
		if(s[i]){
			for(ll v: g[i]){
				if(s[v]) return true;
			}
		}
		if(d[i]){
			for(ll v: g[i]){
				if(d[v]) return true;
			}
		}
	}
	return false;
}
int main(){
	JET
	n=-1;
	ll _; cin>>_; while(_--){
		mset(vis,0); mset(d,0); mset(s,0); mset(ests,0);mset(estd,0); mset(grad,0);
		if(n>0)fore(i,0,n) g[i].clear();
		
		cin>>n>>m;
		fore(i,1,n){
			ll x; cin>>x; x--; g[x].pb(i); g[i].pb(x); grad[x]++; grad[i]++;
		}
		fore(i,0,m) {ll x; cin>>x; x--; s[x]=1;}
		fore(i,0,m) {ll x; cin>>x; x--; d[x]=1;}
		if(m>((n+1)/2)||isIlegal()){
			cout<<"0a\n"; continue;
		}
		fore(i,0,n){
			if(!vis[i]&&s[i]&&(grad[i]==1)) dfs(i,1);
		}
		mset(vis,0);
		fore(i,0,n){
			if(!vis[i]&&d[i]&&(grad[i]==1)) dfd(i,1);
		}
		bool y=true;
		fore(i,0,n)if((s[i]&&ests[i]&&!d[i])||(d[i]&&estd[i]&&!s[i])) {y=false;break;}
		if(!y){cout<<"b0\n"; continue;}
		mset(vis,0);
		fore(i,0,n) cout<<ests[i]<<" ";
		cout<<"\n";
		fore(i,0,n) cout<<estd[i]<<" ";
		cout<<"\n";
		fore(i,0,n){
			if(!vis[i]&&!ests[i]){
				cnt={0,0};
				defese(i);
				if(cnt.fst!=cnt.snd) {y=false; break;}
			} 
		}
		if(!y){cout<<"c0\n"; continue;}
		cout<<"1\n";
	}
	return 0;
}