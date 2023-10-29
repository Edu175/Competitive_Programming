#include "longesttrip.h"
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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#define ask are_connected

ll n,d;

ll find(vector<ll>&a,vector<ll>&b){
	/*vector<ll>pre;
	fore(i,0,SZ(a)){
		pre.pb(a[i]);
		if(ask(b,pre))return i;
	}*/
	ll l=0,r=SZ(a)-1;
	while(l<=r){
		ll m=(l+r)/2;
		vector<ll>pre;
		fore(i,0,m+1)pre.pb(a[i]);
		if(ask(b,pre))r=m-1;
		else l=m+1;
	}
	return l;
}

vector<ll> rot(vector<ll>a, ll d){ // <--
	ll n=SZ(a);
	vector<ll>ai(n);
	fore(i,0,n)ai[i]=a[(i+d)%n];
	return ai;
}

vector<int> longest_trip(int N, int D){
	n=N,d=D;
	vector<ll>P;
	fore(i,0,n)P.pb(i);
	//LL sd; srand((LL)&sd); 
	srand(314159265);
	random_shuffle(ALL(P));
	vector<vector<ll>>h;
	h.pb({P[0]});
	h.pb({P[1]});
	fore(i,2,n){
		ll x=P[i];
		if(ask({h[0].back()},{x}))h[0].pb(x);
		else if(ask({h[1].back()},{x}))h[1].pb(x);
		else {
			while(SZ(h[1]))h[0].pb(h[1].back()),h[1].pop_back();
			h[1]={x};
		}
	}
	/*if(SZ(h[0])>SZ(h[1]))return h[0];
	else return h[1];*/
	//imp(h[0]); imp(h[1]);
	if(!ask({h[0][0],h[0].back()},{h[1][0],h[1].back()})){
		if(!ask(h[0],h[1])){
			if(SZ(h[0])>SZ(h[1]))return h[0];
			else return h[1];
		}
		ll x=find(h[0],h[1]);
		vector<ll>fi={h[0][x]};
		ll y=find(h[1],fi);
		h[0]=rot(h[0],x+1),h[1]=rot(h[1],y);
	}
	if(ask({h[0].back()},{h[1][0]}));
	else if(ask({h[0].back()},{h[1].back()}))reverse(ALL(h[1]));
	else if(ask({h[0][0]},{h[1][0]}))reverse(ALL(h[0]));
	else /*if(ask({h[0][0]},{h[1].back()}))*/
		reverse(ALL(h[0])),reverse(ALL(h[1]));
	for(auto i:h[1])h[0].pb(i);
	h[1].clear();
	return h[0];
}

