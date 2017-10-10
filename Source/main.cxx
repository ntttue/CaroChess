#include "graphics.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>                  
#include <ctype.h>    
using namespace std;
#define MAX 100
int LuotDi=1,ToaDoOX=0,ToaDoOY=0,tempx,tempy,THANG[2][5];
char BanCo[MAX][MAX],NuocDi;
void KhoiTaoBanCo(char a[][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]='.';
}
int kiemtracot(char a[][MAX],int n,int i,int j,char x)
{
	int start=j,end=j,dem=1,k;
	for(k=1;;k++)					//qua trái
	{
		if(j<k) break;
		if(a[i][j-k]==a[i][j]) {dem++;start=j-k;}
		else break;
	}	
	for(k=1;;k++)					//qua phải
	{
		if(j+k>=n) break;
		if(a[i][j+k]==a[i][j]) {dem++;end=j+k;}
		else break;	
	}
	if(dem==5)
	{
		if(x=='X')
		{
			if(a[i][start-1]=='O' && a[i][end+1]=='O')
				return 0;
			else
			{
				int temp=start;
				for(int t=0;t<5;t++)
				{
					THANG[1][t]=temp;
					THANG[0][t]=i;
					temp++;
				}
				return 1;
			}
		}
		if(x=='O')
		{
			if(a[i][start-1]=='X' && a[i][end+1]=='X')
				return 0;
			else
			{
				int temp=start;
				for(int t=0;t<5;t++)
				{
					THANG[1][t]=temp;
					THANG[0][t]=i;
					temp++;
				}
				return 1;
			}
		}
	}
	return 0;
}
int kiemtradong(char a[][MAX],int n,int i,int j,char x)
{
	int start=i,end=i,k,dem=1;
	for(k=1;;k++)					//đi lên
	{
		if(i<k) break;
		if(a[i-k][j]==a[i][j]) {dem++;start=i-k;}
		else break;
	}
	for(k=1;;k++)					//đi xuống
	{
		if(i+k>=n) break;
		if(a[i+k][j]==a[i][j]) {dem++;end=i+k;}
		else break;
	}
	if(dem==5)
	{
		if(x=='X')
		{
			if(a[start-1][j]=='O' && a[end+1][j]=='O')
				return 0;
			else
			{
				int temp=start;
				for(int t=0;t<5;t++)
				{
					THANG[0][t]=temp;
					THANG[1][t]=j;
					temp++;
				}
				return 1;
			}
		}
		if(x=='O')
		{
			if(a[start-1][j]=='X' && a[end+1][j]=='X')
				return 0;
			else
			{
				int temp=start;
				for(int t=0;t<5;t++)
				{
					THANG[0][t]=temp;
					THANG[1][t]=j;
					temp++;
				}
				return 1;
			}
		}
	}
	return 0;
}
int kiemtracheochinh(char a[][MAX],int n,int i,int j,char x)
{
	int starti=i,startj=j,endi=i,endj=j,k,dem=1;
	for(k=1;;k++)			//chéo chính lên trái
	{
		if(j<k || i<k) break;
		if(a[i-k][j-k]==a[i][j]) {dem++;starti=i-k;startj=j-k;}	
		else break;
	}
	for(k=1;;k++)			//chéo chính xuống phải
	{
		if(j+k>=n || i+k>=n) break;
		if(a[i+k][j+k]==a[i][j]) {dem++;endi=i+k;endj=j+k;}
		else break;
	}
	if(dem==5)
	{
		if(x=='X')
		{
			if(a[starti-1][startj-1]=='O' && a[endi+1][endj+1]=='O')
				return 0;
			else
			{
				int temp1=starti;
				int temp2=startj;
				for(int t=0;t<5;t++)
				{
					THANG[0][t]=temp1;
					THANG[1][t]=temp2;
					temp1++;
					temp2++;
				}
				return 1;
			}
		}
		if(x=='O')
		{
			if(a[starti-1][startj-1]=='X' && a[endi+1][endj+1]=='X')
				return 0;
			else
			{
				int temp1=starti;
				int temp2=startj;
				for(int t=0;t<5;t++)
				{
					THANG[0][t]=temp1;
					THANG[1][t]=temp2;
					temp1++;
					temp2++;
				}
				return 1;
			}
		}
	}
	return 0;
}
int kiemtracheophu(char a[][MAX],int n,int i,int j,char x)
{
	int starti=i,startj=j,endi=i,endj=j,k,dem=1;
	for(k=1;;k++)			//chéo phụ lên phải
	{
		if(j+k>=n || i<k) break;
		if(a[i-k][j+k]==a[i][j]) {dem++;starti=i-k;startj=j+k;}	
		else break;
	}
	for(k=1;;k++)			//chéo phụ xuống trái
	{
		if(i+k>=n || j<k) break;
		if(a[i+k][j-k]==a[i][j]) {dem++;endi=i+k;endj=j-k;}
		else break;
	}
	if(dem==5)
	{
		if(x=='X')
		{
			if(a[starti-1][startj+1]=='O' && a[endi+1][endj-1]=='O')
				return 0;
			else
			{
				int temp1=starti;
				int temp2=startj;
				for(int t=0;t<5;t++)
				{
					THANG[0][t]=temp1;
					THANG[1][t]=temp2;
					temp1++;
					temp2--;
				}
				return 1;
			}
		}
		if(x=='O')
		{
			if(a[starti-1][startj+1]=='X' && a[endi+1][endj-1]=='X')
				return 0;
			else
			{
				int temp1=starti;
				int temp2=startj;
				for(int t=0;t<5;t++)
				{
					THANG[0][t]=temp1;
					THANG[1][t]=temp2;
					temp1++;
					temp2--;
				}
				return 1;
			}
		}
	}
	return 0;
}
int DieuKienXuatKyTu(char a[][MAX],int i,int j)
{
	if(a[i][j]=='.')
		return 1;
	return 0;
}
int player(char a[][MAX],int n,int i,int j,char x)
{
	if(kiemtradong(a,n,i,j,x)==1 || kiemtracot(a,n,i,j,x)==1 || kiemtracheochinh(a,n,i,j,x)==1 || kiemtracheophu(a,n,i,j,x)==1) 
		return 1;
	return 0;
}
int DieuKienXuat(int x,int y);
void Help();
void MoDau();
void CauNoi(int x,int y);
void Next(int x,int y);
void GiaoDienBanCo();
void DoiToaDo(int i,int j,int &x,int &y);
void DoiSoO(int &i,int &j,int x,int y);
void NewGame();
void VeBanCo();
void LuotDiTiepTuc(int x,int y);
	int APIENTRY WinMain
		( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	initwindow(780,740,"Microsoft Caro");
	MoDau();
	registermousehandler(WM_LBUTTONDOWN,Next);
	for(;;) 
	{
		delay(10);
	}
}
void savegame(char a[][MAX])
{
	FILE *save=fopen("savecaro.dat","wt");
	fprintf(save,"%d",LuotDi);
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
			fprintf(save,"%c",a[i][j]);
		fprintf(save,"\n");
	}
	fclose(save);
}
void loadgame(char a[][MAX])
{
	FILE *load=fopen("savecaro.dat","rt");
	if(load==NULL) NewGame();
	else
	{
		fscanf(load,"%d",&LuotDi);
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
				fscanf(load,"%c ",&a[i][j]);
		fclose(load);
	}
}
void Help()
{
	cleardevice();
	setcolor(9);
	settextstyle(10,4,5);
	moveto(500,50);
	outtext("LUAT CHOI");
	setcolor(8);
	settextstyle(10,4,2);
	moveto(580,80);
	outtext("Hai ben se lan luot di va chi thang khi:");
	moveto(731,110);
	outtext("+ Mot ben xep dung 5 quan tren mot hang (cot, duong cheo).");
	moveto(320,140);
	outtext("+ Khong bi chan hai dau.");
	setcolor(9);
	settextstyle(10,4,5);
	moveto(580,190);
	outtext("HUONG DAN CHOI");
	setcolor(8);
	settextstyle(10,4,2);
	moveto(400,220);
	outtext("1/ Cac chuc nang trong Menu:");
	moveto(350,250);
	outtext("+ New game: Choi moi.");
	moveto(676,280);
	outtext("+ Load game: Tai lai van choi truoc da luu (neu co),");
	moveto(609,310);
	outtext("neu khong se tao van choi moi.");
	moveto(438,340);
	outtext("+ Quit game: Thoat khoi game.");
	moveto(416,370);
	outtext("2/ Cac chuc nang trong ban co:");
	moveto(640,400);
	outtext("+ Click vao cac o tren man hinh de chon o danh.");
	moveto(449,430);
	outtext("+ Undo de quay lai buoc vua di.");
	moveto(451,460);
	outtext("+ Save de luu lai van dang choi.");
	moveto(368,490);
	outtext("+ New de choi lai tu dau.");
	moveto(789,520);
	outtext("+ Quit de tro lai menu (khong save, van dang choi bi huy bo).");
	setcolor(12);
	settextstyle(10,4,3);
	ellipse(100,600,20,20,60,30);
	outtextxy(133,610,"Back");
	settextstyle(10,4,1);
	setcolor(15);
	outtextxy(740,670,"Microsoft Caro 2013");
	outtextxy(740,690,"Version 1.0");
	outtextxy(740,710,"© 2013 Microsoft Corporation");
	outtextxy(740,730,"All rights reserved");
	registermousehandler(WM_LBUTTONDOWN,CauNoi);
}
void MoDau()
{
	settextstyle(10,4,6);
	setcolor(14);
	outtextxy(750,125,"Welcome Game Caro !!!");
	settextstyle(10,4,6);
	setcolor(11);
	outtextxy(510,200,"Main Menu");
	setcolor(12);
	settextstyle(10,4,5);
	rectangle(150,250,550,300);
	outtextxy(465,298,"New game");
	rectangle(150,350,550,400);
	outtextxy(475,398,"Load game");
	rectangle(150,450,550,500);
	outtextxy(390,498,"Help");
	rectangle(150,550,550,600);
	outtextxy(467,598,"Quit game");
	settextstyle(10,4,1);
	setcolor(15);
	outtextxy(740,670,"Microsoft Caro 2013");
	outtextxy(740,690,"Version 1.0");
	outtextxy(740,710,"© 2013 Microsoft Corporation");
	outtextxy(740,730,"All rights reserved");
	registermousehandler(WM_LBUTTONDOWN,Next);
}
void CauNoi(int x,int y)
{
	if(x>=40 && x<=160 && y>=580 && y<=630)
	{
		cleardevice();
		MoDau();
	}
}
void Next(int x,int y)
{
	if(x>=150 && x<=550 && y>=250 && y<=300)
	{
		cleardevice();
		GiaoDienBanCo();
		KhoiTaoBanCo(BanCo,20);
		registermousehandler(WM_LBUTTONDOWN,LuotDiTiepTuc);
	}
	if(x>=150 && x<=550 && y>=350 && y<=400)
	{
		loadgame(BanCo);
		VeBanCo();
		registermousehandler(WM_LBUTTONDOWN,LuotDiTiepTuc);
	}
	if(x>=150 && x<=550 && y>=450 && y<=500)
		Help();
	if(x>=150 && x<=550 && y>=550 && y<=600)
		exit(0);
}
void GiaoDienBanCo()
{
	int top=50,left=50;
	int width=30,height=30;
	int xlocation=0,ylocation=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			setcolor(8);
			xlocation=width*j;
			ylocation=height*i;
			rectangle(xlocation+top,ylocation+left,xlocation+width+top,ylocation+height+left);
			setfillstyle(1,3);
		}
	}
	setcolor(12);
	rectangle(680,195,760,225);
	settextstyle(10,4,2);
	outtextxy(751,222,"Undo");
	setcolor(11);
	setfillstyle(SOLID_FILL,5);
	rectangle(680,235,760,267);
	outtextxy(748,263,"Save");
	setcolor(14);
	rectangle(680,280,760,308);
	outtextxy(743,305,"New");
	setcolor(15);
	rectangle(680,322,760,350);
	outtextxy(743,347,"Quit");
	setcolor(15);
	settextstyle(10,4,1);
	outtextxy(740,670,"Microsoft Caro 2013");
	outtextxy(740,690,"Version 1.0");
	outtextxy(740,710,"© 2013 Microsoft Corporation");
	outtextxy(740,730,"All rights reserved");
}
int DieuKienXuat(int x,int y)
{
	if(x>=50 && x<=20*30+50 && y>=50 && y<=20*30+50)
		return 1;
	return 0;
}
void DoiToaDo(int i,int j,int &x,int &y)
{
	x=(i*30+50)+25;
	y=(j*30+50)+28;
}
void DoiSoO(int &i,int &j,int x,int y)
{
	i=(x-50)/30;
	j=(y-50)/30;
}
void NewGame()
{
	cleardevice();
	GiaoDienBanCo();
	KhoiTaoBanCo(BanCo,20);
	LuotDi=1;
}
void VeBanCo()
{
	cleardevice();
	GiaoDienBanCo();
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
		{
			if(BanCo[i][j]=='X')
			{
				int x,y;
				DoiToaDo(i,j,x,y);
				setcolor(12);
				settextstyle(10,4,3);
				outtextxy(x,y,"X");
			}
			if(BanCo[i][j]=='O')
			{
				int x,y;
				DoiToaDo(i,j,x,y);
				setcolor(10);
				settextstyle(10,4,3);
				outtextxy(x,y,"O");
			}
		}
}
void LuotDiTiepTuc(int x,int y)
{ 
	DoiSoO(ToaDoOX,ToaDoOY,x,y);
	if(DieuKienXuat(x,y)==1 && DieuKienXuatKyTu(BanCo,ToaDoOX,ToaDoOY)==1)
	{
		if(LuotDi==1)
		{
			tempx=ToaDoOX;
			tempy=ToaDoOY;
			BanCo[ToaDoOX][ToaDoOY]='X';
			VeBanCo();
			setcolor(14);
			rectangle((x-50)/30*30+50,(y-50)/30*30+50,(x-50)/30*30+50+30,(y-50)/30*30+50+30);
			if(player(BanCo,21,ToaDoOX,ToaDoOY,'X')==1)
			{
				int temp=0;
				while(temp<5)
				{
					setcolor(14);
					settextstyle(10,4,3);
					rectangle(THANG[0][temp]*30+50,THANG[1][temp]*30+50,THANG[0][temp]*30+50+30,THANG[1][temp]*30+50+30);
					temp++;
				}
				setcolor(12);
				settextstyle(10,4,8);
				outtextxy(390,740,"WIN");
				LuotDi=-1;
			}
			else LuotDi=0;
		}
		if(LuotDi==0)
		{
			tempx=ToaDoOX;
			tempy=ToaDoOY;
			if(DieuKienXuatKyTu(BanCo,ToaDoOX,ToaDoOY)==1)
			{
				BanCo[ToaDoOX][ToaDoOY]='O';
				VeBanCo();
				setcolor(14);
				rectangle((x-50)/30*30+50,(y-50)/30*30+50,(x-50)/30*30+50+30,(y-50)/30*30+50+30);
				if(player(BanCo,21,ToaDoOX,ToaDoOY,'O')==1)
				{
					int temp=0;
					while(temp<5)
					{
						setcolor(14);
						settextstyle(10,4,3);
						rectangle(THANG[0][temp]*30+50,THANG[1][temp]*30+50,THANG[0][temp]*30+50+30,THANG[1][temp]*30+50+30);
						temp++;
					}
					setcolor(10);
					settextstyle(10,4,8);
					outtextxy(390,740,"WIN");
					LuotDi=-1;
				}
				else LuotDi=1;
			}
		}
	}
	if(x>=680 && x<=760 && y>=260 && y<=308)
		NewGame();
	if(x>=680 && x<=740 && y>=195 && y<=225 && LuotDi!=-1)
	{
		BanCo[tempx][tempy]='.';
		VeBanCo();
		LuotDi=abs(LuotDi-1);
	}
	if(x>=680 && x<=740 && y>=235 && y<=267&& LuotDi!=-1)
	{
		savegame(BanCo);
		setcolor(12);
		settextstyle(10,4,7);
		outtextxy(430,720,"Saved !!!");
	}
	if(x>=680 && x<=740 && y>=322 && y<=350)
	{
		cleardevice();
		MoDau();
	}
}