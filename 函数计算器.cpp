#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const long double rtd=57.295779513082320876798154814105170332405;
const long double e=2.7182818284590452353602874713526624977572;
unsigned short stp=10;
typedef unsigned long long ull;
void SetColor(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
bool ispn(ull n){
	if(n<2) return 0;
	for(ull i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
bool iscn(ull n){
	if(n<2) return 0;
	for(ull i=2;i*i<=n;i++) if(n%i==0) return 1;
	return 0;
}
ull min(ull i,ull n){
	if(i<n) return i;
	else return n;
}
ull max(ull i,ull n){
	if(i<n) return n;
	else return i;
}
void pf(ull num){
	ull cn,np=2,ny=0,y[1000],errcnt;
	if(num<2){
		SetColor(4,0);
		cout<<"错误，值<2！\n";
	}else{
		cn=num;
		while(iscn(num)){
			for(ull p=np;p*p<=num;p++){
				if(p>3&&p%2==0) p++;
				if((num%p==0)&&(ispn(p))){
					np=p;
					num/=p;
					y[ny]=p;
					ny++;
					break;
				}
			}
		}
		if(ispn(cn)) cout<<cn<<"是质数。"; else{
			if(num!=1) y[ny]=num;
			cout<<cn<<" = ";
			for(int i=0;i<ny;i++) cout<<y[i]<<"×";
			cout<<y[ny];
		}
		cout<<endl;
	}
}
unsigned long long gcd(unsigned long long n,unsigned long long x){
	if(n>x) swap(n,x);
	if(ispn(n)&&ispn(x)) return 1; else if(x%n==0) return n; else if(n==1) return 1; else{
		while(1){
			x%=n;
			swap(n,x);
			if(ispn(n)&&ispn(x)) return 1; else if(x%n==0) return min(n,x); else if(n==1) return 1;
		}
	}
}
ull lcm(ull n,ull x){
	if(n>x) swap(n,x);
	return x/gcd(n,x)*n;
}
long double mod(long double n,long double m){
	while(n<0||n>=m) if(n<0) n+=m; else n-=m;
	return n;
}
void cb(){
	long double n,num=0;
	ull lb,b;
	cin>>n>>lb>>b;
	b=max(min(b,36),2);
	lb=max(min(lb,10),2);
	int zn=n;
	long double xn=n-zn;
	char zdig[100]={0},xdig[1000]={0};
	for(int i=0;i<100;i++){
		num+=(zn%10)*pow(lb,i);
		zn/=10;
		if(zn==0) break;
	}for(int i=1;i<100;i++){
		xn*=10;
		xn=mod(xn,10);
		num+=int(xn)/pow(lb,i)*1.0;
		if(xn==0) break;
	}
	int di,znum=num;
	long double xnum=num-znum;
	for(int i=0;i<100;i++){
		zdig[i]=znum%b+'0';
		if(zdig[i]>'9') zdig[i]+=7;
		znum/=b;
		di=i;
		if(znum==0) break;
	}for(int i=di;i>-1;i--) cout<<zdig[i];
	if(xnum!=0){
		cout<<'.';
		for(int i=0;i<1000;i++){
			if(i>stp+1) break;
			xnum*=b;
			xdig[i]=int(xnum)+'0';
			if(i==stp+1) if(xdig[stp+1]-'0'>=b/2) xdig[stp]++;
			if(xdig[i]>'9') xdig[i]+=7;
			xnum-=int(xnum);
			di=i;
			if(xnum==0) break;
		}
		for(int i=0;i<=di;i++) cout<<xdig[i];
	}
}
int main(){
	string code;
	cout<<"函数计算器 v1.7.0\n1998291 B\n"<<setprecision(10);
	while(1){
		cin>>code;
		if(code=="pf"){
			ull n;
			cin>>n;
			SetColor(2,0); 
			pf(n);
			SetColor(15,0);
		}else if(code=="gcd"){
			ull n,m;
			cin>>n>>m;
			SetColor(2,0); 
			cout<<gcd(n,m)<<endl;
			SetColor(15,0); 
		}else if(code=="lcm"){
			ull n,m;
			cin>>n>>m;
			SetColor(2,0);
			cout<<lcm(n,m)<<endl;
			SetColor(15,0);
		}else if(code=="+"){
			long double n,m;
			cin>>n>>m;
			SetColor(2,0);
			cout<<n<<'+'<<m<<'='<<n+m<<endl;
			SetColor(15,0);
		}else if(code=="-"){
			long double n,m;
			cin>>n>>m;
			SetColor(2,0);
			cout<<n<<'-'<<m<<'='<<n-m<<endl;
			SetColor(15,0);
		}else if(code=="*"){
			long double n,m;
			cin>>n>>m;
			SetColor(2,0);
			cout<<n<<"×"<<m<<'='<<n*m<<endl;
			SetColor(15,0);
		}else if(code=="/"){
			long double n,m;
			cin>>n>>m;
			SetColor(2,0);
			cout<<n<<"÷"<<m<<'='<<n/m<<endl;
			SetColor(15,0);
		}else if(code=="^"){
			long double n,m;
			cin>>n>>m;
			SetColor(2,0);
			cout<<n<<'^'<<m<<'='<<pow(n,m)<<endl;
			SetColor(15,0);
		}else if(code=="ispn"){
			ull n;
			cin>>n;
			SetColor(2,0);
			if(ispn(n)) cout<<"是。\n"; else cout<<"否。\n";
			SetColor(15,0);
		}else if(code=="cb"){
			SetColor(2,0);
			cb();
			cout<<endl;
			SetColor(15,0);
		}else if(code=="stp"){
			cin>>stp;
			stp=min(900,stp);
			SetColor(2,0);
			cout<<setprecision(stp)<<"已将精度设为"<<stp<<endl;
			SetColor(15,0);
		}else if(code=="dis"){
			long double x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			SetColor(2,0);
			cout<<pow(pow((x2-x1),2)+pow((y2-y1),2),0.5)<<endl;
			SetColor(15,0);
		}else if(code=="dsin"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"sin "<<d<<"°="<<sin(d/rtd)<<endl;
			SetColor(15,0);
		}else if(code=="dcos"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"cos "<<d<<"°="<<cos(d/rtd)<<endl;
			SetColor(15,0);
		}else if(code=="dtan"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"tan "<<d<<"°="<<tan(d/rtd)<<endl;
			SetColor(15,0);
		}else if(code=="dcot"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"cot "<<d<<"°="<<1.0/tan(d/rtd)<<endl;
			SetColor(15,0);
		}else if(code=="dsec"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"sec "<<d<<"°="<<1.0/cos(d/rtd)<<endl;
			SetColor(15,0);
		}else if(code=="dcsc"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"csc "<<d<<"°="<<1.0/sin(d/rtd)<<endl;
			SetColor(15,0);
		}else if(code=="rsin"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"sin "<<d<<"="<<sin(d)<<endl;
			SetColor(15,0);
		}else if(code=="rcos"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"cos "<<d<<"="<<cos(d)<<endl;
			SetColor(15,0);
		}else if(code=="rtan"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"tan "<<d<<"="<<tan(d)<<endl;
			SetColor(15,0);
		}else if(code=="rcot"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"cot "<<d<<"="<<1.0/tan(d)<<endl;
			SetColor(15,0);
		}else if(code=="rsec"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"sec "<<d<<"="<<1.0/cos(d)<<endl;
			SetColor(15,0);
		}else if(code=="rcsc"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"csc "<<d<<"="<<1.0/sin(d)<<endl;
			SetColor(15,0);
		}else if(code=="dasin"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arcsin "<<d<<"="<<asin(d)*rtd<<"°\n";
			SetColor(15,0);
		}else if(code=="dacos"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arccos "<<d<<"="<<acos(d)*rtd<<"°\n";
			SetColor(15,0);
		}else if(code=="datan"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arctan "<<d<<"="<<atan(d)*rtd<<"°\n";
			SetColor(15,0);
		}else if(code=="dacot"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arccot "<<d<<"="<<1.0/atan(d)*rtd<<"°\n";
			SetColor(15,0);
		}else if(code=="dasec"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arcsec "<<d<<"="<<1.0/acos(d)*rtd<<"°\n";
			SetColor(15,0);
		}else if(code=="dacsc"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arccsc "<<d<<"="<<1.0/asin(d)*rtd<<"°\n";
			SetColor(15,0);
		}else if(code=="rasin"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arcsin "<<d<<"="<<asin(d)<<endl;
			SetColor(15,0);
		}else if(code=="racos"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arccos "<<d<<"="<<acos(d)<<endl;
			SetColor(15,0);
		}else if(code=="ratan"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arctan "<<d<<"="<<atan(d)<<endl;
			SetColor(15,0);
		}else if(code=="racot"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arccot "<<d<<"="<<1.0/atan(d)<<endl;
			SetColor(15,0);
		}else if(code=="rasec"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arcsec "<<d<<"="<<1.0/acos(d)<<endl;
			SetColor(15,0);
		}else if(code=="racsc"){
			long double d;
			cin>>d;
			SetColor(2,0);
			cout<<"arccsc "<<d<<"="<<1.0/asin(d)<<endl;
			SetColor(15,0);
		}else if(code=="log"){
			long double b,n;
			cin>>b>>n;
			SetColor(2,0);
			cout<<"log "<<b<<'('<<n<<")="<<log(n)/log(b)<<endl;
			SetColor(15,0);
		}else if(code=="ln"){
			long double n;
			cin>>n;
			SetColor(2,0);
			cout<<"ln "<<n<<"="<<log(n)/log(e)<<endl;
			SetColor(15,0);
		}else if(code=="pi"){
			SetColor(2,0);
			cout<<3.14159265358979323846264338327950288<<endl;
			SetColor(15,0);
		}else{
			SetColor(4,0);
			cout<<"无效代码！\n";
			SetColor(15,0);
		}
	}return 0;
}
