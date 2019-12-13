#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LlantaDerechaTracera = motor(PORT12, ratio18_1, true);
motor LlantaDerechaDelante = motor(PORT13, ratio18_1, true);
motor LlantaIzquierdaTrace = motor(PORT19, ratio18_1, false);
motor LlantaIzquierdaDelan = motor(PORT18, ratio18_1, false);
motor MotorBrazoRampa = motor(PORT14, ratio18_1, false);
controller Controller1 = controller(primary);
motor BrazoAperturaDer = motor(PORT15, ratio18_1, true);
motor SuccionadorDer = motor(PORT11, ratio18_1, true);
motor SuccionadorIzq = motor(PORT20, ratio18_1, false);
motor BrazoAperturaIzq = motor(PORT17, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}