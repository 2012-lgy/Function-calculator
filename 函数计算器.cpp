#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const long double rtd=57.295779513082320876798154814105170332405;
const long double e=2.7182818284590452353602874713526624977572;
unsigned short stp=10,lang=1,forgc=15,backc=0;
typedef unsigned long long ull;
void SetColor(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void err(){
	SetColor(4,0);
	switch(lang){
		case 1:
			cout<<"[错误]";
			break;
		case 2:
			cout<<"[Error]";
			break;
	}
}
void prom(){
	SetColor(1,0);
	switch(lang){
		case 1:
			cout<<"[提示]";
			break;
		case 2:
			cout<<"[Prompt]";
			break;
	}
}
void warn(){
	SetColor(6,0);
	switch(lang){
		case 1:
			cout<<"[警告]";
			break;
		case 2:
			cout<<"[Warning]";
			break;
	}
}
void succ(){
	SetColor(2,0);
	switch(lang){
		case 1:
			cout<<"[成功运行]";
			break;
		case 2:
			cout<<"[Successful completion]";
			break;
	}
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
	ull cn,np=2,ny=0,y[1000];
	if(num<2){
		err();
		switch(lang){
			case 1:
				cout<<"值<2！\n";
				break;
			case 2:
				cout<<"Value<2！\n";
				break;
		}
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
		succ();
		if(ispn(cn)){
			switch(lang){
			case 1:
				cout<<cn<<"是质数。\n"; 
				break;
			case 2:
				cout<<" is prime number\n";
				break;
			}
		}else{
			if(num!=1) y[ny]=num;
			cout<<cn<<" = ";
			for(int i=0;i<ny;i++) cout<<y[i]<<"×";
			cout<<y[ny];
		}
		cout<<endl;
	}
}
ull gcd(ull n,ull x){
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
	long long lb,b;
	cin>>n>>lb;
	if(lb>10||lb<1) warn();
	switch(lang){
		case 1:
			if(lb>10) cout<<"值>10，已将值转为10。\n";
			if(lb<1) cout<<"值<1，已将值转为1。\n";
			break;
		case 2:
			if(lb>10) cout<<"Value>10，The value has been converted to 10.\n";
			if(lb<1) cout<<"Value<1，The value has been converted to 1.\n";
			break;
	}
	lb=max(min(lb,10),1);
	cin>>b;
	if(b>36||b<2) warn();
	switch(lang){
		case 1:
			if(b>36) cout<<"值>36，已将值转为36。\n";
			if(b<2) cout<<"值<2，已将值转为2。\n";
			break;
		case 2:
			if(b>36) cout<<"Value>36，The value has been converted to 36.\n";
			if(b<2) cout<<"Value<2，The value has been converted to 2.\n";
			break;
	}
	b=max(min(b,36),2);
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
	}
	succ();
	for(int i=di;i>-1;i--) cout<<zdig[i];
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
	cout<<"函数计算器 v1.9.0\n2008719 B\n"<<setprecision(10);
	while(1){
		cin>>code;
		if(code=="pf"){
			ull n;
			cin>>n;
			pf(n);
			SetColor(forgc,backc);
		}else if(code=="gcd"){
			ull n,m;
			cin>>n>>m;
			succ(); 
			cout<<gcd(n,m)<<endl;
			SetColor(forgc,backc); 
		}else if(code=="lcm"){
			ull n,m;
			cin>>n>>m;
			succ();
			cout<<lcm(n,m)<<endl;
			SetColor(forgc,backc);
		}else if(code=="+"){
			long double n,m;
			cin>>n>>m;
			succ();
			cout<<n<<'+'<<m<<'='<<n+m<<endl;
			SetColor(forgc,backc);
		}else if(code=="-"){
			long double n,m;
			cin>>n>>m;
			succ();
			cout<<n<<'-'<<m<<'='<<n-m<<endl;
			SetColor(forgc,backc);
		}else if(code=="*"){
			long double n,m;
			cin>>n>>m;
			succ();
			cout<<n<<"×"<<m<<'='<<n*m<<endl;
			SetColor(forgc,backc);
		}else if(code=="/"){
			long double n,m;
			cin>>n>>m;
			succ();
			cout<<n<<"÷"<<m<<'='<<n/m<<endl;
			SetColor(forgc,backc);
		}else if(code=="^"){
			long double n,m;
			cin>>n>>m;
			succ();
			cout<<n<<'^'<<m<<'='<<pow(n,m)<<endl;
			SetColor(forgc,backc);
		}else if(code=="ispn"){
			ull n;
			cin>>n;
			succ();
			switch(lang){
				case 1:
					if(ispn(n)) cout<<"是。\n"; else cout<<"否。\n";
					break;
				case 2:
					if(ispn(n)) cout<<"True.\n"; else cout<<"False.\n";
					break;
			}
			
			SetColor(forgc,backc);
		}else if(code=="cb"){
			cb();
			cout<<endl;
			SetColor(forgc,backc);
		}else if(code=="stp"){
			cin>>stp;
			stp=min(900,stp);
			succ();
			cout<<setprecision(stp);
			switch(lang){
				case 1:
					cout<<"已将精度设为";
					break;
				case 2:
					cout<<"Precision has been set to ";
					break;
			}
			cout<<stp<<endl;
			SetColor(forgc,backc);
		}else if(code=="dis"){
			long double ox,oy,x,y;
			cin>>ox>>oy>>x>>y;
			succ();
			x-=ox;
			y-=oy;
			cout<<pow(pow(x,2)+pow(y,2),0.5)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dsin"){
			long double d;
			cin>>d;
			succ();
			cout<<"sin "<<d<<"°="<<sin(d/rtd)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dcos"){
			long double d;
			cin>>d;
			succ();
			cout<<"cos "<<d<<"°="<<cos(d/rtd)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dtan"){
			long double d;
			cin>>d;
			succ();
			cout<<"tan "<<d<<"°="<<tan(d/rtd)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dcot"){
			long double d;
			cin>>d;
			succ();
			cout<<"cot "<<d<<"°="<<1.0/tan(d/rtd)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dsec"){
			long double d;
			cin>>d;
			succ();
			cout<<"sec "<<d<<"°="<<1.0/cos(d/rtd)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dcsc"){
			long double d;
			cin>>d;
			succ();
			cout<<"csc "<<d<<"°="<<1.0/sin(d/rtd)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rsin"){
			long double d;
			cin>>d;
			succ();
			cout<<"sin "<<d<<"="<<sin(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rcos"){
			long double d;
			cin>>d;
			succ();
			cout<<"cos "<<d<<"="<<cos(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rtan"){
			long double d;
			cin>>d;
			succ();
			cout<<"tan "<<d<<"="<<tan(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rcot"){
			long double d;
			cin>>d;
			succ();
			cout<<"cot "<<d<<"="<<1.0/tan(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rsec"){
			long double d;
			cin>>d;
			succ();
			cout<<"sec "<<d<<"="<<1.0/cos(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rcsc"){
			long double d;
			cin>>d;
			succ();
			cout<<"csc "<<d<<"="<<1.0/sin(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="dasin"){
			long double d;
			cin>>d;
			succ();
			cout<<"arcsin "<<d<<"="<<asin(d)*rtd<<"°\n";
			SetColor(forgc,backc);
		}else if(code=="dacos"){
			long double d;
			cin>>d;
			succ();
			cout<<"arccos "<<d<<"="<<acos(d)*rtd<<"°\n";
			SetColor(forgc,backc);
		}else if(code=="datan"){
			long double d;
			cin>>d;
			succ();
			cout<<"arctan "<<d<<"="<<atan(d)*rtd<<"°\n";
			SetColor(forgc,backc);
		}else if(code=="dacot"){
			long double d;
			cin>>d;
			succ();
			cout<<"arccot "<<d<<"="<<1.0/atan(d)*rtd<<"°\n";
			SetColor(forgc,backc);
		}else if(code=="dasec"){
			long double d;
			cin>>d;
			succ();
			cout<<"arcsec "<<d<<"="<<1.0/acos(d)*rtd<<"°\n";
			SetColor(forgc,backc);
		}else if(code=="dacsc"){
			long double d;
			cin>>d;
			succ();
			cout<<"arccsc "<<d<<"="<<1.0/asin(d)*rtd<<"°\n";
			SetColor(forgc,backc);
		}else if(code=="rasin"){
			long double d;
			cin>>d;
			succ();
			cout<<"arcsin "<<d<<"="<<asin(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="racos"){
			long double d;
			cin>>d;
			succ();
			cout<<"arccos "<<d<<"="<<acos(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="ratan"){
			long double d;
			cin>>d;
			succ();
			cout<<"arctan "<<d<<"="<<atan(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="racot"){
			long double d;
			cin>>d;
			succ();
			cout<<"arccot "<<d<<"="<<1.0/atan(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="rasec"){
			long double d;
			cin>>d;
			succ();
			cout<<"arcsec "<<d<<"="<<1.0/acos(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="racsc"){
			long double d;
			cin>>d;
			succ();
			cout<<"arccsc "<<d<<"="<<1.0/asin(d)<<endl;
			SetColor(forgc,backc);
		}else if(code=="log"){
			long double b,n;
			cin>>b>>n;
			succ();
			cout<<"log "<<b<<'('<<n<<")="<<log(n)/log(b)<<endl;
			SetColor(forgc,backc);
		}else if(code=="lg"){
			long double n;
			cin>>n;
			succ();
			cout<<"lg "<<n<<"="<<log(n)/log(10)<<endl;
			SetColor(forgc,backc);
		}else if(code=="ln"){
			long double n;
			cin>>n;
			succ();
			cout<<"ln "<<n<<"="<<log(n)/log(e)<<endl;
			SetColor(forgc,backc);
		}else if(code=="pi"){
			succ();
			cout<<3.14159265358979323846264338327950288<<endl;
			SetColor(forgc,backc);
		}else if(code=="cl"){
			cout<<"1. 简体中文\n2. English\n";
			cin>>lang;
			succ();
			switch(lang){
				case 1:
					cout<<"切换成功。\n";
					break;
				case 2:
					cout<<"Switching successful.\n";
					break;
			}
				SetColor(forgc,backc);
		}else if(code=="cc"){
			int lforgc=forgc,lbackc=backc;
			cin>>forgc>>backc;
			if(lforgc==forgc&&lbackc==backc){
				prom();
				switch(lang){
					case 1:
						cout<<"现颜色与改变前相同。\n";
						break;
					case 2:
						cout<<"The current color is the same as before the change.\n";
						break;
				}
			}
			succ();
			SetColor(forgc,backc);
			cout<<"测试test1234567890.abcdefghijklmnopqrstuvwxyz\n";
		}else if(code=="deg"){
			long double ox,oy,x1,y1,x2,y2,off1,off2,ans=180;
			bool canout=1;
			cin>>ox>>oy>>x1>>y1>>x2>>y2;
			x1-=ox;
			x2-=ox;
			y1-=oy;
			y2-=oy;
			if(x1==0&&y1==0){
				err();
				canout=0;
				switch(lang){
					case 1:
						cout<<"点1与原点重合，无法计算角度。\n";
						break;
					case 2:
						cout<<"Point 1 coincides with the origin and cannot calculate the angle.\n";
						break;
				}
			}
			if(x2==0&&y2==0){
				err();
				canout=0;
				switch(lang){
					case 1:
						cout<<"点2与原点重合，无法计算角度。\n";
						break;
					case 2:
						cout<<"Point 2 coincides with the origin and cannot calculate the angle.\n";
						break;
				}
			}
			if(canout){
				long double p1=pow(pow(x1,2)+pow(y1,2),0.5);
				x1/=p1;
				y1/=p1;
				long double p2=pow(pow(x2,2)+pow(y2,2),0.5);
				x2/=p2;
				y2/=p2;
				if(x1<0&&y1>0) off1=asin(y1)*rtd;
				if(x1>0&&y1>0) off1=acos(0-x1)*rtd;
				if(x1>0&&y1<0) off1=180-asin(y1)*rtd;
				if(x1<0&&y1<0) off1=180-acos(x1)*rtd;
				if(x1<0&&y1==0) off1=0;
				if(x1>0&&y1==0) off1=180;
				if(x1==0&&y1>0) off1=90;
				if(x1==0&&y1<0) off1=-90;
				if(x2<0&&y2>0) off2=acos(x2)*rtd;
				if(x2>0&&y2>0) off2=acos(x2)*rtd;
				if(x2>0&&y2<0) off2=asin(y2)*rtd;
				if(x2<0&&y2<0) off2=0-180-asin(y2)*rtd;
				if(x2<0&&y2==0) off2=180;
				if(x2>0&&y2==0) off2=0;
				if(x2==0&&y2>0) off2=90;
				if(x2==0&&y2<0) off2=-90;
				succ();
				if((180-off1-off2)>180) cout<<180+off1+off2<<"°\n";
				else cout<<180-off1-off2<<"°\n";
			}
			SetColor(forgc,backc);
		}else{
			err();
			switch(lang){
				case 1:
					cout<<"无效代码。\n";
					break;
				case 2:
					cout<<"Invalid code.\n";
					break;
			}
			SetColor(forgc,backc);
		}
	}return 0;
}
