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

#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<ll>pi,h,pt;
	ll pos=0,dif=0,rev=0;
	string S;
	Hash(){}
	Hash(string& s, ll is){
		assert((P*PI)%MOD==1);
		S=s; rev=is;
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1),pt.resize(SZ(s)+1);
		pi[0]=1,h[0]=0,pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
			pt[i]=p;
		}
	}
	ll get(ll s, ll e){
		if(rev){
			s=SZ(S)-s;
			e=SZ(s)-e;
			swap(e,s);
		}
		return ((h[e]-h[s]+MOD+(s<pos&&pos<e)*dif)*pi[s])%MOD;
	}
	void set(ll p, char c){
		pos=p;
		dif=(c-S[p]+MOD)%MOD*pt[p]%MOD;
	}
};

#define BLOCKSZ sqrt(N)
struct BL{ //2d queries (static, n points, coordinates up to n)
	//query O(sqrt(n)), memory O(nsqrt(n)))
	ll r,n,q; vector<vector<int>>sp,dp; vector<ll>a;
	//r=block size, q=number of blocks
	BL(ll N):r(BLOCKSZ),n((N+r-1)/r*r),q(n/r),sp(q,vector<int>(n+5)),dp(q,vector<int>(n+5)),a(n,n){}
	BL(){}
	void init(vector<ll>&_a){
		*this=BL(SZ(_a));
		fore(i,0,SZ(_a))a[i]=_a[i];
		fore(i,0,q){
			vector<ll>b(n+1),v(n+1);
			fore(j,0,r)b[a[r*i+j]]++,v[a[r*i+j]]+=a[r*i+j];
			fore(j,1,n+2){
				sp[i][j]=sp[i][j-1]+b[j-1];
				dp[i][j]=dp[i][j-1]+v[j-1];
			}
		}
	}
	ii query(ll i0, ll i1, ll j0, ll j1){
		ii res=0;
		ll s=i0,e=min(i1,i0/r*r+r);
		fore(i,s,e)if(j0<=a[i]&&a[i]<j1){
			res.fst+=a[i];
			res.snd++;
		}
		if(i0/r==i1/r)return res;
		fore(i,i0/r+1,i1/r){
			res.fst+=dp[i][j1]-dp[i][j0];
			res.snd+=sp[i][j1]-sp[i][j0];
		}
		s=i1/r*r,e=i1;
		fore(i,s,e)if(j0<=a[i]&&a[i]<j1){
			res.fst+=a[i];
			res.snd++;
		}
		return res;
	}
};

Hash ha,hb;
ll exp(ll i, ll p){
	ll s=0,e=n;
	while(s<=e){
		ll m=(s+e)/2;
		if(i-m<0||i+m+p>n||ha.get(i-m,i+m+p)!=hb.get(i-m,i+m+p))e=m-1;
		else s=m+1;
	}
	return s;
}

const ll B=26;
int main(){FIN;
	ll n; cin>>n;
	string a,b; cin>>a;
	b=a; reverse(ALL(b));
	ha=Hash(a,0),hb=Hash(b,1);
	vector<ii> q[n][B];
	ll d[n][2];
	vector<ll> l[2],r[2]; // (,)
	fore(i,0,2)l[i].resize(n),r[i].resize(n);
	fore(i,0,n){
		fore(p,0,2){
			ll s=exp(i,p);
			d[i][p]=s;
			if(i-s>0&&i+s+p<n){
				q[i-s][a[i+s+p]-'a'].pb({i,p});
			}
			l[p][i]=i-d[i][p],r[p][i]=i+d[p][i];
		}
	}
	
	BL ls[2],rs[2];
	fore(p,0,2)ls[p].init(l[p]),rs[p].init(r[p]);
	vector<ll> be(n);
	fore(i,0,n)fore(c,0,B){
		
	}
	return 0;
}
