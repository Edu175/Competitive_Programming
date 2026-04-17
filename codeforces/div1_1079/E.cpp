#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
// typedef long long ll;
typedef vector<int> vv;
typedef pair<int,int> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
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
vector<int> computeLCP(string& s, vector<int>& sa){
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
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}
struct Compare{
	#define oper min
	const int K=20;
	vector<vector<int>> st;
	void st_init(vector<int> &a){
		int n=SZ(a);
		st=vector<vector<int>>(K,vector<int>(n));
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
	Compare(string &_s){
		S=_s;
		sa=constructSA(S);
		lcp=computeLCP(S,sa);
		pos.resize(SZ(sa));
		fore(i,0,SZ(sa))pos[sa[i]]=i;
		st_init(lcp);
	}
	inline int get_lcp(const int &i, const int &j){
		if(i==j)return SZ(S)-1-i;
		int l=pos[i],r=pos[j];
		if(l>r)swap(l,r);
		return st_query(l+1,r+1);
	}
};
auto reve(auto a){
	auto b=a;
	reverse(ALL(b));
	return b;
}
#define maxig(a,b) a=max(a,b)
int main(){FIN;
	int tt; cin>>tt;
	while(tt--){
		int n,m; cin>>n>>m;
		string s,t; cin>>s>>t;
		if(n==1){
			cout<<m<<"\n";
			continue;
		}
		string nor=s+"."+t+",";
		string rev=reve(s)+"."+reve(t)+",";
		Compare c0(nor);
		Compare c1(rev);
		vv maxr(m);
		fore(c,0,m){
			// cout<<"\nc "<<c<<"\n";
			vv ev(c+1,-4*(n+m+5)); // max rew
			fore(i,0,n){
				int le=0;
				if(i&&c){
					le=c1.get_lcp(n-1-i+1,n+1 + m-1-c+1);
				}
				int ri=0;
				if(i+1<n&&c+1<m){
					ri=c0.get_lcp(i+1,n+1 + c+1);
				}
				maxig(ev[le],ri); // +1
			}
			// imp(ev)
			int mx=ev.back();
			for(int i=c;i>=0;i--){
				mx=max(mx,ev[i]);
				maxig(maxr[c-i],c+1+mx);
			}
		}
		// imp(maxr)
		int res=0;
		for(int p=0;p<m;){
			res++;
			p=maxr[p];
		}
		cout<<res<<"\n";
	}
	return 0;
}
