#include<iostream>

using namespace std;

int main()
{
    int i, j, a, n, number[1000],l,u,m,x;
        cout<<"Enter the value of n : \n";
        cin>>n;
        cout<<"Input an ascending array : \n";

        for (i = 0; i < n; ++i){
              cin>>number[i];
        }

        cout<<"Ascending array is: ";


          for (i = 0; i < n; ++i){
             cout << number[i]<< " ";
          }
      l=0;
      u=n-1;
      cout << "\n \nEnter the search value: ";
      cin>>x;
      while(l<=u)
      {
          if(u<l){
            cout<<"Search value does not exist";
          }
          else{
             m=l+(u-l)/2;
          if(number[m]<x)
          {
              l=m+1;
          }
          else if(number[m]>x)
          {
              u=m-1;
          }
          else if(number[m]==x)
          {
            cout << x << " Found at location" <<  m;
            break;
          }
          }

      }





}

