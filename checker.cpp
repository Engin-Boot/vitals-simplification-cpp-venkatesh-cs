#include <assert.h>
#include<iostream>
#include<string>
using namespace std;
const int RespLimits[] = {30,95};
const int BPMLimits[] = {70,150};
const int SPO2Limits[] = { 90, 100};
bool vitalsAreOk(float bpm, float spo2, float respRate);
bool isSpo2Ok(float spo2);
bool isBpmOK(float bpm);
bool isRespRateOk(float resprate);

bool isParameterInRange(string parName, float parVal, int lowerLimit, int upperLimit)
{
  if(parVal>upperLimit)
  {
    cout<< "Warning!!! "<< parName<<" is above "<<upperLimit<<endl;
    return false;
  }
  if(parVal<lowerLimit)
  {
    cout<< "Warning!!! "<< parName<<" is below "<<lowerLimit<<endl;
    return false;
  }
return true;
}

bool vitalsAreOk(float bpm, float spo2, float resprate)
{
 return ( 
  isParameterInRange("Blood Pressure", bpm, BPMLimits[0], BPMLimits[1]) &&
  isParameterInRange("Respiratory Rate", resprate, RespLimits[0], RespLimits[1]) &&
  isParameterInRange("SpO2", spo2, SPO2Limits[0], SPO2Limits[1]) 
  );
}

int main()
{
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  assert(isParameterInRange("Blood Pressure", 100, 70,150)==true);
  assert(isParameterInRange("Blood Pressure", 30, 70,150)==false);
  assert(isParameterInRange("Blood Pressure", 250, 70,150)==false);
  assert(isParameterInRange("Blood Pressure", 0, 70,150)==false);
  assert(isParameterInRange("SpO2", 89, 90, 100 )==false);
  assert(vitalsAreOk(30, 100, 200) == false);
  return 0;
}
