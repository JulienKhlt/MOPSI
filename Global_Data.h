//
// Created by julien on 15/10/2020.
//

#ifndef MOPSI_GLOBAL_DATA_H
#define MOPSI_GLOBAL_DATA_H
#include "Data.h"

class Global_Data {
public:
    int n_training;
    int b;
    vector<Data> training_data;
    Global_Data(int i0, int n_training, const string& file_training, int b);
    void print(int i);

    //travail avec des moyenne avec f de la forme x**a

    double alpha_moyen_h(double a);
    double alpha_moyen_a(double a);
    double hyper_log_log_error(double Alpha,double a);
    double biais(double Alpha,double a);
    void test_variance_theorique(double& inf, double& sup,double a,double Alpha);

    //travail avec des moyenne avec f inversible quelconque

    double alpha_moyen_h_f();
    double hyper_log_log_error_f(double Alpha);
    double biais_f(double Alpha);
};

const int n_alpha=100; //nombre de fichiers pour determiner alpha

void intervalle_variance(double Alpha, double a, double& inf, double& sup, int n_global_data, int n_data);
void intervalle_variance_f(double Alpha, double& inf, double& sup, int n_global_data, int n_data);

#endif //MOPSI_GLOBAL_DATA_H
