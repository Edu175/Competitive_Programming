#include<bits/stdc++.h>

using namespace std;

int main(){
	float a,b,c;
	cin>>a>>b>>c;
	cout<<(-b+sqrt(b*b-4*a*c))/(2*a)<<"\n";
	cout<<(-b-sqrt(b*b-4*a*c))/(2*a)<<"\n";
	return 0;
}
