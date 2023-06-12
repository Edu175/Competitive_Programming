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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		map<ll,ll>m;
		ll res=0;
		ll it;
		fore(i,0,n){
			cin>>a[i];
			m[a[i]]++;
			if(m[a[i]]>=3){
				res=1;
				it=a[i];
			}
		}
		//for(auto i:m)cout<<i<<" ";
		//cout<<"\n";
		if(res)cout<<it<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}
