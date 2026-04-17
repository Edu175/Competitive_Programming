#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N=8, K=110;
int dp[N][N][N][N][N][N][K];

int same(int a, int b, int c, int d){
	return a==c&&b==d;
}

int checkWithKing(int x, int y, int kr, int kc){
	return max(abs(x-kr),abs(y-kc))<=1;
}

int checkWithPawn(int x, int y, int pr, int pc){
	return y-1==pc&&abs(x-pr)==1;
}

int check(int x, int y, int kr, int kc, int pr, int pc){
	return checkWithKing(x,y,kr,kc) || checkWithPawn(x,y,pr,pc);
}

int solve(int wkr, int wkc, int pr, int pc, int bkr, int bkc, int t){
	int &r=dp[wkr][wkc][pr][pc][bkr][bkc][t];
	if(r>=0)return r;
	r=0;

	if(t&1){
		if(pc==7){
			r=0;
		}
		else{
			// kill white pawn with black king
			if(checkWithKing(pr,pc,bkr,bkc) && !checkWithKing(wkr,wkc,pr,pc)){
				r=1;
			}
			
			int stale=!check(bkr,bkc,wkr,wkc,pr,pc);

			// move black king
			fore(dx,-1,2) fore(dy,-1,2){
				int x=bkr+dx, y=bkc+dy;
				if(x<0||x>=N||y<0||y>=N || (!dx&&!dy)) continue;
				if(same(x,y,pr,pc) || same(x,y,wkr,wkc)) continue;
				if(check(x,y,wkr,wkc,pr,pc)) continue;
				r|=!solve(wkr,wkc,pr,pc,x,y,t+1);
				stale=0;
			}

			// can't move the black king and it's not in check
			if(stale){
				r=1;
			}
		}
	}

	else{
		if(t==100){
			r=0;
		}
		else{

			// kill king with white pawn
			if(check(bkr,bkc,-100,-100,pr,pc)){
				r=1;
			}

			// move white pawn straight
			fore(it,1,2+(pc==1)){
				int i=pc+it;
				if(it==2 && (same(pr,i-1,wkr,wkc) || same(pr,i-1,bkr,bkc)))continue;
				if(!same(pr,i,wkr,wkc) && (!checkWithKing(pr,i,bkr,bkc) || checkWithKing(pr,i,wkr,wkc))){
					r|=!solve(wkr,wkc,pr,i,bkr,bkc,t+1);
				}
			}
			
			// move white king
			fore(dx,-1,2) fore(dy,-1,2){
				int x=wkr+dx, y=wkc+dy;
				if(x<0||x>=N||y<0||y>=N || (!dx&&!dy)) continue;
				if(same(x,y,pr,pc) || same(x,y,bkr,bkc)) continue;
				if(check(x,y,bkr,bkc,-100,-100)) continue;
				r|=!solve(x,y,pr,pc,bkr,bkc,t+1);
			}
		}
	}

	return r;
}

int main(){FIN;
	vector<int> a(6);
	fore(i,0,6) cin>>a[i];

	memset(dp,-1,sizeof(dp));

	if(solve(a[0],a[1],a[2],a[3],a[4],a[5],0)){
		cout<<"White Wins\n";
	}
	else{
		cout<<"Draw\n";
	}
}