#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fill(Card *const deck,const char *face[],const char *suit[]);    				 
void shuffle(Card *const deck);		
int math(int i,Card *const deck);                                                                    //由牌面算出点数							  				

int main()
{
	Card deck[52];
	const char *face[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	const char *suit[]={"红桃","方块","黑桃","梅花"};
	printf("********欢迎来到澳门首家线上赌场********\n");
	printf("规则：两位玩家进行21点游戏，每一局游戏结束后，获胜玩家将会获得与点数相同的分数\n"); 
	int pla=0,plb=0;                                                                //两位玩家的分数
moregame:	printf("********   新的一盘游戏开始了   ********\n"); 
	while (1) {
		int turn=1;                               									//回合数 
		int i=1;																	//第i张牌 
		int scorea=0,scoreb=0;
		printf("当前两位玩家得分分别为：%d %d\n\n",pla,plb);
		printf("turn 1:\n\n");
		srand(time(0));
		fill(deck,face,suit);														//生成牌堆 
		shuffle(deck);																//洗牌 
		if (turn==1) {
			printf("玩家A获得的牌为：%s%s\n",deck[i].suit,deck[i].face);
			scorea+=math(i,deck);
			i++;
			printf("玩家B获得的牌为：%s%s\n",deck[i].suit,deck[i].face);
			scoreb+=math(i,deck);
			i++;
		}
		while (1) {
			
			int fla=0,flb=0;                                                        //判断玩家是否放弃本轮摸牌
			turn++;
			printf("turn %d:\n",turn);
			printf("本轮玩家A是否摸牌：请输入1（摸）或0（不摸）\n"); 
			scanf("%d",&fla);
			while (fla!=0 && fla!=1) {
				printf("输入错误，请重新输入：\n");
				scanf("%d",&fla);
			}
			if (fla==1) {
				printf("玩家A获得的牌为：%s%s\n",deck[i].suit,deck[i].face);
				scorea+=math(i,deck);
				i++;
				if (scorea>21) goto final;
			}
			if (fla==0) {
				printf("玩家A放弃本轮摸牌\n");
				fla=1;
			}
			printf("本轮玩家B是否摸牌：请输入1（摸）或0（不摸）\n"); 
			scanf("%d",&flb);
			while (flb!=0 && flb!=1) {
				printf("输入错误，请重新输入：\n");
				scanf("%d",&flb);
			}
			if (flb==1) {
				printf("玩家B获得的牌为：%s%s\n",deck[i].suit,deck[i].face);
				scoreb+=math(i,deck);
				i++;
				if (scoreb>21) goto final;
			}
			if (flb==0) {
				printf("玩家B放弃本轮摸牌\n");
				flb=1;
			}
		}
		while (0) {
			final:if (scorea>21) {
				printf("player B win!!!player B got %d scores\n",scoreb);
				plb+=scoreb;
			}
			if (scoreb>21) {
				printf("player A win!!!player A got %d socres\n",scorea);
				pla+=scorea;
			}
			printf("是否开启新一轮游戏？请输入1/0:");
			int newgame=1;
			scanf("%d",&newgame);
			if (newgame!=0 && newgame!=1) {
				printf("error!请重新输入：");
				scanf("%d",&newgame);
			}
			if (newgame==0) goto exit;
			if (newgame==1) goto moregame;
		} 
	}
	exit:printf("游戏最终结束！玩家A和玩家B分别获得%d:%d的分数\n",pla,plb);
	if (pla>plb) printf("player A win!!!\n");
	if (pla<plb) printf("player B win!!!\n");
	if (pla==plb) printf("no one win!!!\n");
																
	return 0; 
}

void fill(Card *const deck,const char *face[],const char *suit[])
{
	int i;
	for (i=0;i<52;i++) {
		deck[i].face=face[i%13];
		deck[i].suit=suit[i/13];
	}
}

void shuffle (Card *const deck)
{
	int i,j;
	Card temp;
	for (i=0;i<52;i++) {
		j=rand()%52;
		temp=deck[i];
		deck[i]=deck[j];
		deck[j]=temp;		
	}
}

int math(int i,Card *const deck)
{
	int ans;
	switch (deck[i].face[0]) {
		case 'A':ans=11; break;
		case '2':ans=2; break;
		case '3':ans=3; break;
		case '4':ans=4; break;
		case '5':ans=5; break;
		case '6':ans=6; break;
		case '7':ans=7; break;
		case '8':ans=8; break;
		case '9':ans=9; break;
		case '1':ans=10; break;
		case 'J':ans=10; break;
		case 'Q':ans=10; break;
		case 'K':ans=10; break;
	}
	
	return ans;
}

