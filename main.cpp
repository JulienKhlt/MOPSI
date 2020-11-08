#include "Data.h"
#include "tools.h"
#include <cstddef>
#include "Global_Data.h"

int main() {
    Data data("Base_Donnees/Data0.csv", 7);
    data.print();
    data.compute_min();
    //cout << data.rho[0] << endl;
    cout << data.hyper_log_log(-1) << endl;
    cout << data.true_n() << endl;
}
/*int main(){
    double a = -1;

    Global_Data global_alpha(0, n_alpha,"Base_Donnees/Testing_Data",7);
    Global_Data global_biais(n_alpha,100,"Base_Donnees/Testing_Data",7);
    double Alpha = global_alpha.alpha_moyen_h(a);

    cout<<"alpha "<<Alpha<<endl;
    cout<<"biais "<<global_biais.biais(Alpha,a)<<endl;
    cout<< global_biais.hyper_log_log_error(Alpha, a) << endl;
    /*Alpha = global_alpha.alpha_moyen_h(-0.75);
    cout<<"alpha "<<Alpha<<endl;
    cout<< global_biais.hyper_log_log_error(Alpha, -0.75) << endl;
    Alpha = global_alpha.alpha_moyen_h(1);
    cout<<"alpha "<<Alpha<<endl;
    cout<< global_biais.hyper_log_log_error(Alpha, 1) << endl;
    Alpha = global_alpha.alpha_moyen_h(0);
    cout<<"alpha "<<Alpha<<endl;
    cout<< global_biais.hyper_log_log_error(Alpha, 0) << endl;
    double inf,sup;*/
    /*intervalle_variance(Alpha,-1,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    intervalle_variance(Alpha,-0.75,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    intervalle_variance(Alpha,-0.25,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;*/
//}