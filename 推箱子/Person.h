#pragma once
#include<iostream>
#include<map>
#include"Map.h"
using namespace std;
class Person {
	friend class Map;
public:
	Person(pair<int,int>&);
	void walk(Map&);
	void getdirection(char);
	void Start_again(Map&);
private:
	pair<int, int> corrd;                      //������
	const pair<int, int> init_corrd;		   //�˳�ʼ����
	char direction;                            //�ƶ�����
	pair<int, pair<int, int>> forward(int,int,Map&);//ǰ��·��
};
