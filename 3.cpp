/******************************************************************************
20190702104
Hasan Can Güler
05.03.2021 Lab2 - Exercise-3
*******************************************************************************/

#include <iostream>

using namespace std;

int defineSeetIndex(int seets[],int startSeet)
{
    for (int index = startSeet; index < startSeet+5; index++) {
      if(seets[index]==0)
      {
        return index;
      }
    }
    return -1;
}

int convertIndextoSeetNumber(int index)
{
    return index+1;
}

int main()
{
    int seets[10];
    for (int index = 0; index < 9; index++) {
        seets[index] = 0;
    }
    int const seetStartFirst = 0;
    int const seetStartEconomy = 5;
    int classType = 0;
    do{
        cout<<"\nPlease type 1 for first class ";
        cout<<"\nPlease type 2 for economy class ";
        cin>>classType;
        
        if(classType!=1 && classType!=2)
        {
            cout<<"\nNot a valid class type";
            continue; //turn start
        }
        
        int seetIndex;
        int startSeet;
        
        //first class
        if(classType==1)
            startSeet = seetStartFirst;
        //economy class
        if(classType==2)
            startSeet = seetStartEconomy;
        
        seetIndex = defineSeetIndex(seets,startSeet);
        
        //If first class could not found seet check economy
        if(seetIndex==-1 && classType==1)
        {
            
            seetIndex = defineSeetIndex(seets,seetStartEconomy);
            if(seetIndex!=-1)
            {
                string acceptFirstClass;
                cout<<"\nFirst Class is full, Do you want to Economy : Y/N ";
                cin>>acceptFirstClass;
                
                if(acceptFirstClass=="Y"||acceptFirstClass=="y")
                {
                    seets[seetIndex] = convertIndextoSeetNumber(seetIndex);
                }
                else
                {
                    cout<<"\nNext flight leaves in 3 hours.";
                    continue;
                }
                    
            }
        }
        if(seetIndex==-1 && classType==2)
        {
            cout<<"\nEconomy is full";
            continue;
        }
            
        if(seetIndex!=-1)
        {
            seets[seetIndex] = convertIndextoSeetNumber(seetIndex);
            cout<<"\nSeet Number : "<< seets[seetIndex]<<" \n ";
        }
        if(seetIndex==-1)
        {
            cout<<"\nAll Fly is full, Next flight leaves in 3 hours.";
        }
        
    }while(true);

    return 0;
}
