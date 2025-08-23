#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
ll get(ll n){
	// string s=to_string(n);
	ll _n=n;
	vv c(10);
	while(n)c[n%10]=1,n/=10;
	vv d;
	fore(i,0,10)if(c[i])d.pb(i);
	// if(d)
	ll g=_n;
	fore(i,0,SZ(d)-1)g=gcd(g,9*(d[i+1]-d[i]));
	return g;
}

ll h[100];

int main(){
	JET
	vv all;
	fore(j,1,3)fore(i,1,10){
		ll num=i;
		fore(k,0,j)num*=3;
		all.pb(num);
	}
	cout<<"get(48) "<<get(48)<<"\n";
	// sort(ALL(all));
	for(auto i:all)cout<<i<<" ";;cout<<"\n";
	for(ll i=0;i<1e10;i+=9){
		ll g=get(i);
		if(g<100){
			if(!h[g]){
				h[g]=i;
				cout<<g<<": "<<i<<endl;
			}
		}
	}
	// fore(g,0,100)if(h[g])cout<<g<<": "<<h[g]<<"\n";
}



/*
got:

12: 48
15: 5055
18: 288
21: 7077
24: 8088
27: 3699
36: 48888
45: 5055555555
54: 222888888
63: 111888
72
81




*/