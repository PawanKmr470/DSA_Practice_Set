#include <iostream>
#include <memory>
using namespace std;

weak_ptr<int> gw;
 
void observe()
{
    cout << "gw.use_count() == " << gw.use_count() << endl;

    // we have to make a copy of shared pointer before usage - gw.lock()
    // to create a shared ptr copy and gw.expired() to check existance.
    
    if (shared_ptr<int> sptr = gw.lock()) {
        cout << "sptr is not null : " << sptr << endl;
        cout << "*sptr value : " << *sptr << endl;
        cout << "1 shared ptr count is : " << sptr.use_count() << endl;
        cout << "2 shared ptr count is : " << gw.use_count() << endl;
    }
    else {
        cout << "gw is null : " << sptr << endl;
        cout << "is gw expired : " << gw.expired() << endl;
        cout << "3 shared ptr count is : " << sptr.use_count() << endl;
        cout << "4 shared ptr count is : " << gw.use_count() << endl;
    }
}
 
int main()
{
    {
        shared_ptr<int> sp = make_shared<int>(42);

        // Now gw will keep info about the sp
        gw = sp;

        observe();
    }
 
    observe();
}