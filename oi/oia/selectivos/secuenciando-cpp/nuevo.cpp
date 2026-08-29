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
		for(int i=0;i<SZ(res)+1;i++){
			auto cand=res; cand.insert(cand.begin()+i,'T');
			if(medir(cand))res=cand;
		}
		return res;
	}
	map<char,ll> oc;
	auto sortit=[&](){
		ll sum=0;
		for(auto c:s){
			oc[c]=get_oc(c,sum);
			sum+=oc[c];
		}
		sort(ALL(s),[&](char a, char b){return oc[a]<oc[b];});
	};
	sortit();
	reverse(ALL(s));
	string res;
	char c;
	auto ask_range=[&](ll l, ll r){ // [l,r]
		auto t=res.substr(0,l)+string(1,c)+res.substr(r);
		ll ret=medir(t);
		// cerr<<"ask_range "<<t<<": "<<ret<<"\n";
		return ret;
	};
	auto oc_in=[&](ll p, ll sum){ // at least one occurence
		auto can=[&](ll m){
			auto t=res.substr(0,p)+string(m,c)+res.substr(p);
			return medir(t);
		};
		ll upp=oc[c]-sum;
		ll lo=1,hi=2;
		while(hi<=upp&&can(hi))hi<<=1;
		hi=min(hi,upp+1);
		while(hi-lo>1){
			ll mid=(lo+hi)/2;
			if(can(mid))lo=mid;
			else hi=mid;
		}
		return lo;
	};
	vv wh;
	auto f=[&](ll l, ll r, auto &&f)->void { // cambiamos las binaries en cascada por una unica binaria separadora
		if(!ask_range(l,r-1))return;
		if(r-l==1){wh.pb(l);return;}
		ll m=(l+r)/2;
		f(l,m,f); f(m,r,f);
	};
	for(auto _c:s){
		c=_c;
		if(!SZ(res)){
			res=string(oc[c],c); // 10 queries
			continue;
		}
		// cerr<<"round "<<c<<": "<<res<<"\n";
		wh.clear();
		f(0,SZ(res)+1,f);
		reverse(ALL(wh));
		ll sum=0;
		for(auto i:wh){
			ll q=i==wh.back()?oc[c]-sum:oc_in(i,sum);
			sum+=q;
			res=res.substr(0,i)+string(q,c)+res.substr(i);
		}
	}
	assert(SZ(res)==n);
	return res;
}