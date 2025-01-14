#ifndef INPUT_H
#define INPUT_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>

#include <sys/ioctl.h>
#include <sys/poll.h>

#include <linux/hidraw.h>

struct SDInput {
  int fd;
  struct SDButtons {
    bool A, B, X, Y;
    bool L1, L2, L3, L4, L5;
    bool R1, R2, R3, R4, R5;
  } current, previous;
};

struct SDInput* SDInput_getInstance();

bool SDInput_tryOpenDevice(struct SDInput *input);
void SDInput_closeDevice(struct SDInput *input);

bool SDInput_pollState(struct SDInput *input);

// external callbacks
extern void sdinput_onUpdate(struct SDInput *input);

#endif
