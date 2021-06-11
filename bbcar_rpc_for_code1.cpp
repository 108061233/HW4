#include "bbcar_rpc.h"
#include <math.h>
RPCFunction rpcStop(&RPC_stop, "stop");
RPCFunction rpcCar(&RPC_car, "car");
RPCFunction rpcTurn(&RPC_turn, "turn");
RPCFunction rpcCT(&RPC_CT, "CT");

extern BBCar car;

void RPC_stop (Arguments *in, Reply *out)   {
    car.stop();
    return;
}

void RPC_turn (Arguments *in, Reply *out)   {
    int speed = in->getArg<double>();
    double turn = in->getArg<double>();
    car.turn(speed,turn);
    return;
}

void RPC_CT(Arguments *in, Reply *out) {
    int speed = in->getArg<double>();
    car.goStraightCalib(speed);
    return;    
}

void RPC_car(Arguments *in, Reply *out)   {
    int R1 = in->getArg<double>();
    int R2 = in->getArg<double>();
    double D1 = in->getArg<double>();
    double D2 = in->getArg<double>();
    double end;

    double ang = atan(D1 / D2) * 180 / 3.14;
    double D = sqrt(D1 * D1 + D2 * D2);

    if (R1 == 1) {
        if (R2 == 0) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (180 + ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 7) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (135 + ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 6) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (90 + ang); i++) ThisThread::sleep_for(10ms);       
        } else if (R2 == 5) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (45 + ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 4) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * ang; i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 1) {
            car.turn(100, -0.01);
            for (int i = 0; i < 1.5 * (135 - ang); i++) ThisThread::sleep_for(10ms);       
        } else if (R2 == 2) {
            car.turn(100, -0.01);
            for (int i = 0; i < 1.5 * (90 - ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 3) {
            if (45 - ang > 0) {
                end = 45 - ang;
                car.turn(100, -0.01);
            } else {
                car.turn(100, 0.01);
                end = ang - 45;
            }
            for (int i = 0; i < 1.5 * end; i++) ThisThread::sleep_for(10ms);
        }
    } else if (R1 == 2) {
        if (R2 == 0) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (180 - ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 7) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (135 - ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 6) {
            car.turn(100, 0.01);
            for (int i = 0; i < 1.5 * (90 - ang); i++) ThisThread::sleep_for(10ms);       
        } else if (R2 == 5) {
            if (45 - ang > 0) {
                car.turn(100, 0.01);
                end = 45 - ang;
            } else {
                car.turn(100, -0.01);
                end = ang - 45;
            }
            for (int i = 0; i < 1.5 * end; i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 4) {
            car.turn(100, -0.01);
            for (int i = 0; i < 1.5 * ang; i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 1) {
            car.turn(100, -0.01);
            for (int i = 0; i < 1.5 * (135 + ang); i++) ThisThread::sleep_for(10ms);       
        } else if (R2 == 2) {
            car.turn(100, -0.01);
            for (int i = 0; i < 1.5 * (90 + ang); i++) ThisThread::sleep_for(10ms);
        } else if (R2 == 3) {
            car.turn(100, -0.01);
            for (int i = 0; i < 1.5 * (45 + ang); i++) ThisThread::sleep_for(10ms);
        }
    }
    car.goStraightCalib(100);
    for (int n = 0; n < 4.8 * D; n++) ThisThread::sleep_for(10ms);
    if (R1 == 1) {
        car.turn(100, -0.01);
        for (int i = 0; i < 1.5* ang; i++) ThisThread::sleep_for(10ms);
        ThisThread::sleep_for(500ms);
    } else if (R1 == 2) {
        car.turn(100, 0.01);
        for (int i = 0; i < 1.5 * ang; i++) ThisThread::sleep_for(10ms);
        ThisThread::sleep_for(500ms);
    }
    car.goStraightCalib(100);
    for (int n = 0; n < 4.8 * 10; n++) ThisThread::sleep_for(10ms);
    car.stop();
    return;

}