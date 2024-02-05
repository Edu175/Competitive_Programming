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
const ll MOD=998244353;

typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		r=min(r,n);	
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

ll fn(ll n){
	return (n*(n+1)/2)%MOD;
}

ll tec(ll a, ll b){return (a+b-1)/b;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>p(n),q(k),aq(k);
		fore(i,0,n)cin>>p[i];//,ap[p[i]]=i;
		fore(i,0,k)cin>>q[i],aq[q[i]]=i;
		ll res=0,sum=0;
		for(ll i=k-1;i>=0;i--){
			if(i+19<k)sum++;
			res=(res+sum*fn(n))%MOD;
			//cout<<i<<" "<<sum<<": "<<sum*fn(n)<<"\n";
		}
		STree pot(k);
		for(ll i=k-1;i>=0;i--){
			ll c=pot.query(0,aq[i]);
			res=(res+c*n)%MOD;
			//cout<<i<<" "<<c<<": "<<c*n<<"\n";
			pot.upd(aq[i],1);
		}
		STree st(2*n);
		for(ll i=n-1;i>=0;i--){
			fore(pt,-18,19){
				ll e=0;
				if(pt>=0)e=p[i]*(1ll<<pt);
				else e=tec(p[i],1ll<<abs(pt));
				ll d=st.query(0,e);
				ll q=max(k-abs(pt),(ll)0);
				//cout<<i<<" "<<pt<<": "<<d<<" "<<q<<": "<<d*q<<"\n";
				res=(res+d*q)%MOD;
			}
			st.upd(p[i],1);
		}
		cout<<res<<"\n";
	}
	return 0;
}
