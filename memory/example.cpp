class A
{
    char *cp;
    double &dr;

public:
    A(char c, double &r) : dr(r)
    {
        cp = new char(c);
    }
    char get() const
    {
        return *cp;
    }
    ~A()
    {
        delete cp;
    }
};

A *foo(double &d)
{
    A *a = new A('c', d);
    return a;
}

int main()
{
    double d = 3.14;
    foo(d)->get();
}