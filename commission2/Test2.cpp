#include <iostream>   // �Ω��X��׺�
#include <iomanip>    // �Ω�榡�ƯB�I�ƿ�X
#include "CommissionEmployee.h" // �]�t CommissionEmployee �����w�q
#include "BasePlusCommissionEmployee.h" // �]�t BasePlusCommissionEmployee �����w�q
using namespace std;   // ²�ƼзǩR�W�Ŷ����ϥ�

int main()
{
    // �إ߰�������
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "222-22-2222", 10000, .06);
    // CommissionEmployee �������� commissionEmployee 
    // ���ܤ@��Ī����u�A�]�t�W�r�B�m��B���|�w�����X�B�P���B�ζĪ��v

    // �ŧi�������w�A��l�Ȭ� nullptr
    CommissionEmployee* commissionEmployeePtr = nullptr;
    // �Ω���V CommissionEmployee ���Ψ�l����������

    // �إ߭l��������
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    // BasePlusCommissionEmployee �O CommissionEmployee ���l����
    // ���� basePlusCommissionEmployee ���ܱa���~���Ī����u

    // �ŧi�l�������w�A��l�Ȭ� nullptr
    BasePlusCommissionEmployee* basePlusCommissionEmployeePtr = nullptr;
    // �Ω���V BasePlusCommissionEmployee ��������

    // �]�w�B�I�ƪ���X�榡�]�p���I��O�d���ơ^
    cout << fixed << setprecision(2);

    // ��X�����M�l�������󪺸�T
    cout << "Print base-class and derived-class objects:\n\n";
    commissionEmployee.print(); // �եΰ����� print �������
    cout << "\n\n";
    basePlusCommissionEmployee.print(); // �եέl������ print �������

    // �ϰ������w���V��������ýե� print
    commissionEmployeePtr = &commissionEmployee; // �������w���V��������
    cout << "\n\n\nCalling print with base-class pointer to "
        << "\nbase-class object invokes base-class print function:\n\n";
    commissionEmployeePtr->print(); // �եΰ����� print �������

    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee; // �l�������w���V�l��������
    cout << "\n\n\nCalling print with derived-class pointer to "
        << "\nderived-class object invokes derived-class "
        << "print function:\n\n";
    basePlusCommissionEmployeePtr->print(); // �եέl������ print �������

    // �ϰ������w���V�l��������ýե� print
    commissionEmployeePtr = &basePlusCommissionEmployee;
    // �������w�i�H���V�l��������]�h�A�欰�^�A���u��եΰ������w�q�����
    cout << "\n\n\nCalling print with base-class pointer to "
        << "derived-class object\ninvokes base-class print "
        << "function on that derived-class object:\n\n";
    commissionEmployeePtr->print();
    // ���B�եΰ����� print ��ơA�ӫD�l������ print ��ơA�]���ӫ��w�����O����

    cout << endl; // ��X����

    system("pause");
}