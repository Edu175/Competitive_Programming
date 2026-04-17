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
	vector<vector<ll>>dp(n+5,vector<ll>(k+5)),opt(n+5,vector<ll>(k+5));
	fore(c,0,k+1)dp[n][c]=0;
	for(ll i=n-1;i>=0;i--)fore(c,0,k+1){
		ll &res=dp[i][c],&mn=opt[i][c];
		res=INF;
		if(c==k)continue;
		//cout<<i<<","<<c<<":\n";
		fore(x,max(i,(!c?0:opt[i][c-1])),(i==n-1?n:opt[i+1][c]+1)){
			ll resi=cost(i,x)+dp[x+1][c+1];
			if(resi<res)res=resi,mn=x;
			//cout<<x<<" "<<resi<<"\n";
		}
		//cout<<res<<" ("<<mn<<")\n\n";
	}
    return dp[0][0];
}
