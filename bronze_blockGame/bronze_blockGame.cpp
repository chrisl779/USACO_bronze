#include <iostream>
#include<fstream>
#include<set>
#include<map>
#include<string>

using namespace std;

int main()
{
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    
    int n{ 0 };
    fin >> n;

    map<char, int> answer; // set up map
    for (char letter = 'a'; letter <= 'z'; ++letter) { // map all letters = 0 
        answer[letter] = 0;
    }

    for (int i = 0; i < n; i++) { // for every board
        string a, b;
        fin >> a >> b;

        map<char, int> acount, bcount;

        for (int ch : a) {
            acount[ch]++;
        }

        for (int ch : b) {
            bcount[ch]++;
        }

        for (char letter = 'a'; letter <= 'z'; letter++) {
            answer[letter] += max(acount[letter], bcount[letter]);
        }
    }

    for (const auto& count : answer) {
        fout << count.second << '\n';
    }
}
