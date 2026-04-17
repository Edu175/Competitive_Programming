#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXV=1e6+5;
ll ft[MAXV+1],total=0;
void upd(int i0, ll v){
	i0=MAXV-1-i0;
	total+=v;
	for(int i=i0+1;i<=MAXV;i+=i&-i)ft[i]+=v;
}
ii find(ll x){ // upperbound on prefix sums], (pos,remainder)
	ll p=0;    // change 19 to floor(log2(MAXN))
	for(ll k=18;k>=0;k--)if(p+(1ll<<k)<=MAXV&&ft[p+(1ll<<k)]<=x){
		p+=1ll<<k;
		x-=ft[p];
	}
	p=MAXV-1-p;
	return {p,x};
}

struct STree2{
	vector<ll>t; int n;
	STree2(int n):t(2*n+5,0),n(n){}
	void upd(int p, ll v){
		for(p+=n,t[p]+=v*(p-n);p>1;p>>=1)
			t[p>>1]=t[p]+t[p^1];
	}
	ll query(int l, int r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};

int main(){FIN;
	int n,m; ll p; cin>>n>>m>>p;
	vector<pair<int,ll>>a(n);
	vector<pair<int,ii>>b(m);
	vector<ii>ev;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,ev.pb({a[i].fst,i});
	fore(i,0,m)cin>>b[i].fst>>b[i].snd.fst>>b[i].snd.snd,ev.pb({b[i].fst,n+i});
	STree2 st2(MAXV);
	ll res=0,sum=0;
	sort(ALL(ev));
	for(auto [d,i]:ev){
		if(i<n){
			sum+=a[i].snd;
		}
		else {
			i-=n;
			upd(b[i].snd.snd,b[i].snd.fst);
			st2.upd(b[i].snd.snd,b[i].snd.fst);
		}
		if(sum==0)continue;
		auto [r,rem]=find(total-sum);
		ll resi;
		if(r<0)resi=st2.query(0,MAXV);
		else {
			auto w=st2.query(r,MAXV);
			resi=w-rem*r;
		}
		cout<<d<<" "<<i<<": "<<r<<" "<<rem<<" = "<<resi<<" ("<<resi-p*d<<")\n";
		res=max(res,resi-p*d);
	}
	cout<<res<<"\n";
	return 0;
}
