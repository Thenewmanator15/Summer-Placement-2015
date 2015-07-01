// Include the OculusVR SDK


#include "OVR.h"                  // Include the OculusVR SDK
#include "OVR_CAPI.h"
#include "OVR_Math.h"
#include "OVR_Kernel.h"
#include <conio.h>
#include "OVR_CAPI.h"
#include "Extras\OVR_Math.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace OVR;

int main()
{
   ovr_Initialize(nullptr);
   
   ovrHmd HMD;

   ovrHmd_Create(0, &HMD);

   ovrHmd_ConfigureTracking(HMD, ovrTrackingCap_Orientation | ovrTrackingCap_MagYawCorrection | ovrTrackingCap_Position, 0);

   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
   GetConsoleScreenBufferInfo(h, &bufferInfo);

   while(true){
      ovrFrameTiming ftiming = ovrHmd_GetFrameTiming(HMD, 0);
      ovrTrackingState hmdState = ovrHmd_GetTrackingState(HMD, ftiming.DisplayMidpointSeconds);
      
      if (hmdState.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)) {
         Posef pose = hmdState.HeadPose.ThePose;
         float yaw, pitch, roll;
         pose.Rotation.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);
         ovrVector3f accel = hmdState.RawSensorData.Accelerometer;

         SetConsoleCursorPosition(h, bufferInfo.dwCursorPosition);

         cout << "yaw: " << RadToDegree(yaw) << ", pitch: " << RadToDegree(pitch) << ", roll: "  << RadToDegree(roll)  << endl;
         cout << "ax: " << accel.x << ", ay: " << accel.y << ", az: "  << accel.z  << endl;
         
         Sleep(50);
      }

      if (_kbhit()) break;
   }
   
   ovrHmd_Destroy(HMD);

   ovr_Shutdown();
}
