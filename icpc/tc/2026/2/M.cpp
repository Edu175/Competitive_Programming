#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cerr<<x<<" ";cerr<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

#ifdef LOCAL
ll x;
bool last=1;
mt19937 rng;
#endif

ll QUERIES=0;

bool ask(vv a){
	QUERIES++;
	string ret;
	#ifndef LOCAL
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;
	cin>>ret;
	#else
	string real=count(ALL(a),x)?"YES":"NO";
	if(!last)ret=real,last=1;
	else {
		if(rng()&1)ret=real,last=1;
		else ret=real=="YES"?"NO":"YES",last=0;
	}
	// cerr<<ret<<" "<<last<<"\n";
	#endif
	return ret=="YES";
}
void answer(vv v){
	assert(SZ(v)<=2);
	#ifdef LOCAL
	cerr<<"v: "<<v<<"\n";
	assert(count(ALL(v),x));
	#else
	cout<<"! "<<v[0]+1<<endl;
	string ret; cin>>ret;
	if(ret==":)")return;
	cout<<"! "<<v[1]+1<<endl;
	cin>>ret;
	assert(ret==":)");
	#endif
}
pair<vv,vv> part(vv a, ll k){
	assert(k<=SZ(a));
	return {vv(a.begin(),a.begin()+k),vv(a.begin()+k,a.end())};
}
vv operator+(vv a, vv b){
	for(auto i:b)a.pb(i);
	return a;
}

map<ii,ii> chicos={
	{{2,1}, {0,1}} ,
	{{4,1}, {0,1}},
	{{2,3}, {0,2}}, 
	{{3,3}, {0,2}}, 
	{{4,3}, {1,2}},
	{{8,1}, {2,1}}, 
	{{4,5}, {0,3}}, 
	{{3,7}, {0,4}}, 
	{{7,3}, {0,3}}
};

void fun(vv v, vv f){
	// cerr<<"fun "<<v<<" "<<f<<"\n";
	if(SZ(v)+SZ(f)<=2){
		answer(v+f);
		return;
	}
	ll a=SZ(v)/2,b=(SZ(f)+1)/2;
	ii key={SZ(v),SZ(f)};
	if(chicos.count(key))tie(a,b)=chicos[key];
	auto [v1,v2]=part(v,a);
	auto [f1,f2]=part(f,b);
	ll got=ask(v1+f1);
	if(got)return fun(v1+f1,v2);
	return fun(v2+f2,v1);
}

int main(){
	// JET
	ll n; cin>>n;
	#ifdef LOCAL
	x=rng()%n;
	// cin>>x; x--;
	cerr<<"x "<<x<<"\n";
	#endif
	vv id(n); iota(ALL(id),0);
	fun(id,{});
	cerr<<"QUERIES "<<QUERIES<<"\n";
	return 0;
}