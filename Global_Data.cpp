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
    return 1/average(alpha);
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
        //cout << data.hyper_log_log(a)*Alpha << endl;
        V += puissance(data.hyper_log_log(a)*Alpha - n, 2)/(training_data.size()-1);
    }
    return sqrt(V)/n;
}


double Global_Data::biais(double Alpha,double a){
    vector<double> E;
    int n = training_data[0].true_n();
    for( Data data: training_data){
        E.push_back(data.hyper_log_log(a)*Alpha);
        // cout<<data.hyper_log_log(a)<<endl;
    }
    double E_barre = average(E);
    return (E_barre-n);
}

void Global_Data::test_variance_theorique(double& inf, double& sup,double a,double Alpha){
    double cov=0;
    double E_barre=0;
    double E2_barre=0;
    double E3_barre=0;
    int n = training_data[0].true_n();
    for (Data data : training_data){
        double E=data.hyper_log_log(a)*Alpha;
        E_barre+=E/training_data.size();
        E2_barre+=E*E/training_data.size();
        E3_barre+=E*E*E/training_data.size();
    }
    double S=0;
    double S2=0;
    for (Data data : training_data){
        double E=data.hyper_log_log(a)*Alpha;
        cout<<"E "<<E<<endl;
        S+=(E-n)*(E-n)/(training_data.size()-1);
        S2+=(E*E-n*n)*(E*E-n*n)/(training_data.size()-1);
    }
    cov=E3_barre-E2_barre*E_barre;
    cout<<"cov ="<<cov<<endl;
    cout<<" E_barre ="<<E_barre<<endl;
    cout<<" E2_barre ="<<E2_barre<<endl;
    cout<<" E3_barre ="<<E3_barre<<endl;
    cout<<" S ="<<S<<endl;
    cout<<" S2 ="<<S2<<endl;
    double V=pow((training_data.size()/(training_data.size()-1)),2)*(4*E2_barre*S-4*E_barre*cov+1/(training_data.size()-1)*S2);
    cout<<"estimateur variance asymptotique"<<V<<endl;
    double Q=1.96; //valeur dans table
    inf=S-Q*sqrt(V/training_data.size());
    sup=S+Q*sqrt(V/training_data.size());

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
