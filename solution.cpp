#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

vector<int> getSlices(int max, int types, vector<int> PizzaArr) {
	int sumMax = 0;
	int sum = 0;
	vector<int> finalSolution;
	vector<int> solution;
	for(int i = types - 1; i >= 0; i--) {
		sum = 0;
		solution.clear();
		for(int j = i; j >= 0; j--) {
			if (sum + PizzaArr[j] <= max) {
				sum = sum + PizzaArr[j];
				solution.push_back(j);
			}
		}
		if(sum > sumMax && sum <= max) {
			sumMax = sum;
			finalSolution = solution;
		}
	}
	return finalSolution;  
}

int main() {
	int max;
	int types;
	ifstream input("e_also_big.in");
	string line1;
	getline(input, line1);
	stringstream ss;
	ss << line1;
	ss >> max >> types;
	vector<int> arr;
	int temp;
	int i = 0;
	while(input && i < types) {
		input >> temp;
		arr.push_back(temp);
		i++;
	}
	vector<int> v1 = getSlices(max, types, arr);
	int size = v1.size();
	ofstream outfile("e_also_big.out");
	outfile << size << "\n";
	for(int i = 0; i < size; i++) {
		outfile << v1[i] << " ";
	}
}
