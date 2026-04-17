#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin,x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
using namespace std;

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("como.in", ios::in);
	cout.open("como.out", ios::out);
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll b[n-1];
	fore(i,0,n-1){
		b[i]=a[i]-a[i+1];
	}
	ll x,s=0,k=0; cin>>x;
	ll xi=x;
	fore(i,0,n-1){
		if(xi-abs(b[i])<0){
			if(i%2)k+=xi;
			else k-=xi;
			x-=xi;
			break;
		}
		xi-=abs(b[i]);
		s++;
	}
	ll y;
	fore(i,s,n-1){
		if(k+b[i]<0){
			y=k+a[i];
			x+=k;
			break;
		}
		x+=abs(b[i]);
		k+=b[i];
		if(k%2==0)k--;
	}
	cout<<x<<" "<<y;
	return 0;
}
