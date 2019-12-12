/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\velaz                                            */
/*    Created:      Wed Dec 11 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// EstDer               motor         10              
// EstIzq               motor         1               
// DelIzq               motor         9               
// TraIzq               motor         8               
// DelDer               motor         2               
// TraDer               motor         3               
// Recolector           motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void extraerCubos(){
  EstDer.setVelocity(25, percent);
  EstIzq.setVelocity(25, percent);

  EstDer.spin(forward);
  EstIzq.spin(forward);
}

void soltarCubos(){
  EstDer.setVelocity(-100, percent);
  EstIzq.setVelocity(-100, percent);

  EstDer.spin(forward);
  EstIzq.spin(forward);
}

void adelanteAtras(bool permitirAdelante){
  if (permitirAdelante){

  DelDer.setVelocity(Controller1.Axis3.position(), percent);
  DelIzq.setVelocity(Controller1.Axis3.position(), percent);

  TraIzq.setVelocity(Controller1.Axis3.position(), percent);
  TraDer.setVelocity(Controller1.Axis3.position(), percent);

  DelDer.spin(forward);
  DelIzq.spin(forward);
  TraDer.spin(forward);
  TraIzq.spin(forward);
  }
}

void derechaIzquierda(bool permitirAdelante){
  if(!permitirAdelante){
     DelDer.setVelocity(-Controller1.Axis1.position(),percent);
   DelIzq.setVelocity(Controller1.Axis1.position(),percent);
   TraDer.setVelocity(-Controller1.Axis1.position(),percent);
   TraIzq.setVelocity(Controller1.Axis1.position(),percent);

    DelDer.spin(forward);
    DelIzq.spin(forward);
    TraDer.spin(forward);
    TraIzq.spin(forward);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  bool permitirAdelante = true;

  while(true){
   while(Controller1.ButtonB.pressing()){
    extraerCubos();
   }
    while(Controller1.ButtonY.pressing()){
    soltarCubos();
   }

   while(Controller1.Axis3.position()){
    permitirAdelante = true;

    adelanteAtras(permitirAdelante);
   }

  while(Controller1.Axis1.position()){
        permitirAdelante = false;

    derechaIzquierda(permitirAdelante);
  }

  while(Controller1.ButtonR1.pressing()){
    Recolector.setVelocity(100,percent);
    Recolector.spin(forward);
  }

  while(Controller1.ButtonR2.pressing()){
    Recolector.setVelocity(-100,percent);
    Recolector.spin(forward);
  }


   EstDer.stop();
   EstIzq.stop();
   DelDer.stop();
   DelDer.stop();
   TraDer.stop();
   TraIzq.stop();
   Recolector.stop();
  }

  vexcodeInit();
  
}
