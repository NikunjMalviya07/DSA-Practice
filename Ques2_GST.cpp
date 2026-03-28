//Question 2: Yeh Bhot Advance Hogya Kyuki Abhi String nhi pda hai
#include<iostream>
#include<string>
using namespace std;
int main()
{
    float n;
    cout<<"Enter amount of item : ";
    cin>>n;
 
    if(n<=3){

    float pen=10;
    float pencil=5;
    float eraser=5;
    float gst=18.0/100;
    float sum=0;

    for(int i=0;i<n;i++){
        string item;
        cin>>item;
        
        if(item == "Done"){
            break;
        }
        else if(item == "pen"){
            cout<<"Final price with gst :";
            float pen_gst = pen + pen*gst;
            cout<<pen_gst<<endl;
            sum=sum+pen_gst;

        }
        else if(item == "pencil"){
            cout<<"Final price with gst :";
            float pencil_gst = pencil + pencil*gst;
            cout<<pencil_gst<<endl;
            sum=sum+pencil_gst;
        }
        else if(item == "eraser"){
            cout<<"Final price with gst :";
            float eraser_gst = eraser + eraser*gst;
            cout<<eraser_gst<<endl;
            sum=sum+eraser_gst;
        }
    }
    cout<<"Grand Total :"<<sum<<endl;

}

}