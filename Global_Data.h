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
    Global_Data(int n_training, const string& file_training, int b);
    void print(int i);
    double hyper_log_log();
};


#endif //MOPSI_GLOBAL_DATA_H
