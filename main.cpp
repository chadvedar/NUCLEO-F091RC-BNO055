#include "mbed.h"
#include "BNO055.h"
#include <cstdint>

// main() runs in its own thread in the OS
BNO055 imu(D4, D5);

int main()
{
    imu.setmode(OPERATION_MODE_IMUPLUS);

    printf("%d\n",imu.check());

    imu.set_orientation(DEGREES);

    while (true) {
        imu.get_angles();
        printf("roll : %d, pitch : %d, yaw : %d\n", (int)(imu.euler.roll), (int)(imu.euler.pitch), (int)(imu.euler.yaw));
    }
}

