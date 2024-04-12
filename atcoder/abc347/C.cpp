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
	ll n,a,b; cin>>n>>a>>b;
	ll m=a+b;
	vector<ll>d(n);
	set<ll>st;
	fore(i,0,n)cin>>d[i],st.insert((d[i]-1)%m);
	d.clear();
	for(auto i:st)d.pb(i);
	n=SZ(d);
	ll flag=n==1;
	fore(i,0,n){
		flag|=(d[(i+1)%n]-d[i]+5*m-1)%m>=b;
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
