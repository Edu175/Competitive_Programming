#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const ll maxn=1e5+5;
ll l[maxn],r[maxn],wh[2*maxn];
ll nxtL[2*maxn], nxtR[2*maxn];
ll vis[maxn];
ll n;

void solve(){
	cin>>n;
	fore(i,0,n) vis[i]=0;
	
	vi lr;
	fore(i,0,n){
		cin>>l[i]>>r[i];
		lr.pb({l[i],i}); 
	}
	sort(ALL(lr));
	
	ll j=lr[0].snd;
	ll R=r[j];
	fore(i,0,n){
		auto [p,k]= lr[i];
		if(p>R) break;
		vis[k]=1;
		R=max(R,r[k]);
	}
	ll bad=1;
	fore(i,0,n) if(!vis[i]) bad=0;
	if(bad){
		cout<<"-1\n"; return;
	}
	fore(i,0,n){
		cout<<vis[i]+1<<" ";
	}
	cout<<"\n";
	
}
int main(){
	JET
	ll _; cin>>_; while(_--){
		solve();
	}
	return 0;
}
