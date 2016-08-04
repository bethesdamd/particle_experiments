### Monitor light level with a Particle.io board and send data to cloud and node-red for visualization

This project uses the http://particle.io board to monitor light levels in a room, and then push the data periodically to the Particle Cloud, where it is then picked up by node-red for visualization (or other processing).

Circuit:
Place a CDS cell across pins A0 and A5 pins
Place a 12k ohm resistor across A0 and GND pins

The code is well-commented.

#### Node-red
This is an IBM open source tool at http://nodered.org.  Beyond the scope of this document to explain what node-red does.  I've included the node-red file so you can try it out.  It requires:

- https://www.npmjs.com/package/node-red-contrib-ui
- https://www.npmjs.com/package/node-red-contrib-particle
