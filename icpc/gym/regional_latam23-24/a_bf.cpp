#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll val(ii a, ii b){
	if(a.fst>=b.fst)return 0;
	if(a.snd>=b.snd)return 0;
	return (b.fst-a.fst)*(b.snd-a.snd);
}

int main(){
	ET;
	ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	
	vector<ii>b;
	
	ll q; cin>>q;
	while(q--){
		char ty; cin>>ty;
		if(ty=='s'){
			ll i; cin>>i; i--;
			ll res=0;
			for(auto j:b)res=max(res,val(a[i],j));
			cout<<res<<"\n";
		}
		else { // fst++
			ll x,y; cin>>x>>y; x++;
			b.pb({x,y});
		}
	}
}