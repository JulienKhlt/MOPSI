//
// Created by julien on 15/10/2020.
//

#ifndef MOPSI_GLOBAL_DATA_H
#define MOPSI_GLOBAL_DATA_H
#include "Data.h"

class Global_Data {
public:
    int n_training;
    int n_alpha;
    int b;
    double x;
    double Alpha;
    vector<Data> training_data;
    vector<Data> alpha_data;
    Global_Data(int n_training, int n_alpha, const string& file_alpha, const string& file_training, int b, double x);
    Global_Data(int i0, int n_training, double Alpha, const string& file_training, int b, double x);
    void print(int i);
    void alpha_moyen_h(double a);
    void alpha_moyen_a(double a);

    double hyper_log_log_error(double a);

    double biais(double a);

    void intervalle_variance_emp(double a, int n_global_data, int n_data);
    void intervalle_variance_ana(double a, int n_global_data, int n_data);
    double variance_asymptotique(double a);

    void histogram_data(double a, const string &file_name);

    void estimateur_better(double a, double b, int n_global_data, int n_data);
};

#endif //MOPSI_GLOBAL_DATA_H
