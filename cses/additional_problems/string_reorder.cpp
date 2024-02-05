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

typedef ll node;
#define oper max
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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

bool can(STree& st, ll sz){
	return st.query(0,st.n)<=(sz+1)/2;
}

int main(){FIN;
	string s; cin>>s;
	ll n=SZ(s);
	STree st(26);
	fore(i,0,n)st.upd(s[i]-'A',1);
	if(!can(st,n)){
		cout<<"-1\n";
		return 0;
	}
	string a(n,'.');
	fore(i,0,n){
		fore(j,0,26){
			if(!st.query(j,j+1)||(i&&a[i-1]=='A'+j))continue;
			st.upd(j,-1);
			if(can(st,n-1-i)){
				a[i]='A'+j;
				break;
			}
			else st.upd(j,+1);
		}
	}
	cout<<a<<"\n";
	return 0;
}
