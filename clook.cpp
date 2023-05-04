#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int head;
    int n;
    cout<<"Enter the initial position of the "<<endl;
    cin >> head;
    cout<<"Enter the number of requests"<<endl;
    cin >> n;

    vector<int> requests(n);
    cout<<"Enter the number of requests"<<endl;
    for ( int i = 0; i < n ; i++){
        cin >> requests[i];
    }

    sort(requests.begin(), requests.end());

    int index = 0;
    for ( int i = 0; i < n ; i++ )
    {
        if ( requests[i] >= head){
            index = i;
            break;
        }
    }

    int distance = 0;
    for (int i = 0; i < n ; i++){
        distance += abs(requests[i] - head);
        head = requests[i];
    }
    distance += abs(requests[n-1] - head);
    head = requests[n-1];
    for( int i = index; i < n ; i++){
        distance += abs(requests[i] - head);
        head = requests[i];
    }

   cout<<"Total head movement: "<<distance<<endl;

    return 0;
}
