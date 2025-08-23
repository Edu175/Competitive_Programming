#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,m;
		cin>>n>>m;
		ll a[n]; fore(i,0,n) cin>>a[i];
		ii s[m]; fore(i,0,m) {cin>>s[i].fst>>s[i].snd; s[i].snd--;}
		ll r=0; sort(s,s+m);
		ll p[n]; vv nxt[n];
		fore(i,0,m) nxt[s[i].snd].pb(i);
		fore(i,0,n) nxt[i].pb(m);
		mset(p,0);
		priority_queue <ii> pq; fore(i,0,n) pq.push((ii){-nxt[i][p[i]],i});
		ll val[n]; ll j=0; fore(i,0,n) val[i]=a[i];
		while(j<m&&SZ(pq)){
			auto [x,t]=s[j];
			ll del;
			assert(val[t]>=0);assert(val[t]<=a[t]);
			while(r<x && SZ(pq)){
				auto [trash,i]=pq.top(); pq.pop();
				assert(val[i]>=0);assert(val[i]<=a[i]);
				if(-trash!=nxt[i][p[i]]) continue;
				del=min(x-r,val[i]);
				val[i]-=del;
				r+=del;
				if(val[i]) {pq.push({-nxt[i][p[i]],i});}
			}
			if(r==x){
				p[t]++;
				assert(p[t]!=SZ(nxt[t]));
				pq.push({-nxt[t][p[t]],t}); val[t]=a[t];
			}
			else break;
			j++;
		} 
		fore(i,0,n){
			assert(val[i]>=0); assert(val[i]<=a[i]);
			r+=val[i];
		}
		cout<<r<<"\n";
	}
	return 0;
}