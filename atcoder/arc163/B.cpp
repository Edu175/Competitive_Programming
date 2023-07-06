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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>l,r;
	fore(i,2,n){
		if(a[i]<a[0])l.pb(a[i]);
		if(a[i]>a[1])r.pb(a[i]);
		if(a[0]<=a[i]&&a[i]<=a[1])k--;
	}
	if(k<=0){
		cout<<"0\n";
		return 0;
	}
	sort(ALL(l)),reverse(ALL(l)),sort(ALL(r));
	vector<ll>s={0},e={0};
	for(auto i:l)s.pb(a[0]-i);
	for(auto i:r)e.pb(i-a[1]);
	ll res=1e10;
	//cout<<l<<" "<<a[0]<<" "<<a[1]<<" "<<r<<"\n"<<s<<" "<<e<<"\n";
	fore(c,0,SZ(s)){
		ll resi=0;
		resi+=s[c];
		if(k-c>SZ(e)-1||k-c<0)continue;
		resi+=e[k-c];
		ll li=a[0],ri=a[1];
		if(c)li=l[c-1];
		if(k-c)ri=r[k-c-1];
		//cout<<c<<" "<<k-c<<": "<<li<<" "<<ri<<": "<<resi<<"\n";
		if(ri<li)resi+=abs(li-ri);
		res=min(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
