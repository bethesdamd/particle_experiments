// Simple Timer (and serial) demo
// From code sample on particle site
// CONNECT THE DEVICE TO THE COMPUTER'S USB, THIS WILL ONLY WORK UNDER THOSE CIRCUMSTANCES

// Then run:
// particle serial monitor

// Watch the published messages on the command line:
// curl https://api.particle.io/v1/devices/events?access_token=fa0d566664ad6e0f7b70f86f87c2b06e1d0a1170 (token may change)

int analogvalue;
int photoresistor = A0;
int power = A5;

void print_every_second()
{
    static int count = 0;
    Serial.println(count++);
}

void read_light() {
    analogvalue = analogRead(photoresistor);
    Particle.publish("light value", String(analogvalue));
}

Timer timer1(1000, print_every_second);

Timer timer2(5000, read_light);

void setup()
{
    Serial.begin(9600);
    timer1.start();
    timer2.start();
    pinMode(photoresistor,INPUT);
    pinMode(power,OUTPUT);
    digitalWrite(power,HIGH);
    Particle.variable("analogvalue", &analogvalue, INT);
    Particle.variable("testvar", "hi");
}
