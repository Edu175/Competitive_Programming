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
typedef pair<ll,ll> ii;
#define ask are_connected

ll n,d;

ll find(vector<ll>&a,vector<ll>&b){
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
	fore(i,0,n)ai[(i+d)%n]=a[i];
	return ai;
}

vector<int> longest_trip(int N, int D){
	n=N,d=D;
	vector<vector<ll>>h;
	h.pb({0});
	h.pb({1});
	fore(x,2,n){
		if(ask({h[0].back()},{x}))h[0].pb(x);
		else if(ask({h[1].back()},{x}))h[1].pb(x);
		else {
			while(SZ(h[1]))h[0].pb(h[1].back()),h[1].pop_back();
			h[1]={x};
		}
	}
	/*if(SZ(h[0])>SZ(h[1]))return h[0];
	else return h[1];*/
	if(ask({h[0].back()},{h[1][0]}));
	else if(ask({h[0].back()},{h[1].back()}))reverse(ALL(h[1]));
	else if(ask({h[0][0]},{h[1][0]}))reverse(ALL(h[0]));
	else if(ask({h[0][0]},{h[1].back()}))reverse(ALL(h[0])),reverse(ALL(h[1]));
	else {
		if(!ask(h[0],h[1])){
			if(SZ(h[0])>SZ(h[1]))return h[0];
			else return h[1];
		}
		ll x=find(h[0],h[1]),y=find(h[1],h[0]);
		h[0]=rot(h[0],x+1),h[1]=rot(h[1],y);
	}
	for(auto i:h[1])h[0].pb(i);
	h[1].clear();
	return h[0];
}

