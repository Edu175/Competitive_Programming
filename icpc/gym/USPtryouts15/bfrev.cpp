#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,h,k; cin>>n>>h>>k;
		vector<ii>a;
		fore(i,0,n){
			ll x,y; cin>>x>>y; y-=x;
			if(y<0)a.pb({x,y});
		}
		sort(ALL(a));
		ll res=1e18;
		n=SZ(a);
		do{
			ll c=0,h=0;
			fore(i,0,n){
				if(i>=n-k)res=min(res,h);
				auto [x,y]=a[i];
				h-=y; h=max(h,x);
			}
			res=min(res,h);
		}while(next_permutation(ALL(a)));
		cout<<res<<"\n";
	}
	return 0;
}