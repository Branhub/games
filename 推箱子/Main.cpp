#include<conio.h>
#include"Map.h"
#include"Person.h"
#include"init.h"
using namespace std;
int main() {
	while (1) {
		string option;
		char dir;
		cout << "choose map[1-4] and input 0 exit:";
		cin >> option;
		cin.clear();
		if (option == "0")
			break;
		system("cls");
		map<int, set<int>> corrd_target;//Ŀ�긲�ǵ�λ
		map<int, set<int>> wall;//ǽ����
		vector<pair<int, int>> Box;//����λ��
		pair<int, int> person;//�˵�����
		pair<int, int> rc;//����������
		rc=initmap(option, corrd_target, wall, Box, person);
		Map Screen(corrd_target,wall,Box, person,rc);
		Person Man(person);
		while (!Screen.iswin()) {
			cout << "     map[" << option << "]" << endl;
			Screen.print();
			dir = getch();
			if (dir == 'w' || dir == 'a' || dir == 's' || dir == 'd') {
				Screen.updateScreen();
				Man.getdirection(dir);
				Man.walk(Screen);
			}
			else if (dir == ' ')
				Man.Start_again(Screen);
			else if ('0')
				break;
			system("cls");
		}
		cout << "Pass!" << endl;
		system("pause");
	}
	cout << "Finished!" << endl;
	return 0;
}