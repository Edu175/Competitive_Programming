#include "aliens.h"
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
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e15;
ll sq(ll n){return n*n;}
vector<ii>a;
ll cost(ll i, ll j){
	ll res=sq(a[j].snd-a[i].fst);
	if(i&&a[i-1].snd>a[i].fst)res-=sq(a[i-1].snd-a[i].fst);
	return res;
}
vector<vector<ll>>dp;
void dnc(ll l, ll r, ll s, ll e, ll c){
	if(r-l<=0)return;
	ll m=(l+r)/2,mn=m,&res=dp[m][c];
	res=INF;
	fore(x,max(s,m),e){
		ll resi=cost(m,x)+dp[x+1][c+1];
		if(resi<res)mn=x,res=resi;
	}
	//cout<<"["<<l<<","<<r<<") "<<m<<","<<c<<" ["<<s<<","<<e<<"): "<<res<<" ("<<mn<<")\n";
	if(r-l>1){
		dnc(l,m,s,mn+1,c),dnc(m+1,r,mn,e,c);
	}
}

long long take_photos(int n, int m, int k, std::vector<int> R, std::vector<int> C) {
	vector<ii>a_;
	fore(i,0,n){
		ll l=R[i],r=C[i];
		if(l>r)swap(l,r);
		r++;
		a.pb({l,-r});
	}
	sort(ALL(a));
	//for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";;
	ll r=0;
	for(auto [s,e]:a){
		e=-e;
		if(e>r)a_.pb({s,e}),r=e;
	}
	a=a_;
	n=SZ(a);
	//for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	dp.resize(n+5,vector<ll>(k+5));
	fore(c,0,k+1)dp[n][c]=0;
	fore(i,0,n+1)dp[i][k+1]=INF;
	for(ll c=k;c>=0;c--)dnc(0,n,0,n,c);
    return dp[0][0];
}
