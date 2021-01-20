#include "Data.h"
#include "tools.h"
#include <cstddef>
#include "Global_Data.h"

int main(){
    double a = -1;


    double z = 1.2;
    Global_Data globalData(200, 100, "Base_Donnees/Testing_Data", "Base_Donnees/Data", 7, 2);
    globalData.estimateur_better(a, -0.75, 50, 100);
    //    globalData.intervalle_variance_emp(a, 200, 100);
//    cout << globalData.variance_asymptotique(a) << endl;
//    Global_Data globalData2(200, 100, "Base_Donnees/Testing_Data", "Base_Donnees/Data", 7, 2);
//    globalData2.intervalle_variance_emp(a, 200, 100);

//    Global_Data globalData3(200, 100, "Base_Donnees/Testing_Data", "Base_Donnees/Data", 7, 2);

    //    globalData2.intervalle_variance_emp(-0.75, 200, 100);

//    globalData.histogram_data(a, "test.txt");

//    Global_Data globalData2(100, 100, "Base_Donnees/Testing_Data", "Base_Donnees/Data",7, z);
//    globalData2.intervalle_variance_emp(a, 10, 100);


}