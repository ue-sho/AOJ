#include<iostream>
#include<vector>
using namespace std;

int calc_area(const vector<int>& height, const int first, const int last){
	int h = height[first];
	int ret = 0;
	for(int i = first + 1; i <= last; i++){
	    ret += h - height[i];
	}
	return ret;
}

int main() {
	
    vector<char> shape;
    char c;
	while(cin >> c){
        shape.push_back(c);
	}

    int n = shape.size();
    
    vector<int> height(n+1);  
    // height[0] = 0 を基準に高さを求める
	for(int i = 1; i <= n; i++){
		switch(shape[i-1]){
		case '/':
			height[i] = height[i - 1] + 1;
			break;
		case '\\':
			height[i] = height[i - 1] - 1;
			break;
		case '_':
			height[i] = height[i - 1];
			break;
		}
	}

	// 面積を求める
    vector<int> lake_area;
    int sumArea = 0;
	for(int i = 0; i < n; i++){
        if(height[i] == height[i+1] || height[i] + 1 == height[i+1]){
            // 隣と高さが一緒か、右隣のほうが高い時
            continue;
        }
		bool islake = false;
        int idx = 0;
        for(int j = i+1; j <= n; ++j){
			if(height[i] == height[j]){
                // 湖を発見
                int area = calc_area(height, i, j);
				lake_area.push_back(area);
                sumArea += area;
				islake = true;
                idx = j;
				break;
			}
        }
        if(islake){
            i = idx - 1;
        }
	}

	cout << sumArea << endl;

	cout << lake_area.size();
	for(auto x : lake_area){
        cout << " " << x;
	}
    cout << endl;
	
	return 0;
}