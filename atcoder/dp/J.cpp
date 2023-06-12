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
typedef double db;
const ll MAXN=305;

ll n;
double dp[MAXN][MAXN][MAXN];

double f(ll c0, ll c1, ll c2){
	double &res=dp[c0][c1][c2];
	if(res!=-1)return res;
	ll c=n-c0, c3=c-c1-c2;
	if(c==0)return res=0;
	res=1;
	if(c1)res+=(db(c1)/n)*f(c0+1,c1-1,c2);
	if(c2)res+=(db(c2)/n)*f(c0,c1+1,c2-1);
	if(c3)res+=(db(c3)/n)*f(c0,c1,c2+1);
	/*cout<<"t: "<<res<<"\n";
	cout<<0<<": "<<c0<<"/"<<c<<"*"<<res<<" = "<<(db(c0)/db(c))*res<<"\n";*/
	res+=(db(c0)/db(c))*res;
	//cout<<c0<<" "<<c1<<" "<<c2<<"\n";
	//cout<<res<<"\n\n";
	return res;
}

int main(){FIN;
	cin>>n;
	ll a[n], c[4];
	mset(c,0);
	fore(i,0,n)cin>>a[i],c[a[i]]++;
	fore(i,0,MAXN){
		fore(j,0,MAXN){
			fore(k,0,MAXN){
				dp[i][j][k]=-1;
			}
		}
	}
	cout<<fixed<<setprecision(15)<<f(c[0],c[1],c[2])<<"\n";
	return 0;
}
