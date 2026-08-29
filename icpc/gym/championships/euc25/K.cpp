#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n; cin>>n;
		set<ll> s;
		vv a(n);
		fore(i,0,n){
			cin>>a[i];
		}
		sort(ALL(a));
		reverse(ALL(a));
		ll r=0;
		fore(i,0,n){
			ll x=a[i];
			while(s.count(x)) x+=a[i];
			s.insert(x);
			r=max(r,x);
		}
		cout<<r<<"\n";
		
	}
	return 0;
}
