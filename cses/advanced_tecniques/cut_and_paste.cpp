#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<string>bag;
ll sq;
vector<ll> cut(vector<ll>&a, ll p){
	ll s=0;
	fore(i,0,SZ(a)){
		if(s+SZ(bag[a[i]])>=p){
			string x[2];
			fore(j,0,SZ(bag[a[i]]))x[j>=p-s].pb(bag[a[i]][j]);
			if(SZ(x[0]))bag.pb(x[0]);
			bag.pb(x[1]);
			vector<ll>b={x[1]};
			fore(j,i+1,SZ(a))b.pb(a[j]);
		}
		else s+=SZ(bag[a[i]]);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	string s; cin>>s;
	sq=sqrt(SZ(a))+.5;
	string x;
	vector<ll>a;
	fore(i,0,SZ(s)){
		x.pb(s[i]);
		if(SZ(x)>=sq)a.pb(SZ(bag)),bag.pb(x),x.clear();
	}
	if(SZ(x))a.pb(SZ(bag)),bag.pb(x);
	
	return 0;
}
