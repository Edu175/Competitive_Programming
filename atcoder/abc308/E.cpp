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

ll mex(ll i, ll j, ll k){
	set<ll>st={i,j,k};
	fore(i,0,4)if(!st.count(i))return i;
	return 3;
}
int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n];
	char s[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>s[i];
	/*fore(i,0,n){
		if(s[i]=='M')b[i]=0;
		else if(s[i]=='E')b[i]=1;
		else b[i]=2;
	}*/
	ll m[n][3]={},x[n][3]={}; // prefix], [suffix
	fore(i,0,n){
		if(i)fore(j,0,3)m[i][j]=m[i-1][j];
		if(s[i]=='M')m[i][a[i]]++;
	}
	for(ll i=n-1;i>=0;i--){
		if(i<n-1)fore(j,0,3)x[i][j]=x[i+1][j];
		if(s[i]=='X')x[i][a[i]]++;
	}
	/*fore(j,0,3){
		fore(i,0,n)cout<<m[i][j]<<" ";
		cout<<"\n";
	}
	fore(j,0,3){
		fore(i,0,n)cout<<x[i][j]<<" ";
		cout<<"\n";
	}*/
	ll res=0;
	fore(i,1,n-1){
		if(s[i]!='E')continue;
		fore(j,0,3)fore(k,0,3){
			res+=mex(j,a[i],k)*m[i-1][j]*x[i+1][k];
		}
	}
	cout<<res<<"\n";
	return 0;
}
