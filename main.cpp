#include "Data.h"
#include "tools.h"
#include <cstddef>
#include "Global_Data.h"



int main(){
    double a = -1;

    Global_Data global_alpha(0, n_alpha,"Base_Donnees/Testing_Data",7);
    Global_Data global_biais(n_alpha,100,"Base_Donnees/Testing_Data",7);
    double Alpha = global_alpha.alpha_moyen_h(a);

    cout<<"alpha "<<Alpha<<endl;
    cout<<"biais "<<global_biais.biais(Alpha,a)<<endl;

    double inf,sup;
    intervalle_variance(Alpha,-1,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    Alpha = global_alpha.alpha_moyen_h(-0.95);
    intervalle_variance(Alpha,-0.95,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    Alpha = global_alpha.alpha_moyen_h(-0.90);
    intervalle_variance(Alpha,-0.90,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    Alpha = global_alpha.alpha_moyen_h(-0.85);
    intervalle_variance(Alpha,-0.85,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    Alpha = global_alpha.alpha_moyen_h(-0.80);
    intervalle_variance(Alpha,-0.80,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    Alpha = global_alpha.alpha_moyen_h(-0.75);
    intervalle_variance(Alpha,-0.75,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
    Alpha = global_alpha.alpha_moyen_h(-0.70);
    intervalle_variance(Alpha,-0.70,inf,sup,10,100);
    cout<<"intervalle de confiance :["<<inf<<";"<<sup<<"]"<<endl;
}