// 分からなかったので他の人の回答を見た
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

double OptimalBSTree(const vector<double>& p, const vector<double>& q, const int n){
    vector<vector<double>> psum(n, vector<double>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j++){
			if(i == 0){
				psum[j][j] = p[j];
			}
			else{
				psum[j][j + i] = psum[j][j + i - 1] + p[j + i];
			}
		}
	}
	vector<vector<double>> qsum(n + 1, vector<double>(n + 1));
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < n + 1 - i; j++){
			if(i == 0){
				qsum[j][j] = q[j];
			}
			else{
				qsum[j][j + i] = qsum[j][j + i - 1] + q[j + i];
			}
		}
	}

	double et = 0.0;
	vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < n + 1 - i; j++){
			if(i == 0){
				dp[j][j] = q[j];
			}
			else{
				double min;
				for (int k = 0; k < i; k++){
					et = dp[j][j + k] + dp[j + k + 1][j + i] + psum[j][i + j - 1] + qsum[j][i + j];
					if (k == 0 || et < min) min = et;
				}
				dp[j][j + i] = min;
			}
		}
	}
	return dp[0][n];
}

int main(){
	int n;
	cin >> n;
    // n 個の各キーに対して探索が起きる確率 p
    // n+1 個の各ダミーキーで探索が終わる確率 q
	vector<double> p(n), q(n + 1);
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < n + 1; i++){
        cin >> q[i];
	}

    cout << fixed << setprecision(4) << OptimalBSTree(p, q, n) << endl;

	return 0;
}