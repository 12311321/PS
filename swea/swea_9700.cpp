#include<iostream>

using namespace std;
double a, b;
int T;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> a >> b;
        cout << "#" << tc;
        if ((1 - a) * b < a * (1 - b) * b) {
            cout << " YES\n";
        }
        else {
            cout << " NO\n";
        }
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}