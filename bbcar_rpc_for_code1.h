#ifndef BBCAR_RPC_H
#define BBCAR_RPC_H

#include "bbcar.h"
#include "mbed_rpc.h"

void RPC_stop(Arguments *in, Reply *out);
void RPC_car(Arguments *in, Reply *out);
void RPC_turn(Arguments *in, Reply *out);
void RPC_CT(Arguments *in, Reply *out);

#endif
