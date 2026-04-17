#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &tex) {
	// AQUI SE DEBE IMPLEMENTAR LA SOLUCION
	ll k=K;
	vector<string> a;
	string p;
	fore(i,0,SZ(tex)){
		if(tex[i]==' ')a.pb(p),p.clear();
		else p.pb(tex[i]);
	}
	a.pb(p);
	map<string,ll>mp;
	ll n=SZ(r1);
	fore(i,0,n){
		mp[r1[i]]=-1;
		mp[r2[i]]=-1;
		mp[r3[i]]=-1;
	}
	ll m=SZ(a);
	fore(i,0,m)mp[a[i]]=-1;
	ll cnt=0;
	for(auto &i:mp)i.snd=cnt++;
	set<pair<ii,ll>>st;
	fore(i,0,n)st.insert({{mp[r1[i]],mp[r2[i]]},mp[r3[i]]});
	ll ki=2;
	fore(i,2,m){
		ll x=mp[a[i-2]],y=mp[a[i-1]],z=mp[a[i]];
		if(!st.count({{x,y},z}))ki++;
	}
	return ki<=k;
}
