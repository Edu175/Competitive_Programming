#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dffyhg:v)cout<<dffyhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
std::vector<int> ask(int i);

const ll MAXN=2e5+5;
ll B=42; // B=466 creo

ii mem[MAXN];
ll ans=-1;
ll sum(ii a){return a.fst+a.snd;}
ii get(ll i){
	auto &res=mem[i];
	if(res.fst!=-1)return res;
	auto rq=ask(i);
	res={rq[0],rq[1]};
	if(sum(res)==0)ans=i;
	return res;
}
random_device rd;
mt19937 rng(rd());
ll medio(ll l, ll r){
	/*r++;
	return l+rng()%(r-l);*/
	return (l+r)/2;
}
int find_best(int n){
	mset(mem,-1);
	B=min(B,n);
	ll mx=0;
	vector<ll>per;
	fore(i,0,n)per.pb(i);
	random_shuffle(ALL(per));
	set<ll>st;
	fore(i,0,B){
		mx=max(mx,sum(get(per[i])));
		st.insert(per[i]);
	}
	ll p=0;
	while(p<n){
		while(p<n&&sum(get(p))<mx)p++;
		if(p==n)break;
		while(SZ(st)&&*st.begin()<=p)st.erase(st.begin());
		while(SZ(st)&&get(*st.begin())==get(p))
			p=*st.begin(),st.erase(st.begin());
		ll l=p+1,r=(SZ(st)?*st.begin():n)-1;
		while(l<=r){
			ll m=medio(l,r);
			st.insert(m);
			if(get(m)==get(p))l=m+1;
			else r=m-1;
		}
		p=l;
	}
	assert(ans!=-1);
	return ans;
}
