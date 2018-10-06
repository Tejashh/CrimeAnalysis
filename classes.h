/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program, e.g. "CrimeReport"
// and "CrimeCode".
//
// << Tejash Contractor >>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


// CrimeCode class
class CrimeCode
{
private:
    string ICUR;
    string PRIMARY_DESCRIPTION;
    string SECONDARY_DESCIPTION;
    int count = 0;
    
public:
    //constructor:
    CrimeCode(string icur, string primary_description, string secondary_description, int cnt)
    : ICUR(icur), PRIMARY_DESCRIPTION(primary_description), SECONDARY_DESCIPTION(secondary_description), count(cnt)
    {
        
    }
    
    string getICUR() const
    {
        return ICUR;
    }
    
    string getPrimary_Description() const
    {
        return PRIMARY_DESCRIPTION;
    }
    
    string getSecondary_Description() const
    {
        return SECONDARY_DESCIPTION;
    }
    
    int getCount() const
    {
        return count;
    }
    
    void setCount()
    {
        count = count + 1;
    }
    
};  //end of the CrimeCode

// CrimeReport method
class CrimeReport
{
private:
    string DateTime;
    string IUCR;
    string Arrest;
    string Domestic;
    int Beat;
    int District;
    int Ward;
    int Community;
    int Year;
    int count;
    
public:
    //constructor:
    CrimeReport(string datetime, string iucr, string arrest, string domestic, int beat, int district,int ward, int community, int year, int cnt)
    : DateTime(datetime), IUCR(iucr), Arrest(arrest), Domestic(domestic), Beat(beat), District(district), Ward(ward), Community(community), Year(year), count(cnt)
    {
        
    }
    
    string getDateTime() const
    {
        return DateTime;
    }
    
    string getIUCR() const
    {
        return IUCR;
    }
    
    string getArrest() const
    {
        return Arrest;
    }
    
    string getDomestic() const
    {
        return Domestic;
    }
    
    int getBeat() const
    {
        return Beat;
    }
    int getDistrict() const
    {
        return District;
    }
    int getWard() const
    {
        return Ward;
    }
    int getCommunity() const
    {
        return Community;
    }
    int getYear() const
    {
        return Year;
    }
    
    int getCount() const
    {
        return count;
    }
    
    
};  //end of the crimeReport method

