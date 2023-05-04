// Compute the no of page faults using FIFO page replacement algorithm
// No of frames - 3
// Request list - 1 2 3 4 1 2 5 1 2 3 4 5

#include<iostream>
#include<queue>

using namespace std;

int main()
{
   int frames;
   int requests;
   cout<<"Enter the number of frames"<<endl;
   cin >> frames;
   cout<<"Enter the number of request"<<endl;
   cin >> requests;

   int faults = 0;
   queue<int> q;

   cout<<"Enter the requests " << endl;
   for ( int i = 0; i < requests; i++ )
   {
    int request;
    cin >> request;
    bool found = false;
    for ( int j = 0; j < q.size(); j++ ){
        if (q.front() == request){
            found = true;
            break;
        }
        q.push(q.front());
        q.pop();
    }
    if (!found)
    {
        if (q.size() == frames){
            q.pop();
        }
        q.push(request);
        faults++;
    }
   }

   cout<<"Number of faults are : "<<faults<<endl;

   return 0;
}
