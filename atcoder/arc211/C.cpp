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

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	while(s.back()=='#')s.pop_back(),a.pop_back(),n--;
	ll mx=0,good=0;
	fore(i,0,n)good|=s[i]=='.',mx=max(mx,good*a[i]);
	vector<array<ll,3>> b; // ty, q, hasmax
	vv cur;
	fore(i,0,n){
		cur.pb(a[i]);
		if(i==n-1||s[i+1]!=s[i]){
			ll curmax=*max_element(ALL(cur));
			ll c=count(ALL(cur),curmax);
			b.pb({s[i]=='#',c,curmax==mx});
			cur.clear();
		}
	}
	// for(auto [x,y]:b)cout<<x<<","<<y<<" ";;cout<<"\n";
	ll res=0;
	fore(i,0,SZ(b))if(b[i][0]==0&&i+2<SZ(b)){
		auto [asd,q,has]=b[i];
		has|=b[i+1][2]||b[i+2][2];
		ll cant=q*b[i+2][1];
		res+=has*cant;
	}
	cout<<res<<"\n";
	return 0;
}
