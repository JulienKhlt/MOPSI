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

    Global_Data globalData(10, "Base_Donnees/Data", 7);
    //globalData.print(0);
    cout << globalData.hyper_log_log() << endl;

}

/*int main(){
    Data test("Base_Donnees/Data16.csv",7);
    test.test_Xi2();

}*/