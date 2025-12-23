const int pin_servo = 0;     // PB0 = pin 5
const int pin_bouton = 3;    // PB3 = pin 2

int compteur = 0;
int switch_state;
int last_switch_state = HIGH;

void setup() {
  pinMode(pin_bouton, INPUT_PULLUP);  // Bouton avec résistance pull-up interne
  pinMode(pin_servo, OUTPUT);         // Configure PB0 en sortie pour le servo
}

void loop() {
  switch_state = digitalRead(pin_bouton);

  if (switch_state == LOW && last_switch_state == HIGH) {
    compteur++;
    delay(150); // anti-rebond
  }

  // Détermination de la largeur d'impulsion selon le compteur
  int pulseWidth;
  if (compteur % 2 == 0) {
    pulseWidth = 1500;  // Position milieu (~90°)
  } else {
    pulseWidth = 450;   // Position extrême (~0°)
  }

  // Génération manuelle du signal PWM pour 1 cycle (20 ms)
  digitalWrite(pin_servo, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(pin_servo, LOW);
  delay(20 - pulseWidth / 1000);  // Compléter les 20 ms

  last_switch_state = switch_state;

  delay(50);  // Délai pour ne pas saturer le bouton
}
