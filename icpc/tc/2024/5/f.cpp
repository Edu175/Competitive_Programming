#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ll>h[m];
	fore(i,0,n){
		ll v,w; cin>>v>>w; v--;
		h[v].pb(w);
	}
	fore(i,0,m)sort(ALL(h[i])),reverse(ALL(h[i]));
	sort(h,h+m,[&](vv& a, vv& b){return SZ(a)<SZ(b);});
	fore(i,0,m){
		ll sum=0,did=0;
		for(auto &j:h[i]){
			if(did)j=0;
			else {
				if(sum+j<0)j=-sum,did=1;
				else sum+=j;
			}
		}
	}
	ll s=0,ans=0,res=0;
	fore(k,1,n+5){
		while(s<m&&SZ(h[s])<k){
			for(auto i:h[s])res-=i;
			s++;
		}
		fore(i,s,m)res+=h[i][k-1];
		ans=max(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}