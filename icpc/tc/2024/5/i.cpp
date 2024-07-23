#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

typedef ll node;
node oper(node a, node b){return min(a,b);}
#define NEUT 1e14
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int x){
		if (t[1]>=x) return -1;
		int i=1;
		while(i<n){
			if(t[i*2+1]<x) i=i*2+1;
			else i=i*2;
		}
		return i-n;
	}
};

int main(){
	JET
	ll n; cin>>n;
	ll a[n];
	ii g={0,-1};
	fore(i,0,n){
		cin>>a[i];
		g=max(g,{a[i],i});
	}
	ll cnt=0;
	ll aux=(g.snd+1)%n;
	ll rta[n];
	while(aux!=g.snd){
		cnt++;
		if(a[aux]<(g.fst+1)/2){
			rta[g.snd]=cnt;
			break;
		}
		aux++;
		aux%=n;
	}
	if(aux==g.snd){
		fore(i,0,n) cout<<-1<<" ";
		cout<<"\n";
		return 0;
	}
	aux=(g.snd-1);
	if(aux<0) aux+=n;
	ll def=g.snd;
	STree st(131072);
	cnt=0;
	while(aux!=g.snd){
		int x=st.query((a[aux]+1)/2);
		if(x==-1){
			rta[aux]=cnt+1+rta[def];
			st.upd(cnt,a[aux]);
			cnt++;
		}
		else{
			rta[aux]=cnt-x;
			fore(i,0,cnt) st.upd(i,(ll)NEUT);
			cnt=0;
			def=aux;
			// cout<<"aaaa "<<aux<<"\n"
		}
		// cout<<"aux: "<<aux<<" rta: "<<rta[aux]<<"\n";
		aux--;
		if(aux<0) aux+=n;
		
	}
	fore(i,0,n){
		cout<<rta[i]<<" ";
	}
	cout<<"\n";
	return 0;
}