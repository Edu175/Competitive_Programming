#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n;cin>>n;
	vector<ll>v;
	fore(i,0,n){
		ll x;
		cin>>x;
		v.pb(x);
	}
	while(SZ(v)&&v.back()%2==0)v.pop_back();
	for(auto i:v){
		cout<<i<<" ";
	}
	 return 0;
}