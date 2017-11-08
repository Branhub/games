#pragma once
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include"Person.h"
using namespace std;
class Map {
	friend class Person;
public:
	Map(const map<int, set<int>>&, const map<int, set<int>>&, const vector<pair<int, int>>&, const pair<int, int>&,const pair<int,int>&);
	void updateScreen();                  //���µ�ͼ
	void print();
	bool iswin();						
private:
	const int row;                        //��������
	const int col;                        //��������
	char screen[30][30];
	const map<int, set<int>> corrd_target;//Ŀ�긲�ǵ�λ
	const map<int, set<int>> wall;        //ǽ����
	vector<pair<int,int>> Box;            //����λ��
	const vector<pair<int, int>> init_Box;//���ӳ�ʼλ��
	pair<int, int> person;                //�˵�����
	const pair<int, int> init_person;     //�˵ĳ�ʼ����;
	void updatabox(const pair<pair<int, int>, pair<int, int>>&);//��������λ�ã���һ��pairΪԭλ�ã��ڶ���pairΪ��λ��
	void getPerson(Person &);             //��ȡ������
	
};
