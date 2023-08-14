#define X_JOY A0 // Пин оси Х
#define Y_JOY A1 // Пин оси Y
#define RIGHT 3 // Кнопка Вправо
#define LEFT 5 // Кнопка Влево
#define DOWN 4 // Кнопка Вниз
#define UP 2 // Кнопка Вверх
#define E 6 // Кнопка Е
#define F 7 // Кнопка F
#define K 8 // Кнопка К (конпка под джойстиком) (на v.1A), на другой версии шилда смотрите сами и меняёте если хотите.

void setup()
{
  // Поддтяшиваем кнопки резистором
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  pinMode(F, INPUT_PULLUP);
  pinMode(K, INPUT_PULLUP);
  Serial.begin(9600); // Запускаем COM-порт
}

void loop()
{
  // Таймер на 30мс (30 раз в секунду)
  static uint32_t tmr;
  if (millis() - tmr >= 30) {
    tmr = millis();
    // Считываем значение с кнопок
    boolean right = !digitalRead(RIGHT);
    boolean left = !digitalRead(LEFT);
    boolean down = !digitalRead(DOWN);
    boolean up = !digitalRead(UP);
    boolean e = !digitalRead(E);
    boolean f = !digitalRead(F);
    boolean kb = !digitalRead(K); // kb потому что просто k евляется какой-то командой.
    // Считываем и обрезаем значение со стика при помощи команд map() и constrain().
    int val_x = analogRead(X_JOY); 
    val_x = map(val_x, 0, 1023, 0, 255);
    val_x = constrain(val_x, 0, 255);
    int val_y = analogRead(Y_JOY);
    val_y = map(val_y, 0, 1023, 0, 255);
    val_y = constrain(val_y, 0, 255);
    // Осталось вывести все занчения с кнопок и стика.
    Serial.print("x: ");Serial.print(val_x);Serial.print(" y: ");Serial.print(val_y);Serial.print("  |  ");
    Serial.print("ButtonDOWN: ");Serial.print(down);Serial.print(" ButtonUP: ");Serial.print(up);Serial.print(" ButtonRIGHT: ");Serial.print(right);Serial.print(" ButtonLEFT: ");Serial.print(left);
    Serial.print(" ButtonE: ");Serial.print(e);Serial.print(" ButtonF: ");Serial.print(f);Serial.print(" ButtonK: ");Serial.println(kb); 
  }
}
// Здарова Алекс и ничикон, надеюсь вы когда-нибудь посмотрите мой канал и этот проект. :)
// https://www.youtube.com/channel/UC8cQtZ49KFYy3E-_9oM-eKg - это мой канал.
