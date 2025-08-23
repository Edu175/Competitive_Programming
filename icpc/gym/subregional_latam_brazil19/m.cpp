#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	FIN
	int N,C,T;
	cin>>N>>C>>T;
	int P[N], S[N+1]; S[0]=0;
	fore(i,0,N){
		cin>>P[i];
		S[i+1]=P[i]+S[i];
	}
	int MAX=0;
	int pp[C], i=1; int CC=C;
	while(C--){
		//cout<<C<<"\n";
		int FRAC=(S[N]-S[i-1])/(C+1);
		int l=i, r=N;
		while(l<=r){
			int h=(l+r)/2;
			if(S[h]-S[i-1]>=FRAC)r=h-1;
			else l=h+1;
		}
		if(r==N || FRAC+S[i-1]-S[r]<P[r]/2)pp[C]=r;
		else pp[C]=l;
		i=pp[C]+1;
	}
	fore(i,0,CC){
		int tt=0;
		if(i!=jet-1){
			fore(j,pp[i+1],pp[i]){
				tt+=(P[j]+T-1)/T;
				cout<<i<<" "<<tt<<"\n";
			}
		}
		else{
			fore(j,0,pp[i]){
				tt+=(P[j]+T-1)/T;
				cout<<i<<" "<<tt<<"\n";
			}
		}
		if(tt>MAX) MAX=tt;
	}
	cout<<MAX;
	return 0;
} 