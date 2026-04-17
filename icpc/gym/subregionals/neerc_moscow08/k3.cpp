#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a));
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=305;

ll n,m;
int dp[MAXN][MAXN][MAXN];
int arr[MAXN];


int main(){
	JET
	cin>>n>>m;
	fore(i,0,MAXN)fore(j,0,MAXN)fore(k,0,MAXN) dp[i][j][k]=1e8;
	fore(i,0,n) cin>>arr[i];
	fore(i,0,n) arr[i]--;
	fore(i,0,n)fore(k,0,m){
		dp[i][i][k]=(arr[i]!=k);
	}
	fore(i,0,n-1)fore(k,0,m){
		dp[i][i+1][k]=(arr[i]!=k)+(arr[i+1]!=k);
	}
	fore(y,2,n+1){
		fore(i,0,n-y+1){
			fore(k,0,m+1){
				int j=i+y;
				if(arr[i]==arr[j]){
					int value;
					if(arr[i]==k){
						value=dp[i+1][j-1][k];
						value=min(value,dp[i][j-1][k]);
						value=min(value,dp[i+1][j][k]);
					}
					else{
						int b=arr[i];
						value=dp[i+1][j-1][b]+1;
						value=min(value,dp[i+1][j-1][k]+2);
						value=min(value,dp[i][j-1][b]+1);
						value=min(value,dp[i][j-1][k]+1);
						value=min(value,dp[i+1][j][b]+1);
						value=min(value,dp[i+1][j][k]+1);
					}
					dp[i][j][k]=value;
				}
				else{
					int value;
					if(arr[i]==k){
						int b=arr[j];
						value=dp[i+1][j-1][k]+1;
						value=min(value,dp[i+1][j-1][b]+1);
						value=min(value,dp[i][j-1][k]+1);
						value=min(value,dp[i][j-1][b]+1);
						value=min(value,dp[i+1][j][k]);
						value=min(value,dp[i+1][j][b]+1);
					}
					else if(arr[j]==k){
						int b=arr[i];
						value=dp[i+1][j-1][k]+1;
						value=min(value,dp[i+1][j-1][b]+1);
						value=min(value,dp[i][j-1][k]);
						value=min(value,dp[i][j-1][b]+1);
						value=min(value,dp[i+1][j][k]+1);
						value=min(value,dp[i+1][j][b]+1);
					}
					else{
						int c=arr[i];
						int d=arr[j];
						value=dp[i+1][j-1][k]+2;
						value=min(value,dp[i+1][j-1][c]+2);
						value=min(value,dp[i+1][j-1][d]+2);
						value=min(value,dp[i][j-1][k]+1);
						value=min(value,dp[i][j-1][d]+1);
						value=min(value,dp[i][j-1][c]+2);
						value=min(value,dp[i+1][j][k]+1);
						value=min(value,dp[i+1][j][c]+1);
						value=min(value,dp[i+1][j][d]+2);
					}
					dp[i][j][k]=value;
				}
			}
		}
	}
	int rta=305;
	fore(i,0,m+1){
		rta=min(rta,dp[0][n-1][i]);
	}
	cout<<rta<<"\n";
}
