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
	ll n; cin>>n;
	map<ll,ll>mpa,mpb;
	set<ll>v;
	fore(i,0,n){
		ll ty,x,t; cin>>ty>>x>>t;
		x-=t;
		if(ty==1)mpa[x]++;
		else mpb[x]++;
		v.insert(x);
	}
	ll res=0;
	for(auto i:v)res+=min(mpa[i],mpb[i]);
	cout<<res<<"\n";
	return 0;
}