![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![author](https://img.shields.io/badge/author-AlexGyver-informational.svg)
# PWMrelay
PWMrelay - библиотека для генерации низкочастотного ШИМ сигнала для реле (для ПИД регуляторов и проч.)
- Настройка периода ШИМ
- Настройка сигнала 0-255 (8 бит)
- Поддержка реле низкого и высокого уровня
- Неблокирующий вызов, не использует таймеры (кроме системного), работает на millis()

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

### Документация
К библиотеке есть [расширенная документация](https://alexgyver.ru/PWMrelay/)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **PWMrelay** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/PWMrelay/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
```cpp
PWMrelay relay(пин);
```

<a id="usage"></a>
## Использование
```cpp
PWMrelay(int pin, bool dir = false, int period = 1000);	// пин, уровень реле HIGH/LOW, период
void tick();					// тик, вызывать как можно чаще, сам управляет реле
void setPWM(byte duty);			// установить величину ШИМ, 0-255. При значении 0 и 255 тик неактивен!
byte getPWM();					// возвращает величину ШИМ
void setPeriod(int period);		// установить период ШИМ в миллисек. (по умолч. 1000мс == 1с)
int getPeriod();				// получить период
void setLevel(bool level);		// установить установить уровень реле (HIGH/LOW)
```

<a id="example"></a>
## Пример
Остальные примеры смотри в **examples**!
```cpp
#include "PWMrelay.h"
PWMrelay relay(13); // реле на 13 пине

// или так
// PWMrelay relay(13, HIGH); // реле высокого уровня на 13 пине
// PWMrelay relay(13, HIGH, 2000); // реле высокого уровня на 13 пине, период 2 секунды

void setup() {
  Serial.begin(9600);
  
  relay.setLevel(HIGH);   // можно поменять уровень реле (HIGH/LOW)
  
  relay.setPeriod(1000);  // можно поменять период, миллисекунды

  relay.setPWM(20);       // задаём сигнал ШИМ 0-255
}

void loop() {
  // вызываем в лупе, данная функция сама управляет реле
  relay.tick();   
}
```

<a id="versions"></a>
## Версии
- v1.2 - исправлены мелкие ошибки с совместимостью

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!