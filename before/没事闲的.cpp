#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

struct player{ //������һ�����Ϣ 
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
player player1={500,50,{{50,65,100},{0,0,0}},{0,4,6},{"��ͨ������Ů45����55�˺�������ȴʱ�䣩","��ѣ��65�˺�����ѣ�Է�һ�غϣ���ȴʱ��3�غϣ�","���У�100�˺�����ȴʱ��5�غϣ�"},1,0};
//�����Ϣ��ʼ�� 
struct monster{ //���������Ϣ 
	int health[5];
	int attack[5];
	int skill[5];
};
monster mon={{400,600,800},{40,60,80},{60,80,100}};
//���������Ϣ��ʼ�� 
void fs(); //����Ҫ�õĺ��� 
void fight(int a);
void luck();
void levelup();
int main()
{
	cout<<"��ӭ�����ж����磬���ʵ������һ�С������ɣ���ʿ��"<<endl;
	cout<<"�����������������Ҫ����20�ַ�����";
	cin>>player1.name; //��ȡ������� 
	cout<<"��ѡ������Ա�m��f����";
	cin>>player1.sex; //���ѡ���Ա��Ա�ͬ���Բ�ͬ 
	if(player1.sex=='m'){
		player1.run=7; //�������ܸ��ʽ��ͣ���ͨ�������� 
		player1.attack[0][0]=55;
	}
	else{
		player1.run=5; //Ů�����ܸ������ӣ���ͨ�������� 
		player1.attack[0][0]=45;
	}
	printf("�¸ҵ�%s��á�\n�����ڵ�Ѫ��Ϊ%d\n����Ϊ%d\n�ȼ�Ϊ%d\n����Ϊ%d\n���ܼ���Ϊ%d\n",player1.name,player1.health,player1.shield,player1.level,player1.xp,player1.run);
	//�����һ�����Ϣ�����ܸ���Ŀǰ����֪����ôд
	luck();
	//�����¼����� 
	return 0;
}

void levelup(){ //�ȼ�����������֮����� 
	player1.level++;
	player1.health+=100; //������������ 
	player1.shield+=20;
	printf("��ĵȼ������ˣ���ǰ�ȼ�%d��",player1.level);
}
int chance=rand()%4;
void fs(int a){ //��ս��ʼ�������Ϣ 
	//����Լ��������������Ϣ 
	printf("��ļ����У�1��%s 2��%s 3��%s\n",player1.skill[0],player1.skill[1],player1.skill[2]);
	printf("�Է�Ѫ��Ϊ%d����ͨ�����˺�Ϊ%d�������˺�Ϊ%d\n",mon.health[a],mon.attack[a],mon.skill[a]);
	printf("�Ƿ�ս������Ϊ���ܣ�����y��n����");
	char choice;
	getchar(); //���⻻�з���ɳ������ 
	cin>>choice;
	if(choice=='y') fight(a);
	else{
		int ch=rand()%player1.run; //����������ж�������ܸ��ʵ�ȡ�࣬��Ϊ������Ϊ���ܳɹ� 
		if(!ch) printf("���ܳɹ���");
		else{
			printf("����ʧ�ܡ���ʼս����"); //����ֱ�ӿ�ʼս�� 
			fight(a);
		}
	}
}
void fight(int a){
	bool turn=true; //�ж��Ƿ�Ϊ��ҹ���
	int ph=player1.health; //����ظ�Ѫ��Ҫ�� 
	while(1){
		if(turn==true){
			if(player1.attack[1][1]!=0) player1.attack[1][1]--; //�ж��Ƿ�����ȴ�����ǣ���ȴ�غϼ�һ 
			if(player1.attack[1][2]!=0) player1.attack[1][2]--;
			int h;
			while(1){ //������ѡ������ȴ�ظ�ѡ��ʱ������������ȴ������ȴ�غϼ��� 
				printf("��Ҫѡ���ĸ����ܣ�1��%s 2��%s 3��%s��������ţ�\n",player1.skill[0],player1.skill[1],player1.skill[2]);
				//���ѡ���� 
				cin>>h;
				h--; 
				if(player1.attack[1][h]!=0){ //�ж���ѡ�����Ƿ�����ȴ 
					printf("���ܻ�����ȴ\n");
					continue;
				}
				else break;
			} 
			
			mon.health[a]-=player1.attack[0][h];
			if(mon.health[a]>0) printf("���%d���˺�������Ѫ����ʣ%d\n",player1.attack[0][h],mon.health[a]);
			else{
				printf("��ϲ�����˹�����Ѫ�����Զ�����\n");
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
				if(player1.health>0) printf("����ʹ������ͨ���������%d���˺������Ѫ����ʣ%d\n",mon.attack[a],player1.health);
				else{
					printf("�㱻�������ˡ����Ѫ�����Զ�����\n");
					player1.health=ph;
					break;
				}
			}
			else{
				player1.health-=mon.skill[a];
				if(player1.health>0) printf("����ʹ���˼��ܣ����%d���˺������Ѫ����ʣ%d\n",mon.skill[a],player1.health);
				else{
					printf("�㱻�������ˡ����Ѫ�����Զ�����\n");
					player1.health=ph;
					break;
				}
			}
			turn=true;
		}
	}
}
void luck(){
	char a[5][50]={"����С�֣�׼��ս����","������Ӣ�֣���С�ġ�","����Boss��Σ�գ�","������һ�����˵��ڵ��ϣ����Ƿ�Ҫ����������y��n��"};
	if(chance<=2){
		printf("%s\n",a[chance]);
		fs(chance);
	}
	else if(chance>2){
		printf("%s\n",a[chance]);
	}
}
