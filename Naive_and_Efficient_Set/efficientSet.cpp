#include<iostream>

class RankSet
{
    private:
        int parent[100];
        int rank[100];
    public:
        void makeSet(int value)
        {
            parent[value] = value;
            rank[value] = 0;// tree height
        }

        int find(int value)
        {
            while(parent[value] != value)
            {
                value = parent[value];
            }
            return parent[value];
        }

        void unionSet(int val1 , int val2)
        {
            int val1_root = find(val1);
            int val2_root = find(val2);
            
            if(val2_root == val1_root)
                return;

            else
            {
                if(rank[val2_root] > rank[val1_root])
                {
                    parent[val1_root] = val2_root;
                }
                else
                {
                    parent[val2_root] = val1_root;
                    if(rank[val2_root] == rank[val1_root])
                        rank[val1_root]++;
                }
            }
            
        }
};

class PassCompressionSet
{
    private:
        int parent[100];
        int rank[100];
    public:
        void makeSet(int value)
        {
            parent[value] = value;
            rank[value] = 0;
        }

        int find(int value)//here is the different from rank set implementation
        {
            if(parent[value] != value)
            {
                parent[value] = find(parent[value]);
            }
            return parent[value];
        }

        void unionSet(int val1 , int val2)
        {
            int val1_root = find(val1);
            int val2_root = find(val2);
            
            if(val2_root == val1_root)
                return

            else
            {
                if(rank[val2_root] > rank[val1_root])
                {
                    parent[val1_root] = val2_root;
                }
                else
                {
                    parent[val2_root] = val1_root;
                    if(rank[val2_root] == rank[val1_root])
                        rank[val1_root]++;
                }
            }
            
        }
};