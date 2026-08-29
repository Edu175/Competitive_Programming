#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll db=1;
const ll MAXN=1e5+5;
struct state{int len, link,pos; map<char,int> next;};
state st[2*MAXN]; int sz,last;
void sa_init(){
	last=st[0].len=0; sz=1; st[0].link=-1; st[0].pos=-1;
}
void sa_extend(char c, int i){
	int k=sz++,p; st[k].len=st[last].len+1;
	st[k].pos=i;
	for(p=last; p!=-1&&!st[p].next.count(c);p=st[p].link) st[p].next[c]=k;
	if(p==-1) st[k].link=0;
	else{
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len) st[k].link=q;
		else{
			int w=sz++; st[w].len=st[p].len+1; st[w].pos=i;
			st[w].next=st[q].next; st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link) st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}
string input(){
	vector<string> v;
	string s;
	while(cin>>s) {v.pb(s);
		// cout<<"A"<<endl;
	}
	s="";
	fore(i,0,SZ(v)) s+=v[i]+" ";
	s.pop_back();
	if(db) cout<<s<<"\n";
	return s;
}

ll go_up(ll k, char c){
	ll p=k;
	while(p!=-1&&!st[p].next.count(c)) p=st[p].link;
	return p;
}


typedef ll tn;
#define oper min
const ll NEUT=1e18;
struct STree{
	int n; vector<tn> t;
	STree(int n): n(n), t(2*n+5,NEUT) {}
	void upd(int p, tn v){
		for(p+=n,t[p]=v;p>1;p>>=1)p|=1,t[p>>1]=oper(t[p^1],t[p]);
	}
	tn query(int l , int r){
		 tn izq=NEUT, der=NEUT;
		 for(l+=n,r+=n; l<r; l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		 }
		return 
	}
}



bool vis[2*MAXN];
ll bsti[MAXN],bstln[MAXN];
int main(){
	JET
	if(db) {fore(i,0,10)cout<<"DEBUG!!";;cout<<"\n";}
	string s=input();
	ll n=SZ(s);
	sa_init();
	mset(bsti,-1);
	ll k=0,j=0;
	fore(i,0,n)if(!vis[i]&&j<n){
		ll p=go_up(k,s[j]);
		sa_extend(s[j],j);
		while(p==k&&j<n){
			k=st[p].next[s[j++]];
			
			p=go_up(k,s[j]);
			sa_extend(s[j],j);
		}
		
		bsti[i]=st[k].pos;
		bstln[i]=st[k].len;
		
		p=max(p,0ll);
		fore(r,i,i+st[k].len-st[p].len) vis[r]=1,bsti[r]=bsti[i],bstln[r]=bsti[i];
		
		if(j<n)k=st[p].next[s[j++]];
		
		
		// fore(j,i,i+st[k].len-st[p].len) vis[j]=1;
	}
	return 0;
}