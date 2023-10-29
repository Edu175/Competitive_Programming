#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

ll vis[4][16];
char a[8][8];
ll res=0,c=0,t=0;
void f(ll x, ll y){
	if(a[x][y]=='*')return;
	if(vis[0][x]||vis[1][y]||vis[2][y+x]||vis[3][y-x+7])return;
	if(c==7){res++;return;}
	//fore(i,0,c)cout<<"  "; cout<<"in "<<x<<" "<<y<<"\n";
	vis[0][x]++, vis[1][y]++, vis[2][y+x]++, vis[3][y-x+7]++;
	c++;
	fore(i,x,8)fore(j,0,8){
		if(i==x&&j<=y)continue;
		f(i,j);
	}
	vis[0][x]--, vis[1][y]--, vis[2][y+x]--, vis[3][y-x+7]--,
	c--;
	//fore(i,0,c)cout<<"  "; cout<<"out "<<x<<" "<<y<<"\n";
}
int main(){FIN;
	fore(i,0,8)fore(j,0,8)cin>>a[i][j];
	fore(i,0,8)fore(j,0,8)f(i,j);
	cout<<res<<"\n";
	return 0;
}
