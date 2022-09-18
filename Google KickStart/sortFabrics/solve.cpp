#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct fabric {
    string color;
    int durability;
    int id;
};


int main()
{
    int N{};
    int fabrics{};
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> fabrics;
        vector<fabric> fabricVector{};
        for(int j = 0; j < fabrics; j++)
        {
            fabric f{};
            cin >>f.color >> f.durability >> f.id;
            fabricVector.push_back(f);
        }  
        //create a copy of fabricVector
        vector<fabric> fabricVectorCopy = fabricVector;

        //sort fabricVector by color
        sort(fabricVector.begin(), fabricVector.end(), [](fabric a, fabric b)
             {return a.color < b.color || (a.color == b.color && a.id < b.id); });

        //sort fabricVectorCopy by durability, or id if durability is the same
        sort(fabricVectorCopy.begin(), fabricVectorCopy.end(), [](fabric a, fabric b) {return a.durability < b.durability || (a.durability == b.durability && a.id < b.id); });
        int count = 0;
        for(size_t k = 0; k < fabricVector.size(); k++)
        {
            if(fabricVector[k].color == fabricVectorCopy[k].color && fabricVector[k].durability == fabricVectorCopy[k].durability && fabricVector[k].id == fabricVectorCopy[k].id)
            {
                count++;
            }
        }

        cout << "Case #" << i + 1 << ": " << count << endl;
    }
}