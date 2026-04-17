#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll mod=1e9+7;
ll addm(ll a, ll b){
	a+=b; return a<mod?a:a-mod;
}
ll subm(ll a, ll b){
	a-=b; return a<0?a+mod:a;
}
ll mulm(ll a, ll b){
	return a*b%mod;
}
typedef ii tn;
typedef ll tl;
tn oper(tn a, tn b){
	return
	{addm(a.fst,b.fst),addm(addm(a.snd,b.snd),mulm(a.fst,b.fst))};
}
void acum(tl &a, tl v){a+=v;}
tn calc(int s, int e, tn a, tl v){
	return 
	{addm(a.fst,mulm(e-s,v)),addm(a.snd,mulm(2*v,a.snd))};
}
const tn NEUT={0,0}; 
const tl CLEAR=0;
struct STree{
	vector<tn> st; vector<tl> lazy; int n;
	STree(int n): st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n) {}
	void init(int k ,int s, int e, vector<ll> &a){
		if(e-s==1)st[k]={a[s],0};
		else{
			int m=(s+e)/2;
			init(2*k,s,m,a);init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR) return ;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){
		if(e<=a||b<=s) return ;
		push(k,s,e);
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return ;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s) return ;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){
		auto [s,p]=query(1,0,n,a,b);
		return subm(mulm(s,s),mulm(2,p));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
};

vector<ii> quer_mo(pair<ii,ii>){
	
}

vector<ll> mo(vector<pair<ii,ii>>){
	
}

int main(){
	JET 
	
	return 0;
}