#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
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
vv doit(vv a, vv b){
	ll n=SZ(a),m=SZ(b);
	vector<vv> pos(n);
	fore(i,0,n)pos[a[i]].pb(i);
	vv wh(n,-1);
	fore(i,0,m)wh[b[i]]=i;
	vv dp(n);
	dp[0]=1;
	STree st(n),st2(n);
	auto acum=[&](ll l, ll r, STree &st){
		ll q=st.query(l+1,r);
		ll coef=fpow(2,q);
		dp[r]=add(dp[r],mul(coef,dp[l]));
		// cout<<"acum "<<l<<" "<<r<<": "<<q<<": "<<mul(coef,dp[l])<<"\n";
	};
	fore(v,0,n){
		ll p=wh[v];
		for(auto i:pos[v])st.upd(i,1);
		if(p!=-1){
			auto &vec=pos[v];
			ll w=p+1<m?b[p+1]:-1;
			vv prox=w==-1?vv(0):pos[w];
			fore(ind,0,SZ(vec)){
				ll i=vec[ind];
				if(ind+1<SZ(vec)){
					acum(i,vec[ind+1],st2);
				}
				auto ptr=upper_bound(ALL(prox),i);
				if(ptr!=prox.end())acum(i,*ptr,st);
				// cout<<i<<": "<<dp[i]<<"\n";
			}
			fore(x,(p==0?0:b[p-1]+1),v+1){
				for(auto i:pos[x])st2.upd(i,1);
			}
		}
	}
	vv ret(n);
	fore(i,0,n)if(wh[a[i]]==m-1)ret[i]=dp[i];
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv vals;
		fore(i,0,n)cin>>a[i],vals.pb(a[i]);
		sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
		for(auto &i:a)i=lower_bound(ALL(vals),i)-vals.begin();
		
		vv pre,suf;
		ll mx=-1;
		fore(i,0,n)if(a[i]>mx)mx=a[i],pre.pb(mx);
		mx=-1;
		for(ll i=n-1;i>=0;i--)if(a[i]>mx)mx=a[i],suf.pb(mx);
		
		auto dpl=doit(a,pre);
		// imp(dpl)
		
		reverse(ALL(a));
		auto dpr=doit(a,suf);
		reverse(ALL(dpr));
		reverse(ALL(a));
		
		// imp(dpr)
		
		ll res=0;
		ll suml=0;
		fore(i,0,n){
			ll cur=mul(dpr[i],add(suml,dpl[i]));
			res=add(res,cur);
			
			// if(dpr[i]){
			// 	cout<<suml<<" "<<dpr[i]<<": "<<suml*dpr[i]<<"\n";
			// }
			suml=mul(suml,2);
			suml=add(suml,dpl[i]);
			
		}
		cout<<res<<"\n";
	}
	return 0;
}
