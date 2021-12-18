#include<iostream>
#include<vector>
using namespace std;
class PQ
{
    private:
        
        struct processInfo
        {
          int th_id = 0;
          long long next_free_time = 0;
        };
        
        vector<processInfo> data;
        int parentIndx(int nodeIndx)
        {
            return ( (nodeIndx-1)/2) ;
        }

        int leftChildIndx(int nodeIndx)
        {
            return (nodeIndx*2+1) ;
        }

        int RightChildIndx(int nodeIndx)
        {
            return (nodeIndx*2+2) ;
        }

        void siftDown(int nodeIndx)
        {
            if(nodeIndx < size-1)            
            {
                int LchildInx = leftChildIndx(nodeIndx);
                int RchildInx = RightChildIndx(nodeIndx);
                // index of the minimum value
                int IndxOfMin = nodeIndx;

                if(data[IndxOfMin].next_free_time > data[LchildInx].next_free_time)
                    IndxOfMin = LchildInx;
                if(data[IndxOfMin].next_free_time > data[RchildInx].next_free_time)    
                    IndxOfMin = RchildInx;

                if(IndxOfMin != nodeIndx)   
                {
                    // SWAP
                    long long temp = data[nodeIndx].next_free_time;
                    data[nodeIndx].next_free_time = data[IndxOfMin].next_free_time;
                    data[IndxOfMin].next_free_time = temp;
                    siftDown(IndxOfMin);
                } 
            }
            
        }

        void siftUp(int nodeIndx)
        {
            if(nodeIndx != 0)
            {
                int P_indx = parentIndx(nodeIndx);

                if(data[nodeIndx].next_free_time > data[P_indx].next_free_time)   
                {
                    // SWAP
                    long long temp = data[nodeIndx].next_free_time;
                    data[nodeIndx].next_free_time = data[P_indx].next_free_time;
                    data[P_indx].next_free_time = temp;
                } 
                siftUp(P_indx);
            }    
            
        }

    public:
        int size=0;

        void Add(long long value)
        {
            data[size].next_free_time = value;
            if(size != 0)
                siftUp(size);               
            size++;
        }  
        long long extractMin(void)
        {
            long long min = data[0].next_free_time;
            data[0].next_free_time = data[size-1].next_free_time;
            siftDown(0);
            size--;
            return min;
        }  
};

int main()
{
    PQ priorityQ;
    std::cout<<priorityQ.size<<std::endl;
    priorityQ.Add(55);
    std::cout<<priorityQ.size<<std::endl;/*
    priorityQ.Add(5);
    priorityQ.Add(15);
    priorityQ.Add(50);
    priorityQ.Add(100);
    std::cout<<priorityQ.size;*/
    return 0;
}