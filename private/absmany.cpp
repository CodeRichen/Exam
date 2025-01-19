// 在 Factory 类中添加 print 函数
class Factory {
public:
    virtual unique_ptr<Product> createProduct() const = 0; // 纯虚函数
    virtual void print() const = 0; // 声明为纯虚函数
    virtual ~Factory() {}
};

// 具体工厂A实现 print
class FactoryA : public Factory {
public:
    unique_ptr<Product> createProduct() const override {
        return make_unique<ProductA>();
    }
    void print() const override {
        cout << "Factory A" << endl;
    }
};

// 具体工厂B实现 print
class FactoryB : public Factory {
public:
    unique_ptr<Product> createProduct() const override {
        return make_unique<ProductB>();
    }
    void print() const override {
        cout << "Factory B" << endl;
    }
};
