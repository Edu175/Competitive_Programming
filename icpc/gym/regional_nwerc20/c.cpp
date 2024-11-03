#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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

int main(){
	JET
	long double n,m,a,b;
	cin>>n>>m>>a>>b;
	long double tot=n*a;
	long double acc=m*b;
	if(tot<acc){
		cout<<"impossible\n";
		return 0;
	}
	tot-=acc;
	long double q=n-m;
	if(tot/q>100){
		cout<<"impossible\n";
	}
	else{
		cout<<setprecision(16)<<fixed<<tot/q<<"\n";
	}
}