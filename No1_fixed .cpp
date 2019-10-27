#include <stdlib.h>
#include<iostream>
using namespace std; 
  

void bestFit(int bSize[], int m, int pSize[], int n) 
{ 

    int allocation[n]; 
    
    int filled[m];
    
    int frag[n];
    
     
    for(int i = 0; i < n; i++)
	{
		allocation[i] = -1;
		
	}
	
	for(int i = 0; i < m; i++)
	{
		filled[i] = -1;
		
	}
     

    for (int i=0; i<n; i++) 
    { 
        
        int bestfit = -1; 
        for (int j=0; j<m; j++) 
        {  
		 if(filled[j] !=1 ){
            if (bSize[j] >= pSize[i]) 
            { 
                if (bestfit == -1) 
                    bestfit = j; 
                else if (bSize[bestfit] > bSize[j]) 
                    bestfit = j; 
            } 
        }
        } 
  
         
        if (bestfit != -1) 
        { 
           frag[i] = bSize[bestfit]-pSize[i];
           
           
            filled[bestfit]=1;
            
            allocation[i] = bestfit;
			
			 
  

        } 
    } 
    cout<<"\n BEST FIT \n\n";
    cout << "\nProcess No.\tProcess Size\tBlock no. \tInternal Fragmentation\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << "   " << i+1 << "\t\t" << pSize[i] << "\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1 << "\t\t"<< frag[i]; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
} 

void firstFit(int bSize[], int m,  
              int pSize[], int n) 
{ 
    
    int allocation[n]; 
    
    int filled[m];
    
    int frag[n];
  
    for(int i = 0; i < n; i++)
	{
		allocation[i] = -1;
		
	}
	
	for(int i = 0; i < m; i++)
	{
		filled[i] = -1;
		
	}
  
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        { 
            if(filled[j] !=1 )
            {
			
            if (bSize[j] >= pSize[i]) 
            { 
                
                allocation[i] = j;
				
				frag[i] = bSize[j] - pSize[i]; 
   
                bSize[j] -= pSize[i]; 
                
                filled[j]=1;
  
                break; 
            } 
        }
        } 
    } 
    cout<<"\n FIRST FIT \n\n";
    cout << "\nProcess No.\tProcess Size\tBlock no. \t internal fragmentation\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << " " << i+1 << "\t\t" 
             << pSize[i] << "\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1 << "\t\t" << frag[i]; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
} 

void worstFit(int bSize[], int m, int pSize[], int n) 
{ 
    
    int allocation[n]; 
    
    int filled[m];
    
    int frag[n];
  
    for(int i = 0; i < n; i++)
	{
		allocation[i] = -1;
		
	}
	
	for(int i = 0; i < m; i++)
	{
		filled[i] = -1;
		
	}
  
 
    for (int i=0; i<n; i++) 
    {  
        int worstfit = -1; 
        for (int j=0; j<m; j++) 
        { 
            if(filled[j] != 1)
            {
            if (bSize[j] >= pSize[i]) 
            { 
                if (worstfit == -1) 
                    worstfit = j; 
                else if (bSize[worstfit] < bSize[j]) 
                    worstfit = j; 
            } 
        }
        } 
  
        if (worstfit != -1) 
        { 
        
            frag[i] = bSize[worstfit] - pSize[i]; 
             
            
            allocation[i] = worstfit; 
            
            filled[worstfit]=1;
            
            
   
            bSize[worstfit] -= pSize[i]; 
        } 
    } 
     cout<<"\n WORST FIT \n\n";
    cout << "\nProcess No.\tProcess Size\tBlock no. \t Internal Fragmentation\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << "   " << i+1 << "\t\t" << pSize[i] << "\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1<<"\t\t"<<frag[i]; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
} 
  
  
int main() 
{ 
   s:
   int memo,pno,scheme,back;
    
    int pSize[pno];
    
    cout << "Enter the memory capacity>>> ";
	cin >> memo;
	
	int bmo = 4; // number of blocks 
	int bSize[] = {0.1*memo, 0.2*memo, 0.3*memo,0.4*memo};
	
	cout << endl;
	cout << "Enter number of process>>> ";
	cin >> pno;
	cout << endl;
	for(int i = 0; i < pno; i++)
	{
		cout << "Enter memory request for process "<<i+1<<">>> ";
		cin >> pSize[i];
		cout << endl;
	}
	
	cout<<"\n Please Choose one Scheme:";
	cout<<"\n 1.Bestfit";
	cout<<"\n 2.firstfit";
	cout<<"\n 3.worstfit";
	cin>>scheme;
	
	if(scheme==1){
		bestFit(bSize, bmo, pSize, pno);
		cout<<"Enter 1 to go back or any key to end ";
		cin>>back;
		if(back==1)
		{
		
		   system("CLS");
		   goto s;
	}
	else{
			exit(0);
		
	}
	}
	
	if(scheme==2){
		firstFit(bSize, bmo, pSize, pno);
		cout<<"Enter 1 to go back or any key to end ";
		cin>>back;
		if(back==1)
		{
		   system("CLS");
		   goto s;
	   }
	   else{
	   	exit(0);
	   }
	
		
	}
	
	if(scheme==3){
		worstFit(bSize, bmo, pSize, pno);
		cout<<"Enter 1 to go back or any key to end ";
		cin>>back;
		if(back==1){
		
		   system("CLS");
		   goto s;
	}
		else{
			exit(0);
		}
		
	}
	
  
  
    return 0 ;
} 

