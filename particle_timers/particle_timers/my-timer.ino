// Simple Timer (and serial) demo
// From code sample on particle site
// See this page for schematic and code:
// https://docs.particle.io/guide/getting-started/examples/photon/#read-your-photoresistor-function-and-variable

// Then run:
// particle serial monitor (serial monitor only works when particle is directly connected to pc via usb)

// Watch the published messages on the command line:
// curl https://api.particle.io/v1/devices/events?access_token=fa0d566664ad6e0f7b70f86f87c2b06e1d0a1170 (token may change)

// Note to self: if the IDE produces "Build didn't produce binary" error, then manually compile from the command line like so:
// particle compile photon
// particle flash <devicename> <photon_firmware_file_name.bin>

// Circuit:
// Place a CDS cell across pins A0 and A5 pins
// Place a 12k ohm resistor across A0 and GND pins

int analogvalue;
int photoresistor = A0;
int power = A5;

// For debugging in the serial monitor
void print_every_second()
{
    static int count = 0;
    Serial.println(count++);
}

void read_light() {
    analogvalue = analogRead(photoresistor);
    Particle.publish("light_value", String(analogvalue));  // Publish the data to the Particle Cloud
}

Timer timer1(3000, print_every_second);

Timer timer2(1 * 60 * 1000, read_light);

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
