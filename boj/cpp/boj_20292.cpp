#include<iostream>
#include<string>
using namespace std;
struct operation {
	string op,m1,m2;
	
};
operation input[10000];
string temp;
int main() {
	ios::sync_with_stdio(false);
	int idx = 0;
	cin >> input[idx].op;
	while (input[idx].op[0] != 'E') {
		bool f = false;
		if (input[idx].op[0] == 'W') {
			cin >> input[idx].m1 >> temp >> input[idx].m2;
			
			
		}
		else {
			cin >> input[idx].m1;

		}
		

		
		idx++;
		cin >> input[idx].op;
	}
	int last = 0;
	for (int i = 0; i <= idx; i++) {
		bool f = false;
		if (input[i].op[0] == 'R') {
			for (int j = i - 1; j >= last; j--) {
				if (input[j].op[0] == 'W' && input[j].m2==input[i].m1) {
					f = true;
					break;
				}
			}
			if (f) {
				cout << "WAIT\n";
				last = i;
			}
			cout << input[i].op << " " << input[i].m1 << "\n";
		}
		else if (input[i].op[0] == 'W') {
			for (int j = i - 1; j >= last; j--) {
				if (input[j].op[0] == 'R' && input[j].m1 == input[i].m2) {
					f = true;
					break;
				}
				else if (input[j].op[0] == 'W') {
					if ((input[j].m1 == input[i].m2) || input[j].m2 == input[i].m1) {
						f = true;
						break;
					}
					else if (input[j].m2 == input[i].m2) {
						f = true;
						break;
					}
					else if ((input[j].m1 == input[i].m2) && (input[j].m2 == input[i].m1)) {
						f = true;
						break;
					}
				}
			}
			if (f) {
				cout << "WAIT\n";
				last = i;
			}
			cout << input[i].op << " " << input[i].m1 << " TO "<< input[i].m2 << "\n";
		}
		else {
			cout << input[i].op << "\n";
		}
		
		
	}
	return 0;
}