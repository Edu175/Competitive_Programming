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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<array<ll,3>> a(n);
		vv _a(n),_b(n);
		fore(i,0,n)cin>>a[i][0];
		fore(i,0,n)cin>>_a[i],_a[i]--;
		fore(i,0,n)cin>>_b[i],_b[i]--;
		auto inv=[&](vector<ll> &a){
			ll n=SZ(a);
			vv pos(n);
			fore(i,0,n)pos[a[i]]=i;
			a=pos;
		};
		inv(_a);
		inv(_b);
		fore(i,0,n)a[i][1]=_a[i],a[i][2]=_b[i];
		sort(ALL(a),[&](array<ll,3> a, array<ll,3> b){
			return a[2]<b[2];
		});
		STree st(n);
		ll res=0;
		priority_queue<ii>pq;
		// fore(i,0,n){
		// 	imp(a[i])
		// }
		// cout<<"\n";
		fore(i,0,n){
			auto [val,cA,cB]=a[i];
			ll goA=val,goB=-st.query(cA+1,st.n);
			if(goA>=goB){
				// cout<<"A\n";
				res+=goA;
				pq.push({cA,val});
				st.upd(cA,val);
			}
			else{
				// cout<<"B\n";
				res+=goB;
				while(SZ(pq)&&pq.top().fst>cA){
					auto [p,asd]=pq.top(); pq.pop();
					st.upd(p,0);
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
