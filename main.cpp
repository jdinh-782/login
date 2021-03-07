#include "Login.h"


int main()
{
    //apply 2FA to this
    Login<char> l;

    l.confirmOption(l.getOption());

    ostringstream o;
    l.outs(o, l);

    cout << endl << o.str();
    ofstream ofs("file.txt");
    ofs << o.str() << endl;

    return 0;
}
