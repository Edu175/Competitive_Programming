#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll ty; cin>>ty;
	assert(ty==1);
	ll n; cin>>n;
	vv h(n);
	fore(i,0,n)cin>>h[i];
	
	auto good=[&](vv s){
		assert(SZ(s)==3);
		vector<ll> ds,hs;
		fore(i,0,3)fore(j,i+1,3)ds.pb(abs(s[i]-s[j]));
		fore(i,0,3)hs.pb(h[s[i]]);
		sort(ALL(hs));
		sort(ALL(ds));
		return ds==hs;
	};
	
	ll res=0;
	
	fore(j,0,n)fore(i,0,j)fore(k,j+1,n)if(good({i,j,k})){
		cerr<<i<<" "<<j<<" "<<k<<": ";
		cerr<<h[i]<<" "<<h[j]<<" "<<h[k]<<"\n";
		res++;
	}
	cerr<<"total "<<res<<"\n";
}