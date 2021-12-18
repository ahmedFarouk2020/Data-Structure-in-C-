#include<iostream>

//template<typename T>
class NaiveSet
{
private:
    int smallestID[100];// contains IDs of the sets
public:
    // make single-element set
    void MakeSet(int value)
    {
        smallestID[value] = value;
    }
    // get the ID of the set containing value
    int Find(int value)
    {
        return smallestID[value];
    }

    void unionSet(int val1, int val2)
    {
        int val1_ID = smallestID[val1];
        int val2_ID = smallestID[val2];

        // get min of the two IDs
        int min;
        if(val1_ID > val2_ID)
            min = val2_ID;
        else
            min = val1_ID;

        for(int i=0; i<100 ;i++)
        {
            if( (smallestID[i] == val1_ID)  || (smallestID[i] == val2_ID) )
                smallestID[i] = min;
        }
    }

};

int main()
{
    NaiveSet set;
    set.MakeSet(5);
    set.MakeSet(0);
    std::cout<< set.Find(0);
    set.unionSet(0,5);
    std::cout<< set.Find(5);
    return 0;
}