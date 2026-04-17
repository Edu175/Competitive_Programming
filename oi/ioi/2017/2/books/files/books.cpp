#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dffyhg:v)cout<<dffyhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll solve(vector<ll>a, ll mx){
	while(SZ(a)&&a.back()==SZ(a)-1)a.pop_back();
	if(!SZ(a))return 0;
	// cout<<"solve "<<mx<<": "; imp(a);
	ll res=0;
	fore(i,0,SZ(a)){
		if(mx<i)res+=2;
		mx=max(mx,a[i]);
	}
	// cout<<res<<"\n";
	return res;
}

long long minimum_walk(std::vector<int> A, int S){
	ll n=SZ(A);
	vector<ll>a;
	fore(i,0,n)a.pb(A[i]);
	ll s=S;
	ll res=0;
	fore(i,0,n)res+=abs(a[i]-i);
	ll mx=s,mn=s;
	fore(i,0,s)mx=max(mx,a[i]);
	fore(i,s+1,n)mn=min(mn,a[i]);
	vector<ll>l,r;
	fore(i,0,s+1)l.pb(s-a[i]);
	reverse(ALL(l));
	mn=s-mn;
	res+=solve(l,mn);
	fore(i,s,n)r.pb(a[i]-s);
	mx-=s;
	res+=solve(r,mx);
	return res;
}
