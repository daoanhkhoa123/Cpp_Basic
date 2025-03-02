#ifndef head1_H
#define head1_H

class IntCell
{
private:
    int value = 5;

public:
    explicit IntCell(int value = 0);
    int read() const;
    void write(const int &x);
};

#endif