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

vector<ll> lis(vector<ll>a){//O(nlog(n))
	ll n=SZ(a);
	vector<pair<ll,ll>>v;
	v.pb({-1,-1});
	ll p[n];
	fore(i,0,n){
		ll lwb=lower_bound(ALL(v),pair(a[i],ll(-1)))-v.begin();
		if(lwb==SZ(v))v.pb({a[i],i});
		else v[lwb]={a[i],i};
		p[i]=v[lwb-1].snd;
	}
	vector<ll>res;
	ll x=v[SZ(v)-1].snd;
	while(x!=-1)res.pb(a[x]),x=p[x];
	reverse(ALL(res));
	return res;
}

int main(){FIN;
	ll n;cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> res=lis(a);
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}
