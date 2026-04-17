#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=6e4+5;

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,NEUT),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){
	ifstream cin;cin.open("autodromo.in", ios::in);
	ofstream cout; cout.open("autodromo.out", ios::out);
	vector<ll> sta[2][MAXN],fin[2][MAXN]; //vericales 1
	vector<ii>ran[2][MAXN]; // horizontales 0
	fore(i,0,2){ // [ , )
		ll n; cin>>n;
		ii a; cin>>a.fst>>a.snd;
		ii s=a;
		fore(j,0,n){
			ii b;
			if(j==n-1)b=s;
			else cin>>b.fst>>b.snd;
			ll d=0,x=b.snd,l=a.fst,r=b.fst;
			if(a.fst==b.fst)d=1,x=b.fst,l=a.snd,r=b.snd;
			if(l>r)swap(l,r);
			l++;
			if(d)sta[i][l].pb(x),fin[i][r].pb(x);
			else ran[i][x].pb({l,r});
			a=b;
		}
	}
	ll res=0;
	fore(i,0,2){
		STree h(MAXN);
		fore(x,0,MAXN){
			for(auto j:sta[i][x])h.upd(j,1);//might change to +=
			for(auto j:fin[i][x])h.upd(j,0);//might change to -=
			for(auto lr:ran[i^1][x])res+=h.query(lr.fst,lr.snd);
		}
	}
	cout<<res<<"\n";
	return 0;
}
