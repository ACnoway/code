#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct player{ //定义玩家基础信息 
	int health;
	int shield;
	int attack[2][4];
	int cooldown[10]; 
	char skill[4][100];
	int level;
	int xp;
	char name[21];
	char sex;
	int run; 
};
player player1={500,50,{{50,65,100},{0,0,0}},{0,4,6},{"普通攻击（女45，男55伤害，无冷却时间）","晕眩（65伤害，晕眩对方一回合，冷却时间3回合）","大招（100伤害，冷却时间5回合）"},1,0};
//玩家信息初始化 
struct monster{ //怪物基本信息 
	int health[5];
	int attack[5];
	int skill[5];
};
monster mon={{400,600,800},{40,60,80},{60,80,100}};
//怪物基本信息初始化 
void fs(); //声明要用的函数 
void fight(int a);
void luck();
void levelup();
int main()
{
	cout<<"欢迎来到中二世界，这里，实力就是一切。出发吧，勇士！"<<endl;
	cout<<"请输入你的姓名（不要超过20字符）：";
	cin>>player1.name; //获取玩家姓名 
	cout<<"请选择你的性别（m或f）：";
	cin>>player1.sex; //玩家选择性别，性别不同属性不同 
	if(player1.sex=='m'){
		player1.run=7; //男性逃跑概率降低，普通攻击增加 
		player1.attack[0][0]=55;
	}
	else{
		player1.run=5; //女性逃跑概率增加，普通攻击降低 
		player1.attack[0][0]=45;
	}
	printf("勇敢的%s你好。\n你现在的血量为%d\n护盾为%d\n等级为%d\n经验为%d\n逃跑几率为%d\n",player1.name,player1.health,player1.shield,player1.level,player1.xp,player1.run);
	//输出玩家基本信息，逃跑概率目前还不知道怎么写
	luck();
	//调用事件函数 
	return 0;
}

void levelup(){ //等级提升函数，之后会用 
	player1.level++;
	player1.health+=100; //各项属性增加 
	player1.shield+=20;
	printf("你的等级提升了！当前等级%d级",player1.level);
}
int chance=rand()%4;
void fs(int a){ //对战开始，输出信息 
	//输出自己和遭遇怪物的信息 
	printf("你的技能有：1、%s 2、%s 3、%s\n",player1.skill[0],player1.skill[1],player1.skill[2]);
	printf("对方血量为%d，普通攻击伤害为%d，技能伤害为%d\n",mon.health[a],mon.attack[a],mon.skill[a]);
	printf("是否战斗（否即为逃跑，输入y或n）？");
	char choice;
	getchar(); //避免换行符造成程序错误 
	cin>>choice;
	if(choice=='y') fight(a);
	else{
		int ch=rand()%player1.run; //用随机数进行对玩家逃跑概率的取余，若为零则视为逃跑成功 
		if(!ch) printf("逃跑成功！");
		else{
			printf("逃跑失败。开始战斗。"); //否则直接开始战斗 
			fight(a);
		}
	}
}
void fight(int a){
	bool turn=true; //判断是否为玩家攻击
	int ph=player1.health; //后面回复血量要用 
	while(1){
		if(turn==true){
			if(player1.attack[1][1]!=0) player1.attack[1][1]--; //判断是否在冷却，若是，冷却回合减一 
			if(player1.attack[1][2]!=0) player1.attack[1][2]--;
			int h;
			while(1){ //避免所选技能冷却重复选择时，其他正在冷却技能冷却回合减少 
				printf("你要选择哪个技能？1、%s 2、%s 3、%s（输入序号）\n",player1.skill[0],player1.skill[1],player1.skill[2]);
				//玩家选择技能 
				cin>>h;
				h--; 
				if(player1.attack[1][h]!=0){ //判断所选技能是否在冷却 
					printf("技能还在冷却\n");
					continue;
				}
				else break;
			} 
			
			mon.health[a]-=player1.attack[0][h];
			if(mon.health[a]>0) printf("造成%d点伤害，怪物血量还剩%d\n",player1.attack[0][h],mon.health[a]);
			else{
				printf("恭喜你打败了怪物！你的血量已自动回满\n");
				player1.health=ph;
				break;
			}
			if(h==1) player1.attack[1][h]=player1.cooldown[h];
			else if(h==2) player1.attack[1][h]=player1.cooldown[h];
			if(h==1) turn=true;
			else turn=false;
		}
		if(turn==false){
			int m=rand()%4;
			if(m){
				player1.health-=mon.attack[a];
				if(player1.health>0) printf("怪物使用了普通攻击，造成%d点伤害，你的血量还剩%d\n",mon.attack[a],player1.health);
				else{
					printf("你被怪物打败了。你的血量已自动回满\n");
					player1.health=ph;
					break;
				}
			}
			else{
				player1.health-=mon.skill[a];
				if(player1.health>0) printf("怪物使用了技能，造成%d点伤害，你的血量还剩%d\n",mon.skill[a],player1.health);
				else{
					printf("你被怪物打败了。你的血量已自动回满\n");
					player1.health=ph;
					break;
				}
			}
			turn=true;
		}
	}
}
void luck(){
	char a[5][50]={"遭遇小怪，准备战斗。","遭遇精英怪，请小心。","遭遇Boss，危险！","你遇到一个老人倒在地上，你是否要帮助他？（y或n）"};
	if(chance<=2){
		printf("%s\n",a[chance]);
		fs(chance);
	}
	else if(chance>2){
		printf("%s\n",a[chance]);
	}
}
