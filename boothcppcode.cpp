#include<iostream>
#include<cmath>
using namespace std;

void insertion (int* arr, int n, int pos, int data){
  for (int i = n - 1; i >= pos - 1; i--){
      arr[i + 1] = arr[i];
    }
  arr[pos] = data;
}
int sizes[3] = {0};
void dectobinpos(int* arr,int number,int n){
    int i=0;
    int temp[32] = {0};
    while(number > 0){
        temp[i] = number%2;
        number = number/2;
        i++;
    }
    for(int j=0;j<i;j++){
        arr[j] = temp[i-j-1];
    }
    insertion(arr,i,0,0);
    i++;
    sizes[n] = i;
}
void dectobinneg(int* arr,int number,int n){
    number = number* -1;
    dectobinpos(arr,number,n);
    for(int j=0;j<=sizes[n];j++){
        if(arr[j] == 0){
            arr[j] = 1;
        }else{
            arr[j] = 0;
        }
    }
    int c = 1;
    for(int j=sizes[n];j>=0;j--){
        arr[j] = arr[j] + c;
        if(arr[j] == 2){
            arr[j] = 0;
            c = 1;
        }else{
            c = 0;
        }
    }
}
void DecimalToBinary(int* arr,int number,int n){
    if(number > 0){
        dectobinpos(arr,number,n);
    }else{
        dectobinneg(arr,number,n);
    }
}
void Binaryadd(int* drr,int* brr){
    int d = 0;
    for(int l=sizes[1]-1;l>=0;l--){
        drr[l] = drr[l] + brr[l] + d;
        if(drr[l] == 3){
            drr[l] = 1;
            d = 1;
        }
        else if(drr[l] == 2){
            drr[l] = 0;
            d = 1;
        }
        else if(drr[l] == 1){
            drr[l] = 1;
            d = 0;
        }
        else{
            d = 0;
        }
    }
}
void ashr(int* a,int* b,int& c,int size){
    int n = 2*(size) + 1;
    int temp[n] = {0};
    for(int i=0;i<size;i++){
        temp[i] = a[i];
    }
    for(int i=size;i<n-1;i++){
        temp[i] = b[i-size];
    }
    temp[n-1] = c;
    int temp1[n] = {0};
    for(int i=0;i<n;i++){
        temp1[i] = temp[i];
    }
    for(int i=1;i<n;i++){
        temp[i] = temp1[i-1];
    }
    for(int i=0;i<size;i++){
        a[i] = temp[i];
    }
    for(int i=size;i<n-1;i++){
        b[i-size] = temp[i];
    }
    c = temp[n-1];
}
int compliment(int* arr,int size){
   for(int i=0;i<size;i++){
       if(arr[i] == 1){
           arr[i] = 0;
       }else{
           arr[i] = 1;
       }
   }
   int c = 1;
   for(int i = size-1;i>=0;i--){
       arr[i] += c;
       if(arr[i] == 2){
           arr[i] = 0;
           c = 1;
       }else{
           c = 0;
       }
   }
    int r = 0;
    for(int i =size-1;i>0;i--){
        r += arr[i] * pow(2,size-1-i);
    }
    return r;
}
void rotate(int* m,int* q,int* negm){
    if(sizes[0] == sizes[1]){
        return;
    }
    else if(sizes[0] > sizes[1]){
        int size = sizes[0] - sizes[1];
        while(size != 0){
        for(int i= sizes[0];i>0;i--){
            q[i] = q[i-1];
        }
        size--;
        }
        sizes[1] = sizes[0];
    }
    else {
        int size = sizes[1] - sizes[0];
        while(size != 0){
            for(int i= sizes[1];i>0;i--){
                m[i] = m[i-1];
                negm[i] = negm[i-1]; 
            }
            size--;
        }
        sizes[0] = sizes[1];
        sizes[2] = sizes[1];
    }
}
int main(){
    int Multiplicand;
    cout<<endl<<"Enter the Multiplicand : ";
    cin>>Multiplicand;
    int tem = Multiplicand;
    int m[32] = {0};
    cout<<endl<<"Multiplicand in Binary signed Number is : ";
    DecimalToBinary(m,Multiplicand,0);
    for(int i=0;i<sizes[0];i++){
        cout<<m[i];
    }
    int Multiplyer;
    cout<<endl<<"Enter the Multiplyer : ";
    cin>>Multiplyer;
    int q[32] = {0};
    cout<<endl<<"Multiplyer in Binary signed Number is : ";
    DecimalToBinary(q,Multiplyer,1);
    for(int i=0;i<sizes[1];i++){
        cout<<q[i];
    }
    int answ = Multiplyer*Multiplicand;
    cout<<endl<<"The Required Answer is : "<<answ;
    int negm[32];
    Multiplicand = Multiplicand * -1;
    cout<<endl<<"Negative of Binary signed Multiplicand is : ";
    DecimalToBinary(negm,Multiplicand,2);
    for(int i=0;i<sizes[2];i++){
        cout<<negm[i];
    }
    rotate(m,q,negm);
    int qn = 0;
    int* ptr = &qn;
    int count = sizes[1];
    int A = sizes[2]-1;
    int a = sizes[2] ;
    int Ac[a] = {0};
    for(int j=0;j<count;j++){
        if(q[A] == 0 && qn == 0 || q[A] == 1 && qn == 1){
            ashr(Ac,q,*ptr,a);
            cout<<endl<<"The contain in Ac is : ";
            for(int i=0;i<sizes[1];i++){
                cout<<Ac[i];
            }
            cout<<endl<<"The contain in q is : ";
            for(int i=0;i<sizes[1];i++){
                cout<<q[i];
            }
            cout<<endl<<"The contain in qn is : "<<qn;
        }
        else if(q[A] == 0 && qn == 1){
            Binaryadd(Ac,m);
            ashr(Ac,q,*ptr,a);
            cout<<endl<<"The contain in Ac is : ";
            for(int i=0;i<sizes[1];i++){
                cout<<Ac[i];
            }
            cout<<endl<<"The contain in q is : ";
            for(int i=0;i<sizes[1];i++){
                cout<<q[i];
            }
            cout<<endl<<"The contain in qn is : "<<qn;
        }
        else if(q[A] == 1 && qn == 0){
            Binaryadd(Ac,negm);
            ashr(Ac,q,*ptr,a);
            cout<<endl<<"The contain in Ac is : ";
            for(int i=0;i<sizes[1];i++){
                cout<<Ac[i];
            }
            cout<<endl<<"The contain in q is : ";
            for(int i=0;i<sizes[1];i++){
                cout<<q[i];
            }
            cout<<endl<<"The contain in qn is : "<<qn;
        }
    }
    int ansize = 2*a;
    int result[ansize] = {0};
    for(int i =0;i<sizes[1];i++){
        result[i] = Ac[i];
    }
    for(int i=sizes[1];i<ansize;i++){
        result[i] = q[i-sizes[1]];
    }
    cout<<endl<<"The Result Of The Booth Multiplication is : ";
    for(int i=0;i<ansize;i++){
        cout<<result[i];
    }
    cout<<endl<<"Let's Check our result by converting it into Decimal Number ";
    int re = 0;
    if(result[0] == 0){
    for(int i =ansize-1;i>=1;i--){
        re += result[i] * pow(2,ansize-1-i);
    }
    }else{
        re = -1 * compliment(result , ansize);
    }
    cout<<endl<<"Our result in Decimal Number is : "<<re;
    if(re == answ){
        cout<<endl<<"Since our calculated and required result are same our Booth algorithm worked perfectely";
    }else{
        cout<<endl<<"There are Some Error in our Result ";
    }
    return 0;
}