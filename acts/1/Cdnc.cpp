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
const ll MAXN=5e5+5,INF=1e10;
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
ll exl[MAXN],exr[MAXN];
ll a[MAXN],h[MAXN];

void dnc_l(ll l, ll r, vector<ll>v){
	if(r-l==1){
		for(auto i:v)exl[i]=l;
		return;
	}
	ll m=(l+r)/2;
	vector<ll>A,B;
	for(auto i:v){
		if(a[i]-h[i]<a[m-1])A.pb(i);
		else B.pb(i);
	}
	dnc_l(l,m,A);
	dnc_l(m,r,B);
}
void dnc_r(ll l, ll r, vector<ll>v){
	if(r-l==1){
		for(auto i:v)exr[i]=l;
		return;
	}
	ll m=(l+r)/2;
	vector<ll>A,B;
	for(auto i:v){
		if(a[i]+h[i]<=a[m])A.pb(i);
		else B.pb(i);
	}
	dnc_r(l,m,A);
	dnc_r(m,r,B);
}
struct event{
	ll l,r,idx;
};
int main(){FIN;
	ll n,nq; cin>>n>>nq;
	fore(i,0,n)cin>>a[i]>>h[i];
	vector<ll>tmp;
	fore(i,0,n)tmp.pb(i);
	dnc_l(0,n,tmp);
	dnc_r(0,n,tmp);
	vector<vector<ll>>hl(n),hr(n);
	fore(i,0,n){
		if(a[i]-h[i]<a[0])exl[i]=-1;
		else hl[exl[i]].pb(i);
		if(a[i]+h[i]>a[n-1])exr[i]=-1;
		else hr[exr[i]].pb(i);
	}
	fore(i,0,n)cerr<<exl[i]<<" ";;cerr<<"\n";
	fore(i,0,n)cerr<<exr[i]<<" ";;cerr<<"\n";
	vector<ll>spl(n+1),spr(n+1);
	fore(i,1,n+1){
		spl[i]=spl[i-1]+SZ(hl[i-1]);
		spr[i]=spr[i-1]+SZ(hr[i-1]);
	}
	vector<event> ev[n+1];
	vector<ll>ans;
	vector<ii>qs;
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		ev[l].pb({l,r,SZ(ans)}); ans.pb(0);
		ev[r].pb({l,r,SZ(ans)}); ans.pb(0);
		qs.pb({l,r});
	}
	STree st(n);
	fore(x,0,n){
		for(auto q:ev[x]){
			ans[q.idx]=st.query(q.l,q.r);
		}
		for(auto i:hl[x])st.upd(exr[i],1);
	}
	ll cnt=0;
	fore(i,0,nq){
		auto [l,r]=qs[i];
		ll res=0;
		fore(j,l,r){
			res+=(exl[j]!=-1&&exl[j]>=l)||(exr[j]!=-1&&exr[j]<r);
		}
		
		//ll res=spl[r]-spl[l]+spr[r]-spr[l]-(ans[cnt+1]-ans[cnt]);
		cout<<res<<"\n";
		cnt+=2;
	}
	return 0;
}
