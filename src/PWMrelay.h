/*
    PWMrelay - библиотека для генерации низкочастотного ШИМ сигнала для реле (для ПИД регуляторов и проч.)
    Документация: https://alexgyver.ru/pwmrelay/
    GitHub: https://github.com/GyverLibs/PWMrelay
    Возможности:
    - Настройка периода ШИМ
    - Настройка сигнала 0-255 (8 бит)
    - Поддержка реле низкого и высокого уровня
    - Неблокирующий вызов, не использует таймеры (кроме системного), работает на millis()

    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.1 - убрана реализация из .h
    v1.2 - исправлены мелкие ошибки с совместимостью
*/

#pragma once
#include <Arduino.h>

class PWMrelay {
   public:
    PWMrelay(uint8_t pin, bool dir = false, uint16_t period = 1000);  // пин, уровень реле HIGH/LOW, период
    void tick();                                                      // тик, вызывать как можно чаще, сам управляет реле
    void setPWM(uint8_t duty);                                        // установить величину ШИМ, 0-255. При значении 0 и 255 тик неактивен!
    uint8_t getPWM();                                                 // возвращает величину ШИМ
    void setPeriod(uint16_t period);                                  // установить период ШИМ в миллисек. (по умолч. 1000мс == 1с)
    uint16_t getPeriod();                                             // получить период
    void setLevel(bool level);                                        // установить уровень реле (HIGH/LOW)

   private:
    void _recalc();
    void _write();

    bool _flag = false;
    bool _dir = false;
    uint8_t _pin = 0;
    uint8_t _duty = 0;
    uint16_t _period = 1000;
    uint16_t _activePeriod = 0;
    uint32_t _tmr = 0;
};
