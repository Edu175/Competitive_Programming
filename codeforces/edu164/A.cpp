#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		ll res=!(k>=n-(n+m-1)/m);
		/*if(m==1)res=0;
		else if(2*(k+1)<=n)res=1;
		else res=0;*/
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

