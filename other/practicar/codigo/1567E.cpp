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
typedef long long ll;
typedef pair<ll,ll> ii;

struct node{
	ll q0=0,q1=0,mid=0,z=0;
	node(ll v):q0(1),q1(!v),mid(0),z(v){}
	node(){}
	node(ll q0, ll q1, ll mid, ll z):q0(q0),q1(q1),mid(mid),z(z){}
};
ll to2(ll n){return n*(n+1)/2;}
node NEUT=node(-1);
node oper(node a, node b){
	if(b.z==-1)return a; // NEUT
	if(a.z==-1)return b; // NEUT
	node res;
	if(!a.z&&!b.z)return node(a.q0+b.q0,a.q1+b.q1,a.mid,a.z);
	if(!a.z){
		res=b;
		res.q0+=a.q1;
		return res;
	}
	if(!b.z){
		res=a;
		res.q1+=b.q0;
		return res;
	}
	res.q0=a.q0;
	res.q1=b.q1;
	res.mid=a.mid+b.mid+to2(a.q1+b.q0);
	res.z=a.z|b.z;
	return res;
}
struct STree{
	vector<node>st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, ll *a){
		if(s+1==e){st[k]=node(a[s]);return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, node v){
		if(s+1==e){st[k]=node(v);return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int p, node v){upd(1,0,n,p,v);}
	node query(int a, int b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll b[n]={};
	fore(i,0,n-1)b[i]=a[i]>a[i+1];
	STree st(n);
	st.init(b);
	//fore(i,0,n)st.upd(i,b[i]);
	while(q--){
		ll ty; cin>>ty; ty--;
		//imp(b);
		if(!ty){
			ll p,v; cin>>p>>v; p--;
			a[p]=v;
			if(p)st.upd(p-1,a[p-1]>a[p]);
			if(p<n-1)st.upd(p,a[p]>a[p+1]);
		}
		else {
			ll l,r; cin>>l>>r; l--;
			node res=st.query(l,r);
			//cout<<res.q0<<" "<<res.mid<<" "<<res.q1<<"\n";
			ll ans=0;
			if(!res.z)ans=to2(res.q1);
			else ans=to2(res.q0)+res.mid+to2(res.q1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
