#include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>

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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
ll n,p;
const ll MAXN=1e5+5;

ll a[MAXN],b[MAXN];

bool can(ld t){
	ll A=0,B=0;
	fore(i,0,n){
		ld l=t*a[i]+b[i];
		if(l>0)continue;
		A+=a[i],B+=b[i];
		// l*=-1;
		// ld c=b[i]/(-a[i]);
		// ld cur=c*l/2;
		// vol+=cur;
	}
	A+=p;
	if(A>=0)return 1;
	return t*A+B>0; // b/(-a) >= t
}
ll R=1e15;
int main(){FIN;
	cin>>n>>p;
	fore(i,0,n){
		cin>>a[i]>>b[i];
		a[i]*=-1;
	}
	ld l=0,r=R;
	fore(_,0,120){
		ld m=(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	if(r>=ll(R)-100)cout<<"-1\n";
	else {
		cout<<fixed<<setprecision(12)<<l<<"\n";
	}
	return 0;
}
