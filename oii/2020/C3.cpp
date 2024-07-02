#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
// 100 points

//#pragma GCC optimize("Ofast") // may lead to precision errors

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}

struct node{
	ll h[4][4]; ll w;
	node():w(0){mset(h,0);}
};
/*string cv(node a){
	string s="["+to_string(a.w)+"|";
	for(auto v:a.h){
		s+="(";
		for(auto i:v)s+=to_string(i)+",";
		s.pop_back();
		s+="),";
	}
	s.pop_back();
	s+="]";
	return s;
}*/
node unit(ll v){
	node ret;
	ret.h[v][v]++;
	if(v==0)ret.h[3][3]++;
	ret.w=1;
	return ret;
}
node oper(node &a, node &b){
	if(a.w==-1)return b;
	if(b.w==-1)return a;
	node c;
	c.w=a.w+b.w;
	if(a.w==1&&b.w==1){
		fore(l,0,4)fore(m,0,4)fore(r,0,4){
			if((l&m)||(r&m))continue;
			c.h[l|m][r|m]+=a.h[l][l]*b.h[r][r];
		}
	}
	else {
		fore(m,0,4)fore(l,0,4)if(a.h[l][m])fore(r,0,4)if(b.h[m][r]){
			ll li=a.w==1?3:l;
			ll ri=b.w==1?3:r;
			c.h[li][ri]=add(c.h[li][ri],mul(a.h[l][m],b.h[m][r]));
		}
	}
//	cout<<"oper "<<cv(a)<<" "<<cv(b)<<": "<<cv(c)<<"\n";
	return c;
}

node NEUT;

struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(){
		fore(i,0,n)t[n+i]=unit(0);
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
int main(){FIN;
	NEUT.w=-1;//=vector<vector<ll>>(4,vector<ll>(4,1));
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	STree st(n);
	st.init();
	while(q--){
		ll ty,i,j; cin>>ty>>i>>j;
		if(ty==1){
			i--,j--;
			a[j]^=1<<i;
			st.upd(j,unit(a[j]));
		}
		else {
			i--;
//			cout<<"query "<<i<<","<<j<<":\n";
			auto rq=st.query(i,j);
			ll res=rq.h[3][3];
			cout<<res<<"\n";
		}
	}
	return 0;
}
