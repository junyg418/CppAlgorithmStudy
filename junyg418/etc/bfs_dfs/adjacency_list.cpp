// 1차

#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// int DFS(){
	
// }
std::string to_string(const std::vector<int>& vec) {
  std::stringstream ss;
  for (int i : vec) {
    ss << i << " ";
  }
  return ss.str();
}

int main(){
	vector<int> arr[100];
	int n;
	cin >> n;
	int temp, var;
	for (int i=0; i<n; i++){
		cin >> temp >> var;
		arr[temp].push_back(var);
	}
	for (auto &k : arr){
		cout << to_string(k) << endl;
	}
}