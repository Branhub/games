#include"Person.h"
#include"Map.h"
using namespace std;
Person::Person(pair<int,int> &person) :init_corrd(person) {
	corrd = person;
}
void Person::walk(Map &screen) {
	pair<int, pair<int, int>> flag;
	pair<int, int> box;//ǰ�������ǣ����ӵ�����
	flag = forward(corrd.first,corrd.second,screen);
	switch(flag.first){
	case 1:						   //ǰ������ǰ��
		corrd=flag.second;
		screen.getPerson(*this);
		break;
	case 0:                        //ǰ��Ϊ���ӣ���Ҫ�����ж�����ǰ��
	{
		box=flag.second;		   //������λ��
		flag=forward(box.first,box.second,screen);
		switch(flag.first){
		case 1:                   //����ǰ��Ϊ��
				screen.updatabox({box,flag.second});//��������λ��
				corrd=box;        //��������
				screen.getPerson(*this);//������λ��
				break;
		default :break;//����ǰ����ǽ��������
		}
	}
	case -1:break;                //ǰ����ǽ�����ֲ���
	default :break;
	}
	
}
pair<int,pair<int,int>> Person::forward(int row,int col,Map &screen) {
	pair<int, pair<int, int>> flag;
	switch (direction) {//ǰ��λ�ã�row,col��
	case'w':row--; break;
	case's':row++; break;
	case'a':col--; break;
	case'd':col++; break;
	default:break;
	}
	switch(screen.screen[row][col]){
	case 'a':                //ǰ����ǽ
		flag={-1,{row,col}};
		break; 
	case 'b':               //ǰ��������
		flag={0 ,{row,col}};
		break;
	default:flag={1,{row,col}};break;//ǰ������ǰ��
	}
	
	return flag;
}
void Person::getdirection(char dir) {
	direction = dir;
}
void Person::Start_again(Map &screen) {
	corrd = init_corrd;
	screen.Box = screen.init_Box;
	screen.person = screen.init_person;
	screen.updateScreen();
}