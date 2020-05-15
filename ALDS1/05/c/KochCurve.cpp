#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

void koch_curve(const int n, const pair<double, double>& begin, const pair<double, double>& end){
    if(n == 0){
        return;
    }
    // 各点の計算
    pair<double, double> p1, p2, p3;
    p1.first = (2.0 * begin.first + end.first) / 3;
    p1.second = (2.0 * begin.second + end.second) / 3;
    p3.first = (begin.first + 2.0 * end.first) / 3;
    p3.second = (begin.second + 2.0 * end.second) / 3;
    p2.first = (p3.first - p1.first) * cos(M_PI / 3) - (p3.second - p1.second) * sin(M_PI / 3) + p1.first;
    p2.second = (p3.first - p1.first) * sin(M_PI / 3) + (p3.second - p1.second) * cos(M_PI / 3) + p1.second;

    koch_curve(n - 1, begin, p1);
    cout << p1.first << " " << p1.second << endl;
    koch_curve(n - 1, p1, p2);
    cout << p2.first << " " << p2.second << endl;
    koch_curve(n - 1, p2, p3);
    cout << p3.first << " " << p3.second << endl;
    koch_curve(n - 1, p3, end);
}

int main(){

    int n;
    cin >> n;

    cout << fixed << setprecision(10);
    pair<double, double> begin = {0.0, 0.0};
    pair<double, double> end = {100.0, 0.0};

    cout << begin.first << " " << begin.second << endl;
    koch_curve(n, begin, end);
    cout << end.first << " " << end.second << endl;

    return 0;
}