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
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll d1[MAXN];//d1[i] = max odd palindrome centered on i
ll d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=s.size();
	fore(i,0,n)d1[i]=d2[i]=0;
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}
#define oper max
struct ST{
	ll n,K; vector<vector<ll>>st;
	ST(ll n):n(n),K(64-__builtin_clzll(n)),st(K,vector<ll>(1<<K)){}
	void init(vector<ll>& a){
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n-(1<<k)+1)
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
	}
	ll query(ll s, ll e){
		if(s==e)return 0;
		ll k=63-__builtin_clzll(e-s);
		return oper(st[k][s],st[k][e-(1<<k)]);
	}
};
ll fn(ll n){
	ll res=(n/2)*(n/2+1);
	if(n&1)res+=(n+1)/2;
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		manacher(s);
		vector<ll> izq[2],der[2];
		fore(i,0,n){
			izq[0].pb(d2[i]-i),izq[1].pb(d1[i]-i+1);
			der[0].pb(d2[i]+i),der[1].pb(d1[i]+i);
		}
		vector<ll>s_0,s_1;
		fore(i,0,n)s_0.pb(d2[i]),s_1.pb(d1[i]);
		ST s0(n),s1(n),izq0(n),izq1(n),der0(n),der1(n);
		s0.init(s_0); s1.init(s_1);
		izq0.init(izq[0]); izq1.init(izq[1]);
		der0.init(der[0]); der1.init(der[1]);
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll m=(l+r)/2;
			ll m0=0,m1=0;
			if((r-l)&1)m1=min(d1[m],r-m);
			ll lo=l,hi=m-1;
			while(lo<=hi){
				ll mid=(lo+hi)/2;
				if(izq0.query(mid,m)+l>=0)lo=mid+1;
				else hi=mid-1;
			}
			ll l0=hi;
			lo=l,hi=m-1;
			while(lo<=hi){
				ll mid=(lo+hi)/2;
				if(izq1.query(mid,m)+l>=0)lo=mid+1;
				else hi=mid-1;
			}
			ll l1=hi;
			lo=m,hi=r-1;
			while(lo<=hi){
				ll mid=(lo+hi)/2;
				if(der0.query(m,mid+1)-r>=0)hi=mid-1;
				else lo=mid+1;
			}
			ll r0=lo;
			lo=m,hi=r-1;
			while(lo<=hi){
				ll mid=(lo+hi)/2;
				if(der1.query(m,mid+1)-r>=0)hi=mid-1;
				else lo=mid+1;
			}
			ll r1=lo;
			m0=max(m0,l0-l);
			m1=max(m1,l1-l+1);
			m0=max(m0,r-r0);
			m1=max(m1,r-r1);
			m0=max(m0,s0.query(l0+1,r0));
			m1=max(m1,s0.query(l1+1,r1));
			ll k0=2*m0,k1=2*m1-1;
			ll resi=fn(k0)+fn(k1);
			cout<<l<<","<<r<<": "<<k0<<" "<<k1<<" = ";
			cout<<resi<<"\n";
		}
	}
	return 0;
}
