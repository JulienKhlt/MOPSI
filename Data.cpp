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
            rho[I] = first_nozero(i);
        }
        else if (rho[I] < first_nozero(i)) {
            rho[I] = first_nozero(i);
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

double Data::hyper_log_log() {
    compute_min();
    double Z = 0;
    for (int j = 0; j < m; j++) {
        Z += puissance(1./2, rho[j]);
    }
    Z = 1./Z;
    return puissance(m, 2)*Z;
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