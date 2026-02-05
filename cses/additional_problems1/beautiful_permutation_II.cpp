#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vv pinga={0, 2, 4, 1, 3};
int main(){FIN;
	ll n; cin>>n;
	vv a(n); iota(ALL(a),1);
	ll u=0;
	for(ll i=0;n-i-5>=4;i+=5){
		fore(j,0,5)a[i+j]=1+i+pinga[j];
		u=i+5;
	}
	auto pl=a.begin()+u,pe=a.end();
	assert(is_sorted(pl,pe));
	ll did=0;
	do{
		ll good=1;
		for(auto p=pl;next(p)<pe;p++)good&=abs(*p-*next(p))!=1;
		did=good;
		if(good)break;
	}while(next_permutation(pl,pe));
	if(!did){
		cout<<"NO SOLUTION\n";
		return 0;
	}
	imp(a)
	return 0;
}