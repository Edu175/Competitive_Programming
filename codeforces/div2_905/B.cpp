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
		vector<ll>a(n),b,c;
		fore(i,0,n)cin>>a[i],b.pb((k-a[i]%k)%k),c.pb((2-a[i]%2)%2);
		sort(ALL(b)); sort(ALL(c));
		ll res=0;
		//imp(b); imp(c);
		if(k==4)res=min(b[0],c[0]+c[1]);
		else res=b[0];
		cout<<res<<"\n";
	}
	return 0;
}
