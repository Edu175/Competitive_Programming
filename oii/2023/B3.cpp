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

struct FTree{
	vector<ll>ft; ll n;
	FTree(ll n):ft(n+5,0),n(n+5){}
	void upd(ll i0, ll v){
		for(ll i=i0+1;i<n;i+=i&-i)ft[i]+=v;
	}
	ll get_sum(ll i0){
		ll res=0;
		for(ll i=i0;i>0;i-=i&-i)res+=ft[i];
		return res;
	}
	ll query(ll a, ll b){
		return get_sum(b)-get_sum(a);
	}
};
struct ran{
	ll l,r,m;
	ran(){}
	ran(ll l, ll r, ll m):l(l),r(r),m(m){}
};
bool comp(ran a, ran b){
	return a.r-a.l<b.r-b.l;
}
int main(){FIN;
	ll n; cin>>n;
	ran a[n];
	fore(i,0,n){
		cin>>a[i].l>>a[i].r;
		a[i].r*=2,a[i].l*=2;
		a[i].m=(a[i].l+a[i].r)/2;
	}
	sort(a,a+n,comp); reverse(a,a+n);
	//comprimir
	vector<pair<ll,ii>>id;
	fore(i,0,n){
		id.pb({a[i].l,{i,0}});
		id.pb({a[i].r,{i,1}});
		id.pb({a[i].m,{i,2}});
	}
	ll k=0;
	sort(ALL(id));
	fore(i,0,SZ(id)){
		if(i&&id[i].fst!=id[i-1].fst)k++;
		ll ty=id[i].snd.snd,idx=id[i].snd.fst;
		if(ty==0)a[idx].l=k;
		if(ty==1)a[idx].r=k;
		if(ty==2)a[idx].m=k;
	}
	k++;
	//done
	FTree ft(k);
	ll res=0;
	fore(i,0,n){
		res+=ft.query(a[i].l,a[i].r+1);
		ft.upd(a[i].m,1);
	}
	cout<<res<<"\n";
	return 0;
}
