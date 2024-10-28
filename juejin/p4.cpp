#include <iostream>
#include <string>

using namespace std;

std::string solution(std::string dna_sequence) {
    // Please write your code here
    int n = dna_sequence.size();
    string doubledDNA = dna_sequence + dna_sequence;
    int minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (doubledDNA.substr(i, n) < doubledDNA.substr(minIndex, n)) {
            minIndex = i;
        }
    }

    return doubledDNA.substr(minIndex, n);
}

int main() {
    // You can add more test cases here
    std::cout << (solution("ATCA") == "AATC") << std::endl;
    std::cout << (solution("CGAGTC") == "AGTCCG") << std::endl;
    std::cout << (solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") == "AGGCTGAGTCCATCTCCAGTAGTCATGGAGTGCTCCTGG")
              << std::endl;
    return 0;
}