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

ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}

struct DS{
	map<ii,vector<ll>>mp;
	DS(){}
	void upd(ll i, ii p){mp[p].pb(i);}
	ll query(ll l, ll r, ii p){
		ll rs=lower_bound(ALL(mp[p]),r)-mp[p].begin();
		ll ls=lower_bound(ALL(mp[p]),l)-mp[p].begin();
		return (rs-ls)>0;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	vector<ii>a;
	for(auto i:s){
		if(i=='U')a.pb({0,1});
		if(i=='D')a.pb({0,-1});
		if(i=='L')a.pb({-1,0});
		if(i=='R')a.pb({1,0});
	}
	vector<ii>nor={{0,0}},rev=nor;
	fore(i,0,n)nor.pb(nor.back()+a[i]);
	reverse(ALL(a));
	fore(i,0,n)rev.pb(rev.back()+a[i]);
	DS st1,st2;
	fore(i,0,SZ(nor))st1.upd(i,nor[i]);
	fore(i,0,SZ(rev))st2.upd(i,rev[i]);
	while(q--){
		ii p; ll l,r; cin>>p.fst>>p.snd>>l>>r;
		ll res=0;
		res|=st1.query(0,l,p)|st1.query(r,n+1,p);
		p=p-nor[l-1];
		r=n+1-r,l=n+1-l;
		p=p+rev[r-1];
		//cout<<"["<<r<<","<<l<<"] "<<p.fst<<","<<p.snd<<"\n";
		res|=st2.query(r,l+1,p);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
