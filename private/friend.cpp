class Base {
public:
    virtual ~Base() {}
    void accessDerivedPrivate(Derived& d);
};

class Derived : public Base {
private:
    int privateData = 42;

    // �N�����]�m���ͤ���
    friend void Base::accessDerivedPrivate(Derived& d);
};

void Base::accessDerivedPrivate(Derived& d) {
    std::cout << "Accessing private data: " << d.privateData << std::endl;
}

int main() {
    Derived derivedObj;
    Base baseObj;
    baseObj.accessDerivedPrivate(derivedObj);

    return 0;
}
