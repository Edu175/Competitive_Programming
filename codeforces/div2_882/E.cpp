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

ll area(ll a, ll b, ll c){ // area**2*16 
	vector<ll>v={a,b,c}; sort(ALL(v));
	if(v[0]+v[1]<=v[2])return 0;
	ll p=a+b+c;
	return p*(p-2*a)*(p-2*b)*(p-2*c);
}
map<ll,vector<vector<ll>>>mp;
int main(){FIN;
	fore(i,1,5)fore(j,i,5)fore(k,j,5)mp[area(i,j,k)].pb({i,j,k}),
		cout<<i<<" "<<j<<" "<<k<<": "<<area(i,j,k)<<"\n";
	for(auto i:mp){
		cout<<i.fst<<": ";
		for(auto j:i.snd){
			for(auto k:j)cout<<k<<",";
			cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
