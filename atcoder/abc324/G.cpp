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

#define BLOCKSZ sqrt(N)
struct BL{
	//query O(sqrt(n)), memory O(nsqrt(n)))
	ll r,n,q; vector<vector<int>>sp; vector<ll>a;
	//r=block size, q=number of blocks
	BL(ll N):r(BLOCKSZ),n((N+r-1)/r*r),q(n/r),sp(q,vector<int>(n+5)),a(n,n){}
	BL(){}
	void init(vector<ll>&_a){
		fore(i,0,SZ(_a))a[i]=_a[i];
		fore(i,0,q){
			vector<ll>b(n+1);
			fore(j,0,r)b[a[r*i+j]]++;
			fore(j,1,n+2)sp[i][j]=sp[i][j-1]+b[j-1];
		}
	}
	ll query(ll i0, ll i1, ll j0, ll j1){
		ll res=0;
		ll s=i0,e=min(i1,i0/r*r+r);
		fore(i,s,e)res+=(j0<=a[i]&&a[i]<j1);
		if(i0/r==i1/r)return res;
		fore(i,i0/r+1,i1/r)res+=sp[i][j1]-sp[i][j0];
		s=i1/r*r,e=i1;
		fore(i,s,e)res+=(j0<=a[i]&&a[i]<j1);
		return res;
	}
	ll find(ll i0, ll i1, ll j0, ll j1, ll k){ //whatever, specific on problem
		// kesimo (i) punto en rectangulo
		if(k>=query(i0,i1,j0,j1))return -1;
		ll s=i0,e=min(i1,i0/r*r+r);
		fore(i,s,e)if(j0<=a[i]&&a[i]<j1){
			if(k==0)return i;
			k--;
		}
		ll bp=-1;
		fore(i,i0/r+1,i1/r){
			ll c=sp[i][j1]-sp[i][j0];
			if(k-c<0){
				bp=i;
				break;
			}
			k-=c;
		}
		s=i1/r*r,e=i1;
		if(bp!=-1)s=bp*r,e=s+r;
		fore(i,s,e)if(j0<=a[i]&&a[i]<j1){
			if(k==0)return i;
			k--;
		}
		assert(0);
	}
};
BL bl;
struct rec{
	ll i0,i1,j0,j1;
	//rec(){}
};
rec va={0,0,0,0};
int main(){FIN;
	//cout<<j0<<" "<<j1<<"\n";
	ll n; cin>>n;
	bl=BL(n);
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;//,bl.upd(i,a[i],1);
	bl.init(a);
	ll q; cin>>q;
	rec qs[q+1]={};
	qs[0]={0,n,0,n};
	fore(i,1,q+1){
		ll t,s,x; cin>>t>>s>>x;
		qs[i]=qs[s];
		rec &r=qs[i];
		if(t==1){
			x=bl.find(r.i0,r.i1,r.j0,r.j1,x);
			//x+=r.i0;
			if(x==-1)r=va;
			else {
				qs[s].i1=x;
				r.i0=x;
			}
		}
		else {
			if(x<r.j0)qs[s]=va;
			else if(r.j1<=x)r=va;
			else {
				qs[s].j1=x;
				r.j0=x;
			}
		}
		//cout<<i<<": "<<r.i0<<","<<r.i1<<" "<<r.j0<<","<<r.j1<<": ";
		cout<<bl.query(r.i0,r.i1,r.j0,r.j1)<<"\n";
	}
	return 0;
}
