#ifndef DATA_H
#define DATA_H

class Data
{
    static Data *data;
    int i;

private:
    Data() {}

public:
    static Data *instance()
    {
        if (!data)
            data = new Data();
        return data;
    }
    int get() const
    {
        return this->i;
    };
    void set(int num)
    {
        this->i = num;
    };
};

#endif
