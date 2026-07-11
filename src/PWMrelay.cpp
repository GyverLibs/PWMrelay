#include "PWMrelay.h"

PWMrelay::PWMrelay(uint8_t pin, bool dir, uint16_t period) {
    _pin = pin;
    _dir = !dir;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _dir);  // сразу выкл
    PWMrelay::setPeriod(period);
}

void PWMrelay::tick() {
    if (_duty != 0 && _duty != 255) {
        uint32_t ms = millis();
        if (ms - _tmr >= (_flag ? _activePeriod : (_period - _activePeriod))) {
            _tmr = ms;
            _flag = !_flag;
            _write();
        }
    }
}

void PWMrelay::setPWM(uint8_t duty) {
    _duty = duty;
    _recalc();
    if (_duty == 0) {
        _flag = false;
    } else if (_duty == 255) {
        _flag = true;
    } else {
        _flag = false;
        _tmr = millis();
    }
    _write();
}

uint8_t PWMrelay::getPWM() {
    return _duty;
}

void PWMrelay::setPeriod(uint16_t period) {
    _period = period ? period : 1;
    PWMrelay::setPWM(_duty);  // на случай "горячей" смены периода
}

uint16_t PWMrelay::getPeriod() {
    return _period;
}

void PWMrelay::setLevel(bool level) {
    _dir = !level;
    _write();
}

void PWMrelay::_recalc() {
    _activePeriod = (uint32_t)_duty * _period / 255;
    if (_duty != 0 && _duty != 255) {
        if (!_activePeriod) _activePeriod = 1;
        if (_activePeriod >= _period) _activePeriod = _period - 1;
    }
}

void PWMrelay::_write() {
    digitalWrite(_pin, _flag ^ _dir);
}
