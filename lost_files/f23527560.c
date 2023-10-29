#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfkg:v)cout<<dfkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

/*struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,0),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};*/
struct FT{
	vector<ll>ft; ll n;
	FT(ll n):ft(n+5,0),n(n+5){}
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
int main(){FIN;
	ll n; cin>>n;
	ran a[n];
	vector<pair<ll,ii>>id;
	fore(i,0,n){
		cin>>a[i].l>>a[i].r;
		a[i].r*=2,a[i].l*=2;
		//a[i].l--,a[i].r--;
		a[i].m=(a[i].l+a[i].r)/2;
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
	vector<pair<ll,ii>>hl[k+5][2],hr[k+5][2];
	ll qs[n][4]={};
	fore(i,0,n){
		ll l=a[i].l,r=a[i].r,m=a[i].m;
		hr[m][0].pb({m,{i,0}}), hr[l][1].pb({m,{i,1}});
		hl[r][0].pb({m,{i,2}}), hl[m][0].pb({m,{i,3}});
	}
	FT stl(k),str(k);
	vector<ll> ms[k];
	fore(i,0,n)ms[a[i].m].pb(i);
	fore(i,0,k){
		//1
		for(auto j:hr[i][1])qs[j.snd.fst][j.snd.snd]=str.query(j.fst,k);
		for(auto j:hl[i][1])qs[j.snd.fst][j.snd.snd]=stl.query(0,j.fst+1);
		//upd
		for(auto j:ms[i])stl.upd(a[j].l,1),str.upd(a[j].r,1);
		//0
		for(auto j:hr[i][0])qs[j.snd.fst][j.snd.snd]=str.query(j.fst,k);
		for(auto j:hl[i][0])qs[j.snd.fst][j.snd.snd]=stl.query(0,j.fst+1);
	}
	ll res=0;
	fore(i,0,n){
		res+=qs[i][0]-qs[i][1]+qs[i][2]-qs[i][3];
	}
	cout<<(res-n)/2<<"\n";
	return 0;
}
