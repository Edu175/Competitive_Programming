#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll INF =2e18;
set<ii> s;
map<ll,ll> mp;

void f(ll P, ll h, ll L){
	vector<ii> put;
	auto it = (s.upper_bound({P,INF+10}));
	it--;
	auto [x,y] = *it;
	if(h<y){
		put.pb({h+1,y});
		mp[h+1] = mp[x];
	}
	else if(h==y){
		auto aux = next(it);
		if(aux!=s.end()){
			auto [x1,y1] = *aux;
			if(mp[x1]==mp[x]+L){
				s.erase(aux);
				mp.erase(x1);
				h=y1;
			}
		}
	}
	if(x<P){
		put.pb({x,P-1});
		put.pb({P,h});
		mp[P] = mp[x]+L;
	}
	else if(x==P){
		if(it != s.begin()){
			auto aux = prev(it);
			auto [x1,y1] = *aux;
			if(mp[x1] == mp[x]+L){
				s.erase(aux);
				put.pb({x1,h});
			}
			else{
				put.pb({P,h});
				mp[P] = mp[x]+L;
			}
		}
	}
	s.erase(it);
	for(auto p:put) s.insert(p);
}

int main(){
	JET
	mp[0] = 0;
	s.insert({0,INF});
	ll n; cin>>n;
	fore(i,0,n){
		char c; ll L,P;
		cin>>c>>L>>P;
		if (c=='|'){
			cout<<"S";
			f(P,P,L);			
		}
		else{
			ll h = P+L-1;
			auto it = s.lower_bound({P,INF+10});
			it--;
			auto [x,y] = *it;
			if(y<h){
				cout<<"U";
			}
			else{
				cout<<"S";
				f(P,h,1);
			}
		}
		
		// cout<<"\nset luego de la interacion "<<i<<"\n";
		// for(auto x:s){
		// 	cout<<"("<<x.fst<<" , "<<x.snd<<") ";
		// }
		// cout<<"\n";
	}
	cout<<"\n";
	return 0;
}