#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(175);

ll lgt(ll n){return __lg(n-1)+1;}

int main(){FIN;
	ll n; cin>>n;
	map<vector<vector<bool>>,ll> mp;
	ll k=lgt(n+1);
	vv per(n); iota(ALL(per),1);
	do{
		vector<vector<bool>> bits(k);
		fore(i,0,n)fore(j,0,k)bits[j].pb(per[i]>>j&1);
		sort(ALL(bits));
		mp[bits]++;
	}while(next_permutation(ALL(per)));
	for(auto [b,c]:mp){
		fore(i,0,SZ(b)){
			for(auto e:b[i])cout<<e;
			cout<<"\n";
		}
		cout<<"= "<<c<<"\n\n";
	}
	return 0;
}
