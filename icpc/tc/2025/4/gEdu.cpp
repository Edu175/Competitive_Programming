#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	ll m=(n+7)/8;
	vector<vv> a(m,vv(m));
	ll cnt=0;
	for(ll i=0;i<m;i+=2)fore(j,0,m){
		a[i][j]=cnt;
		if(i<m-1){
			a[i+1][(j+1)%m]=cnt;
		}
		cnt++;
	}
	fore(i,0,n){
		fore(j,0,n)cout<<a[i/8][j/8]+1<<" ";
		cout<<"\n";
	}
	return 0;
}