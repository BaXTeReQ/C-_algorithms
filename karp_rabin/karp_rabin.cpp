#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Karp(string finalLine, string pattern) {
    int patternHash = 0, finalLineHash = 0, d = 256, prime = 101, h = 1;

    bool flag = 1;

    size_t finalLineLength = finalLine.length();
    size_t patternLength = pattern.length();

    size_t i = 0, j = 0;

    for (i = 0; i < patternLength - 1; i++) {
        h = (h * d) % prime;
    }

    for (i = 0; i < patternLength; i++) {
        patternHash = (d * patternHash + pattern[i]) % prime;
        finalLineHash = (d * finalLineHash + finalLine[i]) % prime;
    }

    for (i = 0; i <= finalLineLength - patternLength; i++) {
        if (patternHash == finalLineHash) {
            flag = 1;
            for (j = 0; j < patternLength; j++) {
                if (finalLine[i + j] != pattern[j]) {
                    flag = 0;
                    break;
                }
            }
            if (j == patternLength) {
                cout << i << " ";
            }
        }
        if (i < finalLineLength - patternLength) {
            finalLineHash = (d * (finalLineHash - finalLine[i] * h) + finalLine[i + patternLength]) % prime;
            if (finalLineHash < 0) finalLineHash += prime;
            if (patternHash < 0) patternHash += prime;
        }
    }
}

int main()
{
    int counter = 0, testCases = 0;
    string line = "", finalLine = "", fileName = "", pattern = "";
    fstream plikIn;

    cin >> testCases;

    while (counter < testCases) {

        cin >> fileName;

        plikIn.open(fileName);
        if (plikIn.is_open()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, pattern);
            while (getline(plikIn, line)) {
                finalLine += line;
            }
            Karp(finalLine, pattern);
            cout << endl;
            counter++;
            line = "", finalLine = "", fileName = "", pattern = "";
            plikIn.close();
        }
    }
}