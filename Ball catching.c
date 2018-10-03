#include<stdio.h>
#include<conio.h>
#include<windows.h>
int x,y=0,temp;
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int map[60][60],mx,my,def[60][60],d1=30,d2=58,score,life=10;
char ch;
void ScoreBoard(){
	gotoxy(70,10);
	printf("score>>%d",score);
	gotoxy(70,13);
	printf("Life>>%d",life);
	if(life==0){
		gotoxy(20,15);
		printf("You loose!!!Lost all your life");
		gotoxy(30,40);
		exit(0);
	}
}
void ground(){
  for(my=0;my<=60;my++){
  	for(mx=0;mx<=60;mx++){
  		if(mx==0||mx==60||my==0||my==60){
  			printf("|");
		  }
		  else{
		  	if(mx==d1&&my==d2){
		  		printf("|^|");
			  }
			  else{
			  printf(" ");	
			  }
		  }
	  }
	  printf("\n");
  }
}
void controls(){
	if(kbhit()){
		ch=getch();
			switch(ch){
				case 'a':{
					printf("\a");
					d1--;
					break;
				}
				case 's':{
					printf("\a");
					d1++;
					break;
				}
				case 'z':{
					printf("\a");
					d1++;
					d1++;
					break;
				}
				case 'w':{
					printf("\a");
					d1--;
					d1--;
					break;
				}
			}
		
	}
}
void results(){
	if(x==d1&&y==d2){
		printf("\a\a");
	    score++;
	}

}
void delay(int t){
    int c;
   for(c=0;c<=t;c++){

   }
}

void move(){
    srand(time(NULL));
    temp=rand()%60+1;
 for(y=0;y<=58;y++){
    system("cls");
    ground();
    controls();
    ScoreBoard();
    x=temp;
    gotoxy(x,2);
    printf("#^#");
    gotoxy(x,y);
    printf("* *");
    results();
    delay(30000000);
  }
  if(x!=d1||y==58){
  	printf("\a");
  life--;	
  }
}
int main(){
    while(1){
     move();
    }
  return 0;
}
