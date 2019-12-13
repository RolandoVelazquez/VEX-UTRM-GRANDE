/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lalo_                                            */
/*    Created:      Thu Dec 12 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LlantaDerechaTracera motor         12              
// LlantaDerechaDelante motor         13              
// LlantaIzquierdaTrace motor         19              
// LlantaIzquierdaDelan motor         18              
// MotorBrazoRampa      motor         14              
// Controller1          controller                    
// BrazoAperturaDer     motor         15              
// SuccionadorDer       motor         11              
// SuccionadorIzq       motor         20              
// BrazoAperturaIzq     motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void joystickDerecho(){
  MotorBrazoRampa.setVelocity(Controller1.Axis2.position(), percent);
}
void joystickIzquierdo(){
  LlantaIzquierdaDelan.setVelocity((Controller1.Axis3.position() + Controller1.Axis4.position())/2, percent);

  LlantaDerechaDelante.setVelocity((Controller1.Axis3.position() - Controller1.Axis4.position())/2, percent);

  LlantaIzquierdaTrace.setVelocity((Controller1.Axis3.position() + Controller1.Axis4.position())/2, percent);

  LlantaDerechaTracera.setVelocity((Controller1.Axis3.position() - Controller1.Axis4.position())/2, percent);
}

void abrirbrazoAper(){
  BrazoAperturaDer.spin(forward);
  BrazoAperturaIzq.spin(forward);

  BrazoAperturaDer.setVelocity(100, percent);
  BrazoAperturaIzq.setVelocity(100,percent);

  BrazoAperturaDer.setMaxTorque(100,percent);
  BrazoAperturaIzq.setMaxTorque(100,percent);

  waitUntil(!Controller1.ButtonR1.pressing());

  BrazoAperturaDer.stop();
  BrazoAperturaIzq.stop();

}

void cerrarbrazoAper(){
  BrazoAperturaDer.spin(forward);
  BrazoAperturaIzq.spin(forward);

  BrazoAperturaDer.setVelocity(-100, percent);
  BrazoAperturaIzq.setVelocity(-100, percent);

  BrazoAperturaDer.setMaxTorque(100,percent);
  BrazoAperturaIzq.setMaxTorque(100,percent);

  waitUntil(!Controller1.ButtonR2.pressing());

  BrazoAperturaDer.stop();
  BrazoAperturaIzq.stop();

}

void extraerCubos(){
  SuccionadorDer.spin(forward);
  SuccionadorIzq.spin(forward);

  SuccionadorDer.setVelocity(100,percent);
  SuccionadorIzq.setVelocity(100, percent);

  waitUntil(!Controller1.ButtonL1.pressing());

  SuccionadorDer.stop();
  SuccionadorIzq.stop();
  
}

void sacarCubos(){
  SuccionadorDer.spin(forward);
  SuccionadorIzq.spin(forward);

  SuccionadorDer.setVelocity(-25,percent);
  SuccionadorIzq.setVelocity(-25,percent);

  waitUntil(!Controller1.ButtonL2.pressing());

  SuccionadorDer.stop();
  SuccionadorIzq.stop();

}

void apagarMotores(){
  LlantaDerechaDelante.stop();
  LlantaDerechaTracera.stop();
  LlantaIzquierdaDelan.stop();
  LlantaIzquierdaTrace.stop();

  MotorBrazoRampa.stop();

  SuccionadorDer.stop();
  SuccionadorIzq.stop();
  BrazoAperturaDer.stop();
  BrazoAperturaIzq.stop();
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  
  
  while(true){
  
    joystickDerecho();

    joystickIzquierdo();
    
    Controller1.ButtonB.pressed(apagarMotores);

    Controller1.ButtonR1.pressed(abrirbrazoAper);

    Controller1.ButtonR2.pressed(cerrarbrazoAper);

    Controller1.ButtonL1.pressed(extraerCubos);

    Controller1.ButtonL2.pressed(sacarCubos);

    MotorBrazoRampa.spin(forward);

    //BrazoAperturaDer.setStopping(hold);
    //BrazoAperturaIzq.setStopping(hold);

    LlantaIzquierdaDelan.spin(forward);
    LlantaDerechaDelante.spin(forward);
    LlantaIzquierdaTrace.spin(forward);
    LlantaDerechaTracera.spin(forward);




  }
  
}
