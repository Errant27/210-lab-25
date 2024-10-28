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
    reader.open("codes.txt");    // file opened
    auto startVecRead = std::chrono::high_resolution_clock::now();    // Vector timer start
    
    while (reader) {    // while loop to add file items to the vector
        reader >> fobj;
        veec.push_back(fobj);
    }
    reader.close();
    
    auto endVecRead = std::chrono::high_resolution_clock::now();    // Vector timer stop
    auto durationVecREAD = duration_cast<std::chrono::milliseconds>(endVecRead - startVecRead);    // Vector read time calculated
    
    // List timer
    reader.open("codes.txt");    // file opened
    auto startListRead = std::chrono::high_resolution_clock::now();    // list timer start
    
    while (reader) {    // while loop to add file items to the list
        reader >> fobj;
        liis.push_back(fobj);
    }
    reader.close();
    
    auto endListRead = std::chrono::high_resolution_clock::now();    // List timer stop
    auto durationListREAD = duration_cast<std::chrono::milliseconds>(endListRead - startListRead);    // list read time calculated

    // Set timer
    reader.open("codes.txt");    // file opened
    auto startSetRead = std::chrono::high_resolution_clock::now();    // Set timer stop
    
    while (reader) {    // while loop to add file items to the set
        reader >> fobj;
        seet.insert(fobj);
    }
    reader.close();
    
    auto endSetRead = std::chrono::high_resolution_clock::now();    // Set timer stop
    auto durationSetREAD = duration_cast<std::chrono::milliseconds>(endSetRead - startSetRead);    // Set read time calculated
    
// SORTING //
    // Vector timer
    auto startVecSORT = std::chrono::high_resolution_clock::now();   // Vector timer start
   
    sort(veec.begin(), veec.end());    // Vector sorted
    
    auto endVecSORT = std::chrono::high_resolution_clock::now();    // Vector timer start
    auto durationVecSORT = duration_cast<std::chrono::milliseconds>(endVecSORT - startVecSORT);    // Vector sort time calculated

    // List timer
    auto startListSORT = std::chrono::high_resolution_clock::now();    // list timer start
    
    liis.sort();    // list sorted
    
    auto endListSORT = std::chrono::high_resolution_clock::now();    // list timer stop
    auto durationListSORT = duration_cast<std::chrono::milliseconds>(endListSORT - startListSORT);    // List read sort calculated

// INSERTING //
    // Vector timer
    auto startVecINSERT = std::chrono::high_resolution_clock::now();   // Vector timer start
    
    veec.insert(veec.begin() + veec.size()/2, "TESTCODE");    // "TESTCODE" inserted in middle of Vector
    
    auto endVecINSERT = std::chrono::high_resolution_clock::now();   // Vector timer stop
    auto durationVecINSERT = duration_cast<std::chrono::milliseconds>(endVecINSERT - startVecINSERT);    // Vector insert time calculated
    
    // List timer
    auto startListINSERT = std::chrono::high_resolution_clock::now();    // list timer start
    
    list<string>::iterator lisIT;    // list iterator to get to the middle of the list
    lisIT = liis.begin();
   
    for (int i = 0; i < liis.size()/2; i++)    //iterator moved to middle of list
        lisIT++;
    liis.insert(lisIT, "TESTCODE");    // "TESTCODE" inserted in middle of list
   
    auto endListINSERT = std::chrono::high_resolution_clock::now();    // list timer stop
    auto durationListINSERT = duration_cast<std::chrono::milliseconds>(endListINSERT - startListINSERT);    // List insert time calculated

    // Set timer
    auto startSetINSERT = std::chrono::high_resolution_clock::now();    // Set timer start
    
    set<string>::iterator setIT;    // set iterator to get to the middle of the set
    setIT = seet.begin();
    
    for (int i = 0; i < seet.size()/2; i++)    // iterator moved to middle of set
        setIT++;
    seet.insert(setIT, "TESTCODE");    // "TESTCODE" inserted in middle of set

    auto endSetINSERT = std::chrono::high_resolution_clock::now();    // set timer stop
    auto durationSetINSERT = duration_cast<std::chrono::milliseconds>(endSetINSERT - startSetINSERT);   // set insert time calculated

// DELETING //
    // Vector timer
    auto startVecDELETE = std::chrono::high_resolution_clock::now();    // Vector timer start
    
    veec.erase(veec.begin() + veec.size()/2);    // middle element of vector erased
    
    auto endVecDELETE = std::chrono::high_resolution_clock::now();    // Vector timer stop
    auto durationVecDELETE = duration_cast<std::chrono::milliseconds>(endVecDELETE - startVecDELETE);   // vector delete time calculated
    
    // List timer
    auto startListDELETE = std::chrono::high_resolution_clock::now();    // list timer start
    
    lisIT = liis.begin();    // list iterator re-initalized to beginning
    
    for (int i = 0; i < liis.size()/2; i++)    // list iterator moved to center of list
        lisIT++;
    liis.erase(lisIT);    // center element of list erased
    
    auto endListDELETE = std::chrono::high_resolution_clock::now();    // list timer stop
    auto durationListDELETE = duration_cast<std::chrono::milliseconds>(endListDELETE - startListDELETE);   // list delete time calculated
    
    // Set timer
    auto startSetDELETE = std::chrono::high_resolution_clock::now();    // set timer start
    
    setIT = seet.begin();
    
    for (int i = 0; i < seet.size()/2; i++)    // list iterator moved to center of set
        setIT++;
    seet.erase(setIT);    // center element of set erased
    
    auto endSetDELETE = std::chrono::high_resolution_clock::now();    // set timer stop
    auto durationSetDELETE = duration_cast<std::chrono::milliseconds>(endSetDELETE- startSetDELETE);   // set delete time calculated
    
// OUTPUT TIMES
    cout << setw(W1) << "Type:" << setw(W1) << "Vector" << setw(W1) << "List" << setw(W1) << "Set" << endl;    // Types outputted

    cout << setw(W1) << "Reading:" << setw(W1) << durationVecREAD.count() << setw(W1) << durationListREAD.count();    // read times outputted
    cout << setw(W1) << durationSetREAD.count() << endl;

    cout << setw(W1) << "Sorting:"  << setw(W1) << durationVecSORT.count() << setw(W1) << durationListSORT.count();    // sort times outputted
    cout << setw(W1) << -1 << endl;

    cout << setw(W1) << "Inserting:" << setw(W1) << durationVecINSERT.count() << setw(W1) << durationListINSERT.count();    // insert times outputted
    cout << setw(W1) << durationSetINSERT.count() << endl;

    cout << setw(W1) << "Deleting:" << setw(W1) << durationVecDELETE.count() << setw(W1) << durationListDELETE.count();    // delete times outputted
    cout << setw(W1) << durationSetDELETE.count() << endl;
    
    return 0;
}

