#include "DynamicLinkedList.h"
#include "Timer.h"

int main()
{
    DynamicLinkedList d;
    Timer t;

//    for (int i = 0; i < 500000; i++)
//    {
//        //d.insertBeginning(i);
//        d.insertEnd(i);
//        //d.insertAt(0, i);
//    }
//
//    t.start();
//    for (int i = 0; i < 500000; i++)
//    {
//        d.remove(0);
//    }
//    t.end();
    
    cout << "It took " << t.getDuration() << " seconds to run someFunction 1M times.";

    return 0;
}
