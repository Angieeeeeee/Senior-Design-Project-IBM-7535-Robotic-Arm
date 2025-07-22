#include "OptaBlue.h"

void setup() {
  OptaController.begin();

  while (OptaController.getExpansionNum() == 0) {
    OptaController.update();
    delay(500);
  }

  // Force the correct type
  //Opta::AnalogExpansion aexp = (Opta::AnalogExpansion&)OptaController.getExpansion(0);

  // Set PWM output on PWM1+ (P1)
  //aexp.setPwm(OA_PWM_CH_0, 50, 20);  // 100% duty cycle = constant high
}

void loop() {
  OptaController.update();
  Opta::AnalogExpansion aexp = (Opta::AnalogExpansion&)OptaController.getExpansion(0);
  aexp.setPwm(OA_PWM_CH_0, 400, 25);
  delay(100);
}
