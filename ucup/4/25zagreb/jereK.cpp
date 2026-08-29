#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t;  cin>>t;
	while(t--){
		ll n; cin>>n;
		n*=2;
		vv a(n), ord(n);
		fore(i,0,n) cin>>a[i];
		iota(ALL(ord),0);
		sort(ALL(ord),[&](int x, int y){return a[x]>a[y];});
		set<ll> s;
		fore(i,0,n) s.insert(i);
		vv res;
		for(auto x:ord){
			if(s.count(x)){
				auto it = s.upper_bound(x);
				if(it!=s.end()){
					res.pb(x+1);
					s.erase(it);
					s.erase(x);
				}
			}
			else{
				auto it = s.upper_bound(x);
				if(it == s.end()) continue;
				auto it2 = it;
				it2++;
				if(it2 == s.end())continue;
				s.erase(it);
				s.erase(it2);
				res.pb(x+1);
			}
		}
		sort(ALL(res));
		show(res);
	}
	return 0;
}