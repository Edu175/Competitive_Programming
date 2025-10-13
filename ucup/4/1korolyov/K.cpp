#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto pera:v) cout<<pera<<" ";;cout<<endl;
#define imp2(v) for(auto [sandia,melon]:v) cout<<sandia<<","<<melon<<" ";;cout<<endl;
#define inp(v) for(auto &uva:v) cin>>uva;
#define inp2(v) for(auto &[fresa,mora]:v) cin>>fresa>>mora;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef __int128 xl;
typedef long double ld;

#define gc getchar_unlocked()
typedef ll tre;
static inline tre re(){ //fast input bestial!!
	tre x=0;
	char c=gc; 
    bool f=0;
    while(c<=' '||c=='\n')c=gc;
    if(c=='-') f=1,c=gc;
	while(c>' '&&c!='\n') { //while is a digit
        x=(x<<3)+(x<<1)+(c&15),c=gc; //x*10 + digit
    }
    return f?-x:x;
}
const ll INF=1e18;
typedef array<ll,4> mtx;
const mtx id=mtx({0,-INF,-INF,0});
mtx operator*(mtx &a, mtx &b){
    mtx r;
    r[0]=max(a[0]+b[0],a[1]+b[2]);
    r[1]=max(a[0]+b[1],a[1]+b[3]);
    r[2]=max(a[2]+b[0],a[3]+b[2]);
    r[3]=max(a[2]+b[1],a[3]+b[3]);
    return r;
}
ii operator*(mtx &a, ii &b){
    ii r;
    r.fst=max(b.fst+a[0],b.snd+a[1]);
    r.snd=max(b.fst+a[2],b.snd+a[3]);
    return r;
}
typedef ii tn; // node type
typedef mtx tl; // lazy type
#define NEUT ii({-INF,-INF})
#define CLEAR id // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a=v*a;
}
tn calc(tn a, tl v){ // calculate STree range, a=previous value
	a=v*a;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, ll d){
		if(e-s==1)st[k]={d,0};
		else {
			int m=(s+e)/2;
			init(2*k,s,m,d); init(2*k+1,m,e,d);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	
	ll find(ll k, ll s, ll e, ll x){ // lwb
		
	}
	ll find(ll x){
		ll s=0,e=n,k=1;
		while(1){
			push(k,s,e);
			if(e-s==1){
				return st[k].fst>=x?s:s+1;
			}
			ll m=(s+e)/2;
			push(2*k,s,m);
			push(2*k+1,m,e);

			if(st[2*k].fst>=x)k=2*k,e=m;
			k=2*k+1,s=m;
		}
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b).fst;}
	void init(ll d){init(1,0,n,d);}
};

int main(){
    JET
    ll n=re(),q=re(),d=re();
    STree ST(n+1);
    ST.init(d);
    ll a[n];
    fore(i,0,n) a[i]=re();
    ii qu[q];
    ll rta[q];
    vector<ii> ord[n];
    fore(i,0,q){qu[i].fst=re()-1, qu[i].snd=re()-1;
        ord[qu[i].snd].pb({qu[i].fst,i});
    }
    fore(i,0,n){
        // ll l=0, r=i;
        // while(l<=r){
        //     ll m=(l+r)/2;
        //     if(ST.query(m,m+1)>=a[i])r=m-1;
        //     else l=m+1; 
        // }
		ll l=ST.find(a[i]);
        // cout<<l<<"actualizo\n";
        ST.upd(l,i+1,tl({-a[i],a[i]-1,-INF,0}));
        // fore(j,0,i+1) cout<<ST.query(j,j+1)<<" ";;cout<<"\n";
        for(auto [lj,j]: ord[i]){
            rta[j]=ST.query(lj,lj+1);
        }
    }
    fore(i,0,q){
        cout<<rta[i]<<"\n";
    }
    return 0;
}