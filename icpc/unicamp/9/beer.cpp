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
const ll INF=4e5;

vector<ii> oper(ll &s, ll &e, ll top, set<ii>&st){
	vector<ii>upd;
	for(auto [r,l]:st){
		if(r>top)break;
		//cout<<l<<","<<r<<"\n";
		s=max(s,l);
		e=min(e,r);
		upd.pb({l,r});
	}
	return upd;
}

void change(set<ii>&st, ii p, ll d){
	if(d)st.insert(p);
	else st.erase(p);
}

struct STree{
	vector<set<ii>>t; ll n,sz;
	STree(ll n):t(2*n+5),n(n),sz(0){}
	void upd(ll p, ll v, ll d){
		sz+=d;
		ll _p=p;
		//cout<<"upd "<<_p<<","<<v<<" "<<d<<"\n";
		for(p+=n;p;p>>=1)change(t[p],{v,_p},d);
	}
	bool query(ll l, ll r){
		//cout<<"query "<<l<<","<<r<<":\n";
		ll s=l,e=r,_r=r;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)for(auto [a,b]:oper(s,e,_r,t[l++]))upd(a,b,-1);
			if(r&1)for(auto [a,b]:oper(s,e,_r,t[--r]))upd(a,b,-1);
		}
		if(e<=s)return 0;
		//cout<<"end query "<<s<<","<<e<<":\n";
		upd(s,e,1);
		return 1;
	}
};

bool cmp(ii a, ii b){
	return a.snd-a.fst<b.snd-b.fst;
}

int main(){FIN;
	ll m,n; cin>>m>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].fst--;
	sort(ALL(a),cmp);
	STree st(m);
	ll flag=1;
	vector<ll>ev(m+1);
	for(auto [l,r]:a){
		flag&=st.query(l,r);
		ev[l]++,ev[r]--;
	}
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	ll res=st.sz,sum=0;
	fore(i,0,m){
		sum+=ev[i];
		if(!sum)res++;
	}
	cout<<res<<"\n";
	return 0;
}
