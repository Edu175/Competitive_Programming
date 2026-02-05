#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5e5+5;
ll D[MAXN],F[MAXN],jump[MAXN]; // Depth, Father
ll V[MAXN],val[MAXN]; // V = Father value, val = jump value
#define oper max
void makeLeaf(ll x){
	if(D[x]!=-1)return; // ya taba
	// F[x]=p;
	// V[x]=_val;
	ll p=F[x];
	makeLeaf(p);
	D[x]=D[p]+1;
	if(D[p]-D[jump[p]]==D[jump[p]]-D[jump[jump[p]]]){
		jump[x]=jump[jump[p]];
		val[x]=oper(V[x],oper(val[p],val[jump[p]]));
	}
	else jump[x]=p,val[x]=V[x];
}
ll go(ll x, ll t){
	while(V[x]<=t){ // while puedo subir
		if(val[x]<=t)x=jump[x]; // aprovecho para saltar si puedo
		else x=F[x];
	}
	return x;
}

struct UF{ // persistent
	ll n;
	vector<vector<ii>> sz; // sz[x][i] = t,z
	UF(ll n):n(n),sz(n,vector<ii>(1,{-1,1})){}
	void init(vector<vector<ii>> &me){ // O(n), me[t] has merges in time t: x <- y
		D[n]=0; F[n]=-1; jump[n]=n;
		fore(i,0,n)F[i]=n,V[i]=n;
		fore(t,0,n)for(auto& [x,y]:me[t]){
			F[y]=x; V[y]=t;
			sz[x].pb({t,sz[x].back().fst+sz[y].back().fst});
		}
		fore(x,0,n)makeLeaf(x);
		
	}
};
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int &x, int &y){ // careful! modifies x,y
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){
    JET
    
    return 0;
}


