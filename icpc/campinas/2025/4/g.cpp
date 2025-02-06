#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef ll tn;
typedef ll tl;
#define NEUT 10000000
#define CLEAR 0
const int maxn=1e5+5;
vv a(maxn,0),b(maxn,0),o(maxn,0),d(maxn,0),nueve(maxn,0);

tn oper(tn a, tn b){
	return min(a,b);
}

void acum(tl &a, tl v){
	a+=v;
}

tn calc(ll s, ll e, tn a, tl v){
	assert(s|e|1);
	a+=v;
	return a;
}

struct STree{
	vector<tn> st; vector<tl> lazy; ll n;
	STree(ll n) : st(4*n+5,NEUT), lazy(4*n+5,CLEAR),n(n){}
	void init(ll k, ll s, ll e, vector<tn> &a){
		if(e-s==1)st[k]=a[s];
		else{
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR) return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){
		push(k,s,e);
		if(e<=a||b<=s) return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v), upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a || b<=s) return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b) return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);};
};


int main(){
	JET
	ll n,q; cin>>n>>q;
	string s,s1; cin>>s>>s1;
	reverse(ALL(s));
	reverse(ALL(s1));
	
	fore(i,0,n-1){
		char c=s[i];
		a[i]=c-'0';
		// cout<<"wtf "<<c<<"\n";
	}
	fore(i,0,n-1){
		char c=s1[i];
		b[i]=c-'0';
	}
	fore(i,0,n){
		int aux=a[i]+b[i]+o[i];
		if(aux==9) nueve[i]=1;
		if(aux==10) d[i]=1;
		if(aux>=10)	o[i+1]=1;
	}
	STree over(n),nue(n),diez(n);
	over.init(o);
	nue.init(nueve);
	diez.init(d);
	fore(i,0,q){
		char c; cin>>c;
		// cout<<"deb  "<<i+1<<" "<<c<<endl;
		if(c=='S'){
			int x; cin>>x;
			x--;
			// cout<<"debug "<<a[x]<<" "<<b[x]<<" "<<over.query(x,x+1)<<endl;
			cout<<(a[x]+b[x]+over.query(x,x+1))%10<<"\n";
		}
		else{
			int x,y; cin>>x>>y;
			x--;
			int prev=a[x]+b[x]+over.query(x,x+1);
			(c=='W')? a[x]=y:b[x]=y;
			int newe =a[x]+b[x]+over.query(x,x+1);
			if(prev==newe) continue;
			if(prev==9) nue.upd(x,x+1,-1);
			if(prev==10) diez.upd(x,x+1,-1);
			if(newe==9) nue.upd(x,x+1,1);
			if(newe==10) diez.upd(x,x+1,1);
			if(prev<10 && newe>=10){
				ll l=x+1,r=n+1;
				while(l<r){
					ll m=(l+r)/2;
					// cout<<"debbb "<<m<<"\n";
					if(nue.query(l,m+1)==0) r=m;
					else l=m+1;
				}
				over.upd(x+1,r+1,1);
				nue.upd(x+1,r,-1);
				diez.upd(x+1,r,1);
				ll aux=a[r]+b[r]+over.query(r,r+1);
				if(aux==9) nue.upd(r,r+1,1);
				if(aux==11) diez.upd(r,r+1,-1);
			}
			if(prev>=10 && newe<10){
				ll l=x+1,r=n+1;
				while(l<r){
					ll m=(l+r)/2;
					if(diez.query(l,m+1)==0) r=m;
					else l=m+1;
				}
				over.upd(x+1,r+1,-1);
				nue.upd(x+1,r,1);
				diez.upd(x+1,r,-1);
				ll aux=a[r]+b[r]+over.query(r,r+1);
				if(aux==10) diez.upd(r,r+1,1);
				if(aux==8) nue.upd(r,r+1,-1);
			}
		}
	}
	return 0;
}
