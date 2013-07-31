/*

Matrix inverse program 

Copyright © 2013 Yaman Kalaji, Antranig Momjian, Rami Haffar 
Website : www.yaman-ka.com
E-Mail : info@yaman-ka.com

This program is free software; you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the Free 
Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, 
write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 

*/




#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
const char *FILENAME = "Result.txt";
using namespace std;

int main()
{
  int n,i,j,zero=0,ii;
	ofstream fout(FILENAME);
	cout<<" Enter \"N\" number of rows & columns of a matrix [N]x[N]: \n";
	cin>> n;
	if(n<=0)
	{
		cout<<"\nPlease make sure from that number .";
		fout<<"\nPlease make sure from that number .";
		goto out;
	}
	
    double X[n][2*n],a;
	cout<< " \nEnter the elemnts of the matrix : \n"<<"\n";

    // To enter elements of the matrix & make ones matrix

	for(i=0;i<n;i++)  
	{
		for(j=0;j<n;j++)
		{
			cout << "X["<<i+1<<"]"<<"["<<j+1<<"] = ";
			cin>>X[i][j];
			
		     	if((X[i][j]==-0)||((X[i][j]>-0.00000001) && (X[i][j]<0.00000001)))
                      {
                       	X[i][j]=0;
                      }
		}
		for(j=n;j<2*n;j++)
		{
			if((i+n)==j)
			X[i][j]=1;
			else
			X[i][j]=0;
		}
	}


           // printing basic matrix
           
            cout<<"\n\n";
            fout<<"\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<n;j++)
                    {
                    
            
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
  
                   }
            }
          cout<<"\n\n\n";
          fout<<"\n\n\n";
          
     

   // CHECKING for zeros



            for(i=0;i<n;i++) // to find if there is any row is full of zeros
              { 
		  	      zero=0;
		 	  
                  for(j=0;j<n;j++)
                {
                  if(X[i][j]==0)
                  {
                     ++zero;
                     if(zero==n)
                       {
                        cout << "\n\nThis matrix can not be inversed , ";
                        fout << "\n\nThis matrix can not be inversed , ";
			 	     	cout << "Because the row number ("<< i+1<<") is full of zeros ";
			 	    	fout << "Because the row number ("<< i+1<<") is full of zeros ";
                         goto out;
                       }
                  }
                }
             }
        
        
            for(j=0;j<n;j++) // to find if there is any column is full of zeros
            { 
			  zero=0;
			  
              for(i=0;i<n;i++)
              {
                if(X[i][j]==0)
                  {
                    ++zero;
                    if(zero==n)
                    {
                    cout << "\nThis Matrix Can Not Be Inversed , " ;
                    fout << "\nThis Matrix Can Not Be Inversed , " ;
					cout << "Because The Column Number ("<< j+1<<") Is Full Of Zeros ";
					fout << "Because The Column Number ("<< j+1<<") Is Full Of Zeros ";
					
                    goto out;
                    }
                  }
             }
           }
        


  // end CHECKING for zeros


	 // Printing the hole extended matrix ( with eye matrix )
	 
            cout<<"\n\n\n";
            fout<<"\n\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<2*n;j++)
                    {
                    
                      
                      if(j==n)
                      {
                      	cout<<"   |      ";
                      	fout<<"   |      ";
                      }
                      
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
            cout<<"\n\n\n";
            fout<<"\n\n\n";
              
            
            
              
         for(ii=0;ii<n-1;ii++)  // main code, (ii) is the looping item
        {
         
           
		    if(X[ii][ii]==0)   // in case the X[ii][ii]=0 , then we'll search for an elemnt !=0 from
			                  // the same column , then we'll add that row to the first row
            {
            	
            	
            	for(i=(ii+1);i<n;i++)
            	{
            		
            		if(X[i][ii]!=0)
            		{
            			for(j=0;j<2*n;j++)
            			{
            				X[ii][j]=X[ii][j]+X[i][j];
            				
            				if((X[ii][j]==-0)||((X[ii][j]>-0.00000001) && (X[ii][j]<0.00000001)))
                                  {
                                 	X[ii][j]=0;
                                  }
                       
            			
            			}
            	    	break;	
            		}
            		
                
            	}
            	
                if(X[ii][ii]==0) // This situation is for two columns with the same numbers , 
                                // or proportion
                {
                    cout << "\n\nThis matrix can not be inversed , " ;
                    fout << "\n\nThis matrix can not be inversed , " ;
					cout << "Because the determinant = 0 ";
					fout << "Because the determinant = 0 ";
					
                    goto out;	
                }
             
             // Printing the hole extended matrix 
            fout<<"\n\n\n";
            cout<<"\n\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<2*n;j++)
                    {
                    
                      if(j==n)
                      {
                      	cout<<"   |      ";
                      	fout<<"   |      ";
                      }
                      
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
          
           }




            
          if(X[ii][ii]!=1)
		  {  
            a=X[ii][ii]; 
            
            for(j=0;j<2*n;j++) 
              {
              
			  X[ii][j]=X[ii][j]/a; // to make X[ii][ii] = 1 & divide all the row on X[ii][ii]
			  
			  if((X[ii][j]==-0)||((X[ii][j]>-0.00000001) && (X[ii][j]<0.00000001)))
                      {
                       	X[ii][j]=0;
                      }
                       
              }
              
           // Printing the hole extended matrix 
            cout<<"\n\n\n";
            fout<<"\n\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<2*n;j++)
                    {
                    
                     
                        if(j==n)
                      {
                      	cout<<"   |      ";
                      	fout<<"   |      ";
                      }
                      
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
            
         }
          
            
            
           
            for(i=ii+1;i<n;i++)  // to make every element under X[ii][ii] equal to zero
            {
                    a=X[i][ii];
              for(j=ii;j<2*n;j++)
                {	
                	X[i][j]=-a*X[ii][j]+X[i][j];
                	
                	if((X[i][j]==-0)||((X[i][j]>-0.00000001) && (X[i][j]<0.00000001)))
                      {
                       	X[i][j]=0;
                      }
                       
                }
            }
                
              // Printing the hole extended matrix 
            cout<<"\n\n\n";
            fout<<"\n\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<2*n;j++)
                    {
                    
                      
                       if(j==n)
                      {
                      	cout<<"   |      ";
                      	fout<<"   |      ";
                      }
                      
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
            
            
       }
             
         
         
          if(X[n-1][n-1]==0)
          {
          	
          	
            	cout << "\n\nThis matrix can not be inversed , ";
                fout << "\n\nThis matrix can not be inversed , ";
			   	cout << "because there is a row full of zeros ( determinant = 0 )";
			   	fout << "because there is a row full of zeros ( determinant = 0 )";
                   goto out;
          	
          	
          }
         

              
          if(X[n-1][n-1]!=1)
		  {  
            a=X[n-1][n-1]; 
            
            for(j=0;j<2*n;j++) 
             {
                              // to make X[n-1][n-1] = 1 & divide all the row on X[n-1][n-1]
			  X[n-1][j]=(X[n-1][j]/a); 
			   
			   if((X[n-1][j]==-0)||((X[n-1][j]>-0.00000001) && (X[n-1][j]<0.00000001)))
                      {
                       	X[n-1][j]=0;
                      }
                       
             }
             
           // Printing the hole extended matrix 
            cout<<"\n\n\n";
            fout<<"\n\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<2*n;j++)
                    {
                    
                    
                       if(j==n)
                      {
                      	cout<<"   |      ";
                      	fout<<"   |      ";
                      }
                      
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
            
            
         }
          
          
          
            for(ii=n-1;ii>0;ii--)
          {
            
               for(i=ii-1;i>=0;i--)  // to make every element over X[ii][ii] equal to zero
            {
            	
                    a=X[i][ii];
              for(j=0;j<2*n;j++)
                {	
                	X[i][j]=-a*X[ii][j]+X[i][j];
                	
                	if((X[i][j]==-0)||((X[i][j]>-0.00000001) && (X[i][j]<0.00000001)))
                      {
                       	X[i][j]=0;
                      }
                }
            }
                
                  
           // Printing the hole extended matrix 
            cout<<"\n\n\n";
            fout<<"\n\n\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	                for(j=0;j<2*n;j++)
                    {
                    
                     
                       if(j==n)
                      {
                      	cout<<"   |      ";
                      	fout<<"   |      ";
                      }
                      
                      cout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                      fout<<setw(12)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
            
            
         }
          
          
           cout<<"\n\n\nThe inversed matrix is :";
           fout<<"\n\n\nThe inversed matrix is :";
         
           // Printing the hole extended matrix 
            cout<<"\n";
            fout<<"\n";
	    	for(i=0;i<n;i++)
	    	{
	           cout<<"\n";
	           fout<<"\n";
	          
	                for(j=n;j<2*n;j++)
                    {
                    
                      if((X[i][j]==-0)||((X[i][j]>-0.00000001) && (X[i][j]<0.00000001)))
                      {
                       	X[i][j]=0;
                      }
                       
  cout<<setw(12)<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
  fout<<setw(12)<<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setprecision(8)<<X[i][j]<<"  ";
                   }
            }
             
             
    out:
    	
    	

            cout<<"\n\n\n*****************************************************";
            cout<<"\n*****************************************************";
            fout<<"\n\n\n*****************************************************";
            fout<<"\n*****************************************************";
              
             cout<<"\n\nThis program is developed by students  : \n"; 
			 cout<<"* Yaman Kalaji , E-Mail : info@yaman-ka.com \n"; 
			 cout<<"* Antranig Momjian , E-Mail : www.antranigmom@hotmail.com \n";
			 cout<<"* Rami Haffar , E-Mail : ram22293@hotmail.it \n"; 
             cout<<"\n\nUnder supervision of :\n * Dr.Abd Al-Naser Shamsi \n * Eng.Ammar Rehawi ";
             cout<<"\n\nUniversity of Aleppo,Syria ";
             cout<<"\n Electrical and Electronic Engineering Faculty";
             cout<<"\n Computer engineering department ";

			 
			 fout<<"\n\nThis program is developed by students  : \n";
			 fout<<"* Yaman Kalaji , E-Mail : info@yaman-ka.com \n"; 
		     fout<<"* Antranig Momjian , E-Mail : www.antranigmom@hotmail.com \n"; 
			 fout<<"* Rami Haffar , E-Mail : ram22293@hotmail.it \n";  
             fout<<"\n\nUnder supervision of :\n * Dr.Abd Al-Naser Shamsi \n * Eng.Ammar Rehawi ";
             fout<<"\n\nUniversity of Aleppo,Syria ";
             fout<<"\nElectrical and Electronic Engineering Faculty";
             fout<<"\nComputer engineering department ";
            
             fout.close(); 
             ifstream fin(FILENAME); 
             fin.close(); 
            
        system ("pause");
	    return 0;
}
