#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll cv(string s){
	return stoll(s.substr(0,2))*60+stoll(s.substr(3));
}

int main(){FIN;
	ll n; cin>>n;
	vector<array<ll,3>> a(n);
	fore(i,0,n){
		string sl; cin>>sl;
		string sr; cin>>sr;
		ll l=cv(sl),r=cv(sr);
		a[i]={l,r,i};
	}
	sort(ALL(a),[&](array<ll,3> a, array<ll,3> b){
		return a[1]<b[1];
	});
	vv res;
	ll R=-1;
	for(auto [l,r,i]:a){
		if(l>=R)R=r,res.pb(i);
	}
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
