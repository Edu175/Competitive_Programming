

#include "lane.h"
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
#define der clockwise
#define izq anticlockwise

int sub1(){ // costs exactly 2n once empty
	ll n=0;
	while(1){
		if(ask())break; // +1
		n++;
		flip();
		der(); // +1
	}
	return n;
}

bool les(ll k){
	fore(i,0,k){
		ll fin=i==0;
		if(i>=k/2&&ask()!=fin)flip();
		if(i<k-1)der();
	}
	fore(i,0,k-1)izq();
	return !ask();
}

int solve(int c) {
	if(c==1)return sub1();
	ll k=1;
	while(!les(k))k+=k;
	return sub1();
}

