#define LED_PIN PA8
#define SPEED    80
#define FREQ    800

class Morse {
private:
    int16_t speed;
    int16_t led_pin;
    int16_t freq;
public:
    void begin(int16_t _led_pin = LED_PIN, int16_t _speed = SPEED, int16_t _freq = FREQ) {
        speed   = _speed;
        led_pin = _led_pin;
        freq    = _freq;
    }
    void morse_str(char*);
    void set_speed(int16_t _speed)      { speed = _speed;};
    void set_led_pin(int16_t _led_pin)  { led_pin = _led_pin;};
    void set_freq(int16_t _freq)        { freq = _freq;};
    void short_beep(void);
    void long_beep(void);
    void morse_chr(char);
};