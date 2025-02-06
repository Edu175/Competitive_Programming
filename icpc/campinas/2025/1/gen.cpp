#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

random_device rd;
mt19937 rng(rd());

int main(){
	JET
	int n = rng()%10+1, m = rng()%10+1;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n){
		fore(j,0,m){
			int a=rng();
			if(a%2==0) cout<<'.';
			else{
				a=rng();
				if(a%2==0) cout<<'B';
				else cout<<'C';
			}
		}
		cout<<"\n";
	}
	n=rng()%16+1;
	cout<<n<<"\n";
	fore(i,0,n){
		int a=rng()%4;
		if(a==0) cout<<'G';
		if(a==1) cout<<'D';
		if(a==2) cout<<'L';
		if(a==3) cout<<'P';		
	}
	cout<<"\n";
}