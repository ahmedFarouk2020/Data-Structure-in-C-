#include<iostream>

template <typename T>
class PQ
{
    private:
        T data[100] = {0};
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
                // index of the maximum value
                int IndxOfMax = nodeIndx;

                if(data[IndxOfMax] < data[LchildInx])
                    IndxOfMax = LchildInx;
                if(data[IndxOfMax] < data[RchildInx])    
                    IndxOfMax = RchildInx;

                if(IndxOfMax != nodeIndx)   
                {
                    // SWAP
                    T temp = data[nodeIndx];
                    data[nodeIndx] = data[IndxOfMax];
                    data[IndxOfMax] = temp;
                    siftDown(IndxOfMax);
                } 
            }
            
        }

        void siftUp(int nodeIndx)
        {
            if(nodeIndx != 0)
            {
                int P_indx = parentIndx(nodeIndx);

                if(data[nodeIndx] > data[P_indx])   
                {
                    // SWAP
                    T temp = data[nodeIndx];
                    data[nodeIndx] = data[P_indx];
                    data[P_indx] = temp;
                } 
                siftUp(P_indx);
            }    
            
        }

    public:
        int size=0;

        void Add(T value)
        {
            data[size] = value;
            if(size != 0)
                siftUp(size);               
            size++;
        }  
        T extractMax(void)
        {
            T max = data[0];
            data[0] = data[size-1];
            siftDown(0);
            size--;
            return max;
        }  
};

int main()
{
    PQ<int> ages;
    ages.Add(12);
    ages.Add(15);
    ages.Add(10);
    ages.Add(20);

    std::cout<<ages.extractMax()<<'\n' ;
    std::cout<<ages.extractMax()<<'\n' ;
    std::cout<<ages.extractMax()<<'\n' ;
    return 0;
}