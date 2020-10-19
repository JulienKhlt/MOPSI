//
// Created by julien on 15/10/2020.
//

#include "Global_Data.h"

Global_Data::Global_Data(int n_training, int n_testing, const string& file_training,  const string& file_testing, int b) {
    this->n_training = n_training;
    this->n_testing = n_testing;
    this->b = b;
    for (int i = 0; i < n_training; i++) {
        string end = to_string(i) + ".csv";
        training_data.emplace_back(file_training + end, b);
    }
    for (int i = 0; i < n_testing; i++) {
        string end = to_string(i) + ".csv";
        testing_data.emplace_back(file_testing + end, b);
    }
}

void Global_Data::print(int i) {
    training_data[i].print();
}

double Global_Data::hyper_log_log() {
    vector<double> alpha;
    for (Data data : training_data) {
        alpha.push_back(data.true_n()/data.hyper_log_log());
    }
    double A = average(alpha);
    vector<double> n_vector;
    for (Data data : testing_data) {
        /*cout << data.hyper_log_log() << endl;
        cout << data.true_n() << endl;*/
        n_vector.push_back(A*data.hyper_log_log()-data.true_n());
    }
    for (double i : n_vector) {
        cout << i << endl;
    }
    return average(n_vector);
}
