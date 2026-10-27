#include <iostream>
using namespace std;

class HillStations
{
public:
    virtual void location()
    {
        cout << "Location of Hill Station" << endl;
    }

    virtual void famousFor()
    {
        cout << "Famous for tourism" << endl;
    }
};

class Manali : public HillStations
{
public:
    void location() override
    {
        cout << "Manali is in Himachal Pradesh" << endl;
    }

    void famousFor() override
    {
        cout << "Manali is famous for snow and mountains" << endl;
    }
};

class Shimla : public HillStations
{
public:
    void location() override
    {
        cout << "Shimla is in Himachal Pradesh" << endl;
    }

    void famousFor() override
    {
        cout << "Shimla is famous for colonial buildings" << endl;
    }
};

class Ooty : public HillStations
{
public:
    void location() override
    {
        cout << "Ooty is in Tamil Nadu" << endl;
    }

    void famousFor() override
    {
        cout << "Ooty is famous for tea gardens" << endl;
    }
};

int main()
{
    Manali m;
    Shimla s;
    Ooty o;

    HillStations *h;

    h = &m;
    h->location();
    h->famousFor();

    h = &s;
    h->location();
    h->famousFor();

    h = &o;
    h->location();
    h->famousFor();

    return 0;
}