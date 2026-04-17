#include<bits/stdc++.h>
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

// const ll MAXN=7;
const ll MAXN=1505;

struct matrix{
	bitset<MAXN> x[MAXN];
	bitset<MAXN> mks[MAXN];

	// matrix():{}
	pair<ll,bitset<MAXN>> add(bitset<MAXN> v, ll i){
		// cout<<"\nadd "<<i<<" "<<v<<"\n";
		bitset<MAXN> mk; mk[i]=1;
		fore(j,0,MAXN){
			if(v[j])v^=x[j],mk^=mks[j];
		}
		ll p=v._Find_first();
		// cout<<"add "<<i<<" "<<p<<": "<<v<<":\n";
		// for(auto j:id)cout<<j<<" ";;cout<<"\n";
		if(p>=MAXN)return {1,mk};
		x[p]=v; mks[p]=mk;
		return {0,mk};
	}
};

int main(){
	JET
	ll n,k; cin>>n>>k;
	vector<bitset<MAXN>> a(n);
	fore(i,0,n){
		string s; cin>>s; s.pb('1');
		fore(j,0,SZ(s))a[i][j]=(s[j]-'0');
	}
	matrix mt;
	vv ans;
	fore(i,0,n){
		auto [bo,mk]=mt.add(a[i],i);
		if(bo){
			fore(i,0,MAXN)if(mk[i])ans.pb(i);
			break;
		}
	}
	if(!SZ(ans))cout<<"*\n";
	else {
		vv ret(n);
		fore(i,0,SZ(ans)){
			ret[ans[i]]=(i<SZ(ans)/2)+1;
		}
		for(auto i:ret)cout<<i;
		cout<<"\n";
	}
	return 0;
}
// 5 3
// 101
// 001
// 010
// 011
// 000

// add 0 0001101
// add 0 0: 0001101:


// add 1 0001100
// add 1 2: 0001100:


// add 2 0001010
// add 2 1: 0001010:


// add 3 0001110
// add 3 3: 0001000:
// 2 1 

// add 4 0001000
// add 4 7: 0000000:
// 3 
// 00021
