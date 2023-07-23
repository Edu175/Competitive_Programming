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
	string s; cin>>s;
	ll a[n];
	fore(i,0,n)a[i]=s[i]-'0';
	ll p[n];
	ll z=-1;
	fore(i,0,n){
		if(!a[i])z=i;
		p[i]=z;
	}
	ll res=0;
	fore(i,0,n){
		ll c=i-p[i],resi=0;
		//if(p[i]==-1)c=i;
		if(p[i]!=-1){
			resi+=(c+1)%2*p[i];
			resi+=c%2;
		}
		resi+=(c+1)/2;
		res+=resi;
		//cout<<i<<": "<<c<<" "<<p[i]<<": "<<resi<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
