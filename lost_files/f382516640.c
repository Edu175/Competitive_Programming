#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
int maxi(vector<ll>v){
	ll res=0;
	for(auto i:v){
		res=max(i,res);
	}
	return res;
}
int mini(vector<ll>v){
	ll res=1000000001;
	for(auto i:v){
		res=min(i,res);
	}
	return res;
}
 
int main(){FIN;
	ll t; cin>>t;
	while(t--){
	
	ll n; cin>>n;
	vector<pair<ll,ll>>l(n),r(n),c(n);
	fore(i,0,n)cin>>l[i].fst>>r[i].fst>>c[i].fst, l[i].snd=i, r[i].snd=i c[i].snd=i;
	ll L=1000000001, R=0;
fore(s,0,n){
	L=min(L,l[s].fst);
	R=max(R,r[s].fst);
	cout<<L<<" "<<R<<"\n";
	ll v,w;
	fore(i,s,s+1){
		if(L==l[i].fst)v=i;
		if(R==r[i].fst)w=i;
	}
	cout<<v<<" "<<w<<"\n";
	ll sumc=1000000001,x=sumc;
	if(v==w)sumc=c[v];
	else sumc=max(c[v]+c[w],max(c[v],c[w]));
	cout<<sumc<<"\n";
	x=min(x,sumc);
	cout<<x<<"\n";
}
	}
	 return 0;
}
