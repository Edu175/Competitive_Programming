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
const ll MAXN=2e5+5;

struct node{
	ll sum=0,mn=0;
	node(ll s):sum(s){}
	// void prnt(){
	// 	cout<<"["<<mn<<"|";
	// 	fore(i,0,2)fore(j,0,2)cout<<c[i][j]<<",";
	// 	cout<<"] ";
	// }
};
node oper(node a, node b){
	node c=a;
	c.mn=min(a.mn,a.sum+b.mn);
	c.sum+=b.sum;
	return c;
}
node NEUT(0);
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
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

ll cv(ll d, ll v, ll p){
	p&=1;
	if(d==0){
		if(v==2&&p==0)return 1;
		if(v==0&&p==1)return 1;
		if(v==0&&p==0)return -1;
		return 0;
	}
	if(d==1){
		if(v==2&&p==1)return 1;
		if(v==0&&p==0)return 1;
		if(v==0&&p==1)return -1;
		return 0;
	}
	if(d==2){
		if(v==2&&p==0)return 1;
		if(v==1&&p==1)return 1;
		if(v==1&&p==0)return -1;
		return 0;
	}
	if(d==3){
		if(v==2&&p==1)return 1;
		if(v==1&&p==0)return 1;
		if(v==1&&p==1)return -1;
		return 0;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		vector<vv> des(4,vv(n));
		fore(d,0,4)fore(i,0,n){
			des[d][i]=cv(d,s[i]-'0',i);
		}
		fore(d,0,4){
			imp(des[d]);
		}
		vector<STree> par(4,STree(n/2)),odd(4,STree((n+1)/2-1));
		fore(h,0,4)fore(i,0,n/2){
			par[h].upd(i,des[h][2*i]+des[h][2*i+1]);
			if(2*i+2<n)odd[h].upd(i,des[h][2*i+1]+des[h][2*i+2]);
		}
		vv dp(n+5);
		for(ll i=n-1;i>=0;i--){
			ll &res=dp[i];
			res=dp[i+1]+1;
			ll l=i/2,r=n/2,p=i&1;
			if(2*r+p>n)r--;
			auto bl=[&](ll i){
				if(!p)return i/2;
				return (i+1)/2-1;
			};
			auto good=[&](ll l, ll r){
				ll flag=1;
				cout<<"good "<<l<<","<<r<<":\n";
				fore(d,0,4){
					ll mn=(p?odd[d]:par[d])
					.query(bl(l),bl(r)).mn;
					flag&=mn>=0;
					cout<<d<<": "<<mn<<"\n";
				}
				cout<<"\n";
				return flag;
			};
			while(l<=r){
				ll m=(l+r)/2;
				ll e=(2*m+p);
				// cout<<l<<","<<r<<": "<<e<<"\n";
				if(good(i,e))l=m+1;
				else r=m-1;
			}
			ll e=2*r+p;
			cout<<"\n";
			cout<<i<<": "<<e<<"\n";
			// (p?odd:par).query(bl(i),bl(e)).prnt(); cout<<"\n";
			res=min(res,dp[e]);
			fore(j,i,n)if(j%2==p){
				cout<<j<<": "<<good(i,j)<<"\n";
			}
			// 	cout<<j<<": ";(p?odd:par).query(bl(i),bl(j)).prnt();cout<<"\n";
			// }
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
