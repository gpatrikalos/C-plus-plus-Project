#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream> 
#include <stdlib.h> 
using namespace std;


//stis klaseis dn vazw sxolia,einai ligo polu gnwsta,to mono pu prepei na pw einai oti o tipos stis katoikies einai tipou string,sta emporika h emporikotita einai 1 gia alithis 0 gia pseudis kai sta oikopeda o oikismos kai h kaliergia einai tipou string


class akinita
{
	public:
  string dieuthinsi;
  int epifania,etos;
  
  
  
  akinita()
  {
  	
  	dieuthinsi="N/A";
  	epifania=0;
  	etos=0;  	
  }
  
  
  akinita(string d,int e,int et)
  {
  	
  	dieuthinsi=d;
  	epifania=e;
  	etos=et;  	
  }
  
  
  
  
  	virtual int calcenfia()=0;

		
	 void display()
 {
 	cout << "Temperature: " << etos << "\n" << "Measurement date: " << epifania<< endl;
 }
	
		
		
		
};


class katikies:public akinita
{
	public:
	int orofos;
	string tipos;
	
	
	
	katikies():akinita()
	{
		
		orofos=1;
		tipos="N/A";
	}
	
	
		katikies(string ti,int orof,string d,int e,int etos):akinita(d,e,etos)
	{
		
		orofos=orof;
		tipos=ti;
	}
	
	int calcenfia()
	{
		if(tipos=="monokatoikia")		
			return 1.3*epifania+150;		  
		else
		   return 1.1*epifania+100;
	}

		
};


class emporika:public akinita
{
	public:
	int emporikotita;
	
	
		emporika():akinita()
	{
		
		emporikotita=1;
	}
	
	
		emporika(int empo,string d,int e,int etos):akinita(d,e,etos)
	{
		
		emporikotita=empo;
		
	}
	
	int calcenfia()
   {
			
	int temp=2*epifania+200*emporikotita;
	return temp;
  }
};





class oikopeda:public akinita
{
	public:
   	string oikismos,kaliergia;
   	
   	  	
   	oikopeda():akinita()
	{
		
		kaliergia="N/A";
		oikismos="N/A";
	}
	
	
		oikopeda(string kal,string oiki,string d,int e,int etos):akinita(d,e,etos)
	{
		
		oikismos=oiki;
		kaliergia=kal;
	}
   	
	   int calcenfia()
	{
	
		if(oikismos=="entos")
				
			return 0.3*epifania+250;		  
		else
		   return 0.3*epifania+70;
	
   }

};





class enfiad
{
	public:
	string onoma,epwnimo,dieuthinsi;
	int afm,etos,katastasi=0;
	vector <akinita*> v;
	
	
	
	enfiad()
	{
		onoma="N/A";
		epwnimo="N/A";
		dieuthinsi="N/A";
		afm=0;
		etos=0;	
	}
	
	
	enfiad(string o,string e,string d,int a,int etos)
	{
		onoma=o;
		epwnimo=e;
		dieuthinsi=d;
		afm=a;
		etos=etos;
				
	}
	
	int upologismos()
	{
		int foros=0;
		for(int i=0;i<v.size();i++)
		  {
		  	   foros=foros+v[i]->calcenfia();
		  }
		return foros;
	}
	
	
	
		int upologismos2(int a)          //sunartisi gia ipologismo forou tou kathe akinitou kai oxi gia oli ti dilwsi
	{
		int counter=0;
		for(int i=0;i<v.size();i++)
		  {
		  	   if(v[i]->calcenfia()>a)
		  	      counter++;
		  	      break;
		  }
		return counter;
	}
	
	
	
	
	void insertakinita(akinita *a)
	{
		
		v.push_back(a);
				
	}
	
	 
			
};



int main()
{
 vector <enfiad> e;         //vector gia na valw tis dilwsis tou kathe forologoumenou
 vector <string> sv;        //vector gia na vazw stoixeia apo to arxeio
 int epilogi,afm,etos,epifania,orofos,emporikotita,epilogi2,epilogi3,epilogi4;
 string onoma,dieuthinsi,epwnimo,d,tipos,oikismos,kaliergia,arxeio,eidos;
 printf("Epelexe\n1.Prosthiki dhlwshs\n2.Tropopoihsh dhlwshs\n3.Akurwsi dhlwshsh\n4.Dwse poso gia emfanisi megaliterwn forwn\n5.Dwse poso gia emnfanisi memonomenwmenwn akinitwn me megalitero foro\n6.Oi 10 Megaliteres dilwseis\n7.Exodos\n");
 scanf("%d",&epilogi);

 while(epilogi!=7)  //oso den exei patisei exodo
{
 
   switch(epilogi)
  {
       case 1:          //theli na kani dilwsi
       {  
          string temp;
          printf("dwse onoma,epwnimo,dieuthinsi,afm kai etos gennisis\n");
          cin>>onoma>>epwnimo>>dieuthinsi>>afm>>etos;
          enfiad neos(onoma,epwnimo,dieuthinsi,afm,etos);     //se kathe nea dilwsi dimiourgite neos forologoumenos
          cout<<"Prosthike apo arxeio keimenou? YES/NO\n";
          cin>>arxeio;
          if(arxeio=="yes")           //theli na vali apo arxeio
          {
          	ifstream infile("dilwseis.txt");
          	infile >>eidos >> d >> epifania >> etos >> orofos>>tipos;
          	
          	if(infile.is_open())
           {
 	          while(!infile.eof())
 	         {
 	           getline(infile,temp);
 	           istringstream ss(temp);
		       string token;
		       while(getline(ss, token,'|')) //split
	           	{
     	         sv.push_back(token);
		       }
		       if(sv[0]=="K")
		       {
			
			    d=sv[1]; //dieuthynsh
		        epifania=atoi(sv[2].c_str());//epifaneia
			    etos=atoi(sv[3].c_str());
			    orofos=atoi(sv[4].c_str());
			    tipos=sv[5];
			    neos.insertakinita( new katikies (tipos,orofos,d,epifania,etos));
		       }
		      else if(sv[0]=="E")
		      {
			    int emp;
				d=sv[1]; //dieuthynsh
				epifania=atoi(sv[2].c_str()); //epifaneia
				etos=atoi(sv[3].c_str()); //etos apokthshs
				emporikotita=atof(sv[4].c_str());
				neos.insertakinita(new emporika (emporikotita,d,epifania,etos));
		       }
		  	else if(sv[0]=="O")
		  {
				d=sv[1]; //dieuthynsh
				 epifania=atoi(sv[2].c_str());//epifaneia
				 etos=atoi(sv[3].c_str());//epifaneia
				oikismos=sv[4]; //entos oikismoy
				kaliergia=sv[5];
				neos.insertakinita(new oikopeda (kaliergia,oikismos,d,epifania,etos));
		   }
		 else
			throw 2;
	 sv.clear();
	}
	e.push_back(neos);          //vazw sto vector tin dilwsi tou neou forologoumenou
  infile.close();
 }
 else
    cout<<"File not found";
 	throw 1;
}
          	         
          else{       //den theeli na vali apo arxeio
		  
	   
         
          printf("Eisagwgh\n1.Katoikia\n2.Emporiko\n3.Oikopedo\n4.Exodos\n");
          cin>>epilogi2;
          while(epilogi2!=4)
         {
		 
           switch(epilogi2)
           {
		  
             case 1: 
			  {
			  printf("dwse dieuthinsi tis katoikias,epifania,etos,orofo kai tipos\n");
                     cin>>d>>epifania>>etos>>orofos>>tipos;
                     neos.insertakinita( new katikies (tipos,orofos,d,epifania,etos));              //dhmiourgia neas katoikias kai eisagwgi tis stin dilwsi
                     break;
                 }
             case 2: 
			 {
			 printf("dwse dieuthinsi tou emporikou,epifania,etos,kai emporikotita\n");
                     cin>>d>>epifania>>etos>>emporikotita;
                     neos.insertakinita(new emporika (emporikotita,d,epifania,etos));                  //dhmiourgia neou emporikou kai eisagwgi tis stin dilwsi
                     break;
			}
             	     
             case 3:
			 {
			 printf("dwse dieuthinsi tou oikopedou,epifania,etos,oikismo kai kaliergia\n");
                     cin>>d>>epifania>>etos>>oikismos>>kaliergia;
                     neos.insertakinita(new oikopeda (kaliergia,oikismos,d,epifania,etos));          //dhmiourgia neou oikopedau kai eisagwgi tis stin dilwsi
                     break;
                 }
             	     
             
	       }
	        printf("Eisagwgh\n1.Katoikia\n2.Emporiko\n3.Oikopedo\n4.Exodos\n");
          cin>>epilogi2;
	      } 
	      e.push_back(neos);                                  //vazw sto vector tin dilwsi tou neou forologoumenou
	      break;
	}}
	   case 2:                                 //allagi stoixeiwn
	   	{
		    int temp2=0,i;
			cout<<"Dwse afm kai etos gennisis gia tautopoihsh stoixeiwn";           //elegxos gia to poios forologoumenos einai
			cin>>afm>>etos;
			for(i=0;i<e.size();i++)
    	    {
    		 if (e[i].afm==afm && e[i].etos==etos )
    		 {
    			temp2=i;
    		 }
		    }
    		
			if(temp2!=0)                                //an iparxei
			{
	   	     printf("1.Allagh stoixeiwn upoxreou\n2.Prosthiki akinitou\n3.Diagrafi akinitou\n");
	   	     cin>>epilogi3;
	   	     switch(epilogi3)
			 {
	   	     case 1:                                  //allagi stoixeiwn
	   	    	{
	   	    	
				    enfiad n;
		   	        printf("Dwse nea stoixeia ipoxreou onoma,epwnimo,dieuthinsi,afm kai etos gennisis\n");
		   	   	    cin>>onoma>>epwnimo>>dieuthinsi>>afm>>etos;				   
		   	   	    e[temp2].onoma=onoma;
			   	    e[temp2].epwnimo=epwnimo;
			   	    e[temp2].dieuthinsi=dieuthinsi;
			   	    e[temp2].afm=afm;
			   	    e[temp2].etos=etos;
		   	   	    break;
		   	   	}
            
	   	   	 case 2:                                //prosthiki neou akinitou
	   	   		
	   	   		printf("Eisagwgh\n1.Katoikia\n2.Emporiko\n3.Oikopedo\n4.Exodos\n");
	   	   		cin>>epilogi4;
		  
                  switch(epilogi4)
                  {		  
                   case 1: 
				   {
				   printf("dwse dieuthinsi tis katoikias,epifania,etos,orofo kai tipos\n");
                     cin>>d>>epifania>>etos>>orofos>>tipos;              
                     e[temp2].insertakinita(new katikies (tipos,orofos,d,epifania,etos));
                     break;
                   }
                   case 2:
                   	{
					   
             	     printf("dwse dieuthinsi tou emporikou,epifania,etos,kai emporikotita\n");
                     cin>>d>>epifania>>etos>>emporikotita;                  
                      e[temp2].insertakinita(new emporika (emporikotita,d,epifania,etos));
                     break;
                    }
                   case 3:
                   	{
             	     printf("dwse dieuthinsi tou oikopedou,epifania,etos,oikismo kai kaliergia\n");
                     cin>>d>>epifania>>etos>>oikismos>>kaliergia;                 
                     e[temp2].insertakinita(new oikopeda (kaliergia,oikismos,d,epifania,etos));
                     break;
				   }
	              }
	        }
	    }
	        break;
	    }
	    case 3:                                   //akurwsi dilwsis
	        {
	        int temp2=0,i;
	        cout<<"Dwse afm kai etos gennisis gia tautopoihsh stoixeiwn";                                    //pali tautopoihsh
			cin>>afm>>etos;
			for(i=0;i<e.size();i++)
    	    {
    		 if (e[i].afm==afm && e[i].etos==etos )
    		 {
    			temp2=i;
    		 }
		    }
			if(temp2!=0)
			 {
	        	e[temp2].katastasi=0;
	        	cout<<"H dilwsh akurwthike"<<endl;
	        }
	        	break;
	       }
	            
	    case 4:                                              //megaliteroi foroi apo x poso
	    	 {
	    	 	int temp,foros=0,k=0;
	    	 	cout<<"Dwse poso"<<endl;
	    	 	cin>>temp;			
	    	 	for(int i=0;i<e.size();i++)
	    	 	 {
	    	 	 foros=foros+e[i].upologismos();
	    	 	 if(foros>temp)
				   k++;	    	 			    	 		
				 }
				 
	    	 	cout<<"Megaluteroi apo auto pou edwses einai:"<<k<<endl;
	    	 	break;
	    	 		    	 	
			 }
			 
		case 5:                               //memonomenoi foroi megaluteroi apo x poso
	    	 {
	    	 	int temp,k=0;
	    	 	cout<<"Dwse poso"<<endl;
	    	 	cin>>temp;
				for(int i=0;i<e.size();i++)			
	    	 	 k=k+e[i].upologismos2(temp);	    	 	   	 			    	 						 
	    	 	cout<<"Megaluteroi apo auto pou edwses einai:"<<k<<endl;
	    	 	break;	 	
		}
			 
		case 6:                             //10 megaluteres dilwseis
	    	 {
	    	 	int temp,foros=0,k=0,max[e.size()],a;
				for(int p=0;p<e.size();p++)
	    	 	  max[p]=e[p].upologismos();;	
	    	 	for (int i = 0; i <e.size(); ++i)
                {
                  for (int j = i + 1; j < e.size(); ++j)
                  {
                    if (max[i] > max[j])
                     {
		                a =max[i];
		                max[i] = max[j];
		                max[j] = a;
                     }
                  }
                 }
                cout<<"Oi 10 Megaluteres dilwseis se xrimata einai:"<<endl;
				for(int i=0;i<e.size();i++)
				  cout<<max[i]<<endl;
	    	 	break;
	    	 		    	 	
			 }
	
   }   
 printf("Epelexe\n1.Prosthiki dhlwshs\n2.Tropopoihsh dhlwshs\n3.Akurwsi dhlwshsh\n4.Emfanise megaliterous forous\n5.Dilwseis me akinito\n6.Oi 10 Megaliteres dilwseis\n7.Exodos\n");
 scanf("%d",&epilogi);
  }
}


