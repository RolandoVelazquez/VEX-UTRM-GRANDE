#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor EstDer = motor(PORT10, ratio18_1, true);
motor EstIzq = motor(PORT1, ratio18_1, false);
motor DelIzq = motor(PORT9, ratio18_1, false);
motor TraIzq = motor(PORT8, ratio18_1, false);
motor DelDer = motor(PORT2, ratio18_1, true);
motor TraDer = motor(PORT3, ratio18_1, true);
motor Recolector = motor(PORT4, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}