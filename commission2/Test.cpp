#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    // �]�w�B�I�ƿ�X�榡
    cout << fixed << setprecision(2);

    // ���հ����O��H���إ߻P�P������
    { // �}�ҷs���@�ΰ�
        CommissionEmployee employee1(
            "Bob", "Lewis", "333-33-3333", 5000, .04
        ); // �إ߰����O��H
        // ���}�@�ΰ��|�۰ʾP�� employee1
    } // end scope

    cout << endl;

    // ���խl�����O��H���إ߻P�P������
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
