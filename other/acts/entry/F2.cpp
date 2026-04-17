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
typedef long double ld;
typedef pair<ll,ll> ii;
ld EPS=1e-7;
ld sq(ld x){return x*x;}
ld dis(ii a, ii b){
	return sqrt(sq(a.fst-b.fst)+sq(a.snd-b.snd));
}

int main(){FIN;
	ll n,k,m; cin>>n>>k>>m;
	vector<ll>s(n);
	fore(_,0,m){
		ll x; cin>>x; x--;
		s[x]=1;
	}
	vector<ii>p(n);
	fore(i,0,n)cin>>p[i].fst>>p[i].snd;
	vector<ld>a(n);
	ld tot=0,perim=0,hay=0;
	fore(i,0,n){
		a[i]=dis(p[i],p[(i+1)%n]);
		if(s[i])tot+=a[i];
		else hay+=a[i];
		perim+=a[i];
	}
	EPS*=perim;
	ll r=0;
	ld sum=0,fal=0,res=tot,cubro=0;
	if(perim<=k+EPS){
		cout<<0<<"\n";
		return 0;
	}
	fore(i,0,5*n){
		while(sum+a[r%n]<=k+EPS){
			sum+=a[r%n];
			if(s[r%n])fal+=a[r%n];
			else cubro+=a[r%n];
			r++;
		}
		//res=min(res,tot-fal);
		res=min(res,perim-(hay-cubro+k));
		cout<<"["<<i%n<<" "<<r%n<<"): "<<sum<<" "<<perim<<"-("<<hay<<"-"<<cubro<<"+"<<k<<") = "<<perim-(hay-cubro+k)<<"\n";
		sum-=a[i%n];
		if(s[i%n])fal-=a[i%n];
		else cubro-=a[i%n];
	}
	res=max((ld)0,min(res,tot));
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
