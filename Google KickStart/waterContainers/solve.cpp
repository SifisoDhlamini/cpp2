#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct node {
    node *connections[2] = {NULL, NULL};
    bool isFull;
    float percentFull{};
};

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        /*
         The first line of each test case contains the two integers N and Q, where N is the number of containers and Q is the number of queries.
 The next N−1 lines contain two integers i and j (1≤i,j≤N, and i≠j) meaning that the i-th water container is connected to the j-th water container.
 Each of the next Q lines contain a single integer i (1≤i≤N) that represents the container to which 1 liter of water should be added.
        */
        int N, Q;
        cin >> N >> Q;
        //create and initialize N nodes
        vector<node> nodes(N);
        for(int i = 0; i < N; i++){
            nodes[i].isFull = false;
            nodes[i].percentFull = 0;
        }
        //connect nodes
        for(int i = 0; i < N-1; i++){
            int a, b;
            cin >> a >> b;
            //connect ath node to bth node
            if(nodes[a-1].connections[0] == NULL){
                nodes[a-1].connections[0] = &nodes[b-1];
            } else {
                nodes[a-1].connections[1] = &nodes[b-1];
            }
        }
        //add water
        for(int i = 0; i < Q; i++){
            int a;
            cin >> a;
            nodes[a-1].isFull = true;
            nodes[a-1].percentFull = 100;
            //check if parent is full
            if(nodes[a-1].connections[0] != NULL && nodes[a-1].connections[0]->isFull){
                nodes[a-1].connections[0]->percentFull += 50;
                if(nodes[a-1].connections[0]->percentFull >= 100){
                    nodes[a-1].connections[0]->isFull = true;
                }
            }
            if(nodes[a-1].connections[1] != NULL && nodes[a-1].connections[1]->isFull){
                nodes[a-1].connections[1]->percentFull += 50;
                if(nodes[a-1].connections[1]->percentFull >= 100){
                    nodes[a-1].connections[1]->isFull = true;
                }
            }
        }
       
        int fullNodes = 0;
        for(int i = 0; i < N; i++){
            if(nodes[i].isFull){
                fullNodes++;
            }
        }
        cout << "Case #" << t << ": " << fullNodes << endl;          
    }
    return 0;
}