#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=2e9+5;
// opt[i] <= opt[i+1] // for customer i, where opt is best client
// dado que clients estan ordenados por x y solo los dominadores
// clients que existen tienen rangos [l,r) que se pueden mantener online
// WA: la demo dependia de mantener los dominados

string cv(ii a){return to_string(a.fst)+","+to_string(a.snd);}
ll val(ii a, ii b){
	// if(a.fst>=b.fst)return 0;
	// if(a.snd>=b.snd)return 0;
	ll ret=(b.fst-a.fst)*(b.snd-a.snd);
	// cout<<"val "<<cv(a)<<" "<<cv(b)<<" = "<<ret<<"\n";
	return ret;
}
ll real(ii a, ii b){
	if(a.fst>=b.fst)return 0;
	if(a.snd>=b.snd)return 0;
	return (b.fst-a.fst)*(b.snd-a.snd);
}
bool dom(ii a, ii b){return a.fst<=b.fst&&a.snd<=b.snd;} // <
int main(){
	ET;
	ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	set<ii> st; // {coords}
	map<ii,ii>mp; // range of element coords
	set<pair<ll,ii>> ls; // {l,who}
	auto gol=[&](auto it){// somos todos montiel
		ll s=0;
		while(it!=st.begin()){
			auto p=prev(it);
			auto &y=mp[*p];
			ll l=y.fst,r=y.snd-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(val(a[m],*p)>=val(a[m],*it))l=m+1;
				else r=m-1;
			}
			s=l;
			// cout<<s<<" s\n";
			if(y.fst==s)ls.erase({y.fst,*p}),st.erase(p);
			else {
				y.snd=s;
				break;
			}
		}
		mp[*it].fst=s;
	};
	
	auto gor=[&](auto it){
		ll e=n;
		while(it!=prev(st.end())){
			auto p=next(it);
			auto &y=mp[*p];
			ll l=y.fst,r=y.snd-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(val(a[m],*p)>val(a[m],*it))r=m-1;
				else l=m+1;
			}
			e=l;
			// cout<<e<<" e\n";
			ls.erase({y.fst,*p});
			if(y.snd==e)st.erase(p);
			else {
				y.fst=e;
				ls.insert({y.fst,*p});
				break;	
			}
		}
		mp[*it].snd=e;
	};
	
	auto upd=[&](ii x){
		// cout<<"upd "<<cv(x)<<":"<<endl;
		auto it=st.insert(x).fst;
		if(next(it)!=st.end()&&dom(x,*next(it))){
			st.erase(it);
			return;
		}
		while(it!=st.begin()&&dom(*prev(it),x)){
			ls.erase({mp[*prev(it)].fst,*prev(it)});
			st.erase(prev(it));
		}
		gol(it);
		gor(it);
		auto [l,r]=mp[*it];
		// cout<<l<<","<<r<<" l r\n";
		if(l==r)st.erase(it); // era un pichichi
		else ls.insert({l,x});
		// impr(st)
	};
	
	ll q; cin>>q;
	while(q--){
		char ty; cin>>ty;
		if(ty=='s'){
			ll i; cin>>i; i--;
			if(!SZ(ls)){cout<<"0\n";continue;}
			auto p=prev(ls.upper_bound({i,{INF,INF}}))->snd;
			ll res=real(a[i],p);
			// cout<<"query: "<<cv(p)<<"\n";
			cout<<res<<"\n";
		}
		else { // fst++
			ll x,y; cin>>x>>y; x++;
			upd({x,y});
		}
	}
}