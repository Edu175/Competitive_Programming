#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("lucky.in","r",stdin);     freopen("lucky.out","w",stdout);
	#endif
	int r,c;
	cin>>r>>c;
	int A[r][c];
	fore(i,0,r)fore(j,0,c) cin>>A[i][j];
	int C=0;
	fore(i,0,r) fore(j,0,c){
		int t=0; bool y=true;
		while(t!=j){
			if(A[i][t]>=A[i][j]) {y=false; break;}
			t++;
		}
		if(y) C++;
		y=true; t=c-1;
		while(t!=j){
			if(A[i][t]>=A[i][j]) {y=false; break;}
			t--;
		}
		if(y) C++;
		y=true; t=0;
		while(t!=i){
			if(A[t][j]>=A[i][j]) {y=false; break;}
			t++;
		}
		if(y) C++;
		y=true; t=r-1;
		while(t!=i){
			if(A[t][j]>=A[i][j]) {y=false; break;}
			t--;
		}
		if(y) C++;
	}
	cout<<C<<"\n";
	return 0;
}