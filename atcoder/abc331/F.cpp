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
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

#define bint __int128
bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
/*struct FTree{
	vector<bint>ft; vector<bint>a; ll n;
	FTree(){}
	FTree(ll n):ft(n+10,0),a(n+10,0),n(n+5){}
	void upd(ll i0, bint v){
		v=(v-a[i0]+MOD)%MOD;
		a[i0]=v;
		for(ll i=i0+1;i<n;i+=i&-i)ft[i]=(ft[i]+v)%MOD;
	}
	bint get_sum(ll i0){
		bint res=0;
		for(ll i=i0;i>0;i-=i&-i)res=(res+ft[i])%MOD;
		return res;
	}
	ll query(ll a, ll b){
		return (get_sum(b)-get_sum(a)+MOD)%MOD;
	}
};
*/
typedef bint node;
node oper(node a, node b){return (a+b)%MOD;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	STree(){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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

struct Hash{
	vector<bint>pt,pi;
	STree st;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		pt.resize(SZ(s)),pi.resize(SZ(s));
		st=STree(SZ(s));
		pt[0]=1; pi[0]=1;
		fore(i,0,SZ(s)){
			if(i){
				pt[i]=pt[i-1]*P%MOD;
				pi[i]=pi[i-1]*PI%MOD;
			}
			st.upd(i,s[i]*pt[i]%MOD);
		}
	}
	void upd(ll i, char v){
		st.upd(i,v*pt[i]%MOD);
	}
	ll query(ll s, ll e){
		return st.query(s,e)*pi[s]%MOD;
	}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	Hash nor(s);
	reverse(ALL(s));
	Hash rev(s);
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll p; char v; cin>>p>>v; p--;
			nor.upd(p,v);
			rev.upd(n-1-p,v);
		}
		else {
			ll l,r; cin>>l>>r; l--,r--;
			if(nor.query(l,r+1)==rev.query(n-1-r,n-l))cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
