#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const long double rtd=90/asin(1),e=2.7182818284590452353602874713526624977572,gtd=100/asin(1);
unsigned short lang=1,forgc=15,backc=0,syst=1;
typedef unsigned long long ull;
ull stp=10,mstp=10022;
void SetColor(int ForgC, int BackC){
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
string msec(){
	switch(lang){
		case 1:
			return "毫秒\n";
		case 2:
			return "ms\n";
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
				cout<<" is prime number.\n";
				break;
			}
		}else{
			if(num!=1) y[ny]=num;
			cout<<cn<<'=';
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
	if(stp>mstp){
		err();
		switch(lang){
		case 1:
			cout<<"精度>"<<mstp<<"，为防止崩溃，已自动停止此程序。\n";
			break;
		case 2:
			cout<<"Precision>"<<mstp<<", this program has been automatically stopped to prevent crashes.\n";
			break;
		}
		return;
	}
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
	if(b>36||b<2){
		warn();
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
	}
	b=max(min(b,36),2);
	int zn=n;
	long double xn=n-zn;
	char zdig[10000]={0},xdig[stp+1]={0};
	for(int i=0;i<10000;i++){
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
	for(int i=0;i<10000;i++){
		zdig[i]=znum%b+'0';
		if(zdig[i]>'9') zdig[i]+=7;
		znum/=b;
		di=i;
		if(znum==0) break;
	}
	succ();
	ull st=GetTickCount();
	bool xs=0;
	if(xnum!=0){
		xs=1;
		for(int i=0;i<stp+1;i++){
			xnum*=b;
			xdig[i]=int(xnum)+'0';
			if(i==stp) if(xdig[stp]-'0'>=b/2) xdig[stp-1]++;
			if(xdig[i]>'9') xdig[i]+=7;
			xnum-=int(xnum);
			di=i;
			if(xnum==0){
				di++;
				break;
			}
		}
	}
	if(xs){
		for(int i=stp-1;i>-1;i--){
			if(xdig[i]>=b){
				if(i>0){	
					xdig[i-1]+=int((xdig[i]-'0')/b);
					xdig[i]-='0';
					xdig[i]%=b;
					xdig[i]+='0';
				}else{
					zdig[0]+=int((xdig[i]-'0')/b);
					xdig[i]-='0';
					xdig[i]%=b;
					xdig[i]+='0';
				}
			}
		}
	}
	for(int i=di;i>-1;i--) if(zdig[i]!=0) cout<<zdig[i];
	if(xs){
		cout<<'.';
		for(int i=0;i<di;i++) cout<<xdig[i];
	}
	ull ed=GetTickCount();
	cout<<"\n>"<<ed-st<<msec();
}
long double cot(long double num){return cos(num)/sin(num);}
long double sec(long double num){return 1.0/cos(num);}
long double csc(long double num){return 1.0/sin(num);}
long double acot(long double num){return acos(num)/asin(num);}
long double asec(long double num){return 1.0/acos(num);}
long double acsc(long double num){return 1.0/asin(num);}
int main(){
	string code;
	
	cout<<"函数计算器 v1.12.0\n2043218 Bytes\n"<<setprecision(10);
	while(1){
		cin>>code;
		if(code=="pf"){
			ull n;
			cin>>n;
			ull st=GetTickCount();
			pf(n);
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="gcd"){
			ull n,m;
			cin>>n>>m;
			succ(); 
			ull st=GetTickCount();
			cout<<gcd(n,m)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc); 
		}else if(code=="lcm"){
			ull n,m;
			cin>>n>>m;
			succ();
			ull st=GetTickCount();
			cout<<lcm(n,m)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="+"){
			long double n,m;
			cin>>n>>m;
			succ();
			ull st=GetTickCount();
			cout<<n<<'+'<<m<<'='<<n+m<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="-"){
			long double n,m;
			cin>>n>>m;
			succ();
			ull st=GetTickCount();
			cout<<n<<'-'<<m<<'='<<n-m<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="*"){
			long double n,m;
			cin>>n>>m;
			succ();
			ull st=GetTickCount();
			cout<<n<<"×"<<m<<'='<<n*m<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="/"){
			long double n,m;
			cin>>n>>m;
			succ();
			ull st=GetTickCount();
			cout<<n<<"÷"<<m<<'='<<n/m<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="^"){
			long double n,m;
			cin>>n>>m;
			succ();
			ull st=GetTickCount();
			cout<<n<<'^'<<m<<'='<<pow(n,m)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
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
			SetColor(forgc,backc);
		}else if(code=="stp"){
			cin>>stp;
			if(stp>mstp){
				warn();
				switch(lang){
					case 1:
						cout<<"值>"<<mstp<<"，可能导致部分程序不可用。\n";
						break;
					case 2:
						cout<<"Value>"<<mstp<<"，may cause some programs to be unavailable.\n";
						break;
				}
			}
			succ();
			ull st=GetTickCount();
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
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="dis"){
			long double ox,oy,x,y;
			cin>>ox>>oy>>x>>y;
			succ();
			ull st=GetTickCount();
			x-=ox;
			y-=oy;
			cout<<pow(pow(x,2)+pow(y,2),0.5)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="sin"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"sin "<<d<<"°="<<sin(d/rtd)<<endl;
					break;
				case 2:
					cout<<"sin "<<d<<"="<<sin(d)<<endl;
					break;
				case 3:
					cout<<"sin "<<d<<"G="<<sin(d/gtd)<<endl;
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="cos"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"cos "<<d<<"°="<<cos(d/rtd)<<endl;
					break;
				case 2:
					cout<<"cos "<<d<<"="<<cos(d)<<endl;
					break;
				case 3:
					cout<<"cos "<<d<<"G="<<cos(d/gtd)<<endl;
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="tan"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"tan "<<d<<"°="<<tan(d/rtd)<<endl;
					break;
				case 2:
					cout<<"tan "<<d<<"="<<tan(d)<<endl;
					break;
				case 3:
					cout<<"tan "<<d<<"G="<<tan(d/gtd)<<endl;
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="cot"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"cot "<<d<<"°="<<cot(d/rtd)<<endl;
					break;
				case 2:
					cout<<"cot "<<d<<"="<<cot(d)<<endl;
					break;
				case 3:
					cout<<"cot "<<d<<"G="<<cot(d/gtd)<<endl;
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="sec"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"sec "<<d<<"°="<<sec(d/rtd)<<endl;
					break;
				case 2:
					cout<<"sec "<<d<<"="<<sec(d)<<endl;
					break;
				case 3:
					cout<<"sec "<<d<<"G="<<sec(d/gtd)<<endl;
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="csc"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"csc "<<d<<"°="<<csc(d/rtd)<<endl;
					break;
				case 2:
					cout<<"csc "<<d<<"="<<csc(d)<<endl;
					break;
				case 3:
					cout<<"csc "<<d<<"G="<<csc(d/gtd)<<endl;
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="asin"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"arcsin "<<d<<"="<<asin(d)*rtd<<"°\n";
					break;
				case 2:
					cout<<"arcsin "<<d<<"="<<asin(d)<<endl;
					break;
				case 3:
					cout<<"arcsin "<<d<<"="<<asin(d)*gtd<<"G\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="acos"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"arccos "<<d<<"="<<acos(d)*rtd<<"°\n";
					break;
				case 2:
					cout<<"arccos "<<d<<"="<<acos(d)<<endl;
					break;
				case 3:
					cout<<"arccos "<<d<<"="<<acos(d)*gtd<<"G\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="atan"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"arctan "<<d<<"="<<atan(d)*rtd<<"°\n";
					break;
				case 2:
					cout<<"arctan "<<d<<"="<<atan(d)<<endl;
					break;
				case 3:
					cout<<"arctan "<<d<<"="<<atan(d)*gtd<<"G\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="acot"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"arccot "<<d<<"="<<acot(d)*rtd<<"°\n";
					break;
				case 2:
					cout<<"arccot "<<d<<"="<<acot(d)<<endl;
					break;
				case 3:
					cout<<"arccot "<<d<<"="<<acot(d)*gtd<<"G\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="asec"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"arcsec "<<d<<"="<<asec(d)*rtd<<"°\n";
					break;
				case 2:
					cout<<"arcsec "<<d<<"="<<asec(d)<<endl;
					break;
				case 3:
					cout<<"arcsec "<<d<<"="<<asec(d)*gtd<<"G\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="acsc"){
			long double d;
			cin>>d;
			succ();
			ull st=GetTickCount();
			switch(syst){
				case 1:
					cout<<"arccsc "<<d<<"="<<acsc(d)*rtd<<"°\n";
					break;
				case 2:
					cout<<"arccsc "<<d<<"="<<acsc(d)<<endl;
					break;
				case 3:
					cout<<"arccsc "<<d<<"="<<acsc(d)*gtd<<"G\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="log"){
			long double b,n;
			cin>>b>>n;
			succ();
			ull st=GetTickCount();
			cout<<"log "<<b<<'('<<n<<")="<<log(n)/log(b)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="lg"){
			long double n;
			cin>>n;
			succ();
			ull st=GetTickCount();
			cout<<"lg "<<n<<"="<<log(n)/log(10)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="ln"){
			long double n;
			cin>>n;
			succ();
			ull st=GetTickCount();
			cout<<"ln "<<n<<"="<<log(n)/log(e)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="pi"){
			succ();
			ull st=GetTickCount();
			cout<<asin(1)*2<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="cl"){
			cout<<"1. 简体中文\n2. English\n";
			cin>>lang;
			succ();
			ull st=GetTickCount();
			switch(lang){
				case 1:
					cout<<"切换成功。\n";
					break;
				case 2:
					cout<<"Switching successful.\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
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
			ull st=GetTickCount();
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
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
				if(x2!=0&&y2>0) off2=acos(x2)*rtd;
				if(x2>0&&y2<0) off2=asin(y2)*rtd;
				if(x2<0&&y2<0) off2=0-180-asin(y2)*rtd;
				if(x2<0&&y2==0) off2=180;
				if(x2>0&&y2==0) off2=0;
				if(x2==0&&y2>0) off2=90;
				if(x2==0&&y2<0) off2=-90;
				succ();
				ull st=GetTickCount();
				if(mod(180-off1-off2,360)>180) cout<<mod(180+off1+off2,360)<<"°\n";
				else cout<<mod(180-off1-off2,360)<<"°\n";
				ull ed=GetTickCount();
				cout<<">"<<ed-st<<msec();
			}
			
			SetColor(forgc,backc);
		}else if(code=="!"){
			long double n;
			cin>>n;
			succ();
			ull st=GetTickCount();
			cout<<n<<"!="<<tgamma(n+1)<<endl;
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="sn"){
			long double num;
			cin>>num;
			succ();
			ull st=GetTickCount();
			if(num==0) cout<<"0=0E0"; else{
				cout<<num<<"=";
				bool fu;
				if(num<0){
					fu=1;
					num=fabs(num);
				}
				int dig=int(log(num)/log(10));
				long double rnum=num/pow(10,dig);
				if(rnum<1){
					rnum*=10;
					dig--;
				}
				if(fu) cout<<"-";
				cout<<rnum<<"E"<<dig<<endl;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
			SetColor(forgc,backc);
		}else if(code=="cs"){
			switch(lang){
				case 1:
					cout<<"1.角度制\n2.弧度制\n3.百分度制\n";
					break;
				case 2:
					cout<<"1.DEG\n2.RAD\n3.GRAD\n";
					break;
			}
			cin>>syst;
			succ();
			ull st=GetTickCount();
			switch(lang){
				case 1:
					cout<<"切换成功。\n";
					break;
				case 2:
					cout<<"Switching successful.\n";
					break;
			}
			ull ed=GetTickCount();
			cout<<">"<<ed-st<<msec();
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
	}
	return 0;
}
