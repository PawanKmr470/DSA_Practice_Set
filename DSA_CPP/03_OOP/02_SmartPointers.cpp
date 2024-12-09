#include <iostream>
#include <memory>
using namespace std;

int main() {

    // **********************************************************************
    // unique_ptr
    // **********************************************************************

    // new int -> make_unique<int>          // preferred way
    // make_unique gives exception safety

    // unique_ptr<int> uP1(new int(10));    // other ways
    // int *p = new int(10);
    // unique_ptr<int> uP1(p);              // other ways

    unique_ptr<int> p = make_unique<int>(10);
    cout << "p ptr's value : " << *p << endl;
    cout << "p ptr's addr  : " << p.get() << endl;

    // ========> OPERATIONS - move, get, swap 
    
    // move - transfers ownership and NULLs previous unique ptr
    unique_ptr<int> q = move(p);
    cout << "q ptr's value now : " << *q << endl;
    // cout << *p << endl;     // not valid now, segmentation fault but should throws exception

    // get - gives pointer to managed object (raw pointer)
    //       it's the address of the unique ptr also
    //       just to arithmatic & don't delete it
    int *raw_ptr = q.get(); // raw_ptr is a normal ptr
    cout << "raw ptr value : " << *raw_ptr << endl;

    // release - releases the ownership & NULLs current unique ptr
    int *raw_ptr2 = q.release();
    cout << "raw ptr2 value : " << *raw_ptr2 << endl;
    // cout << "unq ptr q now  : " << *q << endl;  // seg fault


    // reset - to assign another ptr (ptr to managed obj - raw ptr) to unique ptr
    //         i.e. manage obj will get replaced
    //         previously assinged is deleted, don't worry about that
    int *normal_ptr = new int(20);
    q.reset(normal_ptr);
    cout << "q ptr's value after reset : " << *q << endl;

    // swap - swap two unique ptrs e.g. - swap(p, q)

    cout << "************************************" << endl;
    // **********************************************************************
    // shared_ptr
    // **********************************************************************

    shared_ptr<int> uPtr1 = make_shared<int> (15);
    shared_ptr<int> uPtr2 = uPtr1;
    cout << "uPtr1 ptr's value   : " << *uPtr1 << endl;
    cout << "uPtr2 ptr's value   : " << *uPtr2 << endl;
    cout << "uPtr1 ptr's ref cnt : " << uPtr1.use_count() << endl;
    cout << "uPtr2 ptr's ref cnt : " << uPtr2.use_count() << endl;

    // allocated memory automatically gets deleted once the
    // LAST shared_ptr goes out of scope i.e. ref count -> 0 OR
    // until all copies of shared_ptr have been deleted
    // rest methods are same as unique_ptr

    int *normal_ptr2 = new int(25);

    shared_ptr<int> uPtr3 = uPtr2;
    uPtr2.reset(normal_ptr2);

    cout << "uPtr1 ptr's value   : " << *uPtr1 << endl;
    cout << "uPtr2 ptr's value   : " << *uPtr2 << endl;
    cout << "uPtr3 ptr's value   : " << *uPtr3 << endl;


    cout << "************************************" << endl;
    // **********************************************************************
    // weak_ptr
    // **********************************************************************

    shared_ptr<int> sPtr1 = make_shared<int> (50);
    weak_ptr<int> wPtr1 = sPtr1;
    cout << "wPtr1 ptr's count value : " << wPtr1.use_count() << endl;
    cout << "is wPtr1 ptr expired    : " << wPtr1.expired() << endl;    // bool value

    // lock - is used to check if object pointed by shared_ptr is alive or not
    //        .lock() method creates a copy|ref of shared ptr temprarily
    //        returns shared_ptr type
    cout << wPtr1.lock() << endl;
    cout << *wPtr1.lock() << endl;
    cout << wPtr1.lock().use_count() << endl;   // 2, as said temporarily

    // In short, to use weak ptr to modify data, we need to convert it into
    // a shared ptr.
    shared_ptr<int> sNewPtr = wPtr1.lock();
    cout << "sNewPtr ptr's value   : " << *sNewPtr << endl;
    cout << "sNewPtr ptr's addr    : " << sNewPtr << endl;
    cout << "sNewPtr ptr's ref cnt : " << sNewPtr.use_count() << endl;

    cout << "************************************" << endl;
    weak_ptr<int> wPtr2;
    {
        shared_ptr<int> sPtr2 = make_shared<int> (100);
        wPtr2 = sPtr2;
        cout << "inside scope" << endl;
        cout << "wPtr2 ptr's count value : " << wPtr2.use_count() << endl;  // 1
        cout << "is wPtr2 ptr expired    : " << wPtr2.expired() << endl;    // 0 -> false
        cout << wPtr2.lock() << endl;       // address
    }
    cout << "outside scope" << endl;
    cout << "wPtr2 ptr's count value : " << wPtr2.use_count() << endl;  // 0
    cout << "is wPtr2 ptr expired    : " << wPtr2.expired() << endl;    // 1 -> true
    cout << wPtr2.lock() << endl;       // 0

    // auto_ptr<int> MyPtr(new int(200));
    // cout << "auto MyPtr ptr's value : " << *MyPtr << endl;
    
}