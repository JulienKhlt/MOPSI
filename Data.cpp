//
// Created by julien on 14/10/2020.
//

#include "Data.h"

int puissance(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

vector<double> separator(string text, string delimiter=";") {
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

Data::Data(string file_name, int b) {
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

}

void Data::print() {
    for (double i : data) {
        cout << i << endl;
    }
}

double Data::operator()(int i) const {
    return data.at(i);
}