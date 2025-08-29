#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll n=0;
	vv deb(2); fore(i,0,2)cin>>deb[i],n+=deb[i];
	vector<pair<string,ll>>a(n),b(n);
	vv same;
	map<string,set<ll>> pos;
	fore(i,0,n){
		cin>>a[i].snd>>a[i].fst>>b[i].snd>>b[i].fst;
		if(a[i].fst==b[i].fst)same.pb(i);
		pos[a[i].fst].insert(i);
		pos[b[i].fst].insert(i);
	}
	same.pb(n);
	auto gana=[&](ll i, ll w, string t="pinga")->ll { // mira si va a estar pinga en los testcases?
		if(i==-1)return 0; // neut
		if(a[i].fst==b[i].fst)return a[i].snd<b[i].snd;
		if(a[i].fst==t)return 0;
		if(b[i].fst==t)return 1;
		return w;
	};
	
	vv sum(n+1); // cuantas gana 1: [i,n)
	auto f=[&](ll i, ll w, auto &&f)->ll {
		auto &res=sum[i];
		if(i==n)return res=0;
		ll wp=gana(i,w);
		return res=wp+f(i+1,wp,f);
	};
	f(0,0,f);
	for(auto [pal,st]:pos){
		vv vec={-1}; for(auto i:st)vec.pb(i);
		vec.pb(n);
		ll res=0;
		fore(ind,0,SZ(vec)-1){
			ll i=vec[ind],prox=vec[ind+1];
			ll p=*upper_bound(ALL(same),i);
			p=min(p,prox);
			ll w=gana(i,-1,pal);
			ll cur=w*(p-i)+sum[p]-sum[prox];
			res+=cur;
		}
		if(res==deb[1]){
			cout<<pal<<"\n";
			exit(0);
		}
	}
	cout<<"*\n";
    return 0;
}