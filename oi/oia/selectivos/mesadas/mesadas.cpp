#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

#define oper max
ii NEUT={0,-1};
struct STree{
	ll n; vector<ii>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void upd(ll p, ii v){
		for(p+=n,t[p]=v;p>1;p>>=1){
			t[p>>1]=oper(t[p],t[p^1]);
		}
	}
	ii query(ll l, ll r){
		ii res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
int main(){FIN;
	ifstream cin;   cin.open("mesadas.in", ios::in);
	ofstream cout; cout.open("mesadas.out", ios::out);
	ll n; cin>>n;
	vector<pair<ii,ll>>a;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		a.pb({{x,y},i});
		if(x!=y)a.pb({{y,x},i});
	}
	sort(ALL(a));
	STree st(MAXN);
	vector<ll>f(SZ(a)),vis(SZ(a)),us(n),idx(SZ(a));
	vector<ii>b;
	fore(i,0,SZ(a)){
		ii r=st.query(0,a[i].fst.snd+1); r.fst++;
		f[i]=r.snd;
		//cout<<i<<" "<<a[i].fst.fst<<","<<a[i].fst.snd<<": "<<r.fst<<" "<<r.snd<<"\n";
		r.snd=i;
		st.upd(a[i].fst.snd,r);
		b.pb({r.fst,i});
		idx[i]=a[i].snd;
	}
	sort(ALL(b)); reverse(ALL(b));
	ll res=0;
	//for(auto i:b)cout<<i.fst<<" "<<i.snd<<" "<<f[i.snd]<<"\n";
	fore(i,0,SZ(b)){
		if(vis[b[i].snd]||us[idx[b[i].snd]])continue;
		res++;
		for(ll x=b[i].snd;x!=-1&&!vis[x];x=f[x]){
			//cout<<x<<" ";
			if(us[idx[x]]){/*cout<<". ";*/continue;}
			vis[x]=1,us[idx[x]]=1;
		}
		//cout<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
