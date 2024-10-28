// 210 | Lab 25 | Neil Orton
// IDE Used: Xcode
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
using namespace std;

const int W1 = 11;

int main() {
    vector<string> veec;
    list<string> liis;
    set<string> seet;
    string fobj;
    ifstream reader;
    
// READING //
    // Vector timer
    reader.open("codes.txt");
    auto startVecRead = std::chrono::high_resolution_clock::now();
    while (reader) {
        reader >> fobj;
        veec.push_back(fobj);
    }
    reader.close();
    auto endVecRead = std::chrono::high_resolution_clock::now();
    auto durationVecREAD = duration_cast<std::chrono::milliseconds>(endVecRead - startVecRead);
    
    // List timer
    reader.open("codes.txt");
    auto startListRead = std::chrono::high_resolution_clock::now();
    while (reader) {
        reader >> fobj;
        liis.push_back(fobj);
    }
    reader.close();
    auto endListRead = std::chrono::high_resolution_clock::now();
    auto durationListREAD = duration_cast<std::chrono::milliseconds>(endListRead - startListRead);

    // Set timer
    reader.open("codes.txt");
    auto startSetRead = std::chrono::high_resolution_clock::now();
    while (reader) {
        reader >> fobj;
        seet.insert(fobj);
    }
    reader.close();
    auto endSetRead = std::chrono::high_resolution_clock::now();
    auto durationSetREAD = duration_cast<std::chrono::milliseconds>(endSetRead - startSetRead);
    
// SORTING //
    // Vector timer
    auto startVecSORT = std::chrono::high_resolution_clock::now();
    sort(veec.begin(), veec.end());
    auto endVecSORT = std::chrono::high_resolution_clock::now();
    auto durationVecSORT = duration_cast<std::chrono::milliseconds>(endVecSORT - startVecSORT);

    // List timer
    auto startListSORT = std::chrono::high_resolution_clock::now();
    liis.sort();
    auto endListSORT = std::chrono::high_resolution_clock::now();
    auto durationListSORT = duration_cast<std::chrono::milliseconds>(endListSORT - startListSORT);
    
// INSERTING //
    // Vector timer
    auto startVecINSERT = std::chrono::high_resolution_clock::now();
    veec.insert(veec.begin() + veec.size()/2, "TESTCODE");
    auto endVecINSERT = std::chrono::high_resolution_clock::now();
    auto durationVecINSERT = duration_cast<std::chrono::milliseconds>(endVecINSERT - startVecINSERT);
        
    // List timer
    auto startListINSERT = std::chrono::high_resolution_clock::now();
    list<string>::iterator lisIT;
    lisIT = liis.begin();
    for (int i = 0; i < liis.size()/2; i++)
        lisIT++;
    liis.insert(lisIT, "TESTCODE");
    auto endListINSERT = std::chrono::high_resolution_clock::now();
    auto durationListINSERT = duration_cast<std::chrono::milliseconds>(endListINSERT - startListINSERT);

    // Set timer
    auto startSetINSERT = std::chrono::high_resolution_clock::now();
    set<string>::iterator setIT;
    setIT = seet.begin();
    for (int i = 0; i < seet.size()/2; i++)
        setIT++;
    seet.insert(setIT, "TESTCODE");
    auto endSetINSERT = std::chrono::high_resolution_clock::now();
    auto durationSetINSERT = duration_cast<std::chrono::milliseconds>(endSetINSERT - startSetINSERT);
    
// OUTPUT TIMES //
    cout << setw(W1) << "Type:" << setw(W1) << "Vector" << setw(W1) << "List" << setw(W1) << "Set" << endl;

    cout << setw(W1) << "Reading:" << setw(W1) << durationVecREAD.count() << setw(W1) << durationListREAD.count();
    cout << setw(W1) << durationSetREAD.count() << endl;

    cout << setw(W1) << "Sorting:"  << setw(W1) << durationVecSORT.count() << setw(W1) << durationListSORT.count();
    cout << setw(W1) << -1 << endl;
    
    cout << setw(W1) << "Inserting:" << setw(W1) << durationVecINSERT.count() << setw(W1) << durationListINSERT.count();
    cout << setw(W1) << durationSetINSERT.count() << endl;


    return 0;
}

