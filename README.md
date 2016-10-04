# SmartGreenhouse

### Description:
A repository with the basic functions to an autonomous greenhouse.
There is no limited number of connected components (e.g. sensors)

### Installation:
There is not specific installation, it just need to be uploaded to arduino. But the data struct need to be configured to make the components work.
**How to configure a new component**
*This is really easy to add, just follow the steps below*
* 1. Increment the number os components
  * Go to file "datatype.h" and in "#define TOTAL_COMPONENTS 3" change 3 to the number of your components
* 2. Upload the sketch and run it
  * Run the arduino and use the command "c help" trough the Serial Monitor
* 3. Give them things to do
  * Go to file "components.h" the last function called "check_components" and crete your own method to controle one component,
  using the output of another one, or by time. You know what to do. (Don't forget to reupload)


### Usage:
After the installation, everything should be running fine. If any port number and/or type is change, it changes in realtime, with need to restart. But there ar some precaution, read **Notes** below!
**Note** Changes are not automatically updated, the user needs to update using the command *save*. Data is automatically loaded. 
**Note(2)** It's recomended to not disconnect components from one port and connect to another with arduino running. So, update the data, save it, turn of arduino, change ports and start again.
#### In this example
In this example it uses three components, in this case, two leds and one **potentiometer** (the circuit sketch is at the end)
***The first led*** is controlled by time. At the time *X* it turns on, at the time *Y* it turns off
***The second led*** is controlled using the potentiometer's output.
It can be used as a water dropped controller by hour, using an rtc, and a heater and coller controlled by temperature.
This is just an example. See th sketch ![here](https://github.com/obernardovieira/SmartGreenhouse)

### Contributing:
Everyone is free to contribute. Fork the project, make you changes and pull request. If you find bugs open an issue, or you can fix by yourself just forking, make changings and then pull request. It's complitly free project, so you can download and use it on your own.

### Credits:
obernardovieira

### License:
GNUv3
