//do NOT submit this file.
//do NOT modify this file.

#include <iostream>
#include <string>
#include "TimeManager.h"

using namespace std;

//the following static variable is added for testing purpose (for the memory leak prevention test cases)
//just consider destructionCount as some kind of global variable - you will learn about that later in COMP2012
//destructionCount will keep track of, in total, how many times the Activity objects are properly destructed (i.e. Activity destructor called)
int Activity::destructionCount = 0;

int main()
{
    //*** change testCaseNumber to specify which test case to test ***//
    //** read the code below to see what each test case tests ***//
    int testCaseNumber = 1;

    TimeManager timeManager;

    //test creating and showing an empty db
    if(testCaseNumber == 1)
    {
        cout << endl;
        timeManager.print();
    }

    //test adding persons
    if(testCaseNumber == 2)
    {
        int result1 = timeManager.addPerson("D");
        cout << endl;
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 3)
    {
        int result1 = timeManager.addPerson("K");
        int result2 = timeManager.addPerson("D");
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 4)
    {
        int result1 = timeManager.addPerson("D");
        int result2 = timeManager.addPerson("D"); //should fail
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        timeManager.print();
    }

    //test doesPersonExist
    if(testCaseNumber == 4+1)
    {
        timeManager.addPerson("D");
        timeManager.addPerson("K");
        int result1 = timeManager.doesPersonExist("D");
        int result2 = timeManager.doesPersonExist("K");
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
    }
    if(testCaseNumber == 4+2)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.doesPersonExist("D");
        int result2 = timeManager.doesPersonExist("K");
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
    }

    //test adding activities (single)
    if(testCaseNumber == 6+1)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.addActivityForPerson("d", Activity("a", Timeslot(0, 1)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 6+2)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.addActivityForPerson("d", Activity("a", Timeslot(23, 24)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 6+3)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.addActivityForPerson("d", Activity("a", Timeslot(12, 14)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }

    string a1n = "a1";
    int a1s = 12;
    int a1e = 14;
    string a2n = "a2";
    int a2s = 14;
    int a2e = 16;
    string a3n = "a3";
    int a3s = 13;
    int a3e = 15;

    //test adding activities (multiple, all permutations of 3 activities)
    if(testCaseNumber == 9+1)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.addActivityForPerson("d", Activity(a1n, Timeslot(a1s, a1e)));
        int result2 = timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        int result3 = timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        cout << "result3=" << result3 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 9+2)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.addActivityForPerson("d", Activity(a1n, Timeslot(a1s, a1e)));
        int result3 = timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        int result2 = timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        cout << "result3=" << result3 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 9+3)
    {
        timeManager.addPerson("d");
        int result2 = timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        int result1 = timeManager.addActivityForPerson("d", Activity(a1n, Timeslot(a1s, a1e)));
        int result3 = timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        cout << "result3=" << result3 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 9+4)
    {
        timeManager.addPerson("d");
        int result2 = timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        int result3 = timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        int result1 = timeManager.addActivityForPerson("d", Activity(a1n, Timeslot(a1s, a1e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        cout << "result3=" << result3 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 9+5)
    {
        timeManager.addPerson("d");
        int result3 = timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        int result1 = timeManager.addActivityForPerson("d", Activity(a1n, Timeslot(a1s, a1e)));
        int result2 = timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        cout << "result3=" << result3 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 9+6)
    {
        timeManager.addPerson("d");
        int result3 = timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        int result2 = timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        int result1 = timeManager.addActivityForPerson("d", Activity(a1n, Timeslot(a1s, a1e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        cout << "result3=" << result3 << " ";
        timeManager.print();
    }

    string a4n = "a4";
    int a4s = 12;
    int a4e = 14;
    string a5n = "a5";
    int a5s = 10;
    int a5e = 16;

    //test adding activities (multiple, 2 more special cases: a5 completely includes a4)
    if(testCaseNumber == 15+1)
    {
        timeManager.addPerson("d");
        int result1 = timeManager.addActivityForPerson("d", Activity(a4n, Timeslot(a4s, a4e)));
        int result2 = timeManager.addActivityForPerson("d", Activity(a5n, Timeslot(a5s, a5e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 15+2)
    {
        timeManager.addPerson("d");
        int result2 = timeManager.addActivityForPerson("d", Activity(a5n, Timeslot(a5s, a5e)));
        int result1 = timeManager.addActivityForPerson("d", Activity(a4n, Timeslot(a4s, a4e)));
        cout << endl;
        cout << "result1=" << result1 << " ";
        cout << "result2=" << result2 << " ";
        timeManager.print();
    }

    //test removing persons
    if(testCaseNumber == 17+1)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addPerson("e");
        cout << endl;
        timeManager.print();
        int result1 = timeManager.removePerson("d");
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 17+2)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addPerson("e");
        cout << endl;
        timeManager.print();
        int result1 = timeManager.removePerson("dd");
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }

    string a7n = "a7";
    int a7s = 0;
    int a7e = 1;
    string a8n = "a8";
    int a8s = 1;
    int a8e = 2;
    string a9n = "a9";
    int a9s = 2;
    int a9e = 3;

    //test removing activities
    if(testCaseNumber == 19+1)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addPerson("e");
        timeManager.addActivityForPerson("c", Activity(a7n, Timeslot(a7s, a7e)));
        timeManager.addActivityForPerson("d", Activity(a7n, Timeslot(a7s, a7e)));
        timeManager.addActivityForPerson("d", Activity(a8n, Timeslot(a8s, a8e)));
        timeManager.addActivityForPerson("d", Activity(a9n, Timeslot(a9s, a9e)));
        timeManager.addActivityForPerson("e", Activity(a9n, Timeslot(a9s, a9e)));
        cout << endl;
        timeManager.print();
        int result1 = timeManager.removeActivityForPerson("d", a7n);
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 19+2)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addPerson("e");
        timeManager.addActivityForPerson("c", Activity(a7n, Timeslot(a7s, a7e)));
        timeManager.addActivityForPerson("d", Activity(a7n, Timeslot(a7s, a7e)));
        timeManager.addActivityForPerson("d", Activity(a8n, Timeslot(a8s, a8e)));
        timeManager.addActivityForPerson("d", Activity(a9n, Timeslot(a9s, a9e)));
        timeManager.addActivityForPerson("e", Activity(a9n, Timeslot(a9s, a9e)));
        cout << endl;
        timeManager.print();
        int result1 = timeManager.removeActivityForPerson("d", a8n);
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }
    if(testCaseNumber == 19+3)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addPerson("e");
        timeManager.addActivityForPerson("c", Activity(a7n, Timeslot(a7s, a7e)));
        timeManager.addActivityForPerson("d", Activity(a7n, Timeslot(a7s, a7e)));
        timeManager.addActivityForPerson("d", Activity(a8n, Timeslot(a8s, a8e)));
        timeManager.addActivityForPerson("d", Activity(a9n, Timeslot(a9s, a9e)));
        timeManager.addActivityForPerson("e", Activity(a9n, Timeslot(a9s, a9e)));
        cout << endl;
        timeManager.print();
        int result1 = timeManager.removeActivityForPerson("d", a9n);
        cout << "result1=" << result1 << " ";
        timeManager.print();
    }

    a1s = 0;
    a1e = 3;
    a2s = 3;
    a2e = 22;
    a3s = 22;
    a3e = 24;

    //test findFirstCommonTimeslot - single person
    if(testCaseNumber == 22+1)
    {
        timeManager.addPerson("c");
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+2)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+3)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+4)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+5)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+6)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+7)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 22+8)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }

    //test findFirstCommonTimeslot - multiple persons
    if(testCaseNumber == 30+1)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 30+2)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }
    if(testCaseNumber == 30+3)
    {
        timeManager.addPerson("b");
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        Timeslot* timeslot = timeManager.findFirstCommonTimeslot();
        cout << endl;
        if(timeslot == NULL) cout << "No common timeslot is found.";
        else timeslot->print();
    }

    //test findAllCommonTimeslots - single person
    if(testCaseNumber == 33+1)
    {
        timeManager.addPerson("c");
        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }

    }
    if(testCaseNumber == 33+2)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 33+3)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 33+4)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 33+5)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 33+6)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 33+7)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 33+8)
    {
        timeManager.addPerson("c");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("c", Activity(a3n, Timeslot(a3s, a3e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }

    //test findAllCommonTimeslots - multiple persons
    if(testCaseNumber == 41+1)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addActivityForPerson("d", Activity(a2n, Timeslot(a2s, a2e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 41+2)
    {
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addActivityForPerson("c", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 41+3)
    {
        timeManager.addPerson("b");
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }

    a1s = 2;
    a1e = 4;
    a2s = 1;
    a2e = 5;
    a3s = 0;
    a3e = 6;
    a4s = 22;
    a4e = 23;
    a5s = 20;
    a5e = 21;

    //test findAllCommonTimeslots - single/multiple persons, advanced
    if(testCaseNumber == 44+1)
    {
        timeManager.addPerson("a");
        timeManager.addActivityForPerson("a", Activity(a5n, Timeslot(a5s, a5e)));
        timeManager.addActivityForPerson("a", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("a", Activity(a4n, Timeslot(a4s, a4e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }
    if(testCaseNumber == 44+2)
    {
        timeManager.addPerson("a");
        timeManager.addPerson("b");
        timeManager.addPerson("c");
        timeManager.addPerson("d");
        timeManager.addPerson("e");
        timeManager.addActivityForPerson("a", Activity(a5n, Timeslot(a5s, a5e)));
        timeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
        timeManager.addActivityForPerson("c", Activity(a2n, Timeslot(a2s, a2e)));
        timeManager.addActivityForPerson("d", Activity(a3n, Timeslot(a3s, a3e)));
        timeManager.addActivityForPerson("e", Activity(a4n, Timeslot(a4s, a4e)));

        Timeslot** timeslots = NULL;
        int timeslotCount = 0;
        timeManager.findAllCommonTimeslots(timeslots, timeslotCount);
        cout << endl;
        if(timeslotCount == 0) cout << "No common timeslot is found.";
        else
        {
            for(int i=0; i<timeslotCount; i++)
            {
                timeslots[i]->print();
                cout << " ";
            }
        }
    }

    a1s = 1;
    a1e = 3;
    a2s = 5;
    a2e = 6;
    a3s = 7;
    a3e = 8;

    //test memory leak prevention
    if(testCaseNumber == 46+1)
    {
        //note that below we use a pair of brackets to create a small scope
        //localTimeManager shall be destructed automatically (i.e. the TimeManager destructor should be called) at the end of the scope
        //all dynamic objects should be deleted/destroyed then, if the your destructors are implemented correctly
        {
            TimeManager localTimeManager;
            localTimeManager.addPerson("b");
            localTimeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
            //the "Activity(a1n, Timeslot(a1s, a1e)" is a temporary local Activity object, it will be destructed automatically after the previous line
            //this temporary object destruction contributes 1 to the Activity::destructionCount
        }
        cout << endl;

        const int EXPECTED_DESTRUCTION_COUNT = 2;
        //+1 for the temporary local object "Activity(a1n, Timeslot(a1s, a1e)" mentioned above
        //+1 for the one dynamic activity object created inside the addActivityForPerson function
        //(which should be deleted by student's Person destructor when the TimeManager destructor, which should delete all Person objects, is called at the end of the scope)
        if(Activity::destructionCount >= EXPECTED_DESTRUCTION_COUNT)
        {
            cout << "PASSED - Activity's destructor has been called at least " << EXPECTED_DESTRUCTION_COUNT << " times.";
        }
        else
        {
            cout << "FAILED - Activity's destructor has been called only " << Activity::destructionCount << " times.";
        }
    }
    if(testCaseNumber == 46+2)
    {
        //see the previous test case for explanations; not going to repeat here
        {
            TimeManager localTimeManager;
            localTimeManager.addPerson("b");
            localTimeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
            localTimeManager.addActivityForPerson("b", Activity(a2n, Timeslot(a2s, a2e)));

        }
        cout << endl;

        const int EXPECTED_DESTRUCTION_COUNT = 4;
        //+2 for the two temporary local objects up there (see explanation in the first memory leak test case)
        //+2 for the two dynamic activity objects created inside the addActivityForPerson function - they should be destructed by the student in a destructor
        if(Activity::destructionCount >= EXPECTED_DESTRUCTION_COUNT)
        {
            cout << "PASSED - Activity's destructor has been called at least " << EXPECTED_DESTRUCTION_COUNT << " times.";
        }
        else
        {
            cout << "FAILED - Activity's destructor has been called only " << Activity::destructionCount << " times.";
        }
    }
    if(testCaseNumber == 46+3)
    {
        //see the previous test case for explanations; not going to repeat here
        {
            TimeManager localTimeManager;
            localTimeManager.addPerson("b");
            localTimeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
            localTimeManager.addActivityForPerson("b", Activity(a2n, Timeslot(a2s, a2e)));
            localTimeManager.removeActivityForPerson("b", a1n);

            cout << endl;

            const int EXPECTED_DESTRUCTION_COUNT = 3; //should be just 3 as right here we are still inside of the local scope (so destructor of localTimeManager is not invoked yet)
                                                      //+2 for the two local temporary object destruction up there (see explanation in the first memory leak test case)
                                                      //+1 as we remove one activity with removeActivityForPerson, as the removed activity should be deleted by the student inside removeActivityForPerson

            if(Activity::destructionCount >= EXPECTED_DESTRUCTION_COUNT)
            {
                cout << "PASSED - Activity's destructor has been called at least " << EXPECTED_DESTRUCTION_COUNT << " times.";
            }
            else
            {
                cout << "FAILED - Activity's destructor has been called only " << Activity::destructionCount << " times.";
            }
        }
    }
    if(testCaseNumber == 46+4)
    {
        //see the previous test case for explanations; not going to repeat here
        {
            TimeManager localTimeManager;
            localTimeManager.addPerson("b");
            localTimeManager.addActivityForPerson("b", Activity(a1n, Timeslot(a1s, a1e)));
            localTimeManager.addActivityForPerson("b", Activity(a2n, Timeslot(a2s, a2e)));
            localTimeManager.removePerson("b");

            cout << endl;

            const int EXPECTED_DESTRUCTION_COUNT = 4; //should be just 4 as right here we are still inside of the local scope (so destructor of localTimeManager is not invoked yet)
                                                      //+2 for the two local temporary object destruction up there (see explanation in the first memory leak test case)
                                                      //+2 as we remove the person with removePerson which deletes the person object, when we remove the person, the 2 dynamic activity objects created in addActivityForPerson should also be deleted

            if(Activity::destructionCount >= EXPECTED_DESTRUCTION_COUNT)
            {
                cout << "PASSED - Activity's destructor has been called at least " << EXPECTED_DESTRUCTION_COUNT << " times.";
            }
            else
            {
                cout << "FAILED - Activity's destructor has been called only " << Activity::destructionCount << " times.";
            }
        }
    }

    return 0;
}
