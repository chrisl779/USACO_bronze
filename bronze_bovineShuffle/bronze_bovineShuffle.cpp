#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;

    vector<int> shuffleTemp(n);
    for (int i = 0; i < n; i++) { // read in shuffle template
        fin >> shuffleTemp[i];
        shuffleTemp[i]--; // convert to 0-based index
    }

    vector<int> finalOrder(n);
    for (int i = 0; i < n; i++) { // read in final order
        fin >> finalOrder[i];
    }

    vector<int> inverseShuffleTemp(n);
    for (int i = 0; i < n; i++) {
        inverseShuffleTemp[shuffleTemp[i]] = i; // compute reverse permutation
    }

    vector<int> currentOrder = finalOrder;

    for (int i = 0; i < 3; i++) {
        vector<int> tempOrder(n); // initialize with size n
        for (int j = 0; j < n; j++) {
            tempOrder[inverseShuffleTemp[j]] = currentOrder[j]; // apply reverse shuffle
        }
        currentOrder = tempOrder; // update currentOrder
    }

    for (int i = 0; i < n; ++i) {
        fout << currentOrder[i] << endl; // output the initial order
    }

    return 0;
}
