//
// Created by julien on 15/10/2020.
//

#ifndef MOPSI_GLOBAL_DATA_H
#define MOPSI_GLOBAL_DATA_H
#include "Data.h"

class Global_Data {
public:
    int n_training;
    int n_testing;
    int b;
    vector<Data> training_data;
    vector<Data> testing_data;
    Global_Data(int n_training, int n_testing, const string& file_training,  const string& file_testing, int b);
    void print(int i);
    double hyper_log_log();
};


#endif //MOPSI_GLOBAL_DATA_H
