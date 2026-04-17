#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5005,MAXW=1e4+5;

ll dp[MAXN][MAXW];

int main(){
	JET
	ll n,W,k; cin>>n>>W>>k;
	vv w(n),v(n);
	fore(i,0,n)cin>>w[i]>>v[i];
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){return v[i]>v[j];});
	for(ll i=n-1;i>=0;i--)fore(s,0,W+1){
		auto &res=dp[i][s];
		res=dp[i+1][s];
		ll si=s+w[per[i]];
		if(si<=W){
			res=max(res,v[per[i]]+dp[i+1][si]);
		}
	}
	priority_queue<ll,vv,greater<ll>> pq;
	ll sumv=0;
	fore(i,0,k)pq.push(w[per[i]]),sumv+=v[per[i]];
	ll s=0;
	ll res=sumv+dp[k][0];
	fore(idx,k,n){
		ll i=per[idx];
		pq.push(w[i]),sumv+=v[i];
		s+=pq.top(),pq.pop();
		if(s<=W){
			ll cur=sumv+dp[idx+1][s];
			res=max(res,cur);
			// cout<<idx<<": "<<
		}
	}
	cout<<res<<"\n";
	return 0;
}