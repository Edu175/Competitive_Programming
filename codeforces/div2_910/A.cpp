#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		ll c=0;
		for(auto i:s)c+=(i=='B');
		if(k==c){
			cout<<"0\n";
			continue;
		}
		cout<<"1\n";
		if(c>k){
			ll q=0;
			fore(i,0,n){
				q+=(s[i]=='B');
				if(q==c-k){
					cout<<i+1<<" A\n";
					break;
				}
			}
		}
		else {
			ll q=0;
			fore(i,0,n){
				q+=(s[i]=='A');
				if(q==k-c){
					cout<<i+1<<" B\n";
					break;
				}
			}
		}
	}
	return 0;
}
