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
	ll n; cin>>n;
	ll res=0;
	ll q=1;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,1,n){
		if(a[i]>a[i-1])q++;
		else res=max(res,q),q=1;
	}
	res=max(res,q);
	cout<<res<<"\n";
	return 0;
}
