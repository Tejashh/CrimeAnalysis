/*main.cpp*/

//
// Chicago Crime Analysis program in modern C++.
//
// <<Tejash Contractor>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

// differenet use of libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

//regresing classes.h
#include "classes.h"

using namespace std;

//start of main method
int main()
{
    string  crimeCodesFilename, crimesFilename;
    
    //file names
    cin >> crimeCodesFilename;
    cout << crimeCodesFilename << endl;
    
    cin >> crimesFilename;
    cout << crimesFilename << endl;
    
    //open files
    ifstream  codesFile(crimeCodesFilename);
    ifstream  crimesFile(crimesFilename);
    
    cout << std::fixed;
    cout << std::setprecision(2);
    
    //
    //if first file name is wrong
    //
    if (!codesFile.good())
    {
        cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
        return -1;
    }
    
    //
    //if second file name is wrong
    //
    if (!crimesFile.good())
    {
        cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
        return -1;
    }
    
    
    //
    // TODO
    //
    
    //creating vector crimes of CrimeCode
    vector<CrimeCode> crimes;
    
    string line, icur, primary_discription, secondary_discription;
    
    getline(codesFile,line);
    
    //
    // Parsing the crimes file
    //
    while(getline(codesFile,line))
    {
        stringstream ss(line);
        
        getline(ss,icur,',');
        getline(ss,primary_discription,',');
        getline(ss,secondary_discription);
        
        CrimeCode C(icur,primary_discription,secondary_discription,0);
        
        crimes.push_back(C);    //adding the crimes into vactor
    }
    
    codesFile.close(); //closing file
    
    /*for(CrimeCode& c: crimes)
     {
     cout << " " << c.getICUR() << " (" << c.getPrimary_Description() << "): $" << c.getSecondary_Description() << endl;
     }*/
    
    //Create crimeRoports vector of CrimeReport
    vector<CrimeReport> crimeReports;
    
    string ln, datetime, iucr, arrest, domestic, beat;
    string district, ward, community, year;
    
    
    getline(crimesFile,ln);
    
    //
    // Parsing the crimeReport file:
    //
    
    while(getline(crimesFile,ln))
    {
        
        stringstream ss(ln);
        
        getline(ss,datetime,',');
        getline(ss,iucr,',');
        getline(ss,arrest,',');
        getline(ss,domestic,',');
        getline(ss,beat,',');
        getline(ss,district,',');
        getline(ss,ward,',');
        getline(ss,community,',');
        getline(ss,year);
        
        CrimeReport CR(datetime,iucr,arrest,domestic,stoi(beat),stoi(district),stoi(ward),stoi(community),stoi(year),0);
        
        crimeReports.push_back(CR); //adding info into crimeReports:
    }
    crimesFile.close(); //closing file
    
    cout <<"** Crime Analysis **" << endl << endl;
    
    //
    // Printing the Date Range infomation
    //
    cout << "Date range: " << crimeReports.begin()->getDateTime() << " - " << (crimeReports.end()-1)->getDateTime() << endl << endl;
    
    // Printing the side of crime codes:
    cout << "# of crime codes: "<< crimes.size() << endl;
    
    //
    // sorting the CrimeCode file in terms of its IUCR :
    //
    sort(crimes.begin(),
         crimes.end(),
         [](CrimeCode c1, CrimeCode c2)
         {
             
             if(c1.getICUR() < c2.getICUR())
                 return true;
             else
                 return false;
         }
         );
    /***********************************************************************************/
    
    //
    // Printing the first and last 3 information of the crimecodes:
    //
    int c1 = 0;
    size_t c2 = crimes.size();
    
    for(CrimeCode& c: crimes)
    {
        
        if(c.getICUR() > "0100" && c1 < 3)
        {
            cout << c.getICUR() << ":   " << c.getPrimary_Description() << ":" << c.getSecondary_Description() << endl;
            c1++;
        }
    }
    cout << "..." << endl;
    for(size_t i = c2-3; i < c2 ; i++)
    {
        cout << crimes[i].getICUR() << ":   " << crimes[i].getPrimary_Description() << ":" << crimes[i].getSecondary_Description() << endl;
    }
    
    /*************************************************************************************/
    
    
    // Printing the side of crimes:
    cout << "\n# of crimes: " << crimeReports.size() << endl;
    
    /************************************************************************************/
    
    //
    // Printing the first and last 3 information of the crimeReports including the Arrested and
    // Domestic Violence:
    //
    int c1_1 = 0;
    size_t c2_1 = crimeReports.size();
    for(CrimeReport& c: crimeReports)
    {
        
        if(c.getIUCR() > "0100" && c1_1 < 3)
        {
            // ONly Arrested
            if((c.getArrest() == "TRUE" ||c.getArrest() == "true")
               && (c.getDomestic() == "false" || c.getDomestic() == "FALSE"))
            {
                cout << c.getIUCR() << ":   " << c.getDateTime() << ", "
                << c.getBeat() << ", " << c.getDistrict() << ", " << c.getWard() << ", " << c.getCommunity() << ", arrested" << endl;
                c1_1++;
            }
            // Arrested with Dommestic vilence
            else if((c.getArrest() == "TRUE" ||c.getArrest() == "true")
                    && (c.getDomestic() == "TRUE" || c.getDomestic() == "true"))
            {
                cout << c.getIUCR() << ":   " << c.getDateTime() << ", "
                << c.getBeat()  << ", " << c.getDistrict() << ", " << c.getWard() << ", " << c.getCommunity() << ", arrested, domestic violence" << endl;
                c1_1++;
            }
            // only dommestic violence
            else if((c.getArrest() == "FALSE" ||c.getArrest() == "FALSE")
                    && (c.getDomestic() == "TRUE" || c.getDomestic() == "TRUE"))
            {
                cout << c.getIUCR() << ":   " << c.getDateTime() << ", "
                << c.getBeat()  << ", " << c.getDistrict() << ", " << c.getWard() << ", " << c.getCommunity() << ", domestic violence" << endl;
                c1_1++;
            }
            // Neither arrested nor dommestic violence
            else
            {
                cout << c.getIUCR() << ":   " << c.getDateTime() << ", "
                << c.getBeat() << ", " << c.getDistrict() << ", " << c.getWard() << ", " << c.getCommunity() << endl;
                c1_1++;
            }
        }
    }
    cout << "..." << endl;
    for(size_t i = c2_1-3; i < c2_1 ; i++)
    {
        // ONly Arrested
        if((crimeReports[i].getArrest() == "TRUE" ||crimeReports[i].getArrest() == "true")
           && (crimeReports[i].getDomestic() == "false" || crimeReports[i].getDomestic() == "FALSE"))
        {
            cout << crimeReports[i].getIUCR() << ":   " << crimeReports[i].getDateTime() << ", "
            << crimeReports[i].getBeat() << ", "  << crimeReports[i].getDistrict() << ", "<< crimeReports[i].getWard() << ", " << crimeReports[i].getCommunity() << ", arrested" << endl;
        }
        // Arrested with Dommestic vilence
        else if((crimeReports[i].getArrest() == "TRUE" ||crimeReports[i].getArrest() == "true") && (crimeReports[i].getDomestic() == "TRUE" || crimeReports[i].getDomestic() == "true"))
        {
            cout << crimeReports[i].getIUCR() << ":   " << crimeReports[i].getDateTime() << ", "
            << crimeReports[i].getBeat() << ", "  << crimeReports[i].getDistrict() << ", "<< crimeReports[i].getWard() << ", " << crimeReports[i].getCommunity() << ", arrested, domestic violence" << endl;
        }
        // only dommestic violence
        else if((crimeReports[i].getArrest() == "FALSE" ||crimeReports[i].getArrest() == "false") && (crimeReports[i].getDomestic() == "TRUE" || crimeReports[i].getDomestic() == "true"))
        {
            cout << crimeReports[i].getIUCR() << ":   " << crimeReports[i].getDateTime() << ", "
            << crimeReports[i].getBeat() << ", "  << crimeReports[i].getDistrict() << ", "<< crimeReports[i].getWard() << ", " << crimeReports[i].getCommunity() << ", domestic violence" << endl;
        }
        // Neither arrested nor dommestic violence
        else
        {
            cout << crimeReports[i].getIUCR() << ":   " << crimeReports[i].getDateTime() << ", "
            << crimeReports[i].getBeat() << ", "  << crimeReports[i].getDistrict() << ", " << crimeReports[i].getWard() << ", " << crimeReports[i].getCommunity() <<  endl;
        }
    }
    
    /***************************************************************************************/
    cout << "\n** Top-5 Crimes **" << endl;
    cout << "Code:   Total, Description" << endl;
    //std::list<CrimeCode> L;
    
    
    //
    // USED similar idea as HW04_02 problem to run foreach loop on the crimeReports and serach
    // for the iUCR value from crimeCode and comparing with the iucr value of crimeReport and if
    // it is same then updating the count value in the crimeCode.
    //
    for(auto &c: crimeReports)
    {
        auto S = find_if(crimes.begin(),
                         crimes.end(),
                         [=] (const CrimeCode& cc)
                         {
                             return(cc.getICUR() == c.getIUCR());
                         });
        if(S == crimes.end())   //If not found:
        {
            
        }
        else    //Found:
        {
            S->setCount();  //updated having getter setter
        }
    }
    
    
    /***********************************************************************************/
    
    //
    // sort the crimeCode file interms of the count value (Counted iucr value) so that it would
    // be in biggest to loweast.
    //
    sort(crimes.begin(),
         crimes.end(),
         [](CrimeCode c1, CrimeCode c2)
         {
             
             if(c1.getCount() > c2.getCount())
                 return true;
             else
                 return false;
         }
         );
    
    
    //
    // printing the top five crimes with information including iucr (code) , total (count) and
    // Description (primary, and secondary)
    //
    int counter = 0;
    for(CrimeCode &c: crimes)
    {
        if(counter < 5)
        {
            cout << c.getICUR() << ":   " << c.getCount() << ", " << c.getPrimary_Description() << ": " << c.getSecondary_Description() << endl;
            counter++;
        }
    }
    
    // end of the code
    cout << "\n** Done **" << endl;
    
    return 0;   // returning zero
}   //end of the main method
