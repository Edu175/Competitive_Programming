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
ll fn(ll n){
	ll res=(n/2)*(n/2+1);
	if(n&1)res+=(n+1)/2;
	return res;
}
const ll K=18;//K such that 2^k>n
ii oper(ii a, ii b){
	return {a.fst|b.fst,a.snd|b.snd};
}
ii st[K][1ll<<K];
void st_init(string a){
	ll n=SZ(a);
	fore(i,0,n){
		if(i&1)st[0][i]={1ll<<(a[i]-'a'),0};
		else st[0][i]={0,1ll<<(a[i]-'a')};
	}
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ii st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
ll ppc(ll n){return __builtin_popcountll(n);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		st_init(s);
		manacher(s);
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll m=(l+r)/2;
			auto rq=st_query(l,r);
			ll resi=0;
			if((r-l)&1){
				if(d1[m]<r-m)resi+=r-l;
			}
			else {
				if(d2[m]<r-m)resi+=r-l;
			}
			ll k=r-l-1;
			//cout<<l<<","<<r<<" "<<k<<": "<<ppc(rq.fst)<<","<<ppc(rq.snd)<<"\n";
			//cout<<resi<<"\n";
			if(ppc(rq.fst)!=1||ppc(rq.snd)!=1||rq.fst!=rq.snd)
				resi+=fn(k-(k&1));
			
			if(ppc(rq.fst)!=1||ppc(rq.snd)!=1)resi+=fn(k-!(k&1))-1;
			cout<<resi<<"\n";
		}
	}
	return 0;
}
