//
// Created by julien on 15/10/2020.
//

#ifndef MOPSI_TOOLS_H
#define MOPSI_TOOLS_H
#include <vector>
using namespace std;

int puissance(int a, int b);
double puissance(double a, int b);
bool in(const vector<double>& v, double x);
double average(const vector<double>& v);
double average(const vector<int>& v);
double var(const vector<double>& v);

#endif //MOPSI_TOOLS_H
