//
// Created by julien on 14/10/2020.
//

#ifndef MOPSI_DATA_H
#define MOPSI_DATA_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "tools.h"
using namespace std;

class Data {
public:
    vector<double> data;
    int b;
    int m;
    vector<int> rho;

    void print();
    double operator() (int i) const;
    Data(const string& file_name, int b);

    int first_nozero(double x) const;
    void compute_min();

    int interval(double x) const;

    double hyper_log_log();

    int true_n();

    bool test_Xi2();
};

int classe(double x,int k);


#endif //MOPSI_DATA_H
