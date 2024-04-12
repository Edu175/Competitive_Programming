#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define forr(i,a,b) for(ll i=b-1,ggdem=a;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
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

ll contar(vector<ll>a){
	ll n=SZ(a);
	ll c=0;
	STree inv(n);
	forr(i,0,n){
		c+=inv.query(0,a[i]);
		inv.upd(a[i],1);
	}
	return c;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll K=k;
		vector<ll>a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		STree no(n);
		ll c=contar(a);
		if(k<c||k>n*(n-1)-c||k%2!=c%2){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		k=(k-c)/2;
		/*if(k==0){
			fore(i,0,n)cout<<i+1<<" ";
			cout<<"\n";
			continue;
		}*/
		ll pos=-1;
		forr(i,0,n){
			ll x=no.query(p[i],n);
			if(k<x){pos=i;break;}
			k-=x;
			no.upd(p[i],1);
		}
		if(pos==-1){
			assert(k==0);
			fore(i,0,n)cout<<n-i<<" ";;cout<<"\n";
			continue;
		}
		vector<ll>b;
		fore(i,pos+1,n)if(p[i]>p[pos])b.pb(i-pos-1);
		ll g=n-1-pos;
		if(k)g=b[SZ(b)-k];
		vector<ll>res(n);
		res[pos]=g;
		ll cnt=0;
		//imp(b);
		//cout<<k<<" = "<<g<<"\n";
		fore(i,pos+1,n){
			if(cnt==g)cnt++;
			res[i]=cnt++;
		}
		forr(i,0,pos){
			if(cnt==g)cnt++;
			res[i]=cnt++;
		}
		//imp(res);
		//DEBUG
		/*ll w=0;
		fore(i,0,n)fore(j,i+1,n){
			if(p[i]<p[j]&&res[i]<res[j])w++,cout<<i<<","<<j<<"\n";
		}
		cout<<w<<": "<<c<<"+ 2*"<<w<<" = "<<c+2*w<<" == "<<K<<" ?\n";*/
		vector<ll>qp(n),q(n);
		fore(i,0,n)q[i]=n-res[i]-1;
		fore(i,0,n)qp[i]=q[a[i]];
		//cout<<contar(q)<<'+'<<contar(qp)<<" = "<<contar(q)+contar(qp)<<" == "<<K<<" ?\n";
		fore(i,0,n)cout<<n-res[i]<<" ";;cout<<"\n";
		//cout<<endl;
		assert(contar(q)+contar(qp)==K);
	}
	return 0;
}
