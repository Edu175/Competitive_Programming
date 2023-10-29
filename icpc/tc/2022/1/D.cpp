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
	ll n,m; cin>>n>>m;
	ll t=n-m+1;
	ll k2=((t*(t-1))/2);
	ll c,f;
	c=(n+m-1)/m;
	f=n/m;
	ll k1=((c*(c-1))/2)*(n%m)+((f*(f-1))/2)*(m-n%m);
	cout<<k1<<" "<<k2<<"\n";
	return 0;
}
