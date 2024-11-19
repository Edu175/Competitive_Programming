#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" ";cout<<endl;}
#define impr(v) {cout<<#v<<": ";for(auto [x,y]:v)cout<<x<<","<<y<<" ";cout<<endl;}
#define impri(v) {cout<<#v<<": ";for(auto [x,y]:v)cout<<x.fst<<","<<x.snd<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5,B=550; // 550

vector<ii> h;
struct SQRTree{ // suffix queries only
	#define NEUT N
	ll oper(ll i, ll j){
		if(i==NEUT)return j;
		if(j==NEUT)return i;
		if(h[i].snd<h[j].snd)return i;
		return j;
	}
	#define BLOCKSZ sqrt(N)+.5
	ll N,B,q,n; vv a,Bsuf; vector<vv> Csuf; // Bloque, Casilla
	SQRTree(ll N):N(N),B(BLOCKSZ),q((N+B-1)/B),n(q*B),
		a(n+5,NEUT),Bsuf(q+5,NEUT),Csuf(q+3,vv(B+3,NEUT)){}
	void upd(ll p, ll v){ // O(sqrt(n))
		// cout<<"upd "<<p<<" "<<v<<endl;
		ll b=p/B; a[p]=v;
		for(ll i=p%B;i>=0;i--)Csuf[b][i]=oper(a[b*B+i],Csuf[b][i+1]);
		for(ll i=b;i>=0;i--)Bsuf[i]=oper(Csuf[i][0],Bsuf[i+1]);
	}
	ll query(ll p){ // [p,n) , // O(1)
		ll b=p/B;
		return oper(Csuf[b][p%B],Bsuf[b+1]);
	}
};
ll get_idx(ii x){return lower_bound(ALL(h),x)-h.begin();}
int main(){JET
	ll q; cin>>q;
	vector<ii>upds;
	vector<pair<ii,ll>>ran;
	fore(_,0,q){
		ll l,r=-2; cin>>l;
		if(l>=0)cin>>r;
		l=abs(l); r++;
		if(r!=-1){
			h.pb({l,r});
			upds.pb({SZ(ran),1});
			ran.pb({{l,r},SZ(ran)});
		}
		else upds.pb({l-1,0});
	}
	ll n=SZ(h);
	sort(ALL(ran));
	vv pos(n),at(n+1,n); // at already to pos
	fore(i,0,n){
		ll x=ran[i].snd;
		pos[x]=i;
		at[x]=lower_bound(ALL(ran),pair<ii,ll>({h[x].snd,-1},-1))-ran.begin();
	}
	// impr(h)
	// impri(ran)
	// imp(pos)
	// imp(at)
	// impr(upds)
	// return 0;
	SQRTree dat(n); // pos !!
	auto nxt=[&](ll i){return dat.query(at[i]);};
	auto add=[&](ll i){dat.upd(pos[i],i);};
	auto rem=[&](ll i){dat.upd(pos[i],dat.NEUT);};
	vv dis; vv root;
	auto dis_root=[&](vv is){ // is blocked
		// imp(is);
		dis=vv(n+1);
		root=vv(n+1,n);
		for(ll i=n-1;i>=0;i--){
			ll x=ran[i].snd;
			// if(x==-1)continue;
			ll pa=nxt(x);
			root[x]=is[x]||is[pa]?x:root[pa];
			dis[x]=dis[pa]+1;
		}
		return dis;
	};
	fore(idx,0,q){
		// fore(i,0,n)cout<<nxt(i)<<" ";;cout<<endl;
		if(idx%B==0){
			vv is(n+1);
			ll e=min(q,idx+B);
			fore(i,idx,e){
				ll x=upds[i].fst;
				if(upds[i].snd)add(x);
				is[x]=1;
			}
			dis_root(is);
			// fore(i,0,n+1)cout<<dat.a[i]<<" ";;cout<<"\n";
			fore(i,idx,e)if(upds[i].snd)rem(upds[i].fst);
		}
		ll x=upds[idx].fst;
		if(upds[idx].snd)add(x);
		else rem(x);
		ll s=dat.query(0),res=0;
		
		// cout<<idx<<":\n";
		// fore(i,0,n+1)cout<<dat.a[i]<<" ";;cout<<"\n";
		// fore(i,0,n)cout<<nxt(i)<<" ";;cout<<endl;
		// cout<<"| "<<s<<endl;
		// imp(root)
		// imp(dis)
		while(s<n){
			ll si=root[s];
			res+=dis[s]-dis[si];
			// cout<<s<<" -> "<<si<<" ";
			if(si<n)res++,si=nxt(si);
			// cout<<si<<endl;
			s=si;
		}
		cout<<res<<"\n";
	}
	
    return 0;
}