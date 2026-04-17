#include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <map>
#include <deque>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define inp(v) {for(auto &i:v)cin>>i;}
#define menos1(v) {for(auto &i:v)i--;}
#define pres cout<<res<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=2e3+5,INF=1e18,MOD=1e9+7;

ll mem[MAXV][MAXV];

ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(n==0)return res=1;
	return res=(nCr(n-1,k-1)+nCr(n-1,k))%MOD;
}

ll count(string n, ll b){ // # x<=n with b bits
	ll res=0;
	ll _b=b;
	fore(i,0,SZ(n)){
		if(n[i]=='1'){
			ll cur=nCr(SZ(n)-i-1,b);
			res+=cur;
			res%=MOD;
			b--;
		}
		// if(b<0)continue;
	}
	// if(n.back()=='1')
	res+=b==0;
	res%=MOD;
	if(_b==1){
		res--;
		if(res<0)res+=MOD;
	}
	// cerr<<"count "<<n<<" "<<b<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	mset(mem,-1);
	// freopen("","r",stdin);
	// freopen("","w",stdout);
	ll t=1;
	vv go(MAXV,INF);
	go[1]=0;
	fore(i,2,MAXV){
		ll p=__builtin_popcountll(i);
		go[i]=go[p]+1;
	}
	// imp(go)
	// cerr<<"mx "<<*max_element(ALL(go))<<"\n";
	// return 0;
	// cin>>t;
	while(t--){
		string n;
		ll k; cin>>n>>k;
		if(k==0){
			cout<<"1\n";
			continue;
		}
		ll res=0;
		fore(x,1,MAXV){
			if(go[x]==k-1){
				res+=count(n,x);
				res%=MOD;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
