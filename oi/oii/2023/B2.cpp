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

struct STree{
	vector<ll>st,L,R; ll n,rt;
	STree(ll n):st(1,0),L(1),R(1),n(n),rt(0){}
	ll new_node(ll k){
		ll ks=SZ(st);
		st.pb(st[k]),L.pb(L[k]),R.pb(R[k]);
		//cout<<"new "<<k<<": "<<st[k]<<" "<<L[k]<<" "<<R[k]<<"\n";
		//cout<<ks<<": "<<st[ks]<<" "<<L[ks]<<" "<<R[ks]<<"\n";
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p){
		ll ks=new_node(k);
		/*if(s==18&&e==19){
			//cout<<"upd 18 "<<k<<" "<<st[k]<<"\n";
			cout<<ks<<" "<<st[ks]+1<<"\n";
		}*/
		if(s+1==e){st[ks]++;return ks;}
		ll m=(s+e)/2;
		ll x;
		if(p<m)x=upd(L[k],s,m,p),L[ks]=x;
		else x=upd(R[k],m,e,p),R[ks]=x;
		st[ks]=st[L[ks]]+st[R[ks]];
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		//if(s<=12&&e>12)cout<<"doce "<<k<<" "<<s<<","<<e<<": "<<st[k]<<"\n";
		if(e<=a||b<=s)return 0;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return query(L[k],s,m,a,b)+query(R[k],m,e,a,b);
	}
	ll upd(ll k, ll p){/*cout<<"update "<<rt<<"\n";*/return rt=upd(k,0,n,p);}
	ll upd(ll p){return upd(rt,p);}
	ll query(ll k, ll a, ll b){
		ll x=query(k,0,n,a,b);
		//cout<<"query "<<k<<" "<<a<<","<<b<<": "<<x<<"\n";
		return x;
	}
};
struct ran{
	ll l,r,m;
	ran(){}
	ran(ll l, ll r, ll m):l(l),r(r),m(m){}
};
const ll MAXV=2e9+5;
ll n;
vector<ii>ms={{0,-1}};
vector<ll>rtl={0},rtr={0};

ll cva(ll x){ // ]
	ii fi={x,n+5};
	ll k=upper_bound(ALL(ms),fi)-ms.begin()-1;
	//cout<<x<<"] "<<"="<<k<<"\n";
	return k;
}
ll cvb(ll x){// )
	ii fi={x,-1};
	ll k=lower_bound(ALL(ms),fi)-ms.begin()-1;
	//cout<<x<<") ="<<k<<"\n";
	return k;
}

int main(){FIN;
	cin>>n;
	ran a[n];
	vector<pair<ll,ii>>id;
	fore(i,0,n){
		cin>>a[i].l>>a[i].r;
		a[i].r*=2,a[i].l*=2;
		a[i].m=(a[i].l+a[i].r)/2;
		id.pb({a[i].l,{i,0}});
		id.pb({a[i].r,{i,1}});
		id.pb({a[i].m,{i,2}});
	}
	ll k=1;
	sort(ALL(id));
	fore(i,0,SZ(id)){
		if(i&&id[i].fst!=id[i-1].fst)k++;
		ll ty=id[i].snd.snd,idx=id[i].snd.fst;
		if(ty==0)a[idx].l=k;
		if(ty==1)a[idx].r=k;
		if(ty==2)a[idx].m=k;
	}
	k++;
	fore(i,0,n){
		ms.pb({a[i].m,i});
	}
	sort(ALL(ms));
	STree stl(MAXV),str(MAXV);
	for(auto i:ms){
		rtl.pb(stl.upd(a[i.snd].l));
		rtr.pb(str.upd(a[i.snd].r));
	}
	/*for(auto i:ms)cout<<i.fst<<","<<i.snd<<" ";
	cout<<endl;
	imp(rtl); imp(rtr);*/
	ll res=0;
	fore(i,0,n){
		//cout<<i<<": "<<a[i].l<<","<<a[i].r<<" "<<a[i].m<<endl;
		ll q0=str.query(rtr[cva(a[i].m)+1],a[i].m,MAXV);
		ll q1=str.query(rtr[cvb(a[i].l)+1],a[i].m,MAXV);
		ll q2=stl.query(rtl[cva(a[i].r)+1],0,a[i].m+1);
		ll q3=stl.query(rtl[cva(a[i].m)+1],0,a[i].m+1);
		res+=(q0-q1+q2-q3);
		/*cout<<q0<<"-"<<q1<<"\n";
		cout<<q2<<"-"<<q3<<"\n";
		cout<<q0-q1+q2-q3<<"\n\n";*/
	}
	//cout<<res<<"\n";
	res-=n;
	cout<<res/2<<"\n";
	return 0;
}
