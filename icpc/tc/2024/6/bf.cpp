#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define imp(v) {for(auto fdkhg:v)cout<<fdkhg<<" ";cout<<"\n";}
string cv(vector<ll>a){
	string ret="{ ";
	for(auto i:a)ret+=to_string(i)+" ";
	ret+="}";
	return ret;
}
const ll MAXN=605,MAXM=2005;

string S;

vector<pair<ll,string>>g[MAXN];

vector<ll>ord;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}

int main(){JET
	ll n,m,D,s; cin>>n>>m>>D>>s; s--;
	cin>>S;
	fore(i,0,m){
		ll u,v,l,r,len; cin>>u>>v>>l>>len; u--,v--,l--;
		r=l+len;
		// cout<<u<<","<<v<<" "<<l<<","<<r<<endl;
		string s;
		fore(j,l,r)s.pb(S[j]);
		g[u].pb({v,s});
	}
	dfs(s);
	// reverse(ALL(ord));
	deque<ll>ans[n];
	fore(t,0,n){
		// cout<<t<<" t\n";
		string dp[n];  // aristas
		vector<ll>is(n);
		deque<ll> cam[n]; // nodos
		for(auto x:ord){
			// if(x==t){cam[x]={x};continue;}
			for(auto [y,i]:g[x])if(SZ(cam[y])){
				auto tmp=i+dp[y];
				// cout<<"pruebo "<<x<<" "<<y<<": "<<i<<"+"<<dp[y]<<" = "<<tmp<<"\n";
				if(!is[x]||tmp<dp[x])
					dp[x]=tmp,cam[x]=cam[y];
				is[x]=1;
			}
			if(x==t||SZ(cam[x]))cam[x].push_front(x);
			// cout<<x<<": "<<dp[x]<<" | "; imp(cam[x])
			
		}
		ans[t]=cam[s];
		// cout<<dp[s]<<"\n";
	}
	// fore(x,0,n){
	// 	cout<<x<<" dp: ";
	// 	for(auto i:dp[x])cout<<i+1<<" ";
	// 	cout<<"\n";
	// }
	// cout<<" =============\n";
	fore(x,0,n){
		cout<<SZ(ans[x])<<" ";
		for(auto i:ans[x])cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}