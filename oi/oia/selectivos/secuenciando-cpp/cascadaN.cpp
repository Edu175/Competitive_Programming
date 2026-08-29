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
	map<char,ll> oc;
	auto sortit=[&](){
		ll sum=0;
		for(auto c:s){
			oc[c]=get_oc(c,sum);
			sum+=oc[c];
		}
		sort(ALL(s),[&](char a, char b){return oc[a]<oc[b];});
	};
	if(s=="ACGT"){
		sortit();
		string res;
		for(auto c:s){
			// cerr<<"vuelta "<<c<<": "<<res<<"\n";;
			if(!SZ(res)){res=string(oc[c],c);continue;}
			for(int i=0,cant=0;i<SZ(res)+1&&SZ(res)<n&&cant<oc[c];i++){
				auto cand=res; cand.insert(cand.begin()+i,c);
				if(medir(cand))res=cand,cant++;
			}
		}
		return res;
	}
	string res;
	auto ask_range=[&](char c, ll l, ll r){ // [l,r]
		auto t=res.substr(0,l)+string(1,c)+res.substr(r);
		ll ret=medir(t);
		// cerr<<"ask_range "<<t<<": "<<ret<<"\n";
		return ret;
	};
	for(auto c:s){
		// cerr<<"round "<<c<<"\n";
		ll p=-1;
		while(1){
			ll l=p,r=SZ(res)+1;
			while(r-l>1){
				ll m=(l+r)/2;
				if(ask_range(c,p+1,m))r=m;
				else l=m;
			}
			if(r>SZ(res))break;
			p=r;
			res.insert(res.begin()+p,c);
			while(1){
				auto cand=res;
				cand.insert(cand.begin()+p+1,c);
				if(medir(cand))p++,res=cand;
				else break;
			}
		}
	}
	assert(SZ(res)==n);
	return res;
}