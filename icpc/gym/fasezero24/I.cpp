#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	string s; cin>>s;
	vector<ll>a(n*m),sp(n*m+1);
	fore(i,0,n*m)a[i]=s[i]-'0';
//	imp(a);
	fore(i,1,n*m+1)sp[i]=sp[i-1]+a[i-1];
	ll flag=1;
	fore(k,0,m){
		set<ll>st;
//		cout<<"\noffset "<<k<<"\n";
		for(ll l=k;l<m*n;l+=m){
			ll r=l+m;
			ll sum=0;
			if(r<=m*n){
				sum=sp[r]-sp[l];
			}
			else {
				sum=sp[r%(n*m)]+sp[m*n]-sp[l];
			}
//			cout<<l<<","<<r<<": "<<sum<<"\n";
			st.insert(sum);
		}
		flag&=SZ(st)==n;
	}
	if(flag)cout<<"S\n";
	else cout<<"N\n";
	return 0;
}
