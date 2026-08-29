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
	ll _; cin>>_; while(_--){
		string s; cin>>s;
		ll n=SZ(s);
		ll cnt[n];
		cnt[n-1]=1;
		for(ll i=n-2; i>=0; i--){
			if(s[i]!=s[i+1]) cnt[i]=1;
			else cnt[i]=cnt[i+1]+1;
		}
		auto cmp=[&](const ll _i,const ll _j){
			bool f=false;
			ll i=_i, j=_j;
			if(i>j) f=1, swap(i,j);
			if(j<i+cnt[i]) return false;
			return bool(f^(s[i+cnt[i]]<s[i]));
		};
		ll p[n]; iota(p,p+n,0);
		sort(p,p+n,cmp);
		fore(i,0,n) if(i!=p[(n-1)/2]) cout<<s[i];;cout<<"\n";
	}
	return 0;
}