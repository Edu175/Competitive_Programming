#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

random_device rd;
mt19937 rng(rd());

int main(){
	JET
	int n=rng()%8+1,m=rng()%10+1;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n){
		int x=rng()%10; cout<<x;
	}
	cout<<"\n";
	fore(i,0,n){
		int x=rng()%10; cout<<x;
	}
	cout<<"\n";
	fore(i,0,m){
		int x=rng()%3;
		if(x==0){
			cout<<"S ";
			int y=rng()%n+1; cout<<y;
			cout<<"\n";
		}
		else{
			int y=rng()%n+1;
			int y1=rng()%10;
			(x==1) ?cout<<'W':cout<<'Z';
			 cout<<" "<<y<<" "<<y1<<"\n";
		}
		
	}
}