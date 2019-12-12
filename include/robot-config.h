using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor EstDer;
extern motor EstIzq;
extern motor DelIzq;
extern motor TraIzq;
extern motor DelDer;
extern motor TraDer;
extern motor Recolector;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );