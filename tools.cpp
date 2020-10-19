//
// Created by julien on 15/10/2020.
//
#include "tools.h"
#include <iostream>
using namespace std;


int puissance(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

double puissance(double a, int b) {
    double p = 1;
    if (b < 0) {
        b = - b;
        a = 1/a;
    }
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

bool in(const vector<double>& v, double x) {
    for (double i : v) {
        if (i==x) {
            return true;
        }
    }
    return false;
}

double average(const vector<double>& v) {
    double S = 0;
    for (double x : v) {
        S += x/v.size();
    }
    return S;
}

double average(const vector<int>& v) {
    double S = 0;
    for (int x : v) {
        S += x;
    }
    return S/v.size();
}

double var(const vector<double>& v) {
    double S = average(v);
    double V = 0;
    for (double x : v) {
        V += puissance(x - S, 2);
    }
    return V;
}

