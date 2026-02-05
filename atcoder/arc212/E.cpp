#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=1e6+5;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll comb(ll a, ll b){
	if(a<0||b<0)return 0;
	return mul(fc[a+b],mul(fci[a],fci[b]));
}
struct node{
	ll c=0,r=1,big=1;
};
bool operator<(const node& a, const node& b){
	return false;
}
node bor;
node merge(node a, node b, ll hasl, ll hasr){
	// assert(hasl||hasr);
	node c;
	c.c=a.c+b.c;
	c.r=mul(a.r,b.r);
	ll ul=comb(a.c+1,b.c);
	ll ur=comb(a.c,b.c+1);
	ll both=comb(a.c,b.c);
	ll cur=add(hasl*ul,hasr*ur);
	if(hasl&&hasr)cur=sub(cur,both);
	if(!hasl&&!hasr)cur=add(cur,both);
	c.r=mul(c.r,cur);
	c.c++;
	return c;
}
int main(){FIN;
	factos();
	ll n; cin>>n;
	vv a(n),p(n);
	fore(i,0,n){
		cin>>a[i]; a[i]--;
		p[a[i]]=i;
	}
	set<pair<ll,node>>st;
	fore(i,0,n)st.insert({i,node()});
	bor.big=0;
	st.insert({-1,bor});
	st.insert({n,bor});
	auto eraseit=[&](auto it){
		if(it->snd.c>0)st.erase(it); // if is alive
	};
	ll res=1;
	fore(x,0,n){
		ll i=p[x];
		auto it=st.lower_bound({i,{-1,-1}});
		assert(it->fst==i);
		auto l=prev(it),r=next(it);
		ll hasl=0,hasr=0;
		auto t=l;
		while(!hasl){
			hasl|=t->snd.big;
			if(t==st.begin())break;
			t=prev(t);
		}
		t=r;
		while(!hasr&&t!=st.end()){
			hasr|=t->snd.big;
			t=next(t);
		}
		node cur=merge(l->snd,r->snd,hasl,hasr);
		cur.big=0;
		eraseit(l);
		eraseit(r);
		st.erase(it);
		st.insert({i,cur});
		// cout<<x<<" "<<i<<": "<<cur.c<<" "<<cur.r<<"\n";
		res=cur.r;
	}
	cout<<res<<"\n";
	return 0;
}
