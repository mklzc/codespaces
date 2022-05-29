#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	vector<int>input = { 1, 5, 2, 1, 3, 2, 5 };
	sort(input.begin() + 2, input.begin() + 5);
	for (int i : input)
		cout << i << " ";	
}
