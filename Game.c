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

int main()
{
	Card deck[52];
	const char *face[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	const char *suit[]={"红桃","方块","黑桃","梅花"};
	srand(time(NULL));
	fill(deck,face,suit);
	shuffle(deck);
	int i;
	for (i=0;i<52;i++) {
		printf("%s%s\n",deck[i].suit,deck[i].face);
	}
	
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
