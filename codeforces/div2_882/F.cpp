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
const ll INF=1e12;

ll oper(ll a, ll b){return a|b;}
/*struct ST{
	ll n,K; vector<vector<ll>>st;
	ST(ll n):n(n),K(64-__builtin_clzll(n)),st(K,vector<ll>(1<<K)){}
	void init(vector<ll>& a){
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n-(1<<k)+1)
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
	}
	ll query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
	}
};*/
const ll K=19;//K such that 2^k>n
ll st[K][1<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
ll st_query(ll s, ll e){
	ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
ll n;
bool is(ll l, ll r){
	if(r>=n)r-=n;
	if(r==0&&l!=0)return 0;
	return 1;
}
ll idx(ll l, ll r){ //0-based [,]
	//if(r==0&&l==0)cout<<"!!!!!!!!!!111111111111\n";
	ll sz=r-l+1;
	if(r>=n)r-=n;
	if(r==0&&l==0)return 0;
	//cout<<l<<","<<r<<": ";
	l--,r--;
	ll res=(sz-1)*(n-1)+r;
	res++;
	//cout<<res<<"\n";
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>n>>q;
		//cout<<"scan"<<endl;
		vector<ll>a(2*n);
		fore(i,0,n)cin>>a[i],a[i+n]=a[i];
		//cout<<"st"<<endl;
		//ST st(2*n);
		st_init(a);
		vector<ii>b;
		//cout<<"b"<<endl;
		fore(i,0,n){
			ll x=i;
			while(x<2*n){
				assert(x-i+1<=n);
				if(is(i,x))b.pb({st_query(i,x+1),idx(i,x)});
				ll l=x,r=2*n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(st_query(i,x+1)==st_query(i,m+1))l=m+1;
					else r=m-1;
				}
				x=l;
			}
		}
		//for(auto i:b)cout<<i.fst<<","<<i.snd<<" ";
		//cout<<"\n";
		//cout<<"minp"<<endl;
		sort(ALL(b));
		vector<ll>minp(SZ(b)+1);
		minp[SZ(b)]=INF;
		for(ll i=SZ(b)-1;i>=0;i--)minp[i]=min(b[i].snd,minp[i+1]);
		//cout<<"qs"<<endl;
		while(q--){
			ll x; cin>>x;
			ii fi={x,INF};
			ll w=lower_bound(ALL(b),fi)-b.begin();
			ll res=minp[w];
			if(res==INF)cout<<"-1\n";
			else cout<<res+1<<"\n";
		}
	}
	return 0;
}
