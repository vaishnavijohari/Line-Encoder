#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void decToBin(int n)
{
    // array to store binary number
    int binNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binNum[j];
}

void randGenerator(){
	int arr[32]; int bin;
    srand(time(0));

    arr[0] = rand();
    decToBin(arr[0]); cout<<"\n";
}

int main(){
    cout<<"Choice:\n(1)Completely random sequence OR\n(2)A random sequence with fixed sub-sequences\n";
    cout<<"What type of encoding is needed? Choice:\n(1)NRZ-L\n(2)NRZ-I\n(3)Manchester\n(4)Differential Manchester\n(5)AMI\n";
    int choice, encoding;
    cin>>choice;
    cin>>encoding;

    if(choice == 1){
    	randGenerator();
    }
    else if(choice == 2){

    }
    else{
        cout<<"Wrong choice! Choose from either 1 or 2.";
    }

    if(encoding == 1){
    }
    else if(encoding == 2){
    }
    else if(encoding == 3){
    }
    else if(encoding == 4){
    }
    else if(encoding == 5){
        cout<<"Is scrambling needed? Y: Yes , N: No\n";
        char c;
        cin>>c;
        if(c == 'Y'){
            cout<<"\nWhat type of scrambling technique is needed? Choice: (1)B8ZS , (2)HDB3\n";
            int scramb; cin>>scramb;
        }
    }


    return 0;
}
