#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h> // atoi

using namespace std;

struct Data{
    int day; // 1-7
    int packageNum; // 1-40
    int dist; // -30
} temp;
Data * dataArray = new Data[280]; // 7*40
int lineNum=0;


void t2(){
    int minHely=0;
    for(int i=0;i<lineNum;i++){
        if(dataArray[i].day<=dataArray[minHely].day && dataArray[i].packageNum==1){
            minHely=i;
        }
    }
    cout<<dataArray[minHely].dist<<"km"<<endl;
}
void t3(){
    int maxHely=0;
    for(int i=0;i<lineNum;i++){
        if(dataArray[i].day>=dataArray[maxHely].day){
            maxHely=i;
        }
    }
    for(int i=0;i<lineNum;i++){
        if(dataArray[i].packageNum>=dataArray[maxHely].packageNum && dataArray[i].day==dataArray[maxHely].day){
            maxHely=i;
        }
    }
    cout<<dataArray[maxHely].dist<<"km"<<endl;
}
void t4(){
    int workdays[7];
    for(int k=0;k<7;k++){ // Init
        workdays[k]=0;
    }
    for(int i=0;i<lineNum;i++){
        switch(dataArray[i].day){
        case 1:
            workdays[0]++;
            break;
        case 2:
            workdays[1]++;
            break;
        case 3:
            workdays[2]++;
            break;
        case 4:
            workdays[3]++;
            break;
        case 5:
            workdays[4]++;
            break;
        case 6:
            workdays[5]++;
            break;
        case 7:
            workdays[6]++;
            break;
        }
    }

    for(int i=0;i<7;i++){
        if(workdays[i]==0){
            cout<<i+1<<". nap szabadnap."<<endl;
        }
    }
}
void t5(){
    int shippingNum[7];
    for(int i=0;i<lineNum;i++){
        switch(dataArray[i].day){
        case 1:
            shippingNum[0]++;
            break;
        case 2:
            shippingNum[1]++;
            break;
        case 3:
            shippingNum[2]++;
            break;
        case 4:
            shippingNum[3]++;
            break;
        case 5:
            shippingNum[4]++;
            break;
        case 6:
            shippingNum[5]++;
            break;
        case 7:
            shippingNum[6]++;
            break;
        }
    }

    int maxInd=0;
    for(int i=0;i<7;i++){
        if(shippingNum[i]>shippingNum[maxInd]){
            maxInd=i;
        }
    }
    cout<<"A het "<<maxInd+1<<". napjan volt a legtobb fuvar."<<endl;
}
void t6(){
    int disPerDay[7];
    for(int i=0;i<7;i++){ // Init
        disPerDay[i]=0;
    }
    for(int i=0;i<lineNum;i++){
        switch(dataArray[i].day){
        case 1:
            disPerDay[0]+=dataArray[i].dist;
            break;
        case 2:
            disPerDay[1]+=dataArray[i].dist;
            break;
        case 3:
            disPerDay[2]+=dataArray[i].dist;
            break;
        case 4:
            disPerDay[3]+=dataArray[i].dist;
            break;
        case 5:
            disPerDay[4]+=dataArray[i].dist;
            break;
        case 6:
            disPerDay[5]+=dataArray[i].dist;
            break;
        case 7:
            disPerDay[6]+=dataArray[i].dist;
            break;
        }
    }

    for(int i=0;i<7;i++){
        cout<<i+1<<". nap: "<<disPerDay[i]<<" km"<<endl;
    }
}
void t7(){
    int userInput=0;
    cout<<"Adjon meg egy tavolsagot: ";
    cin>>userInput;

    if(userInput>=1 && userInput<=2){
        cout<<"500Ft"<<endl;
    }else if(userInput>=3 && userInput<=5){
        cout<<"700Ft"<<endl;
    }else if(userInput>=6 && userInput<=10){
        cout<<"900Ft"<<endl;
    }else if(userInput>=11 && userInput<=20){
        cout<<"1400Ft"<<endl;
    }else if(userInput>=21 && userInput<=30){
        cout<<"2000Ft"<<endl;
    }else{
        cout<<"Nem megfelelo adat."<<endl;
    }
}
void t8(){
    ofstream fileOutput("dijazas.txt");

    for(int i=0;i<lineNum-1;i++){
        for(int c=i+1;c<lineNum;c++){
            if(dataArray[c].day<dataArray[i].day && dataArray[c].packageNum<dataArray[i].packageNum){
                temp.day = dataArray[i].day;
                temp.packageNum = dataArray[i].packageNum;
                temp.dist = dataArray[i].dist;

                dataArray[i].day = dataArray[c].day;
                dataArray[i].packageNum = dataArray[c].packageNum;
                dataArray[i].dist = dataArray[c].dist;

                dataArray[c].day = temp.day;
                dataArray[c].packageNum = temp.packageNum;
                dataArray[c].dist = temp.dist;
            }
        }
    }

    for(int i=0;i<lineNum;i++){
        int price=0;
        if(dataArray[i].dist>=1 && dataArray[i].dist<=2){
            price=500;
        }else if(dataArray[i].dist>=3 && dataArray[i].dist<=5){
            price=700;
        }else if(dataArray[i].dist>=6 && dataArray[i].dist<=10){
            price=900;
        }else if(dataArray[i].dist>=11 && dataArray[i].dist<=20){
            price=1400;
        }else if(dataArray[i].dist>=21 && dataArray[i].dist<=30){
            price=2000;
        }

        fileOutput<<dataArray[i].day<<". nap "<<dataArray[i].packageNum<<". ut: "<<price<<" Ft"<<"\n";
    }
    fileOutput.close();
    cout<<"Fajl elmentve."<<endl;
}
void t9(){
    int sum=0;
    for(int i=0;i<lineNum;i++){
        if(dataArray[i].dist>=1 && dataArray[i].dist<=2){
            sum+=500;
        }else if(dataArray[i].dist>=3 && dataArray[i].dist<=5){
            sum+=700;
        }else if(dataArray[i].dist>=6 && dataArray[i].dist<=10){
            sum+=900;
        }else if(dataArray[i].dist>=11 && dataArray[i].dist<=20){
            sum+=1400;
        }else if(dataArray[i].dist>=21 && dataArray[i].dist<=30){
            sum+=2000;
        }
    }
    cout<<"A heti fizetese: "<<sum<<"Ft."<<endl;
}

int main(){
    ifstream fileCounter("tavok.txt");
    ifstream fileInput("tavok.txt");

    string line="";
    if(fileCounter.is_open()){
        while(getline(fileCounter, line)){
            lineNum++;
        }
        fileCounter.close();
    }

    if(fileInput.is_open()){
        for(int i=0;i<lineNum;i++){
            fileInput>>dataArray[i].day;
            fileInput>>dataArray[i].packageNum;
            fileInput>>dataArray[i].dist;
        }
    }

    cout<<"1. Feladat"<<endl;
    cout<<"Fajl beolvasva."<<endl;
    cout<<endl;
    cout<<"2. Feladat"<<endl;
    t2();
    cout<<endl;
    cout<<"3. Feladat"<<endl;
    t3();
    cout<<endl;
    cout<<"4. Feladat"<<endl;
    t4();
    cout<<endl;
    cout<<"5. Feladat"<<endl;
    t5();
    cout<<endl;
    cout<<"6. Feladat"<<endl;
    t6();
    cout<<endl;
    cout<<"7. Feladat"<<endl;
    //t7();
    cout<<endl;
    cout<<"8. Feladat"<<endl;
    t8();
    cout<<endl;
    cout<<"9. Feladat"<<endl;
    t9();
    cout<<endl;

    return 0;
}
