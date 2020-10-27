//
// Created by julien on 15/10/2020.
//

#include "Global_Data.h"

Global_Data::Global_Data(int n_training, const string& file_training, int b) {
    this->n_training = n_training;
    this->b = b;
    for (int i = 0; i < n_training; i++) {
        string end = to_string(i) + ".csv";
        training_data.emplace_back(file_training + end, b);
    }
}

void Global_Data::print(int i) {
    training_data[i].print();
}

double Global_Data::hyper_log_log() {
    int n = training_data[0].true_n();
    vector<double> alpha;
    for (Data data : training_data) {
        cout << data.hyper_log_log() << endl;
        alpha.push_back(data.hyper_log_log()/n);
    }
    double A = 1/average(alpha);
    cerr << A << endl;
    double V = 0;
    for (Data data : training_data) {
        cout << data.hyper_log_log()*A << endl;
        V += puissance(data.hyper_log_log()*A - n, 2)/(training_data.size()-1);
    }
    return sqrt(V)/n;
}
