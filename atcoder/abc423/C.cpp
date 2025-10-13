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
	ll n,p; cin>>n>>p;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll l=0,r=n;
	while(l<p&&a[l])l++;
	while(r>p&&a[r-1])r--;
	ll res=0;
	fore(i,l,r)res+=1+a[i];
	cout<<res<<"\n";
	return 0;
}
