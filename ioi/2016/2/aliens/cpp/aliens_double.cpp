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
typedef long double ld;
typedef pair<ll,ll> ii;
const ll INF=2e12;
const ld EPS=1e-8;
ll sq(ll n){return n*n;}
vector<ii>a;
ll sup(ll i){
	if(i&&a[i-1].snd>a[i].fst)return sq(a[i-1].snd-a[i].fst);
	return 0;
}
const ll MAXN=1e5+5;
ld dp[MAXN];
ll cnt[MAXN];
//(min, increasing insert coefficents, non increasing queries, online) 
//for maximum just change the sign of lines
ll idiv(ll a, ll b){ //int division
	if((a<0)^(b<0))return (a+b-1)/b; //ceil
	return a/b; //floor
}
struct ln{
	ll a;
	ld b;
	ll i;
	ld eq(ll x){return a*x+b;}
	pair<ld,ld> operator%(ln l){
		ld x=ld(b-l.b)/ld(l.a-a);
		return {x,eq(x)};
	}
};
deque<ln>cht; ll k;
pair<ld,ll> query(ll x){
	ln l=cht.back(); cht.pop_back();
	ln r=l;
	while(SZ(cht)&&l.eq(x)>=cht.back().eq(x)){
		l=cht.back();
		cht.pop_back();
		if(l.eq(x)<r.eq(x)+EPS||(abs(l.eq(x)-r.eq(x))<=EPS&&abs(l.i-k)<abs(r.i-k)))r=l;
	}
	cht.pb(l);
	return {r.eq(x),r.i};
}
void insert(ln l){
	if(!SZ(cht)){
		cht.pb(l);
		return;
	}
	ln m=cht.front(); cht.pop_front();
	while(SZ(cht)&&((l%m).fst>(m%cht.front()).fst||l%m==m%cht.front()))
		m=cht.front(),cht.pop_front();
	cht.push_front(m), cht.push_front(l);
}
void f(ll n, ld d){
	cht.clear();
	//cout<<"f "<<d<<":\n";
	//for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	for(ll i=n-1;i>=0;i--){
		insert(ln({-2*a[i].snd,sq(a[i].snd)+dp[i+1],i+1}));
		ld &res=dp[i];
		pair<ld,ll> rq=query(a[i].fst);
		res=rq.fst+sq(a[i].fst)-sup(i)+d;
		cnt[i]=cnt[rq.snd]+1;
		//cout<<i<<": ("<<rq.snd<<") "<<dp[i]<<" "<<cnt[i]<<"\n";
	}
	//cout<<cnt[0]<<" "<<dp[0]<<" ("<<dp[0]-d*cnt[0]<<")\n\n";
}
long long take_photos(int n, int m, int K, std::vector<int> R, std::vector<int> C) {
	k=K;
	vector<ii>a_;
	fore(i,0,n){
		ll l=R[i],r=C[i];
		if(l>r)swap(l,r);
		r++;
		a.pb({l,-r});
	}
	sort(ALL(a));
	//for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";;
	ll r_=0;
	for(auto [s,e]:a){
		e=-e;
		if(e>r_)a_.pb({s,e}),r_=e;
	}
	a=a_;
	n=SZ(a);
	//for(auto i:a)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	ld l=-1e13, r=1e13;
	cout<<n<<" "<<k<<"\n";
	while(r-l>=1e-8){
		cout<<l<<","<<r<<"\n";
		ld m=(l+r)/2;
		f(n,m);
		if(cnt[0]<=k)r=m;
		else l=m;
		cout<<m<<": "<<cnt[0]<<"\n";
	}
	cout<<l<<"\n";
	f(n,l);
	cout<<cnt[0]<<"\n";
	return dp[0]-l*cnt[0];
}
