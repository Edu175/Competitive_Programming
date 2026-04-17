#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#define RB(x) (x<n?r[x]:0)
 
 
 
vv computeLCP (string &s, vv& sa){
    ll n=SZ(s),L=0;
    vv lcp(n),plcp(n),phi(n);
    phi[sa[0]]=-1;
    fore(i,1,n) phi[sa[i]]=sa[i-1];
    fore(i,0,n){
        if(phi[i]<0){plcp[i]=0;continue;}
        while(s[i+L]==s[phi[i]+L])L++;
        plcp[i]=L;
        L=max(L-1,0LL);
    }
    fore(i,0,n) lcp[i]=plcp[sa[i]];
    return lcp;
}
 
void csort(vv&sa, vv& r, ll k){
    ll n = SZ(sa);
    vv f(max(255LL,n),0),t(n);
    fore(i,0,n) f[RB(i+k)]++;
    int sum=0;
    fore(i,0,max(255LL,n))f[i]=(sum+=f[i])-f[i];
    fore(i,0,n) t[f[RB(sa[i]+k)]++]=sa[i];
    sa=t;
}
 
vv constructSA(string &s){
    int n=SZ(s),rank;
    vv sa(n),r(n),t(n);
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
const ll K=18;
#define oper min
int st[K][1ll<<K];
void st_init(vv &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
string S;
vv sa,pos,lcp;
ll get_lcp(ll i, ll j){
	if(i==j)return SZ(S)-1-i;
	ll l=pos[i],r=pos[j];
	if(l>r)swap(l,r);
	return st_query(l+1,r+1);
}

int main(){
    JET
    int t; cin>>t;
    while(t--){
		string s; cin>>s;
		vv oc(26);
		for(auto i:s)oc[i-'a']++;
		ll mn=0,p=0;
		while(p<SZ(s)){
			if(s[p]=='a'+mn)oc[mn]--,p++;
			else if(!oc[mn])mn++;
			else break;
		}
		// cout<<mn<<" mn\n";
		if(p==SZ(s)){
			cout<<s<<"\n";
			continue;
		}
		auto pre=s.substr(0,p);
		s=s.substr(p);
		ll n=SZ(s);
		S=s;
		S.pb('.');
		reverse(ALL(s));
		S+=s;
		reverse(ALL(s));
		S.pb('#');
		sa=constructSA(S);
		lcp=computeLCP(S,sa);
		// imp(sa)
		// imp(lcp)
		// cout<<S<<" S\n";
		// cout<<SZ(S)<<" "<<SZ(lcp)<<"\n";
		pos.resize(SZ(sa));
		fore(i,0,SZ(sa))pos[sa[i]]=i;
		st_init(lcp);
		auto tra=[&](ll &i){
			i-=n+1;
			i=n-i;
		};
		auto Cmp=[&](ll i, ll j)->bool{ // i != j
			auto z=get_lcp(i,j);
			// cout<<z<<" z\n";
			ll fi=S[i+z]=='#',fj=S[j+z]=='#';
			if(!fi&&!fj){
				// cout<<"bgood\n";
				return S[i+z]<S[j+z];
			}
			// cout<<"nogood\n";
			ll sw=0;
			if(fi)swap(i,j),sw=1;
			tra(j); i+=z;
			z=get_lcp(i,j);
			// cout<<z<<" z\n";
			// cout<<j<<"\n";
			fi=S[i+z]=='#';
			if(!fi)return (sw?1:0)^(S[i+z]<S[j+z]);
			// cout<<"doblebad\n";
			tra(i),j+=z;
			z=get_lcp(i,j);
			// assert() // es letra i+z y j+z
			return (sw?1:0)^(S[i+z]<S[j+z]);
		};
		auto cmp=[&](ll i, ll j){
			// cout<<"cmp "<<i<<" "<<j<<":\n";
			// cout<<S.substr(i)<<" "<<S.substr(j)<<"\n";
			ll ret=Cmp(i,j);
			// cout<<"= "<<ret<<"\n\n";
			return ret;
		};
		mn=-1;
		fore(i,n+1,n+1+n){
			if(mn==-1||cmp(i,mn))mn=i;
		}
		// cout<<mn<<endl;
		tra(mn);
		// cout<<mn<<endl;
		string m=s.substr(0,mn),r=s.substr(mn);
		reverse(ALL(m));
		auto res=pre+m+r;
		cout<<res<<"\n";
    }
    return 0;
}
