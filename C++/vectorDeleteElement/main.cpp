#include <iostream>
#include <list>
#include <algorithm>
#include <unistd.h>
#include <iterator>
using namespace  std;
int main(int argc, char* argv[])
{
    list<int> MyList;

    for (int i = 0; i < 10; i++)
    {
        MyList.push_back(i);
    }

    list<int>::iterator Itor;

    for ( Itor = MyList.begin(); Itor != MyList.end(); )
    {

        if ( *Itor == 4 )
        {
            Itor = MyList.erase(Itor);
        }
        else
        {
            Itor++;
        }

    }

    copy(MyList.begin(), MyList.end(), ostream_iterator<int>(cout, " ") );
    cout<<endl;

    return 0;
}
