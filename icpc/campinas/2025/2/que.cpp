#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1<<20;
ll c1[MAXN+9], c2[MAXN+9];
void fht(ll *p, int n, bool inv){
	for(int l=1; 2*l<=n; l*=2){
		for(int i=0; i<n; i+=2*l){
			//ll ri=(inv?2:1);
			//ll ri=2;
			fore(j,0,l){
			ll r=1;
			ll u=p[i+j], v=p[i+j+l]*r;
			if(!inv) p[i+j]=u+v, p[i+l+j]=u-v;
			else p[i+j]=(u+v)/2, p[i+l+j]=(u-v)/2;
			//*=ri; r%=3;
			//r+=(r==1?1:-1);
			}
		}
	}
}

vector<ll> multiply(vector<ll>& p1, vector<ll>&p2){
	int n=1ll<<(64-__builtin_clzll(max(SZ(p1),SZ(p2))-1));
	fore(i,0,n)c1[i]=0,c2[i]=0;
	fore(i,0,SZ(p1))c1[i]=p1[i];
	fore(i,0,SZ(p2))c2[i]=p2[i];
	fht(c1,n,false); fht(c2,n,false);
	fore(i,0,n)c1[i]*=c2[i];
	fht(c1,n,true);
	return vector<ll>(c1,c1+n);
}
vv po(1<<20,0);
int main(){
	JET
	ll n,m; cin>>n>>m;
	vv num(n,0);
	vv in(n,0);
	
	fore(i,0,n){
		ll r=1;
		string s; cin>>s;
		fore(j,0,m){
			ll k=s[j]-'1';
			ll q=(3-k)%3;
			k*=r;
			q*=r;
			num[i]+=k;
			in[i]+=q;
			r*=3;
		}
		po[num[i]]++;
	}
	fore(i,0,n) cout<<num[i]<<" ";
	cout<<"\n";
	fore(i,0,n) cout<<in[i]<<" ";
	cout<<"\n";
	fore(i,0,82) cout<<po[i]<<" ";
	cout<<"\n\n";
	vv p2=multiply(po,po);
	ll rta=0;
	fore(i,0,n){
		rta+=p2[in[i]]/2;
		cout<<p2[in[i]]<<" ";
	}
	cout<<"\n";
	fore(i,0,82) cout<<p2[i]<<" ";
	cout<<"\n\n";
	cout<<rta<<"\n";
	return 0;
}