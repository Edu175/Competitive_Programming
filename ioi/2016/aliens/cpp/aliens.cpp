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

#define bint __int128

const ll INF=2e12;
ll sq(ll n){return n*n;}
vector<ii>a;
ll sup(ll i){
	//cerr<<"sup "<<i<<": "<<(!i?0:sq(max(a[i-1].snd-a[i].fst,(ll)0)))<<"\n";
	return (!i?0:sq(max(a[i-1].snd-a[i].fst,(ll)0)));
}
const ll MAXN=1e5+5;
ll dp[MAXN],cnt[MAXN];
//(min, increasing insert coefficents, non increasing queries, online) 
//for maximum just change the sign of lines
bint idiv(bint a, bint b){ //int division
	if((a<0)^(b<0))return (a+b-1)/b; //ceil
	return a/b; //floor
}
struct ln{
	bint a,b,i;
	bint eq(bint x){return a*x+b;}
	pair<bint,bint> operator%(ln l){
		bint x=idiv(b-l.b,l.a-a);
		return {x,eq(x)};
	}
};
deque<ln>cht;
ii query(bint x){
	ln l=cht.back(); cht.pop_back();
	while(SZ(cht)&&l.eq(x)>=cht.back().eq(x))l=cht.back(),cht.pop_back();
	cht.pb(l);
	//cout<<"query "<<(ll)cht.back().eq(x)<<" --> "<<(ll)cht.back().eq(x)/MAXN<<" or "<<ll(cht.back().eq(x)-cnt[cht.back().i])/MAXN<<"\n";
	ll idx=cht.back().i;
	return {(cht.back().eq(x)-cnt[idx])/MAXN,idx};
}
void insert(ln l){
	l.a*=MAXN,l.b=l.b*MAXN+cnt[l.i];
	if(!SZ(cht)){
		cht.pb(l);
		return;
	}
	ln m=cht.front(); cht.pop_front();
	while(SZ(cht)&&((l%m).fst>(m%cht.front()).fst||l%m==m%cht.front()))
		m=cht.front(),cht.pop_front();
	cht.push_front(m), cht.push_front(l);
}
void f(ll n, ll d){
	cht.clear();
	//cout<<"f "<<d<<":\n";
	for(ll i=n-1;i>=0;i--){
		insert(ln({-2*a[i].snd,sq(a[i].snd)+dp[i+1],i+1}));
		ll &res=dp[i];
		ii rq=query(a[i].fst);
		//cout<<rq.fst<<"\n";
		res=rq.fst+sq(a[i].fst)-sup(i)+d;
		cnt[i]=cnt[rq.snd]+1;
		//cout<<i<<": ("<<rq.snd<<") "<<dp[i]<<" "<<cnt[i]<<"\n";
	}
	//cout<<cnt[0]<<"\n\n";
	//cerr<<d<<" "<<cnt[0]<<"\n";
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
	f(n,0);
	//cerr<<"dp_0 "<<dp[0]<<"\n";
	//for(auto i:a)cerr<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	ll l=0; r=1e13;
	while(l<=r){
		ll m=(l+r)/2;
		f(n,m);
		if(cnt[0]<=k)r=m-1;
		else l=m+1;
	}
	//cout<<n<<" "<<k<<"\n";
	//cout<<l<<"\n";
	f(n,l+1);
	f(n,l);
	//cerr<<k<<"\n";
	ll res=dp[0]-l*k;
	//cout<<cnt[0]<<"\n";
	return res;
}
