#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto slkgh:v)cout<<slkgh<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;


const ll n=16;
bool operator<(bitset<n> a, bitset<n> b){
	fore(i,0,n){
		if(a[i]<b[i])return 1;
		if(a[i]>b[i])return 0;
	}
	return 0;
}
int main(){
	vector<bitset<n>>a;
	auto rot=[&](bitset<n> b, ll x){
		return (b<<x)|(b>>(n-x));
	};
	bitset<n>all=(1ll<<n)-1;
	// fore(i,0,n)all[i]=1;
	unordered_set<bitset<n>>st;
	fore(mk,0,1ll<<n){
		bitset<n> b=mk;
		auto mn=b;
		fore(x,0,n)fore(d,0,2){
			auto bi=rot(b,x);
			if(d)bi^=all;
			if(bi<mn)mn=bi;
			// mn=max(mn,bi);
		}
		if(mn==0)mn=all;
		st.insert(mn);
	}
	cout<<SZ(st)<<"\n";
	imp(st);
	return 0;
}