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
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll ft[MAXV+1],total=0;
void upd(int i0, ll v){
	total+=v;
	for(int i=i0+1;i<=MAXV;i+=i&-i)ft[i]+=v;
}
ll get(int i){
	ll res=0;
	for(;i>0;i-=i&-i)res+=ft[i];
	return res;
}
ll query(int l){
	return total-get(l);
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
		int l=0,r=MAXV;
		while(l<=r){
			int mid=(l+r)/2;
			if(query(mid)>sum)l=mid+1;
			else r=mid-1;
		}
		if(r>=MAXV||sum==0)continue;
		ll resi;
		if(r<0)resi=st2.query(0,MAXV);
		else {
			auto s=query(r);
			auto w=st2.query(r,MAXV);
			assert(s>=sum);
			resi=w-(s-sum)*r;
		}
		//cout<<d<<" "<<i<<": "<<r<<" = "<<resi<<" ("<<resi-p*d<<")\n";
		res=max(res,resi-p*d);
	}
	cout<<res<<"\n";
	return 0;
}
