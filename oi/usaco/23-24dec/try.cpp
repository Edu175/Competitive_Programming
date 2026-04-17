#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;


int main(){FIN;
	ll __; cin>>__;
	while(__--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].snd;
		fore(i,0,n)cin>>a[i].fst;
		vector<ll>p(n);
		fore(i,0,n)cin>>p[i],p[i]=n-1-p[i];
		cout<<"-1\n";
	}
	return 0;
}
