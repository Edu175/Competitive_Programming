#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1e7+10;
int vis[maxn];

int main(){
	TUCUTUCUTUCUTUCU
	int t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		queue<ll> q;
		vv a;
		
		q.push(m);
		vis[m]=1;
		a.pb(m);
		while(!vis[n] && SZ(q)){
			ll x = q.front();
			q.pop();
			if(x+2*x<=n){
				vis[x+2*x]=1;
				q.push(x+2*x);
				a.pb(x+2*x);
			}
			if(x%2==0 && x+x/2<=n){
				vis[x+x/2]=1;
				q.push(x+x/2);
				a.pb(x+x/2);
			}
		}
		(vis[n]) ? cout<<"YES\n" : cout<<"NO\n";
		for (auto x:a) vis[x]=0;
	}
	
	
	return 0;
}