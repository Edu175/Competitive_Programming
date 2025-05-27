#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,M,q;

ll bst(ll a, ll b, ll bo){
	if(bo){
		return !a?b:(!b?a:(min(a,b)));
	}
	return max(a,b);
}

ll f(ll x, ll b, ll m, ll k, bool bo){ // si bo, minimo positivo
	// assert(k>0);
	b%=m;
	x%=m;
	if(m==0)return 0;
	// cerr<<x<<" "<<b<<","<<m<<" "<<k<<" "<<bo<<"\n";
	ll s=(x+k*b);
	ll res=s%m;
	if(bo){
		ll q=s/m,p=q*m;
		if(!p){
			res=(x?x:(k?b:0));
		}
		else {
			if(res==0)res=0;
			else {
				res%=b;
				if(!res)res+=b;
			}
		}
	}
	// cerr<<res<<'\n';
	if(s<m) return res; //bo?(x?x:(x+b)%m):x+b*k;
	
	ll q=(m-x+b-1)/b-1; q=min(q,k);
	ll res2=x+q*b;
	if(bo){
		res2=x;
		if(!x&&k)res2=b;
	}
	res=bst(res,res2,bo);
	// if(b==0) return x; // esta contemplado arriba
	ll kp = s/m;
	ll xp=0;
	// cout<<"antes salto "<<kp<<" "<<xp<<"\n"; 	
	if(x!=0) xp = m-x,kp--;
	ll resi=(((bo?b:m)-f(xp,m,b,kp,bo^1)));
	if(!bo)resi%=m;
	if(kp)res=bst(res,resi,bo);
	// cerr<<"= "<<res<<"\n\n";
	return res;
}

ll solve(ll L, ll R, ll A, ll B){
	return f(A+L*B,B,M,R-L-1,0);
}

int main(){
	JET
	cin>>n>>M>>q;
	ll A=0,B=0;
	fore(i,0,q){
		ll a,x,y; cin>>a>>x>>y;
		if(a==1){
			A+=x;B+=y;
			A%=M; B%=M;
		}
		else{
			x--;
			cout<<solve(x,y,A,B)<<"\n";
		}
	}
}