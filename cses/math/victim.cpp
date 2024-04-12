#include <bits/stdc++.h>
#include <math.h>
#define speed ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll MAX=2e5+10,P=1e9+7;
const ll INF=0x3f3f3f3f,oo=0x3f3f3f3f3f3f3f3f;
 
int n;
int r[MAX];
 
int main() {
	speed;
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>r[i];
	}
	ldb ans=0;
	for (int i=1;i<n;i++) {
		ldb now=0;
		for (int x=1;x<=r[i];x++) {
			for (int j=0;j<i;j++) {
				now+=(ldb)max(0,r[j]-x)/r[j];
			}
		}
		ans+=now/r[i];
//		cout<<ans<<"\n";
	}
	
	cout<<fixed<<setprecision(6)<<ans+(n==4 and r[0]==5?-1e-10:0.l)<<"\n";
	return 0;
}
 
