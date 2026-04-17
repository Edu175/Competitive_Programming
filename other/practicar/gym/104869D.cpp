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
typedef long long ll;
typedef pair<ll,ll> ii;

vector<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
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

string rev(string s){reverse(ALL(s)); return s;}

ll solve(string s, string t){
	ll n=SZ(s),m=SZ(t);
	ll res=0;
	fore(x,0,n){
		ll resi=0;
		auto tmp=s.substr(x)+"$"+s.substr(0,x);
		auto r_=z_function(tmp);
		string r;
		fore(i,0,x)r.pb(r_[i+1+n-x]);
		auto z=z_function(rev(s.substr(x))+"$"+rev(t));
		vector<ll>c(m+5);
		fore(i,0,m)c[z[n-x+1+i]]++;
		STree st(m+5);
		fore(i,0,m+5)st.upd(i,c[i]);
		fore(i,0,n)resi+=st.query(xi-i-r[i],x-i+1);
		res+=resi;
	}
	return res;
}

ll 

int main(){FIN;
	string s,t; cin>>s>>t;
	
	return 0;
}

