//LRU ALGORITHM
#include <iostream>
using namespace std;
int main(){
    int pages[] = {1,2,3,2,4,1,5};
    int n = 7, capacity = 3;
    int frames[3] = {-1,-1,-1};
    int time[3] = {0,0,0};
    int fault = 0, t = 0;
    for(int i = 0; i < n; i++) {
        int pos = 0, found = 0;
        t++;
        for(int j = 0; j < capacity; j++) {
            if(frames[j] == pages[i]){
                time[j] = t;
                found = 1;
                break;
            }
        }
        if(!found) {
            fault++;
            for(int j = 0; j < capacity; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
                if(time[j] < time[pos]) {
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            time[pos] = t;
        }
        cout << "Pages: " << pages[i] << endl;

        for(int j = 0; j < capacity; j++) {
            cout << frames[j] << " ";
        }
        cout << endl;
    }
    cout << "Total page faults: " << fault;
    return 0;
}
