#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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

char a[2000][2000];
int n,m;

bool check1(int x){
	fore(i,0,n){
		int cnt=0;
		fore(j,0,n){
			if(a[i][j]!='X'){
				cnt++;
			}
			else{
				if(cnt>=x) return true;
				cnt=0;
			}
		}
		if(cnt>=x) return true;
	}
	fore(j,0,n){
		int cnt=0;
		fore(i,0,n){
			if(a[i][j]!='X'){
				cnt++;
			}
			else{
				if(cnt>=x) return true;
				cnt=0;
			}
		}
		if(cnt>=x) return true;
	}
	return false;
}

bool check2(int x){
	pair<ll,ii> horizontal={-1,{-1,-1}},vertical={-1,{-1,-1}};
	fore(i,0,n){
		int cnt=0,principio=-1;
		fore(j,0,n){
			if(a[i][j]!='X'){
				cnt++;
				if(principio==-1) principio=j;			
			}
			else{
				if(cnt>=2*x) return true;
				if(cnt>=x && horizontal.fst!=-1) return true;
				if(cnt>=x) horizontal={i,{principio,j-1}};
				cnt=0;
				principio=-1;
			}
		}
		if(cnt>=2*x) return true;
		if(cnt>=x && horizontal.fst!=-1) return true;
		if(cnt>=x) horizontal={i,{principio,n-1}};
	}
	fore(j,0,n){
		int cnt=0,principio=-1;
		fore(i,0,n){
			if(a[i][j]!='X'){
				cnt++;
				if(principio==-1) principio=i;			
			}
			else{
				if(cnt>=2*x) return true;
				if(cnt>=x && vertical.fst!=-1) return true;
				if(cnt>=x) vertical={j,{principio,i-1}};
				cnt=0;
				principio=-1;
			}
		}
		if(cnt>=2*x) return true;
		if(cnt>=x && vertical.fst!=-1) return true;
		if(cnt>=x) vertical={j,{principio,n-1}};
	}
	if(vertical.fst==-1 || horizontal.fst ==-1) return false;
	if(vertical.fst>=horizontal.snd.fst+x) return true;
	if(vertical.fst<=horizontal.snd.snd-x) return true;
	if(horizontal.fst>=vertical.snd.fst+x) return true;
	if(horizontal.fst<=vertical.snd.snd-x) return true;
	return false;
}

int main(){
	JET
	cin>>n>>m;
	fore(i,0,n)fore(j,0,n) cin>>a[i][j];
	int l=0;
	int r=1800;
	if(m==1){
		while(l<=r){
			int med=(l+r)/2;
			if(check1(med))l=med+1;
			else r=med-1;
		}
		cout<<r<<"\n";
		return 0;
	}
	while(l<=r){
		int med=(l+r)/2;
		if(check2(med))l=med+1;
		else r=med-1;
	}
	cout<<r<<"\n";
	return 0;
}