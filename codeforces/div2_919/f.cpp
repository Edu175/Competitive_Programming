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
ii o;
bool toca(ii &a, ii &b){
	return (a.fst>o.fst&&(a.snd>=o.snd)!=(b.snd>=o.snd));
}
ll n,m;
ll cv(ii x){return m*x.fst+x.snd;}
ii cv(ll x){return {x/m,x%m};}
vector<ii> dir={{1,0},{0,1},{-1,0},{0,-1}};
ll go(ll _x, ll d){
	auto x=cv(_x);
	x.fst+=dir[d].fst;
	x.snd+=dir[d].snd;
	if(x.fst<0||x.fst>=n||x.snd<0||x.snd>=m)return -1;
	return cv(x);
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
