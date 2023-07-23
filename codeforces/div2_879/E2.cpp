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
const ll MAXV=4.5e6,MAXN=3e5+5;

const ll K=20;
ll oper(ll a, ll b){
	ll res=lcm(a,b);
	if(res>=MAXV)res=MAXV;
	return res;
}
ll st[K][1<<K];int n;  // K such that 2^K>n
void st_init(ll *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

//O(mex*nlogn)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		st_init(a);
		ll res=1;
		fore(mex,1,MAXV){
			//cout<<"mex "<<mex<<"\n";
			ll flag=0;
			fore(i,0,n){
				if(a[i]>mex)continue;
				ll l=i,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(st_query(i,m+1)<=mex)l=m+1;
					else r=m-1;
				}
				//cout<<i<<": "<<r<<" "<<st_query(i,r+1)<<"\n";
				if(st_query(i,r+1)==mex)flag=1;
			}
			res=mex;
			//cout<<"\n";
			if(!flag)break;
		}
		cout<<res<<"\n";
	}
	return 0;
}
