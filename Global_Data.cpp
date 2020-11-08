//
// Created by julien on 15/10/2020.
//

#include "Global_Data.h"

Global_Data::Global_Data(int i0, int n_training, const string& file_training, int b) {
    this->n_training = n_training;
    this->b = b;
    for (int i = i0; i < n_training+i0; i++) {
        string end = to_string(i) + ".csv";
        training_data.emplace_back(file_training + end, b);
    }
}

void Global_Data::print(int i) {
    training_data[i].print();
}

double Global_Data::alpha_moyen_h(double a){
    int n = training_data[0].true_n();
    vector<double> alpha;
    for (Data data : training_data) {
        alpha.push_back(data.hyper_log_log(a)/n);
    }
    double A = 1/average(alpha);
    return A;
}

double Global_Data::alpha_moyen_a(double a){
    vector<double> alpha;
    for (Data data : training_data) {
        int n = data.true_n();
        double E=data.hyper_log_log(a);
        alpha.push_back(n/E);  //moyenne arithmétique sur alpha
    }
    double A = average(alpha);
    return A;
}

double Global_Data::hyper_log_log_error(double Alpha, double a){
    int n = training_data[0].true_n();
    double V = 0;
    for (Data data : training_data) {
        //cout << data.hyper_log_log(a)*A << endl;
        V += puissance(data.hyper_log_log(a)*Alpha - n, 2)/(training_data.size()-1);
    }
    return sqrt(V)/n;
}


double Global_Data::biais(double Alpha,double a){
    vector<double> E;
    int n = training_data[0].true_n();
    for( Data data: training_data){
        E.push_back(data.hyper_log_log(a)*Alpha);
        //cout<<data.hyper_log_log(a)*Alpha<<endl;
    }
    double E_barre = average(E);
    return (E_barre-n);
}

void intervalle_variance(double Alpha,double a,double& inf, double& sup,int n_global_data, int n_data){
    vector<double> V;
    for (int i=0; i<n_global_data; i++){
        Global_Data global_test = Global_Data(n_alpha+i*n_data, n_data,"Base_Donnees/Testing_Data",7);
        //cout<<n_alpha+i*n_data<<endl;
        V.push_back(global_test.hyper_log_log_error(Alpha, a));
    }
    sort(V.begin(), V.end());
    inf=V[int(0.025*n_global_data)];
    sup=V[int(0.975*n_global_data)];
};
