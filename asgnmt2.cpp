#include<iostream>
#include<ctime>
#include<cstdlib>
#include<graphics.h>
using namespace std;

//function to print binary data stream
void printBinArr(int binArr[], int length){
    for(int j=0;j<length;j++){
        cout<<binArr[j];
    }
}

//function to generate digital data stream
int* randGenerator(int choice){
	static int arr[32]; int num, length,index;

    //to generate completely random data stream
    if(choice == 1){
        length = 10;
        for(int i=0;i<length;i++){
            arr[i] = rand()%2;
        }
        printBinArr(arr,length); cout<<"\n";
        return arr;
    }
    //to generate a random sequence with fixed subsequence of zeroes
    else if(choice == 2){
        length = 24;
        for(int i=0;i<length;i++){
            arr[i] = rand()%2;
        }

        cout<<"enter the number of consecutive zeroes needed in subsequence, it should be greater than or equal to8 but less than length, which is 24 here.";
        cin>>num;
        index = (rand()%(length-num+1)); // to compute a random starting index for the subsequence of zeroes

        //to create subsequence
        for(int i = index; i<=(index+num-1);i++){
            arr[i] = 0;
        }
        printBinArr(arr,length);
        return arr;
    }

}

void encodeSignal(int type, int arr[]){


}



int main(){
    cout<<"Choice:\n(1)Completely random sequence OR\n(2)A random sequence with fixed sub-sequences\n";
    cout<<"What type of encoding is needed? Choice:\n(1)NRZ-L\n(2)NRZ-I\n(3)Manchester\n(4)Differential Manchester\n(5)AMI\n";
    int choice, encoding;
    cin>>choice;
    cin>>encoding;
    srand(time(0));
    int *p;
    int arr1[32],arr2[32];
    p = randGenerator(choice);

    int gd = DETECT, gm;
    int x0,y0,x1,y1,V,d;
    x0=150;y0=120;V=20;d=20;
    initgraph(&gd, &gm, "");
    setcolor(GREEN);
    line(x0,y0,(x0+(d*10)),y0);
    line(x0,(y0-(2*V)),x0,(y0+(2*V)));

    if(choice == 1){
    	for(int i=0;i<10;i++){
            arr1[i] = *(p+i);
    	}
    	/*for(int i=0;i<10;i++){
            cout<<*(p+i);
    	}*/
    }

    else if(choice == 2){
        for(int i=0;i<24;i++){
            arr2[i] = *(p+i);
    	}
    }
    else{
        cout<<"Wrong choice! Choose from either 1 or 2.";
    }

    setcolor(RED);

    if(encoding == 1){

        x1 = x0 ; y1=y0;
        for(int i=0;i<10;i++){
            setcolor(RED);
            if(arr1[i] == 0){
               if(i==0){
                line(x1,y1,x1,y1-V);
                    y1=y1-V;
               }
               line(x1,y1,x1+d,y1);
               x1=x1+d;
               if(arr1[i]!=arr1[i+1]){
                line(x1,y1,x1,y1+2*V);
                y1=y1+2*V;
               }
            }
            else{
                if(i==0){
                    line(x1,y1,x1,y1+V);
                    y1=y1+V;
               }
               line(x1,y1,x1+d,y1);
               x1=x1+d;
               if(arr1[i]!=arr1[i+1]){
                    line(x1,y1,x1,y1-2*V);
                    y1=y1-2*V;
               }
            }
        }
    }
    else if(encoding == 2){
        x1 = x0; y1=y0-d; int c = 0;
        for(int i=0;i<10;i++){
            if(i==0){
                line(x1,y1,x1+d,y1);
                x1=x1+d;
            }
            else{
                if(arr1[i]==0){
                    line(x1,y1,x1+d,y1);
                    x1=x1+d;
                }
                else{
                    if(c==0){
                        line(x1,y1,x1,y1+2*V);
                        y1=y1+2*V;
                        line(x1,y1,x1+d,y1);
                        x1=x1+d;
                        c = 1;
                    }
                    else{
                        line(x1,y1,x1,y1-2*V);
                        y1=y1-2*V;
                        line(x1,y1,x1+d,y1);
                        x1=x1+d;
                        c = 0;
                    }
                }
            }
        }
    }
    else if(encoding == 3){
        int xv,yv; x1=x0;y1=y0;
        for(int i=0;i<10;i++){
            if(arr1[i]==0){
                //if(i==0){
                    line(x1,y0-V,x1+d/2,y0-V);
                    x1=x1+d/2; y1=y0-V;

                line(x1,y1,x1,y1+2*V);
                y1+=2*V;
                line(x1,y1,x1+d/2,y1);
                x1=x1+d/2;

                if(arr1[i]==arr1[i+1])
                    y1=y0-V;
                else
                    y1=y0+V;
            }
            else{
                //if(i==0){
                    line(x1,y0+V,x1+d/2,y0+V);
                    x1=x1+d/2; y1=y0+V;
                line(x1,y1,x1,y1-2*V);
                y1-=2*V;
                line(x1,y1,x1+d/2,y1);
                x1=x1+d/2;

                if(arr1[i]==arr1[i+1])
                    y1=y0+V;
                else
                    y1=y0-V;
            }
            if(arr1[i]==arr1[i+1]){
                xv=x1;yv=y0-V;
                line(xv,yv,xv,yv+2*V);
            }
        }
    }
    else if(encoding == 4){
        int c;
        if(arr1[0]==0){
            c=1;
        }
        else{
            c=0;
        }
        x1=x0; y1=y0-V;
        for(int i=0;i<10;i++){
            if(arr1[i]==0){
                if(i==0){
                    line(x1,y1,x1,y1+2*V);
                    y1+=2*V;
                    line(x1,y1,x1+d/2,y1); x1+=d/2;
                    line(x1,y1,x1,y1-2*V); y1-=2*V;
                    line(x1,y1,x1+d/2,y1); x1+=d/2;
                    if(arr1[i+1]==1) c=0;
                }
                else{
                    if(c==0){
                        line(x1,y1,x1,y1-2*V); y1-=2*V;
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        line(x1,y1,x1,y1+2*V); y1+=2*V;
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        if(arr1[i+1]==1) c=1;
                    }
                    else{
                        line(x1,y1,x1,y1+2*V); y1+=2*V;
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        line(x1,y1,x1,y1-2*V); y1-=2*V;
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        if(arr1[i+1]==1) c=0;
                    }
                }
            }
            else{
                if(i==0){
                    line(x1,y1,x1+d/2,y1); x1+=d/2;
                    line(x1,y1,x1,y1+2*V); y1+=2*V;
                    line(x1,y1,x1+d/2,y1); x1+=d/2;
                    if(arr1[i+1]==1) c=1;
                }
                else{
                    if(c==0){
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        line(x1,y1,x1,y1+2*V); y1+=2*V;
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        if(arr1[i+1]==1) c=1;
                    }
                    else{
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        line(x1,y1,x1,y1-2*V); y1-=2*V;
                        line(x1,y1,x1+d/2,y1); x1+=d/2;
                        if(arr1[i+1]==1) c=0;
                    }
                }
            }
        }
    }
    else if(encoding == 5){
        cout<<"Is scrambling needed? Y: Yes , N: No\n";
        char c;
        cin>>c;
        if(c == 'Y'){
            cout<<"\nWhat type of scrambling technique is needed? Choice: (1)B8ZS , (2)HDB3\n";
            int scramb; cin>>scramb;
            int count2,i,j,c, ind[10];
            count2=0;i=0;c=0;j=0;
            setcolor(GREEN);
            line(x0,y0,(x0+(d*24)),y0);
            setcolor(RED);
            if(scramb == 1){
                for(i=0;i<24;i++){
                    if(arr2[i]==1)
                        count2=0;
                    else{
                        count2++;
                        if(count2==8){
                            ind[j]=i-7;
                            c++;
                            count2=0;
                        }
                    }
                }
                int D=0;
                x1=x0;y1=y0;int c=0;
                setcolor(RED);
                for(int k=0;k<24;k++){
                    if(k<ind[D] || k>ind[D]+7){
                        for(int i=0;i<10;i++){
                            if(arr2[i]==0){
                                line(x1,y1,x1+d,y1); x1+=d;
                            }
                            else{
                                if(c==0){
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    c=1;
                                }
                                else{
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    c=0;
                                }
                            }
                        }
                    }
                    else{
                        for(k=ind[D];k<ind[D]+8;k++){
                            if(k<ind[D]+3){
                                line(x1,y1,x1+d,y1);x1+=d;
                            }
                            else if(k==(ind[D]+3) || k==(ind[D]+6)){
                                if(c==0) c=1; else c=0;
                                if(c==0){
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    c=1;
                                }
                                else{
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    c=0;
                                }
                            }
                            else if(k==(ind[D]+4) || k==(ind[D]+7)){
                                if(c==0){
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    c=1;
                                }
                                else{
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    c=0;
                                }
                            }
                            else if(k==(ind[D]+5)){
                                line(x1,y1,x1+d,y1); x1+=d;
                            }
                            D++;
                        }
                    }
                }
            }
            else{
                count2=0;
                for(i=0;i<24;i++){
                    if(arr2[i]==1)
                        count2=0;
                    else{
                        count2++;
                        if(count2==4){
                            ind[j]=i-7;
                            c++;
                            count2=0;
                        }
                    }
                }
                int D=0;
                x1=x0;y1=y0;int c=0;
                setcolor(RED);
                for(int k=0;k<24;k++){
                    if(k<ind[D] || k>ind[D]+7){
                        for(int i=0;i<10;i++){
                            if(arr2[i]==0){
                                line(x1,y1,x1+d,y1); x1+=d;
                            }
                            else{
                                if(c==0){
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    c=1;
                                }
                                else{
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    c=0;
                                }
                            }
                        }
                    }
                    else{
                        for(k=ind[D];k<ind[D]+8;k++){
                            if(k<ind[D]+3){
                                line(x1,y1,x1+d,y1);x1+=d;
                            }
                            else if(k==(ind[D]+3) || k==(ind[D]+6)){
                                if(c==0) c=1; else c=0;
                                if(c==0){
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    c=1;
                                }
                                else{
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    c=0;
                                }
                            }
                            else if(k==(ind[D]+4) || k==(ind[D]+7)){
                                if(c==0){
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    c=1;
                                }
                                else{
                                    line(x1,y1,x1,y1+V); y1+=V;
                                    line(x1,y1,x1+d,y1); x1+=d;
                                    line(x1,y1,x1,y1-V); y1-=V;
                                    c=0;
                                }
                            }
                            else if(k==(ind[D]+5)){
                                line(x1,y1,x1+d,y1); x1+=d;
                            }
                            D++;
                        }
                    }
                }

            }
        }
        else if(c == 'N'){
            x1=x0;y1=y0;int c=0;
            setcolor(RED);
            for(int i=0;i<10;i++){
                if(arr1[i]==0){
                    line(x1,y1,x1+d,y1); x1+=d;
                }
                else{
                    if(c==0){
                        line(x1,y1,x1,y1-V); y1-=V;
                        line(x1,y1,x1+d,y1); x1+=d;
                        line(x1,y1,x1,y1+V); y1+=V;
                        c=1;
                    }
                    else{
                        line(x1,y1,x1,y1+V); y1+=V;
                        line(x1,y1,x1+d,y1); x1+=d;
                        line(x1,y1,x1,y1-V); y1-=V;
                        c=0;
                    }
                }
            }
        }
    }

    getch();
    closegraph();
    return 0;
}
