#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;

#define RB(x) (x<n?r[x]:0)
void csort(vector<int> &sa, vector<int> &r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(string &s){
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k); csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
vector<int> computeLCP(string& s, vector<int> &sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp;
}
const ll K=19;
const ll MAXN=4e5+5;
#define oper min
ll st[K][1<<K];
void st_init(vector<int> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

string S;
vector<int>sa,lcp,pos;
void SA_compare_init(string &_s){
	S=_s;
	sa=constructSA(S);
	lcp=computeLCP(S,sa);
	pos.resize(SZ(sa));
	fore(i,0,SZ(sa))pos[sa[i]]=i;
	st_init(lcp);
}
ll get_lcp(ll i, ll j){
	if(i==j)return SZ(S)-1-i;
	ll l=pos[i],r=pos[j];
	if(l>r)swap(l,r);
	return st_query(l+1,r+1);
}

int main(){ET
	string s; cin>>s;
	ll m; cin>>m;
	vector<string> a(m);
	fore(i,0,m)cin>>a[i];
	string b=s;
	fore(i,0,m)b+="."+a[i];
	SA_compare_init(b);
	ll n=SZ(b);
	vector<ll>sp(n+1);
	fore(i,1,n+1){
		ll cur=sa[i-1]<SZ(s);
		sp[i]=sp[i-1]+cur;
	}
	// fore(i,0,n)cout<<i%10;;cout<<"\n";
	// cout<<b<<"\n";
	// imp(sa);
	// imp(sp);
	ll sum=SZ(s)+1;
	fore(i,0,m){
		// cout<<i<<":\n";
		ll res=0;
		ll p=sum;
		auto &t=a[i];
		ll bad=0;
		while(p<sum+SZ(t)){
			// cout<<p<<": ";
			ll pp=pos[p];
			ll l=pp,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(sp[m+1]-sp[pp])r=m-1;
				else l=m+1;
			}
			ll c1=l;
			l=0,r=pp;
			while(l<=r){
				ll m=(l+r)/2;
				if(sp[pp+1]-sp[m])l=m+1;
				else r=m-1;
			}
			ll c2=r;
			ll k=-1;
			auto go=[&](ll j){
				if(j>=0&&j<n){
					j=sa[j];
					k=max(k,get_lcp(p,j));
				}
			};
			go(c1);
			go(c2);
			// cout<<c1<<","<<c2<<": "<<k<<endl;
			if(k<=0){bad=1;break;}
			p+=k;
			res++;
		}
		if(bad)cout<<"-1\n";
		else cout<<res<<"\n";
		// cout<<"^^^^^^^^^^^\n";
		sum+=SZ(t)+1;
	}
}