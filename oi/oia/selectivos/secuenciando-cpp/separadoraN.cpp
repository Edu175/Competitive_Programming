#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
int medir(string cad);

string secuenciar(int n, string s){
	auto get_oc=[&](char c, ll sum=0){
		ll l=0,r=n-sum+1;
		while(r-l>1){
			ll m=(l+r)/2;
			if(medir(string(m,c)))l=m;
			else r=m;
		}
		return l;
	};
	if(s=="AC"){
		auto res=string(get_oc('A'),'A');
		res.resize(n,'C');
		return res;
	}
	if(s=="GT"){
		string res=string(get_oc('G'),'G');
		for(int i=0;i<SZ(res)+1&&SZ(res)<n;i++){
			auto cand=res; cand.insert(cand.begin()+i,'T');
			if(medir(cand))res=cand;
		}
		return res;
	}
	// auto sortit=[&](){
	// 	map<char,ll> oc;
	// 	ll sum=0;
	// 	for(auto c:s){
	// 		oc[c]=get_oc(c,sum);
	// 		sum+=oc[c];
	// 	}
	// 	sort(ALL(s),[&](char a, char b){return oc[a]<oc[b];});
	// };
	// sortit();
	// reverse(ALL(s));
	string res;
	char c;
	auto ask_range=[&](ll l, ll r){ // [l,r]
		auto t=res.substr(0,l)+string(1,c)+res.substr(r);
		ll ret=medir(t);
		// cerr<<"ask_range "<<t<<": "<<ret<<"\n";
		return ret;
	};
	char c;
	vv wh;
	auto f=[&](ll l, ll r, auto &&f)->void { // cambiamos las binaries en cascada por una unica binaria separadora
		if(!ask_range(l,r-1))return;
		if(r-l==1){wh.pb(l);return;}
		ll m=(l+r)/2;
		f(l,m,f); f(m,r,f);
	};
	for(auto _c:s)if(SZ(res)<n){
		c=_c;
		// cerr<<"round "<<c<<": "<<res<<"\n";
		wh.clear();
		f(0,SZ(res)+1,f);
		reverse(ALL(wh));
		ll qued=SZ(wh);
		for(auto i:wh){
			res.insert(res.begin()+i,c);
			qued--;
			while(SZ(res)+qued<n){
				auto cand=res;
				cand.insert(cand.begin()+i,c);
				if(medir(cand))res=cand;
				else break;
			}
		}
	}
	assert(SZ(res)==n);
	return res;
}