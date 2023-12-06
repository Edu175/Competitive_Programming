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
	ll n,s,m,l; cin>>n>>s>>m>>l;
	ll res=n*l;
	fore(i,0,n+1)fore(j,0,n+1)fore(k,0,n+1){
		if(i*6+j*8+k*12>=n)res=min(res,i*s+j*m+k*l);
	}
	cout<<res<<"\n";
	return 0;
}
