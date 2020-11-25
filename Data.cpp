//
// Created by julien on 14/10/2020.
//

#include "Data.h"

//TODO: Commentaire
//TODO: Implémenter le calcul de alpha_m lorsqu'il est connu
//TODO: Verifier que les données sont bien réparties

vector<double> separator(string text, const string& delimiter=";") {
    vector<double> vector_double;
    size_t pos = 0;
    string token;
    while ((pos = text.find(delimiter)) != string::npos) {
        token = text.substr(0, pos);
        vector_double.push_back(stod(token));
        text.erase(0, pos + delimiter.length());
    }
    return vector_double;
}

double average(vector<int> rho, double m) {
    double Z = 0;
    if (m == 0) {
        Z = 1;
        for (auto i:rho) {
            Z *= pow(pow(2, i), 1./rho.size());
        }
        return Z;
    }
    else {
        for (auto i:rho) {
            //cout << i << endl;
            Z += pow(pow(2, i), m);
        }
    }
    return pow(Z/rho.size(), 1/m);
}

Data::Data(const string& file_name, int b) {
    this->b = b;
    this->m = puissance(2, b);
    ifstream file(file_name.c_str());
    if ( !file )
    {
        cerr << "Erreur d'ouverture\n";
        return;
    }
    string line;
    if (! (file >> line)) {
        cout << "Erreur" << endl;
    }
    data = separator(line);
    rho.resize(m);
}

void Data::print() {
    for (double i : data) {
        cout << i << endl;
    }
}

double Data::operator()(int i) const {
    return data.at(i);
}

void Data::compute_min() {
    int I;
    for (double i : data) {
        I = interval(i);
        if (rho[I] == 0) {
            rho[I] = first_nozero(i)-b;
        }
        else if (rho[I] < first_nozero(i)-b) {
            rho[I] = first_nozero(i)-b;
        }
    }
}

int Data::interval(double x) const {
    double i = 1.;
    while (x > i/m) {
        i ++;
    }
    return int(i)-1;
}

int Data::first_nozero(double x) const {
    for (int i = 0; i < b; i++) {
        if (x > puissance(0.5, i+1)) {
            x -= puissance(0.5, i+1);
        }
    }
    int I = b+1;
    while (x < puissance(0.5, I)) {
        I++;
    }
    return I;
}

double Data::hyper_log_log(double a) {
    compute_min();
    double Z = average(rho, a);
    return m*Z;
}

double Data::hyper_log_log_f(){
    compute_min();
    double S=0;
    for (auto i:rho){
        S+=f(pow(2,i));
    }
    return f_i(S);

}

int Data::true_n() {
    vector<double> v;
    for (double & i : data) {
        if (not in(v, i)) {
            v.push_back(i);
        }
    }
    return v.size();
}

int classe(double x, int k){
    int i = 0;
    while(x > (i+1)*1/double(k)){
        i++;
    }
    return i;
}

bool Data::test_Xi2() {
    double Xi=59.70;
    int k = 31;
    int observations[k];
    for( int i = 0; i < k; i++)
        observations[i] = 0;
    for (int i = 0; i < data.size(); i++) {
        observations[classe(data[i], k)]=observations[classe(data[i], k)]+1;
    }
    double Q = 0;
    int n = data.size();
    for (int i = 0; i < k; i++) {
        Q = Q + (observations[i] - n * 1 / double(k)) * (observations[i] - n * 1 / double(k)) / (n * 1 / double(k));
    }
    if (Q<=Xi){cout<<"bon avec proba 0.999"<<endl;}
    else{cout<<"mauvais avec proba d'erreur 0.001"<<endl;}
    return(Q<=Xi);
}