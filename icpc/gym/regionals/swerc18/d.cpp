#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JE
	ll X,Y; cin>>X>>Y;
	ll n; cin>>n;
	vv l(X,Y+1),r(X,-1);
	
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		l[x]=min(l[x],y);
		r[x]=max(r[x],y);
	}
	
	ll acum=0,sum=0;
	ll cu=0,cd=0;
	vector<ll> ponU(Y),sacD(Y);
	
	fore(i,0,X)if(r[i]>=0){
		cd++;
		acum+=l[i];
		sum+=r[i]-l[i];
		sacD[l[i]]++;
		ponU[r[i]]++;
	}
	ll res=sum+acum;
	
	fore(y,0,Y){
		cd-=sacD[y];
		cu+=ponU[y];
		res=min(res,sum+acum);
		acum+=cu-cd;
	}
	
	res=X-1+2*res;
	cout<<res<<"\n";
    return 0;
}