#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    // 設定浮點數輸出格式
    cout << fixed << setprecision(2);

    // 測試基底類別對象的建立與銷毀順序
    { // 開啟新的作用域
        CommissionEmployee employee1(
            "Bob", "Lewis", "333-33-3333", 5000, .04
        ); // 建立基底類別對象
        // 離開作用域後會自動銷毀 employee1
    } // end scope

    cout << endl;

    // 測試衍生類別對象的建立與銷毀順序
    BasePlusCommissionEmployee employee2(
        "Lisa", "Jones", "555-55-5555", 2000, .06, 800
    );

    cout << endl;

    BasePlusCommissionEmployee employee3(
        "Mark", "Sands", "888-88-8888", 8000, .15, 2000
    );

    cout << endl;

    BasePlusCommissionEmployee employee4(
        "MIKU", "Sands", "888-88-8888", 8000, .15, 2000
    );

    cout << endl;
  /*  for (int i = 0; i < 2; ++i) {
        BasePlusCommissionEmployee tempEmployee(
            "MIku", "Richen" + to_string(i + 1),
            "000-00-000" + to_string(i + 1), 
            3000 + i * 1000, 
            0.05 + i * 0.01, 
            1000 + i * 500  
        );
    }*/

    return 0;
}
