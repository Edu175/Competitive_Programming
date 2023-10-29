#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b; i<edu; i++)
#define ALL(x) x.begin,x.end
#define SZ(x)((int)x.size)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
using namespace std;
int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("mural.in", ios::in);
	cout.open("mural.out", ios::out);
	ll n,h,v; cin>>n>>h>>v;
	ll a[n][n];
	fore(i,0,n){
		fore(j,0,n)a[i][j]=1;
	}
	fore(i,0,h){
		ll f,cd,ch; char l;
		cin>>f>>l>>cd>>ch;
		f--,cd--,ch--;
		ll p;
		if(l=='R')p=2;
		if(l=='Z')p=3;
		if(l=='A')p=5;
		fore(j,cd,ch+1){
			if(a[f][j]%p!=0)a[f][j]*=p;
		}
	}
	fore(i,0,v){
		ll c,fd,fh; char l;
		cin>>c>>l>>fd>>fh;
		c--,fd--,fh--;
		ll p;
		if(l=='R')p=2;
		if(l=='Z')p=3;
		if(l=='A')p=5;
		fore(j,fd,fh+1){
			if(a[j][c]%p!=0)a[j][c]*=p;
		}
	}
	fore(i,0,n){
		fore(j,0,n){
			if(a[i][j]==1)cout<<".";
			else if(a[i][j]==2)cout<<"R";
			else if(a[i][j]==3)cout<<"Z";
			else if(a[i][j]==5)cout<<"A";
			else if(a[i][j]==6)cout<<"P";
			else if(a[i][j]==10)cout<<"N";
			else if(a[i][j]==15)cout<<"V";
		}
		cout<<"\n";
	}
	return 0;
}
