#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;
class ChessPlate
{
public:
    void printCp();
    int judge(int array[16][16]);
    static int chess[16][16];
};
int ChessPlate::chess[16][16]={0};
void ChessPlate::printCp() //棋盘
{
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
}
int ChessPlate::judge(int array[16][16])
{
	int nBlack(1), i, j, k(0), nWhite(1), num(0), mark_1(0), mark_1b(0), mark_1w(0);//mark_反映结果，mark_2是否有5个
	//判断行
	for (i = 0;i < 16;i++)
	{
		num = mark_1 = 0;
		for (j = 0;j < 16;j++)
		{
			if (array[i][j] == 0)num++;
			if (num > 11)
			{
				mark_1 = 1;
				break;
			}
		}
		//判断是否连续
		if (mark_1 == 0)
		{
			for (k = 0;k < 15;k++)
			{
				while(1)
				{
					if (array[i][k] == 0){
                        nBlack=nWhite=1;
                        break;
					}
					else {
						if (array[i][k] != array[i][k+1]){
                            nBlack=nWhite=1;
                            break;
						}
						if (array[i][k] == array[i][k+1] && array[i][k] == 1)nBlack++;
						if (array[i][k] == array[i][k+1] && array[i][k] == 2)nWhite++;
					}
					if (nBlack == 5)mark_1b = 1;
					if (nWhite == 5)mark_1w = 1;
					break;
				}
				if (mark_1b == 1 || mark_1w == 1)break;
			}
		}
		if (mark_1b == 1 || mark_1w == 1)break;
	}
	//output result
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	//判断列
	mark_1b = mark_1w = mark_1 = num = 0;
	nBlack = nWhite = 1;
	for (j = 0;j < 16;j++)
	{
		num = mark_1=0;
		for(i = 0;i < 16;i++ )
		{
			if (array[i][j] == 0)num++;
			if (num > 11)
			{
				mark_1 = 1;
				break;
			}
		}
		//判断是否连续
		if (mark_1 == 0)
		{
			for (k = 0;k < 15;k++)
				while(1)
				{
					if (array[k][j] == 0){
                        nBlack=nWhite=1;
                        break;
					}
					else {
						if (array[k][j] != array[k+1][j]){
                            nBlack=nWhite=1;
                            break;
						}
						if (array[k][j] == array[k+1][j] && array[k][j] == 1)nBlack++;
						if (array[k][j] == array[k+1][j] && array[k][j] == 2)nWhite++;
					}
					if (nBlack == 5)mark_1b = 1;
					if (nWhite == 5)mark_1w = 1;
					break;
				}
				if (mark_1b == 1 || mark_1w == 1)break;
			}
		if (mark_1b == 1 || mark_1w == 1)break;
	}
	//output result
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	//右上
	int N(4);
	while (N <= 26)
	{
		nBlack = nWhite = 1;
		mark_1 = mark_1b = mark_1w = num = 0;
		if (N < 16) {
			j = 0;
			for (i = N;i >= 0;i--)
			{
				for (;j <=N;)
				{
					if (array[i][j] == 0)num++;
					if (num > N - 4) mark_1 = 1;
					j++;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		else {
			j= N - 15;
			for (i = 15;i >= N - 15;i--)
			{
				for (;j < 16;)
				{
					if (array[i][j] == 0)num++;
					if (num > 26 - N)mark_1 = 1;
					j++;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		if (mark_1 == 0)//存在五个及以上棋子
		{
			if (N < 16) {
				j=0;
				for (k = N;k > 0;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j++;
							nBlack=nWhite=1;
							break;
						}
						else {
							if (array[k][j] != array[k - 1][j + 1] ) {
								j++;
								nBlack=nWhite=1;
								break;
							}
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 1 )nBlack++;
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 2 )nWhite++;
						}
						if (nBlack == 5)mark_1b = 1;
						if (nWhite == 5)mark_1w = 1;
						j++;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
			else {
				j=N-15;
				for (k = 15;k >= N - 15;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j++;
							nBlack=nWhite=1;
							break;
						}
						else {
							if (array[k][j] != array[k - 1][j + 1]) {
								j++;
								nBlack=nWhite=1;
								break;
							}
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 1)nBlack++;
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 2)nWhite++;
							if (nBlack == 5)mark_1b = 1;
							if (nWhite == 5)mark_1w = 1;
						}
						j++;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
		}
		if (mark_1b == 1 || mark_1w == 1)break;
		N++;
	}
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	N = 4;//左上
	while (N <=26)
	{
		nBlack = nWhite = 1;
		num = mark_1 = mark_1b = mark_1w = 0;
		if (N < 16) {
			j = 15;
			for (i = N;i >= 0;i--)
			{
				while(1)
				{
					if (array[i][j] == 0)num++;
					if (num > N - 4) mark_1 = 1;
					j--;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		else {
			j = 30 - N;
			for (i = 15 ;i >= N - 14;i--) {
				while(1) {
					if (array[i][j] == 0)num++;
					if (num > 26 - N)mark_1 = 1;
					j--;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		if (mark_1 == 0)//存在五个以上棋子
		{
			if (N < 16) {
				j = 15;
				for (k = N;k > 0;k--)
					while(1)
					{
						if (array[k][j] == 0) {
							j--;
							nBlack=nWhite=1;
							break;
						}
						if (array[k][j] != array[k - 1][j - 1] ) { j--;
						nBlack=nWhite=1;
						break;
						}
						if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 1 )nBlack++;
						if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 2 )nWhite++;
						if (nBlack == 5)mark_1b = 1;
						if (nWhite == 5)mark_1w = 1;
						j--;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			else {
				j = 30 - N;
				for (k = 15;k >= N - 14;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j--;
							nBlack=nWhite=1;
							break;
						}
						else {
							if (array[k][j] != array[k - 1][j - 1] && j != 0) {
								j--;
								nBlack=nWhite=1;
								break;
							}
							if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 1 )nBlack++;
							if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 2 )nWhite++;
						}
						if (nBlack == 5)mark_1b = 1;
						if (nWhite == 5)mark_1w = 1;
						j--;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
		}
		N++;
		if (mark_1b == 1 || mark_1w == 1)break;
	}
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	return 0;
}
class BlackSide
{
public:
    void chessdown_1();
    void regrettimes_1();
    void displayResult_1();
    void displaySide_1();
    int controOper(int c_);
    void withdraw();
};
class WhiteSide:public BlackSide
{
private:
    static int chessNum_2;
};
static int chessNum_2=0;
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void hidden()//隐藏光标
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;//赋1为显示，赋0为隐藏
	SetConsoleCursorInfo(hOut,&cci);
}
void displaySteps(int x,int y,int z,int q,int p)
{
        hidden();
        gotoxy(154,7);
        cout<<"  \b\b"<<x;
        gotoxy(154,9);
        if(p==1){
            if(x%2!=0)cout<<"黑";
            else cout<<"白";
        }
        else{
            if(x%2!=0)cout<<"白";
            else cout<<"黑";
        }
        gotoxy(154,13);
        cout<<q;
        gotoxy(y,z);
}
void displayRegret(int x,int y,int m,int n,int p,int z)//rb,rw,pastx,pasty,times,c_
{
    gotoxy(154,15);
    if(z==1){
        if(p%2==0)cout<<y;
        else cout<<x;
    }
    else
        if(p%2==0)cout<<x;
    	else cout<<y;
    gotoxy(m,n);
}
void displayTitle(int x)
{
        gotoxy(145,3);
        cout<<" ------------";
        gotoxy(145,4);
        cout<<"| 五  子  棋 |";
        gotoxy(145,5);
        cout<<" ------------";
        gotoxy(145,7);
        cout<<"steps  : 0  步";
        gotoxy(145,9);
        cout<<"出棋方 :    方";
        gotoxy(145,11);
        cout<<"result :";
        gotoxy(136,13);
        cout<<"number of games : "<<--x<<" inning";
        gotoxy(131,15);
        cout<<"regretting chance(s) :   time(s)";
        gotoxy(149,19);
        cout<<"  game instruction";
        gotoxy(137,21);
        cout<<" -------------------------------------------";
        gotoxy(137,22);
        cout<<"|1.You can click 'w','a','s','d' to move and |";
        gotoxy(137,23);
        cout<<"|  control your direction.                   |";
        gotoxy(137,24);
        cout<<"|--------------------------------------------|";
        gotoxy(137,25);
        cout<<"|2.click 'z' to take back a move. (note: you |";
        gotoxy(137,26);
        cout<<"|  are only allowed to return to the lastest |";
        gotoxy(137,27);
        cout<<"|  step and you have only three chances to t-|";
        gotoxy(137,28);
        cout<<"|  -ake back a move)                         |";
        gotoxy(137,29);
        cout<<"|--------------------------------------------|";
        gotoxy(137,30);
        cout<<"|3.click 'e' to end and exit a game.         |";
        gotoxy(137,31);
        cout<<"|--------------------------------------------|";
        gotoxy(137,32);
        cout<<"|4.When a game was finished,you can click 'n'|";
        gotoxy(137,33);
        cout<<"|  to build a new game.                      |";
        gotoxy(137,34);
        cout<<" -------------------------------------------- ";
}
void displayResult(int x,int y,int m,int n,int z)
{
    hidden();
    if(y>=9){
        if(z==1){
            if(x==1){
                gotoxy(153,10);
                cout<<" -----------------------";
                gotoxy(153,11);
                cout<<"| game over,black win ! |";
                gotoxy(153,12);
                cout<<" -----------------------";
            }
            else if(x==2){
                gotoxy(153,10);
                cout<<" -----------------------";
                gotoxy(153,11);
                cout<<"| game over,white win ! |";
                gotoxy(153,12);
                cout<<" -----------------------";
            }
             else{
            gotoxy(153,11);
            cout<<" 对弈进行中... ...";
        }
        }
        else{
            if(x==1){
                gotoxy(153,10);
                cout<<" -----------------------";
                gotoxy(153,11);
                cout<<"| game over,white win ! |";
                gotoxy(153,12);
                cout<<" -----------------------";
            }
            else if(x==2){
                gotoxy(153,10);
                cout<<" -----------------------";
                gotoxy(153,11);
                cout<<"| game over,black win ! |";
                gotoxy(153,12);
                cout<<" -----------------------";
            }
             else{
            gotoxy(153,11);
            cout<<" 对弈进行中... ...";
        }
        }
    }
    else{
        gotoxy(153,11);
        cout<<" 对弈进行中... ...";
    }
    gotoxy(m,n);
}
int judge(int array[16][16])
{
	int nBlack(1), i, j, k(0), nWhite(1), num(0), mark_1(0), mark_1b(0), mark_1w(0);//mark_反映结果，mark_2是否有5个
	//判断行
	for (i = 0;i < 16;i++)
	{
		num = mark_1 = 0;
		for (j = 0;j < 16;j++)
		{
			if (array[i][j] == 0)num++;
			if (num > 11)
			{
				mark_1 = 1;
				break;
			}
		}
		//判断是否连续
		if (mark_1 == 0)
		{
			for (k = 0;k < 15;k++)
			{
				while(1)
				{
					if (array[i][k] == 0){
                        nBlack=nWhite=1;
                        break;
					}
					else {
						if (array[i][k] != array[i][k+1]){
                            nBlack=nWhite=1;
                            break;
						}
						if (array[i][k] == array[i][k+1] && array[i][k] == 1)nBlack++;
						if (array[i][k] == array[i][k+1] && array[i][k] == 2)nWhite++;
					}
					if (nBlack == 5)mark_1b = 1;
					if (nWhite == 5)mark_1w = 1;
					break;
				}
				if (mark_1b == 1 || mark_1w == 1)break;
			}
		}
		if (mark_1b == 1 || mark_1w == 1)break;
	}
	//output result
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	//判断列
	mark_1b = mark_1w = mark_1 = num = 0;
	nBlack = nWhite = 1;
	for (j = 0;j < 16;j++)
	{
		num = mark_1=0;
		for(i = 0;i < 16;i++ )
		{
			if (array[i][j] == 0)num++;
			if (num > 11)
			{
				mark_1 = 1;
				break;
			}
		}
		//判断是否连续
		if (mark_1 == 0)
		{
			for (k = 0;k < 15;k++)
			{
				while(1)
				{
					if (array[k][j] == 0){
                        nBlack=nWhite=1;
                        break;
					}
					else {
						if (array[k][j] != array[k+1][j]){
                            nBlack=nWhite=1;
                            break;
						}
						if (array[k][j] == array[k+1][j] && array[k][j] == 1)nBlack++;
						if (array[k][j] == array[k+1][j] && array[k][j] == 2)nWhite++;
					}
					if (nBlack == 5)mark_1b = 1;
					if (nWhite == 5)mark_1w = 1;
					break;
				}
				if (mark_1b == 1 || mark_1w == 1)break;
			}
		}
		if (mark_1b == 1 || mark_1w == 1)break;
	}
	//output result
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	//右上
	int N(4);
	while (N <= 26)
	{
		nBlack = nWhite = 1;
		mark_1 = mark_1b = mark_1w = num = 0;
		if (N < 16) {
			j = 0;
			for (i = N;i >= 0;i--)
			{
				for (;j <=N;)
				{
					if (array[i][j] == 0)num++;
					if (num > N - 4) mark_1 = 1;
					j++;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		else {
			j= N - 15;
			for (i = 15;i >= N - 15;i--)
			{
				for (;j < 16;)
				{
					if (array[i][j] == 0)num++;
					if (num > 26 - N)mark_1 = 1;
					j++;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		if (mark_1 == 0)//存在五个及以上棋子
		{
			if (N < 16) {
				j=0;
				for (k = N;k > 0;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j++;
							nBlack=nWhite=1;
							break;
						}
						else {
							if (array[k][j] != array[k - 1][j + 1] ) {
								j++;
								nBlack=nWhite=1;
								break;
							}
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 1 )nBlack++;
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 2 )nWhite++;
						}
						if (nBlack == 5)mark_1b = 1;
						if (nWhite == 5)mark_1w = 1;
						j++;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
			else {
				j=N-15;
				for (k = 15;k >= N - 15;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j++;
							nBlack=nWhite=1;
							break;
						}
						else {
							if (array[k][j] != array[k - 1][j + 1]) {
								j++;
								nBlack=nWhite=1;
								break;
							}
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 1)nBlack++;
							if (array[k][j] == array[k - 1][j + 1] && array[k][j] == 2)nWhite++;
							if (nBlack == 5)mark_1b = 1;
							if (nWhite == 5)mark_1w = 1;
						}
						j++;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
		}
		if (mark_1b == 1 || mark_1w == 1)break;
		N++;
	}
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	N = 4;//左上
	while (N <=26)
	{
		nBlack = nWhite = 1;
		num = mark_1 = mark_1b = mark_1w = 0;
		if (N < 16) {
			j = 15;
			for (i = N;i >= 0;i--)
			{
				while(1)
				{
					if (array[i][j] == 0)num++;
					if (num > N - 4) mark_1 = 1;
					j--;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		else {
			j = 30 - N;
			for (i = 15 ;i >= N - 14;i--) {
				while(1) {
					if (array[i][j] == 0)num++;
					if (num > 26 - N)mark_1 = 1;
					j--;
					break;
				}
				if (mark_1 == 1)break;
			}
		}
		if (mark_1 == 0)//存在五个以上棋子
		{
			if (N < 16) {
				j = 15;
				for (k = N;k > 0;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j--;
							nBlack=nWhite=1;
							break;
						}
						if (array[k][j] != array[k - 1][j - 1] ) { j--;
						nBlack=nWhite=1;
						break;
						}
						if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 1 )nBlack++;
						if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 2 )nWhite++;
						if (nBlack == 5)mark_1b = 1;
						if (nWhite == 5)mark_1w = 1;
						j--;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
			else {
				j = 30 - N;
				for (k = 15;k >= N - 14;k--)
				{
					while(1)
					{
						if (array[k][j] == 0) {
							j--;
							nBlack=nWhite=1;
							break;
						}
						else {
							if (array[k][j] != array[k - 1][j - 1] && j != 0) {
								j--;
								nBlack=nWhite=1;
								break;
							}
							if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 1 )nBlack++;
							if (array[k][j] == array[k - 1][j - 1] && array[k][j] == 2 )nWhite++;
						}
						if (nBlack == 5)mark_1b = 1;
						if (nWhite == 5)mark_1w = 1;
						j--;
						break;
					}
					if (mark_1b == 1 || mark_1w == 1)break;
				}
			}
		}
		N++;
		if (mark_1b == 1 || mark_1w == 1)break;
	}
	if (mark_1b == 1)return 1;
	if (mark_1w == 1)return 2;
	return 0;
}
void cancel(int x,int y,int array[16][16],int m,int n)
{
    array[m/5-10][(n-1)/2]=0;
    if(x!=m||y!=n){
        if(array[x/5-10][(y-1)/2]==0){
            cout<<" ";
            gotoxy(m,n);
            cout<<" \b@\b";
        }
        else{
            gotoxy(x+2,y);
            cout<<" ";
            gotoxy(m,n);
            cout<<" \b@\b";
        }
    }
    if(x==m&&y==n){
        cout<<"   \b\b\b@\b";
    }
}
int chesschoose()
{
    hidden();
    char a;
    gotoxy(70,15);
    cout<<" ----------------------------";
    gotoxy(70,16);
    cout<<"|Choos a side to start a game|";
    gotoxy(70,17);
    cout<<" ----------------------------";
    gotoxy(50,20);
    cout<<"Black side : ● (input 'b' to choose)";
    gotoxy(90,20);
    cout<<"White side : ○ (input 'w' to choose)";
    gotoxy(60,22);
    cout<<"Please input your choice :";
    loop1:a=getch();
    if(a=='w'){
        system("cls");
        return 2;
    }
    else if(a=='b'){
        system("cls");
        return 1;
    }
    else goto loop1;
}
int movement(int c_,int x2,int rB,int rW)
{
    int x(50),y(3),t1(0),t2(0),times(0),index,pastX,pastY,cancelIndex(0);//index上越界
    int chess[16][16]={0};
    char a;
    gotoxy(155,1);
    cout<<"copyright 2019 @ NEU reserved";
    gotoxy(x,y);
    cout<<"@\b";
    a=getch();
    while(1)
    {
        if(a=='w'||a=='s'||a=='a'||a=='d')
        {
            if(a=='w'){
                t1=chess[x/5-10][(y-1)/2];
                y-=2;
                if(y<1){
                    index=0;
                    y+=2;
                }
                else{index=1;}
            if(index==1){
                    t2=chess[x/5-10][(y-1)/2];
                    y+=2;
                    if(t1==0&&t2==0){
                        cout<<" ";
                        y-=2;
                        gotoxy(x,y);
                        cout<<"@\b";
                    }
                    if(t1==0&&t2!=0){
                        cout<<" \b";
                        x+=2;
                        y-=2;
                        gotoxy(x,y);
                        cout<<"#\b\b\b";
                        x-=2;
                    }
                    if(t1!=0&&t2==0){
                        x+=2;
                        gotoxy(x,y);
                        cout<<" ";
                        x-=2;
                        y-=2;
                        gotoxy(x,y);
                        cout<<"@\b";
                    }
                    if(t1!=0&&t2!=0){
                        x+=2;
                        gotoxy(x,y);
                        cout<<" ";
                        y-=2;
                        gotoxy(x,y);
                        cout<<"#\b\b\b";
                        x-=2;
                    }
            }
            }
            if(a=='a'){
                t1=chess[x/5-10][(y-1)/2];
                x-=5;
                if(x<50){
                    index=0;
                    x+=5;
                }
                else{index=1;}
                if(index==1){
                    t2=chess[x/5-10][(y-1)/2];
                    if(t1==0&&t2==0){
                        x+=5;
                        cout<<" \b";
                        x-=5;
                        gotoxy(x,y);
                        cout<<"@\b";
                    }
                    if(t1==0&&t2!=0){
                        x+=5;
                        cout<<" \b";
                        x-=3;
                        gotoxy(x,y);
                        x-=2;
                        cout<<"#\b\b\b";
                    }
                    if(t1!=0&&t2==0){
                        x+=7;
                        gotoxy(x,y);
                        x-=7;
                        cout<<" ";
                        gotoxy(x,y);
                        cout<<"@\b";
                    }
                    if(t1!=0&&t2!=0){
                        x+=7;
                        gotoxy(x,y);
                        cout<<" ";
                        x-=5;
                        gotoxy(x,y);
                        cout<<"#\b\b\b";
                        x-=2;
                    }
                }
            }
            if(a=='s'){
                t1=chess[x/5-10][(y-1)/2];
                y+=2;
                if(y>31){
                    index=0;
                    y-=2;
                }
                else{index=1;}
                if(index==1){
                    t2=chess[x/5-10][(y-1)/2];
                    y-=2;
                    if(t1==0&&t2==0){
                        cout<<" \b";
                        y+=2;
                        gotoxy(x,y);
                        cout<<"@\b";
                    }
                    if(t1==0&&t2!=0){
                        cout<<" \b";
                        y+=2;
                        x+=2;
                        gotoxy(x,y);
                        cout<<"#\b\b\b";
                        x-=2;
                    }
                    if(t1!=0&&t2==0){
                        x+=2;
                        gotoxy(x,y); cout<<" ";
                        x-=2;
                        y+=2;
                        gotoxy(x,y); cout<<"@\b";
                    }
                    if(t1!=0&&t2!=0){
                        x+=2;
                        gotoxy(x,y); cout<<" ";
                        y+=2;
                        gotoxy(x,y); cout<<"#\b\b\b";
                        x-=2;
                    }
                }
            }
            if(a=='d'){
                t1=chess[x/5-10][(y-1)/2];
                x+=5;
                if(x>125){
                    index=0;
                    x-=5;
                }
                else{index=1;}
                if(index==1){
                    t2=chess[x/5-10][(y-1)/2];
                    x-=5;
                    if(t1==0&&t2==0){
                        cout<<" ";
                        x+=5;
                        gotoxy(x,y); cout<<"@\b";
                    }
                    if(t1==0&&t2!=0){
                        cout<<" ";
                        x+=7;
                        gotoxy(x,y); cout<<"#\b\b\b";
                        x-=2;
                    }
                    if(t1!=0&&t2!=0){
                        x+=2;
                        gotoxy(x,y); cout<<" ";
                        x+=5;
                        gotoxy(x,y); cout<<"#\b\b\b";
                        x-=2;
                    }
                    if(t1!=0&&t2==0){
                        x+=2;
                        gotoxy(x,y); cout<<" ";
                        x+=3;
                        gotoxy(x,y); cout<<"@\b";
                    }
                }
            }
            }
            if(a=='j'&&judge(chess)==0){
                cancelIndex=1;
                if(chess[x/5-10][(y-1)/2]==1||chess[x/5-10][(y-1)/2]==2)
                {
                    index=0;
                }
                else{index=1;}
                if(index==1){
                    if(c_==1){
                        if(times==0||times%2==0){
                        cout<<"●#\b\b";
                        chess[x/5-10][(y-1)/2]=1;
                        }
                        if(times==1||times%2!=0){
                            cout<<"○#\b\b";
                            chess[x/5-10][(y-1)/2]=2;
                        }
                    }
                    else{
                        if(times==0||times%2==0){
                        cout<<"○#\b\b";
                        chess[x/5-10][(y-1)/2]=1;
                        }
                        if(times==1||times%2!=0){
                            cout<<"●#\b\b";
                            chess[x/5-10][(y-1)/2]=2;
                        }
                    }
                    times++;
                }
                displaySteps(times,x,y,x2,c_);
                displayResult(judge(chess),times,x,y,c_);
                displayRegret(rB,rW,x,y,times,c_);
                //displayRS(times,rB,rW,c_);
                pastX=x;
                pastY=y;
        }
        if(a=='e')exit(1);
        a=getch();
        if(a=='z'&& cancelIndex==1&&judge(chess)==0){
                if(times%2==0){
                    if(rW>0)
                    {
                        cancel(x,y,chess,pastX,pastY);
                        times--;
                        cancelIndex--;
                        if(c_==1) rW--;
                        else      rB--;
                        x=pastX; y=pastY;
                        displaySteps(times,x,y,x2,c_);
                        displayRegret(rB,rW,pastX,pastY,times,c_);
                    }
                }
                else{
                    if(rB>0)
                    {
                        cancel(x,y,chess,pastX,pastY);
                        times--;
                        cancelIndex--;
                        if(c_==1)rB--;
                        else rW--;
                        x=pastX;
                        y=pastY;
                        displaySteps(times,x,y,x2,c_);
                        displayRegret(rB,rW,pastX,pastY,times,c_);
                    }
                }
        }
        if(a=='n'&&judge(chess)!=0){
            system("cls");
            gotoxy(70,15);
            for(int i=0;i<2;i++){
                cout<<"preparing a new game for you,loading...";
                Sleep(500);
                cout<<" ...";
                Sleep(500);
                cout<<"\b\b\b   ";
                gotoxy(70,15);
            }
            system("cls"); gotoxy(0,0);
            return 1;
        }
        if(a=='r'){
            system("cls"); return 1;
            }
    }
    return 0;
}
void chessPlate()
{
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
    cout<<"\t\t\t\t\t\t|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |"<<endl;
    cout<<"\t\t\t\t\t\t ------------------------------------------------------------------------------- "<<endl;
}
int Register()
{
    char a;
    int b;
    while(1)
{


    cout<<"\t\t\t\t                                                                                            q              q       q"<<endl;
    cout<<"\t\t\t\t    wwwwwwwwwwwwwwwwwwwwwww                          zzzzzzzzzz                             q              q        q"<<endl;
    cout<<"\t\t\t\t              w                                              z                              q              q        q"<<endl;
    cout<<"\t\t\t\t             w                                              z                          qqqqqqqqqq       qqqqqqqqqqqqqqqq"<<endl;
    cout<<"\t\t\t\t            w                                              z                               qqq             q        q"<<endl;
    cout<<"\t\t\t\t           w                                 zzzzzzzzzzzzzzzzzzzzzzzzzzzz                 q q q            qqqqqqqqqq"<<endl;
    cout<<"\t\t\t\t      wwwwwwwwwwwwwwwwww                                    z                            q  q  q           q        q"<<endl;
    cout<<"\t\t\t\t          w         w                                        z                          q   q   q          qqqqqqqqqq"<<endl;
    cout<<"\t\t\t\t         w         w                                         z                         q    q    q         q        q"<<endl;
    cout<<"\t\t\t\t        w         w                                    z    z                         q     q     q   qqqqqqqqqqqqqqqqqqqqq"<<endl;
    cout<<"\t\t\t\t       w         w                                      z  z                                q              q        q   "<<endl;
    cout<<"\t\t\t\tzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz                         z                                  q             q          q    "<<endl;
    cout<<"\t\t\t\t                                                                                            q            q            q         \n\n\n\n\n\n\n\n\n\n "<<endl;
    cout<<"\t\t\t\t                                             **************************"<<endl;
    cout<<"\t\t\t\t                                             *          Start         *"<<endl;
    cout<<"\t\t\t\t                                             **************************\n\n\n"<<endl;
    cout<<"\t\t\t\t                                             **************************"<<endl;
    cout<<"\t\t\t\t                                             *          Rules         *"<<endl;
    cout<<"\t\t\t\t                                             **************************\n\n\n"<<endl;
    cout<<"\t\t\t\t                You can press 'a' to start or 's' to check the rules :";
    a=getch();
    system("cls");
    if(a=='a')
        {
            gotoxy(70,20);
            cout<<"Please enter password:";
            cin>>b;
            if(b==123456)
                return 0;
            else
                cout<<"\n                                                  Password input error\n";
                cout<<"                                                    press any key to return";
        a=getch();
        system("cls");
        }
    if(a=='s')
       {
        cout<<"\n\n\n\n    \t\t\t\t\t\t\t\t\t\t    game instruction";
        gotoxy(70,11);
        cout<<" -------------------------------------------";
        gotoxy(70,12);
        cout<<"|1.You can click 'w','a','s','d' to move and |";
        gotoxy(70,13);
        cout<<"|  control your direction.                   |";
        gotoxy(70,14);
        cout<<"|--------------------------------------------|";
        gotoxy(70,15);
        cout<<"|2.click 'z' to take back a move. (note: you |";
        gotoxy(70,16);
        cout<<"|  are only allowed to return to the lastest |";
        gotoxy(70,17);
        cout<<"|  step and you have only three chances to t-|";
        gotoxy(70,18);
        cout<<"|  -ake back a move)                         |";
        gotoxy(70,19);
        cout<<"|--------------------------------------------|";
        gotoxy(70,20);
        cout<<"|3.click 'e' to end and exit a game.         |";
        gotoxy(70,21);
        cout<<"|--------------------------------------------|";
        gotoxy(70,22);
        cout<<"|4.When a game was finished,you can click 'n'|";
        gotoxy(70,23);
        cout<<"|  to build a new game.                      |";
        gotoxy(70,24);
        cout<<" -------------------------------------------- \n\n\n\n\n\n\n\n";
        cout<<"                                                    press any key to return";
        a=getch();
        system("cls");
       }
}
}
int main()
{
    system("color F0");
    Register();
    int times(1),regretB(3),regretW(3);
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	hidden();
    loop:int color=chesschoose();
    gotoxy(0,0);
    displayTitle(times);
    gotoxy(0,0);
 	chessPlate();
    if(movement(color,times,regretB,regretW)==1){
        times++;
        goto loop;
    }
    return 0;
}

