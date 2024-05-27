#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll k;
string cv(ii i){return to_string(i.fst)+","+to_string(i.snd);}
ll solve(ii s, ii e, ll ad){
	ll x=abs(s.fst-e.fst),y=abs(s.snd-e.snd);
	ll mx=max(x,y),mn=min(x,y),d=mx-mn;
	assert(d%2==0);
	ll res=2*mn+min((ll)4,k+1)*(d/2);
	
//	cout<<"solve "<<cv(s)<<" "<<cv(e)<<": "<<x<<" "<<y<<" | "<<res<<" +"<<ad<<" = "<<res+ad<<"\n";
//	cout<<x<<" "<<y<<" | "<<mx<<" "<<mn<<" | "<<d<<" "<<k<<"\n";
	return res+ad;
}
pair<vector<ii>,vector<ll>> f(ii s){
	vector<ii>ss;
	vector<ll>cs;
	if(!((s.fst/k+s.snd/k)&1)){
		ss.pb({s.fst/k+1,s.snd/k}); cs.pb(k-s.fst%k);
		ss.pb({s.fst/k,s.snd/k+1}); cs.pb(k-s.snd%k);
		ss.pb({s.fst/k-1,s.snd/k}); cs.pb(s.fst%k+1);
		ss.pb({s.fst/k,s.snd/k-1}); cs.pb(s.snd%k+1);
	}
	else ss.pb({s.fst/k,s.snd/k}),cs.pb(0);
	return {ss,cs};
}
int main(){FIN;
	cin>>k;
	ii s,e; cin>>s.fst>>s.snd>>e.fst>>e.snd; s.fst+=k,s.snd+=k,e.fst+=k,e.snd+=k;
	auto [ss,cs]=f(s);
	auto [es,ce]=f(e);
	ll res=abs(s.fst-e.fst)+abs(s.snd-e.snd);
	fore(i,0,SZ(ss))fore(j,0,SZ(es)){
		res=min(res,solve(ss[i],es[j],cs[i]+ce[j]));
	}
	cout<<res<<"\n";
	return 0;
}
