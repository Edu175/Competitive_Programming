#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv xp(n+1);
		fore(i,0,n)xp[i+1]=xp[i]^a[i];
		if(xp[n]!=0){
			cout<<"YES\n2\n1 1\n2 "<<n<<"\n";
			continue;
		}
		vector<ii> cuts;
		ll p=0;
		fore(_,0,2){
			fore(r,p+1,n+1){
				if((xp[r]^xp[p])&&(xp[n]^xp[r])){
					cuts.pb({p,r});
					p=r;
					break;
				}
			}
		}
		cuts.pb({p,n});
		if(SZ(cuts)<3)cout<<"NO\n";
		else {
			cout<<"YES\n3\n";
			for(auto [l,r]:cuts)cout<<l+1<<" "<<r<<"\n";
		}
	}
	return 0;
}