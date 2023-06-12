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
const ll MAXN=2e5+5,INF=MAXN;
#define NEUT INF
#define CLEAR 0 // cleared lazy node
ll oper(ll a, ll b){return min(a,b);}
void acum(ll &a, ll v){a+=v;} // accumulate lazy node
ll calc(ll s, ll e, ll a, ll v){return a+v;} // calculate STree range, a=previous value

struct STree{// min query, sum update
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	/*void init(int k, int s, int e, int *a){
		lazy[k]=CLEAR;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}*/
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};
ll n;
STree st(MAXN),st2(MAXN);
ll findl(){
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st.query(0,m+1)<0)r=m-1;
		else l=m+1;
	}
	return l;
}
ll findr(){
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st.query(m,n)<0)l=m+1;
		else r=m-1;
	}
	return r;
}
#define NEUT2 0
ll oper2(ll a, ll b){return max(a,b);}
struct STree2{// min query, sum update
	vector<ll>st,lazy; ll n;
	STree2(ll n):st(4*n+5,NEUT2),lazy(4*n+5,CLEAR),n(n){}
	/*void init(int k, int s, int e, int *a){
		lazy[k]=CLEAR;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}*/
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper2(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT2;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper2(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};
ll findl2(){
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st.query(0,m+1)>0)r=m-1;
		else l=m+1;
	}
	return l;
}
ll findr2(){
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(st.query(m,n)>0)l=m+1;
		else r=m-1;
	}
	return r;
}
int main(){FIN;
	ll q; cin>>n>>q;
	string s; cin>>s;
	if(n&1){
		while(q--){
			ll k; cin>>k;
			cout<<"NO\n";
		}
		return 0;
	}
	ll c=0;
	fore(i,0,n){
		if(s[i]=='(')c++;
		else c--;
		st.upd(i,i+1,-NEUT+c);
		st2.upd(i,i+1,c);
	}
	set<ll>p2,m2;
	fore(i,0,n-1){
		if(s[i]==s[i+1]){
			if(s[i]=='(')p2.insert(i);
			else m2.insert(i);
		}
	}
	while(q--){
		ll k; cin>>k; k--;
		if(k&&s[k]==s[k-1]){
			if(s[k]=='(')p2.erase(k-1);
			else m2.erase(k-1);
		}
		if(k<n-1&&s[k]==s[k+1]){
			if(s[k]=='(')p2.erase(k);
			else m2.erase(k);
		}
		ll u=0;
		if(s[k]=='(')u=-2,s[k]=')';
		else u=2,s[k]='(';
		st.upd(k,n,u);
		ll l=findl(),r=findr();
		ll l2=findl2(),r2=findr2();
		ll x=-st.query(0,n);
		ll bc=st.query(n-1,n);
		x+=x%2;
		ll flag=0;
		x=max((ll)0,x);
		if(x>0){
			if(!SZ(p2)||*p2.begin()>=l)flag=0;
		}
		if(bc+x>0){
			if(!SZ(m2))flag=0;
			else{
				auto ult=m2.end(); ult--;
				if(*ult<=r2)flag=0;
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
