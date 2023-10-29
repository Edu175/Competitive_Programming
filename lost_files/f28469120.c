#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//char a;
// [?,~]
int main(){FIN;
	//cout<<c<<"\n";
	char a='0';
	ll res=0;
	while((ll)a>=0)cout<<a<<" "<<(int)a<<"\n",a++,res++;
	string s="?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	cout<<"\n"<<SZ(s)<<"\n";
	fore(i,0,SZ(s))cout<<s[i]<<" "<<i<<"\n";
	for(char b='?';b<='~';b++)cout<<b;
	cout<<"\n";
	cout<<(int)'?'<<" "<<(int)'~'<<": "<<'~'-'?'+1<<"\n";
	cout<<res<<"\n";
	return 0;
}
