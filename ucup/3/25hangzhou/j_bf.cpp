#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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

vector<ii>ed;
ll n1,n2,m,k;

vv hay0,hay1;
set<pair<vv,vv>>st;
void check(){
	for(auto [a,b]:ed){
		ll good=0;
		good|=hay0[a]&&hay1[b];
		good|=hay0[b]&&hay1[a];
		if(!good)return;
	}
	st.insert({hay0,hay1});
}
void f(ll i){
	if(i==n1+n2){check();return;}
	fore(j,0,m){
		(i<n1?hay0:hay1)[j]++;
		f(i+1);
		(i<n1?hay0:hay1)[j]--;
	}
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		cin>>n1>>n2>>m>>k;
		hay0=hay1=vv(m);
		st.clear(); ed.resize(k);
		fore(i,0,k)cin>>ed[i].fst>>ed[i].snd,ed[i].fst--,ed[i].snd--;
		f(0);
		cout<<SZ(st)<<"\n";
		for(auto [a,b]:st){
			cerr<<"{ ";
			for(auto i:a)cerr<<i<<" ";
			cerr<<"} { ";
			for(auto i:b)cerr<<i<<" ";
			cerr<<"}\n";
		}
	}
	return 0;
}
