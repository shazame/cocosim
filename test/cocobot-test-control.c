// Make sure to have the server side running in V-REP!
// Start the server from a child script with following command:
// simExtRemoteApiStart(portNumber) -- starts a remote API server service on the specified port

#include <stdio.h>
#include <stdlib.h>

#include "extApi.h"
/*#include "extApiCustom.h" if you wanna use custom remote API functions! */

#define CHECK_REMOTE_CALL(CALL,RETURN_CODE) {\
  RETURN_CODE=CALL; \
  if (RETURN_CODE != 0) { printf("Error %d during remote function call.\n", RETURN_CODE); } }

int main(void)
{
    int portNumber=1234;
    int leftMotorHandle;
    int rightMotorHandle;

    int ret=0;

    int clientID=simxStart((simxChar*)"127.0.0.1",portNumber,1,1,2000,5);
    if (clientID!=-1)
    {
        printf("Client successfully connected to port %d.\n", portNumber);

        CHECK_REMOTE_CALL(simxGetObjectHandle(clientID,"cocobotLeftMotor#",&leftMotorHandle,simx_opmode_oneshot_wait),ret);
        CHECK_REMOTE_CALL(simxGetObjectHandle(clientID,"cocobotRightMotor#",&rightMotorHandle,simx_opmode_oneshot_wait),ret);

        float motorSpeeds[2];

        while (simxGetConnectionId(clientID)!=-1)
        {
            // going forward:
            motorSpeeds[0]=3.1415f/2;
            motorSpeeds[1]=3.1415f;

            simxSetJointTargetVelocity(clientID,leftMotorHandle,motorSpeeds[0],simx_opmode_oneshot);
            simxSetJointTargetVelocity(clientID,rightMotorHandle,motorSpeeds[1],simx_opmode_oneshot);

            extApi_sleepMs(5);
        }
        simxFinish(clientID);
    }
    else
    {
        printf("Error while connecting to VREP remote API server. Did you start the simulation with virtual-cocobot scene?\n");
    }
    printf("Connection aborted.\n");

    return(0);
}
