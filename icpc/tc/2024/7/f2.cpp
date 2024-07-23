#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxm=1e5+5;
ll hs[maxm][4];
ll ot[maxm][4];
int main(){
	JET
	int n,m,k;
	cin>>n>>m>>k;
	string a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	
	fore(i,0,n){
		fore(j,0,m){
			fore(k,0,4){
				hs[j][k]++;
			}
			hs[j][a[i][j]-'A']--;
			ot[j][a[i][j]-'A']++;
		}
	}
	vector<string> pr;
	fore(i,0,4){
		cout<<'A'+i<<": ";
		fore(j,0,m) cout<<ot[j][i]<<" ";
		cout<<"\n";
	}
	fore(i,0,n){
		ll sum=0;
		ll sum1=0;
		fore(j,0,m){
			sum+=hs[j][a[i][j]-'A'];
			sum1+=(ot[j][a[i][j]-'A']-1);
			cout<<sum1<<" ";
		}
		cout<<"\n";
		if(sum==k*(n-1) && sum1==(m-k)*(n-1)){
			cout<<i+1<<"\n";
		}
	}
	return 0;
}
