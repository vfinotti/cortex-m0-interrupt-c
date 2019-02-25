/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#define LedToggle 0xf0f0f0f0

#define X0             (*(volatile signed long int*)0x40000000)
#define Y0             (*(volatile signed long int*)0x40000004)
#define Z0             (*(volatile signed long int*)0x40000008)
#define CONTROL_START0 (*(volatile signed long int*)0x4000000c)
#define X_RESULT0      (*(volatile signed long int*)0x40000010)
#define Y_RESULT0      (*(volatile signed long int*)0x40000014)
#define Z_RESULT0      (*(volatile signed long int*)0x40000018)
#define CONTROL_DONE0  (*(volatile signed long int*)0x4000001c)

#define X1             (*(volatile signed long int*)0x40000100)
#define Y1             (*(volatile signed long int*)0x40000104)
#define Z1             (*(volatile signed long int*)0x40000108)
#define CONTROL_START1 (*(volatile signed long int*)0x4000010c)
#define X_RESULT1      (*(volatile signed long int*)0x40000110)
#define Y_RESULT1      (*(volatile signed long int*)0x40000114)
#define Z_RESULT1      (*(volatile signed long int*)0x40000118)
#define CONTROL_DONE1  (*(volatile signed long int*)0x4000011c)

#define X2             (*(volatile signed long int*)0x40000200)
#define Y2             (*(volatile signed long int*)0x40000204)
#define Z2             (*(volatile signed long int*)0x40000208)
#define CONTROL_START2 (*(volatile signed long int*)0x4000020c)
#define X_RESULT2      (*(volatile signed long int*)0x40000210)
#define Y_RESULT2      (*(volatile signed long int*)0x40000214)
#define Z_RESULT2      (*(volatile signed long int*)0x40000218)
#define CONTROL_DONE2  (*(volatile signed long int*)0x4000021c)

#define X3             (*(volatile signed long int*)0x40000300)
#define Y3             (*(volatile signed long int*)0x40000304)
#define Z3             (*(volatile signed long int*)0x40000308)
#define CONTROL_START3 (*(volatile signed long int*)0x4000030c)
#define X_RESULT3      (*(volatile signed long int*)0x40000310)
#define Y_RESULT3      (*(volatile signed long int*)0x40000314)
#define Z_RESULT3      (*(volatile signed long int*)0x40000318)
#define CONTROL_DONE3  (*(volatile signed long int*)0x4000031c)



int main(void)
{
  unsigned int counter; // dummy
  unsigned int ii;      // loop iterator
  unsigned int trap;    // memory access pattern receiver
  unsigned int period;  // time interval for memory access
  period=1000000;      // period for FPGA implementation; roughly 3 seconds for a 10MHz osc in CM0_DS
  /* period=100;           // period for simulations in ARM/Keil MDK and Xilinx ISIM tool */

  signed long int x,y,z;

  while(1)
    {

      // Calculate sine and cosine of pi/3
      CONTROL_START0 = 0;
      X0 = 1073741824; // 1 in Q1.30 notation
      Y0 = 0;
      Z0 = 715827883; // angle pi/3, since 2pi = 2^32
      CONTROL_START0 = 1;

      // Calculate sine and cosine of pi/4
      CONTROL_START1 = 0;
      X1 = 1073741824; // 1 in Q1.30 notation
      Y1 = 0;
      Z1 = 536870912; // angle pi/4, since 2pi = 2^32
      CONTROL_START1 = 1;

      // Calculate sine and cosine of pi/6
      CONTROL_START2 = 0;
      X2 = 1073741824; // 1 in Q1.30 notation
      Y2 = 0;
      Z2 = 357913941; // angle pi/6, since 2pi = 2^32
      CONTROL_START2 = 1;

      // Calculate sine and cosine of pi
      CONTROL_START3 = 0;
      X3 = 1073741824; // 1 in Q1.30 notation
      Y3 = 0;
      Z3 = 4294967295; // angle pi, since 2pi = 2^32
      CONTROL_START3 = 1;

      // Wait for calculations results
      while(CONTROL_DONE0 != 1)
      {}
      while(CONTROL_DONE1 != 1)
      {}
      while(CONTROL_DONE2 != 1)
      {}
      while(CONTROL_DONE3 != 1)
      {}


      // count until period and put the pattern that toggles the LED on the bus
      counter=0;
      for(ii=0; ii<period; ii++)
        {
          counter++;
        }
      trap=LedToggle; // memory access pattern (toggle LED)
      trap++; // force toggle value to change value
    }
}
