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
const ll MAXN=2e5+5;

ll a[MAXN];
ll sd(ll x){
	ll res=0;
	while(x)res+=x%10,x/=10;
	return res;
}
int main(){FIN;
	fore(i,1,MAXN)a[i]=sd(i)+a[i-1];
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<a[n]<<"\n";
	}
	return 0;
}
