#include "koala.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcont=b;i<mxcont;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jfhg:v)cout<<jfhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

ll fn(ll n){return n*(n+1)/2;}
ll n,w;
vector<ll> alice(vector<ll>&b){
	vector<vector<ll>>dp(n+1,vector<ll>(w+1));
	for(ll i=n-1;i>=0;i--)fore(u,0,w+1){
		ll &res=dp[i][u];
		res=dp[i+1][u];
		if(u+b[i]+1<=w)res=max(res,i+1+dp[i+1][u+b[i]+1]);
	}
	ll u=0;
	vector<ll>r(n);
	fore(i,0,n){
		ll q=0;
		if(dp[i][u]!=dp[i+1][u])q=b[i]+1;
		r[i]=q;
		u+=q;
	}
	return r;
}
vector<ll>b,t,best;
ll val=-1;
ll value(vector<ll>r){
	ll c=0;
	fore(i,0,n){
		c+=t[i]==t.back()&&r[i]>b[i];
	}
	if(!c)return n+5;
	return c;
}
ll s;
void f(){
	if(SZ(b)==n){
		ll vali=value(alice(b));
		if(val==-1||vali<val)best=b,val=vali; // minimize value
		return;
	}
	ll i=SZ(b);
	auto go=[&](ll v){
		s+=v; b.pb(v);
		if(s<=w)f();
		s-=v; b.pop_back();
	};
	if(i&&t[i]==t[i-1])go(b.back());
	else fore(v,0,w-s+1)go(v);
}
ll cnt=0;
void max_value(){
	if(cnt>10||t.back()!=t.end()[-2])return;
	cout<<"\n\npaso "<<cnt++<<"\nt: ";
	imp(t);
	f();
	cout<<val<<":\nb: ";
	imp(best); 
	cout<<"r: ";
	auto r=alice(best);
	imp(r);
	cout<<"wins: ";
	fore(i,0,n)cout<<ll(r[i]>best[i])<<" ";;cout<<"\n";
	fore(i,0,n)if(t[i]==t.back()&&r[i]>best[i])t[i]=t.back()+1;
	max_value();
}
int main(){
	cin>>n>>w;
	t.resize(n,0);
	max_value();
	// fore(i,n/2,n)t[i]=1;
	// f();
	// cout<<val<<":\nb: ";
	// imp(best); 
	// cout<<"r: ";
	// auto r=alice(best);
	// imp(r);
	// cout<<"wins: ";
	// fore(i,0,n)cout<<ll(r[i]>best[i])<<" ";;cout<<"\n";
	return 0;
}
