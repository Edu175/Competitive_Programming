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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll l=0,r=n-1;
		ll p=0,q=n-1;
		auto esta=[&](ll x){return b[p]==x||b[q]==x;};
		ll win=1;
		while(l<=r){
			auto gol=[&](){
				if(b[p]==a[l])p++;
				else q--;
				l++;
			};
			auto gor=[&](){
				if(b[p]==a[r])p++;
				else q--;
				r--;
			};
			if(!esta(a[l])||!esta(a[r])){win=0;break;}
			else {
				gol();
				gor();
			}
		}
		if(win)cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
}
