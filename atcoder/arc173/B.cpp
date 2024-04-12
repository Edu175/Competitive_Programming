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
typedef pair<ll,ll> ii;
const ll MOD=269979449;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
ii pen(ii a, ii b){
	ii r={b.snd-a.snd,b.fst-a.fst};
	ll g=gcd(r.fst,r.snd);
	r.fst/=g,r.snd/=g;
	if(r.snd<0)r.snd*=-1,r.fst*=-1;
	if(r.snd==0)r.fst=abs(r.fst);
	//cout<<"pen "<<cv(a)<<" "<<cv(b)<<": "<<cv(r)<<"\n";
	return r;
}
ii rec(ii a, ii b){
	ii r=pen(a,b);
	ll m=(r.fst+MOD)%MOD*fpow(r.snd,MOD-2)%MOD;
	ll c=(a.snd-m*a.fst%MOD+MOD)%MOD;
	if(r.snd==0)c=MOD+a.fst;
	return {m,c};
}
int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	map<ii,set<ll>>mp;
	ll c=0;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		mp[rec(a[i],a[j])].insert(i);
	}
	for(auto i:mp)c=max(c,(ll)SZ(i.snd));
	/*for(auto i:mp){
		cout<<cv(i.fst)<<": ";
		imp(i.snd);
	}*/
	ll res=n/3;
	if(c/2>n-c)res=n-c;
	cout<<res<<"\n";
	return 0;
}
