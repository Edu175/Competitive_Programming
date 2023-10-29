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
const ll MAXN=2005;

ll inv(ll l, ll r){
	if(l==r)return 0;
	l++,r++;
	cout<<"? "<<l<<" "<<r<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}
ll dnc(ll l, ll r){
	if(l==r)return l;
	ll m=(l+r)/2;
	ll x=dnc(l,m),y=dnc(m+1,r);
	if(inv(l,y)-inv(l,y-1)==0)return y;
	return x;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==-1)exit(0);
		ll res=dnc(0,n-1)+1;
		cout<<"! "<<res<<endl;
	}
	return 0;
}
