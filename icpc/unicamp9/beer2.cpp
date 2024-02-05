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
typedef int ll;
typedef pair<ll,ll> ii;

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
	if(d==1)st.insert(p);
	else st.erase(p);
}

struct STree{
	vector<set<ii>>t; ll n; set<ii>st;
	STree(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll v, ll d){
		if(d==1)st.insert({p,v});
		else st.erase({p,v});
		ll _p=p;
		//cout<<"upd "<<_p<<","<<v<<" "<<d<<"\n";
		for(p+=n;p;p>>=1)change(t[p],{v,_p},d);
	}
	bool query(ll l, ll r){
		//cout<<"query "<<l<<","<<r<<":\n";
		ll s=l,e=r,_r=r;
		vector<ii>up;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)for(auto i:oper(s,e,_r,t[l++]))up.pb(i);
			if(r&1)for(auto i:oper(s,e,_r,t[--r]))up.pb(i);
		}
		if(e<=s)return 0;
		//cout<<"end query "<<s<<","<<e<<":\n";
		for(auto i:up)upd(i.fst,i.snd,-1);
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
	vector<ll>ev(m+1,-1),ev2(m+1,0);
	for(auto [l,r]:a){
		flag&=st.query(l,r);
		ev2[l]++,ev2[r]--;
	}
	ll res=0,sum=0;
	fore(i,0,m){
		sum+=ev2[i];
		if(!sum)res++;
	}
	// [ , )
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	vector<ii>b;
	for(auto i:st.st){
		b.pb(i);//,cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		ev[i.fst]=max(ev[i.fst],i.snd);
	}
	
	//imp(ev);
	ll acum=-1;
	fore(i,0,m){
		ev[i]=acum=max(acum,ev[i]);
	}
	//imp(ev);
	vector<ll>dp(m+1);
	dp[m]=0;
	for(ll i=m-1;i>=0;i--){
		dp[i]=dp[i+1];
		//cout<<i<<": "<<i+1;
		if(ev[i]>i)dp[i]=max(dp[i],1+dp[ev[i]]);//,cout<<" 1+dp["<<ev[i]<<"]";
		//cout<<" = "<<dp[i]<<"\n";;
	}
	cout<<res+dp[0]<<"\n";
	return 0;
}
