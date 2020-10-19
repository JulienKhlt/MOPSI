#include "Data.h"
#include "tools.h"
#include <cstddef>
#include "Global_Data.h"

int main() {
    /*Data data("Base_Donnees/Data0.csv", 7);
    data.print();
    data.compute_min();
    cout << data.rho[0] << endl;
    cout << data.hyper_log_log() << endl;
    cout << data.true_n() << endl;*/

    Global_Data globalData(4, 5, "Base_Donnees/Data", "Base_Donnees/Testing_Data", 7);
    //globalData.print(0);
    cout << globalData.hyper_log_log() << endl;

}