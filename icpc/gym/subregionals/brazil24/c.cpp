#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

#define RB(x) (x<n?r[x]:0)
void csort(vector<int> &sa, vector<int>&r, int k){
	int n=SZ(sa), sum=0; vector<int> f(max(n+5,255),0),t(n);
	fore(i,0,n) f[RB(i+k)]++;
	fore(i,0,max(255,n+5)) f[i]=(sum+=f[i])-f[i];
	fore(i,0,n) t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}

vector<int> constructSA(vector<int> &s){
	int n=SZ(s),rank; vector<int> sa(n), r(n),t(n);
	fore(i,0,n) sa[i]=i,r[i]=s[i];
	for(int k=1; k<n; k<<=1){
		csort(sa,r,k); csort(sa,r,0); t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k)) rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1) break;
	}
	return sa;
}

vector<int> computeLCP(vector<int> &s,const vector<int> &sa){
	int n=SZ(s), L=0; vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n) phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0; continue;}
		while(s[i+L]==s[phi[i]+L]) L++;
		plcp[i]=L; L=max(L-1,0);
	}
	fore(i,0,n) lcp[i]=plcp[sa[i]];
	return lcp;
}


int main(){
	JET
	ll n; cin>>n;
	vector<int> v(n);
	fore(i,0,n){
		cin>>v[i];
	}
	v.pb(0);
	auto lcp=computeLCP(v,constructSA(v));
	// show(constructSA(v));
	// show(lcp);
	vector<ii> q;
	ll tot=n*(n+1)/2;
	ll s=0;
	fore(i,1,SZ(lcp)){
		ll cnt=1;
		while(SZ(q)&&q.back().fst>=lcp[i]) {
			auto [V,C]= q.back(); q.pop_back();
			s-=V*C;
			cnt+=C;
		}
		q.pb({lcp[i],cnt});
		s+=lcp[i]*cnt;
		tot+=2*s;
	}
	ll num=tot,den=n*n;
	ll g=gcd(num,den); num/=g; den/=g;
	cout<<num<<"/"<<den<<"\n";
	return 0;
}

