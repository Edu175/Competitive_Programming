#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfkjhg:v)cout<<dfkjhg.fst<<","<<dfkjhg.snd<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

ll n;
ll a[MAXN];
bool can(ll m){
	if(m==1)return 0;
	vector<ll>oc(n);
	set<ii>st;
	fore(i,0,m)oc[a[i]]++;
	fore(i,0,n)st.insert({oc[i],a[i]});
	auto valid=[&](){
		ll k=prev(st.end())->fst;
		return k>m-k;
	};
	if(valid())return 1;
//	cout<<"\n"<<m<<"\n";
	fore(i,m,n){
//		imp(st);
		st.erase({oc[a[i-m]],a[i-m]});
		st.erase({oc[a[i]],a[i]});
		oc[a[i-m]]--;
		oc[a[i]]++;
		st.insert({oc[a[i-m]],a[i-m]});
		st.insert({oc[a[i]],a[i]});
		if(valid())return 1;
	}
	return 0;
}

int main(){FIN;
	cin>>n;
	vector<ll>c;
	fore(i,0,n)cin>>a[i],c.pb(a[i]);
	sort(ALL(c));
	auto _c=c;
	c.clear();
	for(auto i:_c)if(!SZ(c)||i!=c.back())c.pb(i);
	auto id=[&](ll x){
		return lower_bound(ALL(c),x)-c.begin();
	};
	fore(i,0,n)a[i]=id(a[i]);
	/*ll l=1,r=n;
	while(l<=r){
		ll m=(l+r)/2;
//		cout<<"\n"<<m<<":\n";
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";*/
	ll res=0;
	for(ll m=n;m;m--)if(can(m)){res=m;break;}
	cout<<res<<"\n";
	return 0;
}
