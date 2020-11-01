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

    Global_Data globalData(100, "Base_Donnees/Data", 7);
    //globalData.print(0);
    cout << globalData.hyper_log_log(-1) << endl;
    cout << globalData.hyper_log_log(-0.5) << endl;
    cout << globalData.hyper_log_log(-0.25) << endl;
    cout << globalData.hyper_log_log(-0.75) << endl;
    /*for (int i = 1; i < 10; i++) {
        cout << i << " " << globalData.hyper_log_log(i) << endl;
        cout << -i << " " << globalData.hyper_log_log(-i) << endl;
    }*/

}

/*int main(){
    Data test("Base_Donnees/Data16.csv",7);
    test.test_Xi2();

}*/