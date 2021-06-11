#include"mbed.h"
#include "bbcar.h"
#include "mbed_rpc.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);
BufferedSerial pc(USBTX,USBRX);
BufferedSerial uart(D1,D0); //tx,rx
BBCar car(pin5, pin6, servo_ticker);

void line(Arguments *in, Reply *out);
RPCFunction Line(&line, "line");

int main() {
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-9.646, -9.784, -9.025, -8.445, -4.882, 0.000, 5.777, 10.364, 9.885, 9.895, 9.965};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-8.530, -8.132, -8.690, -8.929, -4.824, 0.000, 4.829, 8.132, 8.371, 9.849, 9.769};

    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    char buf[256], outbuf[256];
    FILE *devin = fdopen(&uart, "r");
    FILE *devout = fdopen(&uart, "w");

    while(1) {
        memset(buf, 0, 256);
        for (int i = 0; ; i++) {
            char recv = fgetc(devin);
            if (recv == '\n') {
                printf("\r\n");
                break;
            }
            buf[i] = fputc(recv, devout);
        }
        //Call the static call method on the RPC class
        RPC::call(buf, outbuf);
    }
}

void line(Arguments *in, Reply *out) {
    double x1 = in->getArg<double>();
    double y1 = in->getArg<double>();
    double x2 = in->getArg<double>();
    double y2 = in->getArg<double>();
    double ang = in->getArg<double>();

    if (y1 < 100)
        if (x2 > 90 && x2 < 150) {          // turn left
            car.turn(60, 0.7);
            ThisThread::sleep_for(200ms);
            car.stop(); 
        } else if (x2 < 70 && x2 > 15) {   // turn right
            car.turn(80, -0.1);
            ThisThread::sleep_for(300ms);
            car.stop();
        } else {                // go straight
            car.turn(60, -0.01);
            ThisThread::sleep_for(200ms);
            car.goStraightCalib(10);
            ThisThread::sleep_for(100ms);
            car.stop(); 
        }
    else car.goStraightCalib(8);   
}