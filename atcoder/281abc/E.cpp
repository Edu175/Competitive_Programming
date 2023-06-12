#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll INF=1e10+1;
priority_queue<ll,vector<ll>,greater<ll>>qb;
priority_queue<ll>qc;
map<ll,ll>b,c;

void put(ll w,ll v){
	if(w==0){
		b[v]++;
		qb.push(v);
	}
	else {
		c[v]++;
		qc.push(v);
	}
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>v;
	fore(i,0,m)v.pb(a[i]);
	sort(ALL(v));
	ll sum=0;
	fore(i,0,k)sum+=v[i];
	cout<<sum<<" ";
	fore(i,0,k){
		c[v[i]]++;
		qc.push(v[i]);
	}
	fore(i,k,SZ(v))b[v[i]]++,qb.push(v[i]);
	fore(i,0,n-m){
		ll r=i+m;
		if(b[a[i]])b[a[i]]--;
		if(c[a[i]])c[a[i]]--,sum-=a[i],put(1,INF);
		put(0,a[r]);
		while(c[qc.top()]==0)qc.pop();
		while(b[qb.top()]==0)qb.pop();
		ll g=qc.top(),h=qb.top();
		if(h<g){
			c[g]--;
			qc.pop();
			if(g!=INF)put(0,g),sum-=g;
			put(1,h);
			sum+=h;
			b[h]--;
			qb.pop();
		}
		cout<<sum<<" ";
	}
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
