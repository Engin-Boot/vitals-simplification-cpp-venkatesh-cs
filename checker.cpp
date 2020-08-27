#include <assert.h>
const int RespLimits[] = {30,95};
const int BPMLimits[] = {70,150};
const int SPO2Min = 90;
bool vitalsAreOk(float bpm, float spo2, float respRate);
bool isSpo2Ok(float spo2);
bool isBpmOK(float bpm);
bool isRespRateOk(float resprate);


bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if(isRespRateOk(respRate) && isSpo2Ok(spo2) && isBpmOK(bpm) )
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isSpo2Ok(float spo2)
{
  return spo2>=SPO2Min;
}

bool isRespRateOk(float resprate)
{
  return ( resprate>=RespLimits[0] && resprate<=RespLimits[1]);
}
bool isBpmOK(float bpm)
{
  return (bpm>=BPMLimits[0] && bpm<=BPMLimits[1]);
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  return 0;
}
