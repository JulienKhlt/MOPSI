//
// Created by julien on 15/10/2020.
//

#include "Global_Data.h"

double momentum(vector<double> E, int p) {
    double S = 0;
    for (auto e : E) {
        S += pow(e, p);
    }
    return S;
}

Global_Data::Global_Data(int n_training, int n_alpha, const string& file_alpha, const string& file_training, int b, double x) {
    this->n_training = n_training;
    this->n_alpha = n_alpha;
    this->b = b;
    this->x = x;
    for (int i = 0; i < n_training; i++) {
        string end = to_string(i) + ".csv";
        training_data.emplace_back(file_training + end, b, x);
    }

    for (int i = 0; i < n_alpha; i++) {
        string end = to_string(i) + ".csv";
        alpha_data.emplace_back(file_alpha + end, b, x);
    }
}

Global_Data::Global_Data(int i0, int n_training, double Alpha, const string& file_training, int b, double x) {
    this->n_training = n_training;
    this->b = b;
    this->x = x;
    this->Alpha = Alpha;
    for (int i = i0; i < n_training+i0; i++) {
        string end = to_string(i) + ".csv";
        training_data.emplace_back(file_training + end, b, x);
    }
}

void Global_Data::print(int i) {
    training_data[i].print();
}

void Global_Data::alpha_moyen_h(double a){
    int n = alpha_data[0].true_n();
    vector<double> alpha;
    for (Data data : alpha_data) {
        alpha.push_back(data.hyper_log_log(a)/n);
    }
    Alpha = 1/average(alpha);
}

void Global_Data::alpha_moyen_a(double a){
    vector<double> alpha;
    for (Data data : alpha_data) {
        int n = data.true_n();
        double E = data.hyper_log_log(a);
        alpha.push_back(n/E);  //moyenne arithmétique sur alpha
    }
    Alpha = average(alpha);
}

double Global_Data::hyper_log_log_error(double a){
    int n = training_data[0].true_n();
    double V = 0;
    for (Data data : training_data) {
        //cout << data.hyper_log_log(a)*Alpha << endl;
        V += puissance(data.hyper_log_log(a)*Alpha - n, 2)/(training_data.size()-1);
    }
    return sqrt(V)/n;
}


double Global_Data::biais(double a){
    vector<double> E;
    int n = training_data[0].true_n();
    for( Data data: training_data){
        E.push_back(data.hyper_log_log(a)*Alpha);
        //cout<<data.hyper_log_log(a)*Alpha<<endl;
    }
    double E_barre = average(E);
    return (E_barre-n);
}

void Global_Data::intervalle_variance_emp(double a, int n_global_data, int n_data) {
    alpha_moyen_h(a);
    cout << Alpha << endl;

    vector<double> V;

    for (int i = 0; i < n_global_data; i++){
        Global_Data global_test = Global_Data(i*n_data, n_data, Alpha, "Base_Donnees/Data", 7, x);
        V.push_back(global_test.hyper_log_log_error(a));
    }
    sort(V.begin(), V.end());
    cout<<"intervalle de confiance :["<<V[int(0.025*n_global_data)]<<";"<<V[int(0.975*n_global_data)]<<"]"<<endl;
}

void Global_Data::estimateur_better(double a, double b, int n_global_data, int n_data) {
    alpha_moyen_h(b);
    cout << Alpha << endl;
    double Alpha2 = Alpha;
    alpha_moyen_h(a);
    cout << Alpha << endl;
    double A, B;


    for (int i = 0; i < n_global_data; i++) {
        Global_Data global_testA = Global_Data(i * n_data, n_data, Alpha, "Base_Donnees/Data", 7, x);
        Global_Data global_testB = Global_Data(i * n_data, n_data, Alpha2, "Base_Donnees/Data", 7, x);

        A = (global_testA.hyper_log_log_error(a));
        B = (global_testB.hyper_log_log_error(b));

        cout << "pour a = " << a << " et x = " << x << " on a : " << A << endl;
        cout << "pour b = " << b << " et x = " << x << " on a : " << B << endl;
    }
}


void Global_Data::intervalle_variance_ana(double a, int n_global_data, int n_data) {

}

double Global_Data::variance_asymptotique(double a) {
    vector<double> E;
    for (Data data : training_data) {
        E.push_back(Alpha * data.hyper_log_log(a));
    }
    double E_1 = momentum(E, 1);
    double E_2 = momentum(E, 2);
    double E_3 = momentum(E, 3);
    double E_4 = momentum(E, 4);

    return (4*pow(E_1, 2)*(E_2 - pow(E_1, 2)) - 4*E_1*(E_3-E_1*E_2) + E_4 - pow(E_2, 2));
};

void Global_Data::histogram_data(double a, const string& file_name) {
    alpha_moyen_h(a);
    vector<double> E;
    for( Data data: training_data){
        E.push_back(data.hyper_log_log(a)*Alpha);
        //cout<<data.hyper_log_log(a)*Alpha<<endl;
    }
    histogram(file_name, E);
}