#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
typedef long long ll;
unordered_map<string, int> strToNum;
string numToStr[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
string input;
bool isUpperCase(char c) {
	return c >= 'A' && c <= 'Z';
}
bool isDigit(char c) {
	return c >= '0' && c <= '9';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> input;
	for (int i = 0; i < 10; i++) {
		strToNum[numToStr[i]] = i;
	}
	string temp = "";
	string numStr = "";
	for (int i = 0; i < input.size(); i++) {
		if (isUpperCase(input[i])) {
			temp += input[i];
		}
		else {
			if (temp != "" || i == 0 || !isUpperCase(input[i - 1])) {
				cout << "Madness!" << "\n";
				return 0;
			}
			numStr += input[i];
			
		}
		if (strToNum.count(temp) != 0) {
			numStr += strToNum[temp]+'0';
			temp = "";
		}
	}
	ll ans = 0;
	ll k = 0;
	char op = '+';
	for (int i = 0; i < numStr.size(); i++) {
		if (isDigit(numStr[i])) {
			k *= 10;
			k += (ll)numStr[i] - '0';
		}
		else {
			switch (op) {
			case '+':
				ans += k;
				break;
			case '-':
				ans -= k;
				break;
			case 'x':
				ans *= k;
				break;
			case '/':
				ans /= k;
				break;
			}
			op = numStr[i];
			k = 0;
		}
	}
	cout << numStr << "\n";
	string ansStr = to_string(ans);
	for (int i = 0; i < ansStr.size(); i++) {
		if (isDigit(ansStr[i])) {
			cout << numToStr[ansStr[i] - '0'];
		}
		else {
			cout << ansStr[i];
		}
	}

	return 0;
}