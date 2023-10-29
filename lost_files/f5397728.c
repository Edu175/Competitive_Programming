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
		ll n; cin>>n;
		string s; cin>>s;
		ll x=0,g=0;
		fore(i,0,n/2){
			if(s[i]==s[n-1-i])g++;
			else x++;
		}
		vector<ll>res(n+1);
		fore(i,0,n+1){
			if(i>=x&&n-1-i>=x){
				if(n&1)res[i]=1;
				else if(i%2==x%2)res[i]=1;
			}
		}
		for(auto i:res)cout<<i;
		cout<<"\n";
	}
	return 0;
}
