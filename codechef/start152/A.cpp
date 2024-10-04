#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		map<char,ll> mp[n];
		fore(i,0,m){
			string s; cin>>s;
			fore(j,0,n)mp[j][s[j]]++;
		}
		ll res=0;
		fore(i,0,n){
			ll a=mp[i]['0'],b=mp[i]['1'],c=mp[i]['?'];
			while(c){
				if(a<b)a++;
				else b++;
				c--;
			}
			res+=a*b;
		}
		cout<<res<<"\n";
	}
	return 0;
}
