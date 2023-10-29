#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
ll p[MAXN];
LL res=0;
ll amin(ll a, ll b){ //arg min
	if(p[a]<p[b])return a;
	return b;
}
ll amax(ll a, ll b){ //arg max
	if(p[a]>p[b])return a;
	return b;
}
struct node{ //all arg
	ii all;
	vector<ii>pre,suf;
	node(ll v):all({v,v}),pre(1,all),suf(1,all){}
	node(){}
	void prnt(){
		cout<<all.fst<<","<<all.snd<<"\n";
		for(auto i:pre)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";
		for(auto i:suf)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n\n";
	}
};

inline void calc(vector<pair<ii,ll>> &u, vector<pair<ii,ll>> &v, ll cnt, ll fl){
	vector<vector<pair<ll,ll>>> upd(cnt+1);
	vector<vector<ll>>h(cnt);
	for(auto i:u){
		ll l=i.fst.fst,r=i.fst.snd,is=i.snd;
		if(fl){
			if(!is){
				upd[l].pb({r,-1});
				upd[r+1].pb({r,1});
			}
		}
		else {
			if(is){
				upd[l].pb({r,1});
				upd[r+1].pb({r,-1});
			}
		}
	}
	if(fl){
		sort(ALL(v));
		for(auto i:u){
		pair<ii,ll> fi={{i.fst.fst,-1},-1};
			res+=SZ(v)-(lower_bound(ALL(v),fi)-v.begin());
		}
	}
	for(auto i:v)h[i.fst.fst].pb(i.fst.snd);
	STree st(cnt);
	fore(i,0,cnt){
		for(auto j:upd[i])st.upd(j.fst,j.snd);
		for(auto j:h[i]){
			res+=st.query(j,cnt); //a.is / b.is
		}
	}
}
node merge(node &a, node &b){
	//merged ret
	node ret;
	ret.pre=a.pre;
	for(auto &i:b.pre)
		ret.pre.pb({amin(i.fst,a.all.fst),amax(i.snd,a.all.snd)});
	ret.suf=b.suf;
	for(auto &i:a.suf)
		ret.suf.pb({amin(i.fst,b.all.fst),amax(i.snd,b.all.snd)});
	ret.all.fst=amin(a.all.fst,b.all.fst);
	ret.all.snd=amax(a.all.snd,b.all.snd);
	//compress
	//ll sz=2*SZ(a.suf)+2*SZ(b.suf);
	//pair<ll,ll*> srt[sz];
	vector<pair<ll,ll*>>srt;
	//map<ll,ll>id;
	vector<pair<ii,ll>>u,v; //a.suf, b.pre
	for(auto i:a.suf)u.pb({{p[i.fst],p[i.snd]},i.fst<i.snd});
	for(auto i:b.pre)v.pb({{p[i.fst],p[i.snd]},i.fst<i.snd});
	for(auto &i:u){
		srt.pb({i.fst.fst,&i.fst.fst});
		srt.pb({i.fst.snd,&i.fst.snd});
	}
	for(auto &i:v){
		srt.pb({i.fst.fst,&i.fst.fst});
		srt.pb({i.fst.snd,&i.fst.snd});
	}
	/*cout<<"merge de:\n";
	a.prnt(); b.prnt();
	for(auto i:u)cout<<"{{"<<i.fst.fst<<","<<i.fst.snd<<"},"<<i.snd<<"} ";
	cout<<"\n";
	for(auto i:v)cout<<"{{"<<i.fst.fst<<","<<i.fst.snd<<"},"<<i.snd<<"} ";
	cout<<"\ncompress\n";*/
	sort(ALL(srt));
	ll cnt=-1,lst=-1;
	for(auto &i:srt){
		if(i.fst!=lst)cnt++,lst=i.fst;
		*i.snd=cnt;
	}
	cnt++;
	/*cout<<cnt<<"\n";
	for(auto i:u)cout<<"{{"<<i.fst.fst<<","<<i.fst.snd<<"},"<<i.snd<<"} ";
	cout<<"\n";
	for(auto i:v)cout<<"{{"<<i.fst.fst<<","<<i.fst.snd<<"},"<<i.snd<<"} ";
	cout<<"\ndone\n";*/
	//calc
	calc(u,v,cnt,1);
	calc(v,u,cnt,0);
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>p[i],p[i]--;
	vector<node>dnc;
	fore(i,0,n)dnc.pb(node(i));
	while(SZ(dnc)>1){
		/*cout<<"dnc ("<<SZ(dnc)<<"):\n";
		for(auto i:dnc)i.prnt();
		cout<<"\n";*/
		vector<node>tmp;
		for(ll i=0;i<SZ(dnc);i+=2){
			if(i==SZ(dnc)-1)tmp.pb(dnc[i]);
			else tmp.pb(merge(dnc[i],dnc[i+1]));
		}
		dnc=tmp;
	}
	/*cout<<"dnc ("<<SZ(dnc)<<"):\n";
	for(auto i:dnc)i.prnt();
	cout<<"\n";*/
	cout<<res<<"\n";
	return 0;
}
