//
// Created by julien on 14/10/2020.
//

#ifndef MOPSI_DATA_H
#define MOPSI_DATA_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Data {
public:
    vector<double> data;
    int b;
    int m;

    void print();
    double operator() (int i) const;
    Data(string file_name, int b);
};


#endif //MOPSI_DATA_H
