#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef __int128 ll;
typedef pair<ll,ll> ii;

ll oper(ll a, ll b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=a[i];
		for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(int p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
	// metodo de la papa
	ll query(ll p){return query(0,p+1);}
	void upd(ll l, ll r, ll x){upd(l,x),upd(r,-x);}
};
struct qu{
	ll l,r,x;
	qu(){}
	qu(ll l, ll r, ll x):l(l),r(r),x(x){}
	//void prnt(){cout<<"["<<l<<","<<r<<"]";}
};
int main(){FIN;
	int n,m; cin>>n>>m;
	int a[m];
	vector<ll>p[n];
	fore(i,0,m)cin>>a[i],a[i]--,p[a[i]].pb(i);
	int k[n];
	fore(i,0,n)cin>>k[i];
	int q; cin>>q;
	qu qs[q];
	fore(i,0,q){
		int l,r,x; cin>>l>>r>>x; l--; //can be r <= l
		qs[i]=qu(l,r,x);
	}
	vector<qu>bs(n,qu(0,q-1,0)); // []
	//fore(i,0,n)cout<<i<<": ",bs[i].prnt(), cout<<"\n";
	while(1){
		STree st(m+1);
		vector<ll>ms[q];
		fore(i,0,n)if(bs[i].l<=bs[i].r)ms[(bs[i].l+bs[i].r)/2].pb(i);
		/*fore(i,0,q){
			cout<<i<<": "; imp(ms[i]);
		}*/
		ll br=1;
		fore(i,0,q){
			//upd
			//cout<<"q "<<i<<":\n";
			//cout<<"["<<qs[i].l<<","<<qs[i].r<<") +"<<qs[i].x<<"\n";
			if(qs[i].l>=qs[i].r){
				st.upd(0,qs[i].r,qs[i].x);
				st.upd(qs[i].l,m,qs[i].x);
				//cout<<"rev\n";
			}
			else st.upd(qs[i].l,qs[i].r,qs[i].x);
			/*fore(i,0,m+1)cout<<st.query(i,i+1)<<" ";
			cout<<"\n";
			fore(i,0,m+1)cout<<st.query(i)<<" ";
			cout<<"\n";*/
			if(SZ(ms[i]))br=0;
			for(auto j:ms[i]){ // nation j
				ll sum=0;
				for(auto h:p[j])sum+=st.query(h);
				//cout<<"nation "<<j<<" ";
				//bs[j].prnt();
				//cout<<": "<<sum<<" "<<k[j]<<": ";
				if(sum>=k[j])bs[j].r=i-1;
				else bs[j].l=i+1;
				//bs[j].prnt();
				//cout<<"\n";
			}
		}
		//fore(i,0,n)cout<<i<<": ",bs[i].prnt(),cout<<"\n";
		//cout<<"\n";
		if(br)break;
	}
	fore(i,0,n){
		int ans=bs[i].l;
		if(ans==q)cout<<"NIE\n";
		else cout<<ans+1<<"\n";
	}
	return 0;
}
