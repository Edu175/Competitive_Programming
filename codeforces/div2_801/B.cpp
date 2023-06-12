#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		pair<ll,ll> m={1e10,-1}, j={1e10,-1};
		fore(i,0,n){
			ll a;
			cin>>a;
			if(i%2){
				if(a<j.fst)j.fst=a, j.snd=i;
			}
			else {
				if(a<m.fst)m.fst=a, m.snd=i;
			}
		}
		if(n%2)cout<<"Mike\n";
		else {
			if(m>j)cout<<"Mike\n";
			else cout<<"Joe\n";
		}
	}
	return 0;
}
