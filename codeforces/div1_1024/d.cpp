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
const ll INF=2e6;
typedef ll node;
// node oper(node a, node b){return a+b;}
#define oper min
#define NEUT INF
struct STree{
	int n; vector<node>t;
	STree(int N):n(2<<__lg(N)),t(2*n+5,NEUT){}
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
	int find(int k, int s, int e, int a, int b, int x){
		// ejemplo: primera pos en la cual el bit j esta apagado 
		if(e<=a||b<=s) return b; // b es que no lo encontre
		// push(k,s,e); // para lazy
		int m = (s+e)/2;
		bool bad=(t[k]>=x); // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return b;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,x);
		if(res==b)res=find(2*k+1,m,e,a,b,x);
		return res; // cuando lo encuentra devuelve algo en [a,b)
	}
	int find(int a, int b, int x){return find(1,0,n,a,b,x);}
};
vv pm(vv a, bool menor=0){
	ll n=SZ(a);
	if(menor){
		for(auto &i:a)i=-i;
	}
	vv r(n);
	for(ll i=n-1;i>=0;i--)
		for(r[i]=i+1;r[i]!=n&&a[i]>=a[r[i]];r[i]=r[r[i]]);
	return r;
}

vv getUlt(vv a, ll dbg=0){
	ll n=SZ(a);
	vv may(pm(a));//,men(pm(a,1));
	vv ans(n);
	// if(dbg){
	// 	cout<<"getUlt\n";
	// 	imp(a)
	// 	imp(may)
	// 	cout<<endl;
	// 	// imp(men)
	// }
	vv p(n); fore(i,0,n)p[a[i]]=i;
	vv to(n);
	STree st(n);
	for(ll x=n-1;x>=0;x--){
		ll i=p[x];
		ll r=may[i];
		to[i]=n;
		if(r<n){
			to[i]=st.find(i,n,a[r]);
		}
		st.upd(i,a[i]);
	}
	
	for(ll i=n-1;i>=0;i--){
		ll r=may[i];
		// ll bad=n;
		// if(r<n){
		// 	bad=men[r];
		// 	if(bad<n&&a[i]>=a[bad])bad=n;
		// }
		// ans[i]=bad;
		ans[i]=to[i];
		if(r<n)ans[i]=min(ans[i],ans[r]);
		// if(dbg){
		// 	cout<<i<<": "<<r<<" "<<to[i]<<": "<<ans[i]<<"\n";
		// }

		// ans[i]=min(ans[r],bad);
	}
	return ans;
}
vv getUlt(vv a, ll rev, ll neg, ll dbg=0){
	ll n=SZ(a);
	if(rev)reverse(ALL(a));
	if(neg){
		for(auto &i:a)i=n-1-i;
	}
	auto ans=getUlt(a,dbg);
	if(rev){
		reverse(ALL(ans));
		for(auto &i:ans)i=n-1-i;
	}
	return ans;
}

ll num(ll l, ll r){
	ll n=r-l;
	return (n*(n+1))/2;
}

ll solve(vector<ii> a){
	for(auto& [l,r]:a)r=-r,l++; // [,)
	sort(ALL(a));
	ll R=-1;
	ll res=0;
	// cout<<"solve\n";
	for(auto& [l,r]:a){
		r=-r;
		if(r<=R)continue;
		// cout<<l<<","<<r<<"\n";
		res+=num(l,r);
		// cout<<res<<"\n";
		if(R>l)res-=num(l,R);
		
		R=r;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vv ru=getUlt(a,0,0);
		vv rd=getUlt(a,0,1);
		vv ld=getUlt(a,1,1);
		vv lu=getUlt(a,1,0);
		
		vv l(n),r(n);
		vector<ii>ps;
		fore(i,0,n){
			l[i]=max(ld[i],lu[i]);
			r[i]=min(rd[i],ru[i]);
			// cout<<i<<": "<<lu[i]<<","<<ld[i]<<" "<<ru[i]<<","<<rd[i]<<"\n";
			assert(l[i]<i&&i<r[i]);
			// cout<<i<<": "<<l[i]<<" "<<r[i]<<"\n";
			ps.pb({l[i],r[i]});
		}
		ll res=solve(ps);
		
		// fore(i,0,n){ // overcounting
		// 	ll L=l[i],R=r[i];
		// 	ll resi=R-L-1;
		// 	res+=resi;
		// }
		cout<<res<<"\n";
	}
	return 0;
}
