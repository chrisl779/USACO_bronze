#include<fstream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main() {
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");

	int n{}, m{};
	fin >> n >> m;

	vector<string> spotty, plain;

	for (int i{ 0 }; i < n; i++) { //spotty cows
		string str;
		fin >> str;
		spotty.push_back(str);
	}

	for (int i{ 0 }; i < n; i++) { //plain cows
		string str;
		fin >> str;
		plain.push_back(str);
	}

	return 0;
}